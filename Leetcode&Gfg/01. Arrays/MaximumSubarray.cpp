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

// Constraints:
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4

// Optimal algorithm: Kadane's algorithm is based on the idea of carrying a running sum of the maximum subarray
// ending at each index, and updating the maximum sum found so far. If the running sum becomes negative, it is reset to 0.
// This allows the algorithm to efficiently find the maximum subarray sum in a single pass through the array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Similar to optimised brute force of 'Leetcode&Gfg\01. Arrays\LongestSubarrayWithSumK.cpp'
    // T.C: O(n^2)
    // S.C: O(1)
    int maxSubArray_bruteforce(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;   // never initialize to 0, because maximum sum can even be negative. In that case, you will get wrong output as 0.
        for(int i = 0 ; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

// -------------------------------------------------------------------------------------------------------------

    // Kadane's algorithm
    // T.C: O(n)
    // S.C: O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }

// -------------------------------------------------------------------------------------------------------------

    // ● Follow up question: Print the elements of maximum subarray.
    // Algorithm: It is very simple.
    // 1. One thing we can observe is that if the sum becomes 0 in Kadane's algorithm, then a new subarray starts from
    //    that index. So, we can keep track of the starting index of the subarray.
    // 2. Whenever we find a new maximum sum, we can update the starting index (already marked when sum was 0) in a
    //    variable say 'ansStart' and ending index in a variable say 'ansEnd' of the subarray respectively.
    // 3. After iterating all the elements, we can use the starting and ending indices (ansStart and ansEnd) to print
    //    the elements of the maximum subarray.
    // T.C: O(n)
    // S.C: O(1)
    vector<int> maxSubArray_print(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;

        int start = 0, ansStart = 0, ansEnd = 0;
        for(int i = 0; i < n; i++) {
            if(sum == 0) start = i;   // a new subarray starts from index 'i' if sum is 0
            sum += nums[i];
            // If current sum is greater than maxSum, update maxSum and the indices of the subarray that gives this sum
            if(sum > maxSum) {
                maxSum = sum;
                ansStart = start;   // start index of the maximum subarray
                ansEnd = i;   // end index of the maximum subarray
            }
            if(sum < 0) sum = 0;
        }

        vector<int> ans;
        for(int i = ansStart; i <= ansEnd; i++) ans.push_back(nums[i]);
        return ans;
    }
};


int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {-4, -3};

    cout << Solution().maxSubArray_bruteforce(nums) << endl;
    cout << Solution().maxSubArray(nums) << endl;
    vector<int> ans = Solution().maxSubArray_print(nums);
    for(auto it: ans) cout << it << " ";

    return 0;
}
