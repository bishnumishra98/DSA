// Problem link: https://www.naukri.com/code360/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Unique Paths   --->   You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is
// point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths
// from point ‘A’ to point ‘B’. In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’,
// your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
// To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j],
// you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

// Example 1:
// Input:
// 2 2
// Output:
// 2
// Explanation:
// We are given a 2 x 2 matrix, to move from matrix[0][0] to matrix[1][1] we have the following possible paths.
// Path 1 = (0, 0) -> (0, 1) -> (1, 1)
// Path 2 = (0, 0) -> (1, 0) -> (1, 1)
// Hence a total of 2 paths are available, so the output is 2.

// Example 2:
// Input:
// 3 2
// Output:
// 3

// Example 3:
// Input:
// 3 3
// Output:
// 6

// Algorithm: We are allowed to move only right or down to reach from [0][0] to [m - 1][n - 1] in a grid. Thus, it means
// the same as going only left or up from [m - 1][n - 1] to [0][0]. So find out all possible ways in which we can reach
// from [m - 1][n - 1] to [0][0].

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j) {
	// Base cases:
    // 1) If i or j goes out of bounds, return 0 starting that no path found.
    if(i < 0 || j < 0) return 0;
    // 2) If i and j both are at 0, it means we successfully reached [0][0]. Thus return 1 stating that 1 path is found.
    if(i == 0 && j == 0) return 1;

    int left = solve(i, j - 1);   // find no.of paths found by going left of [i][j]
    int up = solve(i - 1, j);   // find no.of paths found by going up of [i][j]
    return left + up;   // return the sum of no.of paths found by going left of [i][j] and up of [i][j].
}

// T.C: O(2^(m + n))
// S.C: O(m + n)
int uniquePaths_recursion(int m, int n) {
    return solve(m - 1, n - 1);
}

// ----------------------------------------------------------------------------------------------------------------------------

int solve(int i, int j, vector<vector<int>>& dp) {
    if(i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int left = solve(i, j - 1, dp);
    int up = solve(i - 1, j, dp);
    dp[i][j] = left + up;
    return dp[i][j];
}

// T.C: O(m*n)
// S.C: O(m+n)
int uniquePaths_memoization(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n, -1));   // 2D vector of size m * n
    return solve(m - 1, n - 1, dp);
}

// ----------------------------------------------------------------------------------------------------------------------------

// T.C: O(m*n)
// S.C: O(m+n)
int uniquePaths_tabulation(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n, 0));   // 2D vector of size m * n, with initial values 0.

    // Compute all values of dp[i][j] where i: 0 -> m - 1, and j: 0 to n - 1.
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            int left = 0, up = 0;   // let no.of paths found from left and up be 0 initially.
            if(j >= 1) left = dp[i][j - 1];   // if() condition is to avoid heap buffer overflow for j = 0
            if(i >= 1) up = dp[i - 1][j];   // if() condition is to avoid heap buffer overflow for i = 0
            dp[i][j] = left + up;
        }
    }

    return dp[m - 1][n - 1];   // the result is stored in the bottom-right cell (m-1, n-1).
}

// ----------------------------------------------------------------------------------------------------------------------------

// T.C: O(m*n)
// S.C: O(m+n)
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

    return prev[n - 1];   // the result is stored in the last cell of the previous row (n-1).
}

// ----------------------------------------------------------------------------------------------------------------------------

// Problem link: https://www.naukri.com/code360/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// Extension of this problem: If suppose there is blockage in the grid denoted by -1. Then in how many ways can you reach
//                            from [0][0] to [n - 1][n - 1].

// Example 1:
// Input:
// n = 3, m = 3,
// mat = {{0,  0,  0}
//        {0, -1,  0}
//        {0,  0,  0}}
// Output:
// 2
// Explanation:
// 0  0  0
// 0 -1  0
// 0  0  0
// We can reach source to destination in only 2 ways
// Algorithm: Same as the above code, just add an extra base case:

int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>>& dp) {
    if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;   // EXTRA BASE CASE
    if(i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int left = solve(i, j - 1, mat, dp);
    int up = solve(i - 1, j, mat, dp);
    dp[i][j] = left + up;
    return dp[i][j];
}

// T.C: O(m*n)
// S.C: O(m+n)
int uniquePathsII_memoization(int m, int n, vector<vector<int>> &mat) {
    vector<vector<int>>dp(m, vector<int>(n, -1));   // 2D vector of size m * n
    return solve(m - 1, n - 1, mat, dp);
}


int main() {
    int m = 3, n = 3;
    cout << "uniquePaths_recursion: " << uniquePaths_recursion(m, n) << endl;
    cout << "uniquePaths_memoization: " << uniquePaths_memoization(m, n) << endl;
    cout << "uniquePaths_tabulation: " << uniquePaths_tabulation(m, n) << endl;
    cout << "uniquePaths_tabulation_SO: " << uniquePaths_tabulation_SO(m, n);

// ----------------------------------------------------------------------------------------------------------------------------

    vector<vector<int>> mat{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    n = mat.size();
    m = mat[0].size();
    cout << "\nNumber of paths with obstacles: " << uniquePathsII_memoization(n, m, mat) << endl;

    return 0;
}
