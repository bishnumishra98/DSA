// GFG: Perfect Sum Problem   --->   Given an array arr of non-negative integers and an integer target, the task
// is to count all subsets of the array whose sum is equal to the given target.

// Example 1:
// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// Example 2:
// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

// Example 3:
// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.

// Example 4:
// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.

// Problem link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Algorithm: Very easy. Its just a small extension of 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp'.
//            There, we were asked to just return true if a subset is equal to given target, else false. But here we
//            are asked to return the number of subsets.
//            The code remains almost the same with some minor changes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& arr, int target) {
        // Base cases:
        // 1) If the target is 0, we have found a subset that sums to the target. Thus return 1.
        // 2) If we have no elements left (i == 0), we can only form the subset if the first element equals target.
        if(target == 0) return 1;
        if(i == 0) return (arr[0] == target);   // returns 1 if 'arr[0] == target', else 0

        int notTake = solve(i - 1, arr, target);
        // By default, assume we cannot take the current element. If the current element is less than or equal to
        // the target, we can consider taking it.
        int take = 0;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i]);
        return take + notTake;
    }

    // T.C: O(2^n)
    // S.C: O(n);   recursion stack space
    int perfectSum_recursion(vector<int>& arr, int target) {
        int n = arr.size();
        return solve(n - 1, arr, target);
    }

// --------------------------------------------------------------------------------------------------------------

    int solve(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(target == 0) return 1;
        if(i == 0) return (arr[0] == target);

        if(dp[i][target] != -1) return dp[i][target];

        int notTake = solve(i - 1, arr, target, dp);
        int take = 0;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i], dp);
        
        return dp[i][target] = take + notTake;
    }

    // S.C: O(n * sum)
    // T.C: O(n * sum) for dp table + O(n) for recursion stack space = O(n * sum)
    int perfectSum_memoization(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, arr, sum, dp);
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * sum)
    // S.C: O(n * sum)
    int perfectSum_tabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        // dp[i][j] means i are the index of the array till which we are considering elements, and j is the target sum.
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // Base cases:
        // 1) A subset is already formed if target is 0, so mark all rows in the first column as 1.
        // 2) If the first element is equal to target, mark it as 1.
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        if(arr[0] <= sum) dp[0][arr[0]]= 1;   // if(arr[0] <= sum) condition is added to avoid the case when the
        // first element itself is greater than sum. If the first element is itself is greater than sum, then it does
        // not makes any sense to mark dp[0][arr[0]] as 1, because dp[0][arr[0]] means that we can form a subset
        // with the first element itself, which is not possible if the first element is greater than sum.

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                int notTake = dp[i - 1][target];
                int take = 0;
                if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
                dp[i][target] = take + notTake;
            }
        }

        return dp[n - 1][sum];
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * sum)
    // S.C: O(sum)
    int perfectSum_tabulation_SO(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

        // Base cases:
        prev[0] = curr[0] = 1;   // a subset is already formed if target is 0, so mark all rows in the first column as 1
        if(arr[0] <= sum) prev[arr[0]] = 1;   // if the first element is equal to target, mark it as 1.

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                int notTake = prev[target];
                int take = 0;
                if(arr[i] <= target) take = prev[target - arr[i]];
                curr[target] = take + notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};


int main() {
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;

    cout << Solution().perfectSum_recursion(arr, target) << endl;
    cout << Solution().perfectSum_memoization(arr, target) << endl;
    cout << Solution().perfectSum_tabulation(arr, target) << endl;
    cout << Solution().perfectSum_tabulation_SO(arr, target);

    return 0;
}
