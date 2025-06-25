// leetcode: 221. Maximal Square   --->   Given an m x n binary matrix filled with 0's and 1's,
// find the largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4

// Example 2:
// Input: matrix = [["0","1"],["1","0"]]
// Output: 1

// Example 3:
// Input: matrix = [["0"]]
// Output: 0

// Algorithm: It is a simple recursive solution. Call a function f(i, j) which returns the length of side of
//            a square from the position (i, j) [(i, j) being excluded] of the matrix. If we know length of
//            side of a square, we can easily find out its area by multiplying side * side.
//            Thus, call the recursive function f(i, j) from the last cell of the matrix, i.e., (row - 1, col - 1).
//            until either of 'i' or 'j' goes beyond the matrix.
//            But one thing to remember is that we are not interested in knowing the length of side of square
//            from the position (row - 1, col - 1), but interested in knowing the maximum length formed at any
//            point of time across the entire matrix. To store it, we we will pass one more parameter 'maxSide'
//            to the function f(i, j).
//            1. Base case: If either of 'i' or 'j' goes out of boundary of matrix, return 0 stating that
//                          no length of side found, i.e., if(i < 0 || j < 0) return 0.
//            2. Recursive relation: From a position (i, j), we have to traverse towards 3 directions to find out the
//                                   length of side of a square from the position (i, j) [(i, j) being excluded].
//                                   I.  Left: Traversing left means 'i' stands still, 'j' moves back, i.e.,
//                                             call f(i, j - 1) and store its returned value.
//                                   II.  Diagonal: Traversing diagonally up means both 'i' and 'j' moves back,
//                                                  i.e, call f(i - 1, j - 1) and store its returned value.
//                                   III. Up: Traversing up means 'i' moves back and 'j' stands still, i.e.,
//                                            call f(i - 1, j) and store its returned value.
//                                   Once we have values of lengths from all 3 directions, we have 2 choices based
//                                   on the position (i, j) we are standing on:
//                                   I.  if(matrix[i][j] == '1'): If we are standing on a '1', we can form a square from
//                                                                this position. The length of side of the square till
//                                                                the position (i, j) will be: 1 + min({left, diag, up}).
//                                                                1 is added to include the current poistion (i, j) in
//                                                                side of square. Minimum of {left, diag, up} is taken
//                                                                because maximum side of a square can be formed
//                                                                only by calculating the minimum of all 3 directions.
//                                                                Example: Lets consider the position (2, 2) in matrix:
//                                                                    0 1 2 3 4
//                                                                   ----------
//                                                                0 | 1 0 1 0 0
//                                                                1 | 1 0 1 1 1
//                                                                2 | 1 1 1 1 1
//                                                                3 | 1 0 0 1 0
//                                                                For position (2, 2), the side of square possible is
//                                                                given by f(2, 2). As f(2, 2) calls 3 functions f(2, 1),
//                                                                f(1, 1) and f(1, 2) to gather the length of side of
//                                                                square possible from 3 directions respectively, it
//                                                                gets a value 1, 0, 1 from them. We got 0 from f(1, 1)
//                                                                because no square can be formed from there as its a
//                                                                '0'. Hence, the diagonal is blocked for building a
//                                                                square, so min({1, 0, 1}) is 0 which means side of
//                                                                square from position (2, 2) will be 1 + 0 = 1.
//                                   II. if(matrix[i][j] != '1'): If we are standing on a '0', we cannot form a square
//                                                                from this position as it is blocked. Hence, length of
//                                                                side of square returned from here will 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<char>>& matrix, int &maxSide) {
        // Base case: If either of 'i' or 'j' goes out of bounds, return 0.
        if(i < 0 || j < 0) return 0;
        
        // Recursively calculate the side length of the largest square ending at (i, j) [(i, j) being excluded]
        int left = solve(i, j - 1, matrix, maxSide);
        int diag = solve(i - 1, j - 1, matrix, maxSide);
        int up = solve(i - 1, j, matrix, maxSide);
        
        if(matrix[i][j] == '1') {
            int side = 1 + min(left, min(up, diag));
            maxSide = max(maxSide, side);
            return side;
        } else {
            return 0;
        }
    }

    // T.C: O(3^(m*n));   where m and n are number of rows and columns in the matrix
    // S.C: O(min(m, n)) as recursion stack can go as deep as the matrix size's diagonal length in the worst case
    int maximalSquare_recursion(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;   // to store the maximum side of square found so far

        solve(rows - 1, cols - 1, matrix, maxSide);   // no need to store the value returned by solve()
        return maxSide * maxSide;   // returning area of the square
    }

// -----------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<vector<char>>& matrix, int &maxSide, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solve(i, j - 1, matrix, maxSide, dp);
        int diag = solve(i - 1, j - 1, matrix, maxSide, dp);
        int up = solve(i - 1, j, matrix, maxSide, dp);
        
        if(matrix[i][j] == '1') {
            int side = 1 + min(left, min(up, diag));
            maxSide = max(maxSide, side);
            return dp[i][j] = side;
        } else {
            return dp[i][j] = 0;
        }
    }

    // T.C: O(m * n);   where m and n are number of rows and columns in the matrix
    // S.C: O(m * n) for dp table + O(min(m, n)) for recursion stack space = O(m * n)
    int maximalSquare_memoization(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        solve(rows - 1, cols - 1, matrix, maxSide, dp);
        return maxSide * maxSide;
    }

// -----------------------------------------------------------------------------------------------------

    int solve_shifted(int i, int j, vector<vector<char>>& matrix, int &maxSide, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solve_shifted(i, j - 1, matrix, maxSide, dp);
        int diag = solve_shifted(i - 1, j - 1, matrix, maxSide, dp);
        int up = solve_shifted(i - 1, j, matrix, maxSide, dp);
        
        if(matrix[i - 1][j - 1] == '1') {
            int side = 1 + min(left, min(up, diag));
            maxSide = max(maxSide, side);
            return dp[i][j] = side;
        } else {
            return dp[i][j] = 0;
        }
    }

    // T.C: O(m * n);   where m and n are number of rows and columns in the matrix
    // S.C: O(m * n) for dp table + O(min(m, n)) for recursion stack space = O(m * n)
    int maximalSquare_memoization_shifted(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));

        solve_shifted(rows, cols, matrix, maxSide, dp);
        return maxSide * maxSide;
    }

// -----------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m and n are number of rows and columns in the matrix
    // S.C: O(m * n)
    int maximalSquare_tabulation(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                int left = dp[i][j - 1];
                int diag = dp[i - 1][j - 1];
                int up = dp[i - 1][j];
                
                if(matrix[i - 1][j - 1] == '1') {
                    int side = 1 + min(left, min(up, diag));
                    maxSide = max(maxSide, side);
                    dp[i][j] = side;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxSide * maxSide;
    }

// -----------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m and n are number of rows and columns in the matrix
    // S.C: O(n)
    int maximalSquare_tabulation_SO(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        vector<int> curr(cols + 1, 0), prev(cols + 1, 0);

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                int left = curr[j - 1];
                int diag = prev[j - 1];
                int up = prev[j];
                
                if(matrix[i - 1][j - 1] == '1') {
                    int side = 1 + min(left, min(up, diag));
                    maxSide = max(maxSide, side);
                    curr[j] = side;
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return maxSide * maxSide;
    }
};


int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << Solution().maximalSquare_recursion(matrix) << endl;
    cout << Solution().maximalSquare_memoization(matrix) << endl;
    cout << Solution().maximalSquare_memoization_shifted(matrix) << endl;
    cout << Solution().maximalSquare_tabulation(matrix) << endl;
    cout << Solution().maximalSquare_tabulation_SO(matrix);

    return 0;
}
