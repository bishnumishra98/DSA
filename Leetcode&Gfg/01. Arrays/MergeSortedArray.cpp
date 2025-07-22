// Leetcode: 88. Merge Sorted Array   --->   You are given two integer arrays nums1 and nums2, sorted in non-decreasing
// order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To
// accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Algorithm: Extremely simple 2 pointer approach. Elements to be compared from nums1 is from nums1[0 to m], and
//            elements to be compared from nums2 is from nums2[0 to n]. The result is to be stored in nums1 which is
//            of size m + n.
// 1. Initialize three variables i, j and k to m - 1, n - 1 and m + n - 1.
// 2. Use a while loop to compare elements from nums1 and nums2 starting from the end.
//    i.  If nums1[i] is greater than nums2[j], place nums1[i] at nums1[k] and decrement i and k.
//    ii. If nums1[i] is less than or equal to nums2[j], place nums2[j] at nums1[k] and decrement j and k.
// 3. After the while loop, if there are any remaining elements in nums1, copy them to nums1. Similarly, if there are
//    any remaining elements in nums2, copy them to nums1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m + n)
    // S.C: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        // Start merging from the end of nums1 and nums2
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                k--;
            } else {   // if(nums1[i] <= nums2[j])
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        // If there are remaining elements in nums1, copy them
        while(i >= 0) {
            nums1[k] = nums1[i];
            i--;
            k--;
        }

        // If there are remaining elements in nums2, copy them
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution().merge(nums1, m, nums2, n);
    for(auto it: nums1) cout << it << " ";

    return 0;
}
