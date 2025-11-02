// Leetcode: 37. Sudoku Solver   --->   Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// 1. Each of the digits 1-9 must occur exactly once in each row.
// 2. Each of the digits 1-9 must occur exactly once in each column.
// 3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:
// Input:
// board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],
// ["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
// [".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output:
// [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],
// ["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],
// ["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

// Problem link: https://leetcode.com/problems/sudoku-solver/description/

// Algorithm: https://www.youtube.com/watch?v=FWAIf_EVUKE&t=939s

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // isValid() function validates if the character 'c' is possible to be kept at the position [i][j] or not.
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) return false;   // vertical check: checking if the character 'c' is already present in the column 'col'
            if(board[row][i] == c) return false;   // horizontal check: checking if the character 'c' is already present in the row 'row'
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;   // 3x3 box check
        }
        return true;
    }

    // solve() function builds the Sudoku board.
    bool solve(vector<vector<char>>& board) {
        // Traverse all cells of the Sudoku board to find blank cells where numbers have to be inserted 
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                // If a blank cell is found, try all numbers from '1' to '9' that fit valid in that position
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            // If solve() returns true, it means a valid Sudoku board has been built. Thus,
                            // return true to indicate the same.
                            // If solve() returns false, it means the current combination of the board is invalid.
                            // Backtrack by removing the character from this position [i][j] and try a new path.
                            if(solve(board)) return true;
                            else board[i][j] = '.';   // backtrack
                        }
                    }
                    return false;   // If no number from '1' to '9' fits in the blank cell, return
                                   // false to indicate that the current board configuration is invalid.
                }
            }
        }
        // If no blank spaces are left, the Sudoku board is complete. Thus, return true.
        return true;
    }

    // T.C: O(9^b);   where b = no. of empty cells on the board
    // S.C: O(b);   due to recursive call stack
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

// --------------------------------------------------------------------------------------------------------------------------

// Leetcode 36. Valid Sudoku   --->   Given an incomplete sudoku, return true if it is a valid sudoku, else return false.

    // isValidCharacter() function validates if the character 'c' at position [i][j] is consistent with Sudoku rules.
    // 'i != row', 'i != col' and '(boxRow != row || boxCol != col)' conditions are extra than isValid() function. They
    // ensure that the current cell does not count itself as a duplicate. Without these extra conditions, the function
    // would always find the current cell's value in its own row, column, and 3x3 sub-box, leading to a false negative.
    bool isValidCharacter(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            // Vertical check: ensures 'c' is not already present in the column 'col'
            if(board[i][col] == c && i != row) return false;
            
            // Horizontal check: ensures 'c' is not already present in the row 'row'
            if(board[row][i] == c && i != col) return false;
            
            // 3x3 box check: ensures 'c' is not already present in the 3x3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if(board[boxRow][boxCol] == c && (boxRow != row || boxCol != col)) return false;
        }
        return true;
    }

    // T.C: O(1)
    // S.C: O(1)
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(!isValidCharacter(board, i, j, board[i][j])) return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "isValidSudoku: " << (sol.isValidSudoku(board) ? "true" : "false") << endl;

    sol.solveSudoku(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
