// Ye problem dubara dekhna hai due to failure of a test case {0, 0, 4} and all 0 related test cases.

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
//            1) Base case needs to be changed, we need to got deeper into the recursion tree and return when we reach
//               the first index of array; not when the target becomes zero because if we return as soon as target
//               becomes zero, we will miss out on some subsets that can be formed with 0s.
//               For example:
//               arr[] = {0, 0, 4}, target = 4
//               If we return as soon as target becomes zero, we will only count the subset {4} and miss out on the
//               other subsets like {0, 0, 4}, {0, 4}, {0, 4} which also sums to 4.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& arr, int target) {
        // Base cases: When we reach the first index of the array, we need to check if we can form a subset.
        // 1) If target is 0 and the first element is also 0, we can form two subsets: One by taking this 0,
        //    and one by not taking it. So, we return 2.
        // 2) If target is 0, we can form a subset by not taking the 0th element, so we return 1.
        // 3) If the 0th element is equal to target, we can form a subset by taking this element, so we return 1.
        // 4) If none of the above conditions are met, we cannot form a subset, so we return 0.
        if(i == 0) {
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }

        int notTake = solve(i - 1, arr, target);
        // By default, assume we cannot take the current element. If the current element is less than or equal to
        // the target, we can consider taking it.
        int take = 0;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i]);
        return take + notTake;
    }

    // T.C: O(2^n);   where n is the size of the array.
    // S.C: O(n);   recursion stack space
    int perfectSum_recursion(vector<int>& arr, int target) {
        int n = arr.size();
        return solve(n - 1, arr, target);
    }

// --------------------------------------------------------------------------------------------------------------

    int solve(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int notTake = solve(i - 1, arr, target, dp);
        int take = 0;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i], dp);
        
        return dp[i][target] = take + notTake;
    }

    // S.C: O(n * target)
    // T.C: O(n * target) for dp table + O(n) for recursion stack space = O(n * target)
    int perfectSum_memoization(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, arr, target, dp);
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * target)
    // S.C: O(n * target)
    int perfectSum_tabulation(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[i][j] means i are the index of the array till which we are considering elements, and j is the target target.
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        for(int i = 0; i < n; i++) dp[i][0] = 1;   // a subset is already formed if target is 0, so mark all rows in the first column as 1
        if (arr[0] == 0) dp[0][0] = 2;   // if target is 0, and first element is also 0, 2 subsets can be formed
        if (arr[0] <= target && arr[0] != 0) dp[0][arr[0]] = 1;   // if first element is equal to target, a subset can be formed

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[i - 1][t];   // exclude current element
                int take = 0;
                if (arr[i] <= t) take = dp[i - 1][t - arr[i]];   // include current element if valid
                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * target)
    // S.C: O(target)
    int perfectSum_tabulation_SO(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        // Base cases
        prev[0] = curr[0] = 1;   // a subset is already formed if target is 0, so mark all rows in the first column as 1
        if (arr[0] == 0) prev[0] = 2;    // if target is 0, and first element is also 0, 2 subsets can be formed
        if (arr[0] <= target && arr[0] != 0) prev[arr[0]] = 1;   // if first element is equal to target, a subset can be formed

        // Fill the DP table row-by-row
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int notTake = prev[t];   // exclude current element
                int take = 0;
                if (arr[i] <= t) take = prev[t - arr[i]];   // include current element if valid
                curr[t] = take + notTake;
            }
            prev = curr;   // move to the next row
        }

        return prev[target];
    }
};


int main() {
    vector<int> arr = {0, 0, 4};
    int target = 4;

    cout << Solution().perfectSum_recursion(arr, target) << endl;
    cout << Solution().perfectSum_memoization(arr, target) << endl;
    cout << Solution().perfectSum_tabulation(arr, target) << endl;
    cout << Solution().perfectSum_tabulation_SO(arr, target);

    return 0;
}
