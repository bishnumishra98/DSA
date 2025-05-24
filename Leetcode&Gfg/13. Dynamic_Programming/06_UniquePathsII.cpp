// Leetcode: 63. Unique Paths II   --->   You are given an m x n integer array grid. There is a robot initially
// located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner
// (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include
// any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 10^9.

// Example 1:
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:
// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

// Algorithm: Exactly same as 'Leetcode&Gfg\13. Dynamic_Programming\05_UniquePaths.cpp',
//            the difference being here we have an extra base case.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // Base cases:
        // 1) For a valid cell, if the cell is blocked, return 0 as no path can be formed through it.
        //    Note: Make sure to keep this base case at first, to pass the test case for the input {{1}}.
        // 2) If i or j goes out of bounds, return 0 stating no path found.
        // 3) If i and j both are at 0, it means we successfully reached [0][0]. Thus return 1 stating that 1 path is found.
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, obstacleGrid, dp);
        int up = solve(i - 1, j, obstacleGrid, dp);
        int totalPaths = left + up;
        dp[i][j] = totalPaths;
        return dp[i][j];
    }
    
public:
    // T.C: O(m * n)
    // S.C: O(m * n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};


int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid);

    return 0;
}
