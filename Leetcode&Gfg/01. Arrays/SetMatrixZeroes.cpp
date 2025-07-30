// Leetcode: 73. Set Matrix Zeroes   --->   Given an m x n integer matrix matrix, if an element is 0, set its entire
// row and column to 0's.
// You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Algorithm: 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void markRow(int i, vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void markCol(int j, vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int i = 0; i < n; i++) {
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    // T.C: O(m * n) for nested loops * O(m + n) for marking rows and columns as '-1' + O(m * n) for turning back -1s to 0s 
    //      = O((m * n) * (m + n)) + O(m + n)
    // S.C: O(1)
    void setZeroes_bruteforce(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Don't turn elements 0s for now, otherwise we will not be able to differentiate which 0 existed initially,
        // and which 0 is made after transformation. Thus, first turn elements as -1, then turn back -1 to 0.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    markRow(i, matrix);   // mark all elements in 'i'th row as -1
                    markCol(j, matrix);   // mark all elements in 'j'th column as -1
                }
            }
        }

        // Turn back all -1s to 0s
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }
    }

// -----------------------------------------------------------------------------------------------------------------

    // Approach: Very simple. Just mark the rows and columns which have 0s, and then turn all elements in those rows
    //           and columns to 0.
    // T.C: O(m * n) + O(m * n) = O(2 * m * n)
    // S.C: O(m + n)
    void setZeroes_better(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = true;   // marking this row true means all elements of this row has to be made 0
                    col[j] = true;   // marking this column true means all elements of this column has to be made 0
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }

// -----------------------------------------------------------------------------------------------------------------

    // Algorithm: It is simple. We will use the same approach of marking rows and columns that needs to be zeroed, the
    //            difference being that here we will not take the extra row and col vectors to mark the rows and columns.
    //            Instead, we will use the first column and first row of the matrix itself to mark the rows and columns that
    //            needs to be zeroed. But row0 and col0 will be the same cell, so we will consider row0 to last row as row
    //            headings, and col1 to last column as column headings. For col0, we can initialize a separate variable named
    //            'col0' to keep track of whether the first column has to be zeroed or not.
    //            If an element of row or col headings are zero, it means that the entire row or column has to be zeroed.
    //            1. Initialize the variable 'col0' to 1, meaning that the first column does not have to be zeroed initially.
    //            2. Iterate through the matrix, and if an element is zero, mark the corresponding row and column headings as
    //               0. Row and column headings are nothing but row0 to row(m - 1) and col0, col1 to col(n - 1) respectively.
    //               If any of the elements in the first column of the matrix is found to be 0, then set the 'col0' heading to 0.
    //            3. Iterate through the matrix in reverse order, from last row to first row, i.e., from m - 1 to 0, and
    //               from last column to second column, i.e., from n - 1 to 1. If the element in the row heading is 0,
    //               or the element in the column heading is 0, then set the element at that position of their intersection to 0.
    //               If the 'col0' variable is 0, then set the entire first column of the matrix to 0.
    // T.C: O(m * n)
    // S.C: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;   // Initially let the first column not be zeroed

        // Step 1: Mark rows and cols to be zeroed using matrix itself
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) col0 = 0;   // if any element in the first column of matrix is found to be 0, set col0 to 0
            for(int j = 1; j < n; j++) {
                // If an element is 0, mark the corresponding row and column headings as 0
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Iterate in reverse and update the matrix
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 1; j--) {
                // If the element in the row heading is 0, or the element in the column heading is 0, set the element to 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            // If the 'col0' variable is 0, set the entire first column to 0
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1}};
    Solution().setZeroes_bruteforce(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1, 1, 1},
              {1, 0, 1},
              {1, 1, 1}};
    Solution().setZeroes_better(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1, 1, 1},
              {1, 0, 1},
              {1, 1, 1}};
    Solution().setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
