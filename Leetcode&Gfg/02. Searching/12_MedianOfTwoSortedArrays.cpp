// Leetcode: 4. Median of Two Sorted Arrays   --->   Given two sorted arrays nums1 and nums2 of size m and n
// respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Optimal algorithm: 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m + n);   where m = nums1.size(), n = nums2.size()
    // S.C: O(m + n)
    double findMedianSortedArrays_bruteforce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {   // if(nums1[i] >= nums2[j])
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }

        double median;
        int len = result.size();   // number of elements in 'results' array
        if(len & 1) {   // if 'result' has odd number of elements, median is the middle element
            median = result[len / 2];
        } else {   // if 'result' has even number of elements, median is the average of two middle elements
            int sum = result[len / 2] + result[(len / 2) - 1];
            median = (double)sum / 2;
        }

        return median;
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(log(min(m, n)));   where m = nums1.size(), n = nums2.size()
    // S.C: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);   // to make sure 'nums1' is always of shorter or equal length than 'nums2'

        int n = n1 + n2;   // total elements in the resultant array of 'nums1' and 'nums2'
        int left = (n1 + n2 + 1) / 2;   // no.of elements supposed to be kept in left symmetry

        int start = 0, end = n1;
        while(start <= end) {
            int mid1 = start + (end - start) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1) {
                if(n & 1) return max(l1, l2);
                return double(max(l1, l2) + min(r1, r2)) / 2;
            }
            else if(l1 > r2) end = mid1 - 1;
            else start = mid1 + 1;   // if(l2 > r1)
        }

        return 0;   // program will never reach here, but just to avoid compilation error
    }
};


int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << Solution().findMedianSortedArrays_bruteforce(nums1, nums2) << endl;
    cout << Solution().findMedianSortedArrays(nums1, nums2);

    return 0;
}
