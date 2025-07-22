// Leetcode: 53. Maximum Subarray   --->   Given an integer array nums, find the subarray with the largest sum,
// and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Algorithm: A subarray is a contiguous part of the array. Example:
//            For the arr: [1, 2, 3, 4, 5, 6]
//            Subarrays can be: [1] or [2] or [1, 2] or [1, 2, 3] or [2, 3] or [4, 5, 6], etc.
//            But [1, 3, 4] or [1, 3] or [2, 3, 5] cannot be called a subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    int maxSubArray(vector<int>& nums) {
        
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << Solution().maxSubArray(nums);

    return 0;
}
