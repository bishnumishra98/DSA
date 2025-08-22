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

// Optimal algorithm: The algorithm may look massive, but it is actually simple if you dry run it on paper.
//                    The idea is to partition the resultant array(sum of both arrays) into two halves such that
//                    all elements in the left half are less than or equal to all elements in the right half. Each half
//                    may contain some elements from both arrays, though there can be several cases where one half
//                    contains all elements from only one array, but that is not a problem.
//                    If resultant has even number of elements, then each half shall contain 'total / 2' elements, and
//                    if resultant has odd number of elements, then left half shall contain 'total + 1 / 2' elements,
//                    whereas the right half shall contain 'total / 2' elements, where total = nums1.size() + nums2.size().
//                    Generalised formula for number of elements in left half = (total + 1 / 2), and in right half
//                    = (total / 2). This formula works for both even and odd length resultant arrays.
//                    Now, let's say number of elements in left half is 'left', out of which 'l1' elements are from
//                    nums1 and 'l2' elements are from nums2, then we get the formula: left = l1 + l2.
//                    Similarly, if number of elements in right half is 'right', out of which 'r1' elements are from
//                    nums1 and 'r2' elements are from nums2, then we get the formula: right = r1 + r2.
//                    If number of elements in left half from nums1 is 'l1', then number of elements in right half
//                    from nums1 will be 'r1 = nums1.size() - l1'. Similarly, if number of elements in left half
//                    from nums2 is 'l2', then number of elements in right half from nums2 will be 'r2 = nums2.size() - l2'.
//                    There will be only one configuration of l1, l2, r1 and r2 such that all elements in left half are
//                    less than or equal to all elements in right half. Also, changing value of l1 will change the value
//                    of l2, r1 and r2. Hence, we can say there will be only one configuration of l1 such that all
//                    elements in left half are less than or equal to all elements in right half.
//                    Once we find the correct configuration of l1, we can easily find the median.
//
//                    ● Illustration for even length resultant: nums1 = [1, 3, 5], nums2 = [2, 4, 6];
//                      As resultant has even number of elements, left half is considered to have equal number of
//                      elements as right half, i.e., left half will have (3 + 3) / 2 = 3 elements, and right half
//                      will have (3 + 3) / 2 = 3 elements.
//                      Correct configuration for this problem will be: left half = [1, 2, 3], right half = [4, 5, 6].
//                      l1 will be 2, l2 will be (3 - 2) = 1; thus r1 and r2 will be (3 - 2) = 1 and (3 - 1) = 2,
//                      respectively. The configuration will be: left half = [1, 2, 3], right half = [4, 5, 6].
//                      To be precise, the detailed configuartion is actually:
//                      Left half (l1 = 2, l2 = 1)     |   Right half (r1 = 1, r2 = 2)
//                      nums1 = [1, 3]                 |   nums1 = [5]
//                      nums2 = [2]                    |   nums2 = [4, 6]
//                      Now we can observe that median will be average of largest element of left half and smallest
//                      element of right half, thus median = maxElement(l1, l2) + minElement(r1, r2) / 2, i.e.,
//                      (3 + 4) / 2 = 3.5.
//
//                    ● Illustration for odd length resultant: nums1 = [1, 3, 5], nums2 = [2, 4];
//                      As resultant has odd number of elements, left half is considered to have one extra element
//                      than right half, i.e., left half will have (3 + 2 + 1) / 2 = 3 elements, and right half
//                      will have (3 + 2) / 2 = 2 elements. Correct configuration for this problem will be:
//                      left half = [1, 2, 3], right half = [4, 5]; where l1 = 2, l2 = (3 - 2) = 1.
//                      r1 will be nums1.size() - l1 = (3 - 2) = 1, and r2 will be nums2.size() - l2 = (2 - 1) = 1.
//                      To be precise, the detailed configuartion is actually:
//                      Left half (l1 = 2, l2 = 1)     |   Right half (r1 = 1, r2 = 1)
//                      nums1 = [1, 3]                 |   nums1 = [5]
//                      nums2 = [2]                    |   nums2 = [4]
//                      Now we can observe that median lies on left haf, thus median = maxElement(l1, l2), i.e., 3.
//                   
//                      Hence, the whole problem boils down to finding the value of l1 such that all elements in left half
//                      are less than or equal to all elements in right half. If we can find such a value of l1, we can
//                      easily find the median.

//                      The range of l1 will be from 0 to nums1.size(), i.e., from the case when we do not consider any
//                      element from nums1 to the case when we consider all elements from nums1, in the left half.
//                      Thus, initialize the search space for l1 as start = 0 and end = nums1.size().
//                      Now, we can apply binary search on this search space to find the correct value of l1.
//                      PRO TIP: Always apply binary search on the smaller array to minimize the search space.
//                      Thus, if nums1 is larger than nums2, swap the two arrays, so that l1 always belongs to the
//                      smaller array.
//                      While start <= end, do the following:
//                      1. Find the mid-point of current search space, mid1 = (start + end) / 2. mid1 represents the
//                         number of elements from nums1 in left half, i.e., l1 = mid1.
//                         Also, find the number of elements from nums2 in left half, mid2 = left - mid1.
//                      2. Find the boundary elements around the partition:
//
//                      

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
        int left = (n1 + n2 + 1) / 2;   // no.of elements supposed to be kept in left half

        int start = 0, end = n1;
        while(start <= end) {
            int mid1 = start + (end - start) / 2;   // 'mid1' represents the number of elements from 'nums1' in left half
            int mid2 = left - mid1;   // 'mid2' represents the number of elements from 'nums2' in left half
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
