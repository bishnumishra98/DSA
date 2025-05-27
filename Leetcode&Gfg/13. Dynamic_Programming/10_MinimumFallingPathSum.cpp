// Leetcode: 931. Minimum Falling Path Sum   --->   Given an n x n array of integers matrix, return the
// minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is
// either directly below or diagonally left/right. Specifically, the next element from position (row, col)
// will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.

// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

// Algorithm: The problem is similar to the previous problem 'Leetcode&Gfg\13. Dynamic_Programming\09_Triangle.cpp',
//            but here we have both variable starting and ending points. Its also an easy problem.
//            We can start the recursion from the anywhere whether it is the first row or the last row. For isntance,
//            we can start from bottom, i.e., the last row and move to the top, i.e., the first row.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Base cases:
        // 1) If the indices are out of bounds, we return a large value (1e9) to avoid considering that path. Note that
        //    this condition should be written first to avoid any out of bound error.
        // 2) If we reach the first row, return the value at that position.
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[i][j];

        // Movements can be done in 3 directions: diagonally right, up and diagonally left
        int left_diagonal = matrix[i][j] + solve(i - 1, j - 1, matrix);
        int up = matrix[i][j] + solve(i - 1, j, matrix);
        int right_diagonal = matrix[i][j] + solve(i - 1, j + 1, matrix);

        return min({left_diagonal, up, right_diagonal});
    }

    // T.C: O(3^(n - 1));   where n is the no.of rows in the matrix
    // S.C: O(n);   recursion stack space
    int minFallingPathSum_recursion(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            mini = min(mini, solve(n - 1, j, matrix));
        }

        return mini;
    }

// --------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int left_diagonal = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        int right_diagonal = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);

        dp[i][j] = min({left_diagonal, up, right_diagonal});
        return dp[i][j];
    }

    // T.C: O(n^2);   where n is the no.of rows in the matrix
    // S.C: O(n^2) for dp array + O(n) for recursion stack space = O(n^2)
    int minFallingPathSum_memoization(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            mini = min(mini, solve(n - 1, j, matrix, dp));
        }

        return mini;
    }

// --------------------------------------------------------------------------------------------------

    // T.C: O(n^2);   where n is the no.of rows in the matrix
    // S.C: O(n^2)
    int minFallingPathSum_tabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the first row of dp with values of first row of matrix
        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        // Fill the rest of the dp table row by row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int left_diagonal = 1e9, up, right_diagonal = 1e9;

                if(j >= 1) left_diagonal = matrix[i][j] + dp[i - 1][j - 1];
                up = matrix[i][j] + dp[i - 1][j];
                if(j < n - 1) right_diagonal = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({left_diagonal, up, right_diagonal});
            }
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }

// --------------------------------------------------------------------------------------------------

    // T.C: O(n^2);   where n is the no.of rows in the matrix
    // S.C: O(n)
    int minFallingPathSum_tabulation_SO(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);   // to store the previous row's results

        // Fill the first row of prev with values of first row of matrix
        for(int j = 0; j < n; j++) prev[j] = matrix[0][j];

        for(int i = 1; i < n; i++) {
            vector<int> cur(n, 0);   // to store the current row's results

            for(int j = 0; j < n; j++) {
                int left_diagonal = 1e9, up, right_diagonal = 1e9;

                if(j >= 1) left_diagonal = matrix[i][j] + prev[j - 1];
                up = matrix[i][j] + prev[j];
                if(j < n - 1) right_diagonal = matrix[i][j] + prev[j + 1];

                cur[j] = min({left_diagonal, up, right_diagonal});
            }

            prev = cur;
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};


int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    Solution sol;
    cout << sol.minFallingPathSum_recursion(matrix) << endl;
    cout << sol.minFallingPathSum_memoization(matrix) << endl;
    cout << sol.minFallingPathSum_tabulation(matrix) << endl;
    cout << sol.minFallingPathSum_tabulation_SO(matrix);

    return 0;
}

// Note: The same type of problem can be asked in interviews with different variation like to find maximum falling path sum.
//       The approach remains the same, just the comparison changes from min to max.
// Problem link: https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
