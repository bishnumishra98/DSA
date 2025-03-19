// Leetcode 746. Min Cost Climbing Stairs   --->   You are given an integer array cost where cost[i] is the cost of ith step
// on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

// Example 1:
// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Example 2:
// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

// This problem is similar to 'BaseBuildingPrograms\21. Dynamic_Programming\DP02_FrogJump.cpp'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, vector<int>& cost) {
        // Base cases: If you are at 0th step, pay cost[0] and climb the top. If you are at 1st step, pay cost[1] and climb the top.
        if(index == 0) return cost[0];
        if(index == 1) return cost[1];

        // For landing on current index, you must have landed previously on either 'index-1'th or 'index-2'th step.
        // Minimum cost to land at current index = minimum cost path between the above two paths + cost of current index step.
        int minCost = min(solve(index-1, cost), solve(index-2, cost)) + cost[index];
        return minCost;
    }

    // T.C: O(2 * 2^n) = O(2^(n+1))
    // S.C: O(2 * 2^n) = O(2^(n+1))
    int minCostClimbingStairs_recursion(vector<int>& cost) {
        int n = cost.size();
        // We want to reach the top of the floor, i.e., beyond the last element of 'cost'. In order to jump out of
        // the vector 'cost', our 2nd last foot must fall on any one of the two steps: either 'n-1'th or 'n-2'th step,
        // i.e., the last element or the 2nd last element of 'cost'.
        // Thus, we try finding minimum cost from both the cases; and return the minimum cost path between the two.
        return min(solve(n-1, cost), solve(n-2, cost));
    }

// --------------------------------------------------------------------------------------------------------------------------

    int solve(int index, vector<int>& cost, vector<int>& dp) {
        if(index == 0) return cost[0];
        if(index == 1) return cost[1];

        if(dp[index] != -1) return dp[index];

        dp[index] = min(solve(index-1, cost, dp), solve(index-2, cost, dp)) + cost[index];
        return dp[index];
    }

    // T.C: O(n)
    // S.C: O(n)
    int minCostClimbingStairs_memoization(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }

// --------------------------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int minCostClimbingStairs_tabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the dp array
        for(int index = 2; index < n; index++) {
            dp[index] = min(dp[index-1], dp[index-2]) + cost[index];
        }

        return min(dp[n-1], dp[n-2]);
    }

// --------------------------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(1)
    int minCostClimbingStairs_tabulation_SO(vector<int>& cost) {
        int n = cost.size();
        int prev = cost[1];
        int prev2 = cost[0];

        for(int index = 2; index < n; index++) {
            int curr = min(prev, prev2) + cost[index];
            prev2 = prev;
            prev = curr;
        }

        return min(prev, prev2);
    }

};

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    Solution sol;
    cout << "minCostClimbingStairs_recursion: " << sol.minCostClimbingStairs_recursion(cost) << endl;
    cout << "minCostClimbingStairs_memoization: " << sol.minCostClimbingStairs_memoization(cost) << endl;
    cout << "minCostClimbingStairs_tabulation: " << sol.minCostClimbingStairs_tabulation(cost) << endl;
    cout << "minCostClimbingStairs_tabulation_SO: " << sol.minCostClimbingStairs_tabulation_SO(cost);

    return 0;
}
