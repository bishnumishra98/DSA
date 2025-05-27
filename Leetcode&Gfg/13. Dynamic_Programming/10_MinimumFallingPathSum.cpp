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

    int minFallingPathSum_tabulation(vector<vector<int>>& matrix) {
        
    }

// --------------------------------------------------------------------------------------------------

    int minFallingPathSum_tabulation_SO(vector<vector<int>>& matrix) {
        
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
