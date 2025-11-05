// Leetcode 36. Valid Sudoku   --->   Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to
// be validated according to the following rules:

// 1. Each row must contain the digits 1-9 without repetition.
// 2. Each column must contain the digits 1-9 without repetition.
// 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:
// ● A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// ● Only the filled cells need to be validated according to the mentioned rules.

// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true

// Example 2:
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there
//              are two 8's in the top left 3x3 sub-box, it is invalid.

// Problem link: https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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

public:
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
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    
    Solution sol;

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}
