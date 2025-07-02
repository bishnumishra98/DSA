// Leetcode: 300. Longest Increasing Subsequence   --->   Given an integer array nums, return the length of the
// longest strictly increasing subsequence.

// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Brute force: The brute force approach is to generate all the subsequences of the given array and then check
//              which of them is strictly increasing and return the length of the longest one.
//              This approach has exponential time complexity and is not efficient for large inputs.

// Optimal algorithm: It is based on the same pattern as subsequence problems are, pick and not pick pattern.
//                    We have to find all possible ways to find the LIS using recursion.
//                    Call a function f(index, lastIndex) which returns the length of LIS starting from 'index'. The
//                    'lastIndex' is an additional argument passed to the function which is used to keep track of
//                    the index of last element that was included in the LIS. It helps in making sure that the next
//                    element to be inserted in the LIS is strictly greater than the last element inserted in the LIS.
//                    For illustration, f(3, 1) would mean that we are at 3rd index of 'nums', and the last element
//                    inserted in the LIS was element at 1st index of 'nums' array. Thus, if the element at 3rd index
//                    of 'nums' wants to get included in the LIS, it must be greater than the last element of the
//                    LIS which is 1st element of 'nums'.
//                    Start the recursive call with f(0, -1) meaning that we are starting to build the LIS from the
//                    first element of the array and there is no last element currently in the LIS.
// 1. Base case: It is very simple. When 'nums' gets exhausted, i.e., when 'index' reaches nums.size(), return 0 stating
//               that no more length of LIS can be formed.
// 2. Recursive relation: At any index, we just have two choice in hand, either include the element at that index in
//                        your LIS, or exclude it. Thus, there will be two simple recursive relations:
//    I.  Include the 'index'th element in LIS: If you choose to include the 'index'th element in the LIS, either of the
//                                              two conditions must be true. Either the previous index must point to -1
//                                              (case when we are at first element of the 'nums' array), or if 'index'th
//                                              element is greater than the 'lastIndex'th element (case when current
//                                              element is greater than the last element inserted in the LIS). If the
//                                              current element is valid to be included in the LIS, add 1 to the length
//                                              of the LIS as current element was included in LIS; and then call the next
//                                              recursive function for next element of 'nums' and update the 'lastIndex'
//                                              as 'index' because the current element is included in the LIS, hence it
//                                              becomes the last element included in the LIS, i.e., call
//                                              1 + f(index + 1, index) and store the length returned by it in a
//                                              variable say 'takeLen', meaning length of LIS if current element is taken
//                                              in the LIS.
//    II. Exclude the 'index'th element in LIS: If you choose to exclude the 'index'th element in the LIS, add 0 to the
//                                              length of LIS as current element was not included in LIS; and then call
//                                              the next recursive function for next element of 'nums' and keep the
//                                              'lastIndex' same as it was because no element is included in the LIS. Thus,
//                                              call 0 + f(index + 1, lastIndex) and store the length returned by it in a
//                                              variable say 'notTakeLen', meaning length of LIS if current element is not
//                                              taken in the LIS.
//    At the end, return the larger value returned by trying out both the above paths.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int lastIndex, vector<int>& nums, int n) {
        // Base case: If the 'nums' is exhausted, return 0 stating that no more length of LIS can be found
        if(index == n) return 0;

        int takeLen = 0;   // length of LIS if you include the 'index'th element in LIS
        if(lastIndex == -1 || nums[index] > nums[lastIndex]) {   // writing 'lastIndex == -1' first is mandatory
            takeLen = 1 + solve(index + 1, index, nums, n);
        }

        int notTakeLen = 0 + solve(index + 1, lastIndex, nums, n);   // length of LIS if you exclude the 'index'th element in LIS

        return max(notTakeLen, takeLen);
    }

    // T.C: O(2^n)   because for every element, we have two choices: either take it or not take it
    // S.C: O(n)   recursion stack space
    int lengthOfLIS_recursion(vector<int>& nums) {
        int n = nums.size();
        return solve(0, -1, nums, n);
    }

// -------------------------------------------------------------------------------------------------------------

    int solve(int index, int lastIndex, vector<int>& nums, int n, vector<vector<int>>& dp) {
        // Base case: If the 'nums' is exhausted, return 0 stating that no more length of LIS can be found
        if(index == n) return 0;

        if(dp[index][lastIndex + 1] != -1) return dp[index][lastIndex + 1];

        int takeLen = 0;
        if(lastIndex == -1 || nums[index] > nums[lastIndex]) {   // writing 'lastIndex == -1' first is mandatory
            takeLen = 1 + solve(index + 1, index, nums, n, dp);
        }

        int notTakeLen = 0 + solve(index + 1, lastIndex, nums, n, dp);

        return dp[index][lastIndex + 1] = max(notTakeLen, takeLen);
    }

    // T.C: O(n^n) = O(n^2)
    // S.C: O(n^2) for dp table + O(n) for recursion stack space = O(n^2)
    int lengthOfLIS_memoization(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, n, dp);
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << Solution().lengthOfLIS_recursion(nums) << endl;
    cout << Solution().lengthOfLIS_memoization(nums) << endl;

    return 0;
}
