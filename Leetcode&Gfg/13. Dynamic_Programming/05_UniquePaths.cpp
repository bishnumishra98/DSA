// Leetcode: 62. Unique Paths   --->   There is a robot on an m x n grid. The robot is initially located at the
// top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
// The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the
// bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: m = 3, n = 7
// Output: 28

// Example 2:
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Algorithm: We will simply apply brute force recursion to find the number of unique paths from the top-left corner
//            to the bottom-right corner.
//            In the problem, we are asked move from [0][0] to [m - 1][n - 1] in a grid. Thus, it means the same as
//            going from [m - 1][n - 1] to [0][0]. So find out all possible ways in which we can reach
//            from [m - 1][n - 1] to [0][0].
//            The reason we are going from [m - 1][n - 1] to [0][0] is that it is easier to think of the base cases
//            when we are at the destination cell [0][0].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j) {
        // Base cases:
        // 1) If i or j goes out of bounds, return 0 stating no path found.
        // 2) If i and j both are at 0, it means we successfully reached [0][0]. Thus return 1 stating that 1 path is found.
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;

        int left = solve(i, j - 1);   // find no.of paths found by going left of [i][j]
        int up = solve(i - 1, j);   // find no.of paths found by going up of [i][j]
        int totalPaths = left + up;   // the total number of paths to reach [i][j] from [m - 1][n - 1] is the sum of paths from left and up
        return totalPaths;
    }

    // T.C: O(2^(m + n))
    // S.C: O(m + n)
    int uniquePaths_recursion(int m, int n) {
        return solve(m - 1, n - 1);
    }

// --------------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, dp);
        int up = solve(i - 1, j, dp);
        int totalPaths = left + up;
        dp[i][j] = totalPaths;
        return dp[i][j];
    }

    // T.C: O(m * n)
    // S.C: O(m * n)
    int uniquePaths_memoization(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(m * n)
    int uniquePaths_tabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int left = 0, up = 0;
                    if(j >= 1) left = dp[i][j - 1];   // if() to avoid heap buffer overflow
                    if(i >= 1) up = dp[i - 1][j];   // if() to avoid heap buffer overflow
                    int totalPaths = left + up;
                    dp[i][j] = totalPaths;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
// --------------------------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(n)
    int uniquePaths_tabulation_SO(int m, int n) {
        // Create a vector to represent the previous row of the grid.
        vector<int> prev(n, 0);

        // Iterate through the rows of the grid.
        for(int i = 0; i < m; i++) {
            vector<int> temp(n, 0);   // create a temporary vector to represent the current row.

            // Iterate through the columns of the grid.
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                int left = 0, up = 0;   // let no.of paths found from left and up be 0 initially.
                if(i >= 1) up = prev[j];   // if we are not at the first row (i >= 1), update 'up' with the value from the previous row.
                if(j >= 1) left = temp[j - 1];   // if we are not at the first column (j >= 1), update 'left' with the value from the current row.
                temp[j] = up + left;   // calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            }

            prev = temp;   // update the previous row with the values calculated for the current row.
        }

        return prev[n - 1];   // the result is stored in the last cell of the previous row (n - 1)
    }
};


int main() {
    int m = 3, n = 7;

    Solution sol;
    cout << "uniquePaths_recursion: " << sol.uniquePaths_recursion(m, n) << endl;
    cout << "uniquePaths_memoization: " << sol.uniquePaths_memoization(m, n) << endl;
    cout << "uniquePaths_tabulation: " << sol.uniquePaths_tabulation(m, n) << endl;
    cout << "uniquePaths_tabulation_SO: " << sol.uniquePaths_tabulation_SO(m, n);

    return 0;
}
