// leetcode: 70. Clibing Stairs   --->   You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top ?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// This problem is exactly similar to nth term of fibonacci number. Just the base case is slightly different.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(2^n)
    // S.C: O(2^n)
    int climbStairs_recursion(int n) {
        // Base case
        if(n <= 2) return n;

        int ans = climbStairs_recursion(n-1) + climbStairs_recursion(n-2);
        return ans;
    }

// ---------------------------------------------------------------------------------

    int solve(int n, vector<int>& dp) {
        // Base case
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    // T.C: O(n)
    // S.C: O(n)
    int climbStairs_memoization(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }

// ---------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int climbStairs_tabulation(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        if(n >= 2) dp[2] = 2;   // 'if(n >= 2)' to avoid heap buffer overflow

        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

// ---------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(1)
    int climbStairs_tabulation_SO(int n) {
        int prev2 = 1;
        if(n == 1) return prev2;
        int prev = 2;

        for(int i=3; i<=n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};


int main() {
    int n = 4;

    Solution sol;

    cout << sol.climbStairs_recursion(n) << endl;;
    cout << sol.climbStairs_memoization(n) << endl;
    cout << sol.climbStairs_tabulation(n) << endl;
    cout << sol.climbStairs_tabulation_SO(n) << endl;

    return 0;
}
