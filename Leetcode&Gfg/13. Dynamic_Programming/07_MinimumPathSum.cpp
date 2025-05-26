// Leetcode: 64. Minimum Path Sum   --->   Given a m x n grid filled with non-negative numbers, find a path from
// top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// Algorithm: Very easy. Almost similar to 'Leetcode&Gfg\13. Dynamic_Programming\05_UniquePaths.cpp'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        // Base cases:
        // 1) If i or j is less than 0, it means we are out of bounds. Thus, return a large value so that
        //    this path is never considered while choosing the minimum path sum.
        // 2) If we reach the top-left cell (0, 0), return its value as it is the only path available.
        if(i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[0][0];

        int left = grid[i][j] + solve(i, j - 1, grid);
        int up = grid[i][j] + solve(i - 1, j, grid);
        int pathSum = min(left, up);
        return pathSum;
    }

    // T.C: 2 ^ (m + n)
    // S.C: O(m + n);   recursion stack space
    int minPathSum_recursion(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m - 1, n - 1, grid);
    }

// ----------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[0][0];

        if(dp[i][j] != -1) return dp[i][j];

        int left = grid[i][j] + solve(i, j - 1, grid, dp);
        int up = grid[i][j] + solve(i - 1, j, grid, dp);
        int pathSum = min(left, up);
        dp[i][j] = pathSum;
        return dp[i][j];
    }

    // T.C: O(m * n)
    // S.C: O(m * n) for dp array + O(m + n) for recursion stack space = O(m * n)
    int minPathSum_memoization(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }

// ----------------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(m * n)
    int minPathSum_tabulation(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    int left = grid[i][j];
                    if(j >= 1) left += dp[i][j - 1];
                    else left += 1e9;
                    int up = grid[i][j];
                    if(i >= 1) up += dp[i - 1][j];
                    else up += 1e9;
                    dp[i][j] = min(left, up);
                }
            }
        }

        return dp[m - 1][n - 1];
    }

// ----------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(n)
    int minPathSum_tabulation_SO(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);   // this will store the previous row's results.

        for(int i = 0; i < m; i++) {
            vector<int> cur(n, 0);   // this will store the current row's results.
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) cur[j] = grid[0][0];   
                else {
                    int left = grid[i][j];
                    if(j >= 1) left += cur[j - 1];
                    else left += 1e9;
                    int up = grid[i][j];
                    if(i >= 1) up += prev[j];
                    else up += 1e9;
                    cur[j] = min(left, up);
                }
            }

            prev = cur;
        }

        return prev[n - 1];
    }
};


int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution().minPathSum_recursion(grid) << endl;
    cout << Solution().minPathSum_memoization(grid) << endl;
    cout << Solution().minPathSum_tabulation(grid) << endl;
    cout << Solution().minPathSum_tabulation_SO(grid);

    return 0;
}
