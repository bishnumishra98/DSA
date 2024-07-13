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
        // Base cases: If index is 0, pay cost[0] and climb up. If index is 1, pay cost[0] and climb up.
        if(index == 0) return cost[0];
        if(index == 1) return cost[1];

        int left = solve(index-1, cost) + cost[index];
        int right = solve(index-2, cost) + cost[index];

        return min(left, right);
    }

    // T.C: O(2 * 2^n) = O(2^(n+1))
    // S.C: O(2 * 2^n) = O(2^(n+1))
    int minCostClimbingStairs_recursion(vector<int>& cost) {
        return min(solve(cost.size() - 1, cost), solve(cost.size() - 2, cost));
    }

// ---------------------------------------------------------------------------------------------


};

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    Solution sol;
    cout << "minCostClimbingStairs_recursion: " << sol.minCostClimbingStairs_recursion(cost) << endl;

    return 0;
}
