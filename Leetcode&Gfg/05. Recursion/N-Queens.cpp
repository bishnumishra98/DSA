// Leetcode: 51. N-Queens   --->   The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
// no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen
// and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

// Problem link: https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // The function to check whether this particular position '[row][col]' is safe to keep a queen or not
    bool iSafe(int row, int col, vector<string>& board, int n) {
        int rowDup = row;
        int colDup = col;

        // If any queen found in the following directions, return false stating that a queen cannot be placed in this '[row][col]' position.
        // Direction 1: Upwards diagonally towards left.
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // Reset values of 'row' and 'col' as they became 0 in the above loop
        row = rowDup;
        col = colDup;

        // Direction 2: Horizontally towards left
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        col = colDup;   // reset value of 'col' as it became 0 in the above loop

        // Direction 3: Downwards diagonally towards left
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        // If no queens found in any of the above 3 directions, placing a queen at this position '[row][col]' is safe. Thus, return true.
        return true;
    }

    // solve() function helps in placing queen at all safe rows of the 'col' column
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case: If 'col' exceeds the last column of board, it means all columns of the board has
        // been filled with a queen in each column. Thus, push the 'board' in 'ans', and return.
        if(col == n) {
            ans.push_back(board);
            return;
        }

        // Check if a queen can be placed at each row of this column. And if a queen is placed at any row of
        // this column, recursively find all safe row no. for the queen to be placed in further columns too.
        for(int row = 0; row < n; row++) {
            if(iSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';   // backtracking
            }
        }
    }

    // T.C: O(n^n * n);
    // S.C: O(n^2 + n + s);   where S = total space for all solutions
    vector<vector<string>> solveNQueens_bruteForce(int n) {
        vector<vector<string>> ans;   // 'ans' contains the configuration of all boards where queens do not attack each other
        vector<string> board(n);   // 'board' stores positions of queens in a chess board where they do not attack each other
        string s(n, '.');   // initializaing a string of length 'n' with value '.'
        for(int i = 0; i < n; i++) board[i] = s;   // initializing each element of 'board' with the above string 's'.
        // Thus, a 2D chess board is made with all values initially as '.'. Example if n = 4, the board would look like:
        // . . . .   -> element0 or row0
        // . . . .   -> element1 or row1
        // . . . .   -> element2 or row2
        // . . . .   -> element3 or row3
        solve(0, board, ans, n);
        return ans;
    }

// --------------------------------------------------------------------------------------------------------------------------

    // solve() function helps in placing queen at all safe rows of the 'col' column
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        // Base case: If 'col' exceeds the last column of board, it means all columns of the board has
        // been filled with a queen in each column. Thus, push the 'board' in 'ans', and return.
        if(col == n) {
            ans.push_back(board);
            return;
        }

        // Check if a queen can be placed at each row of this column. And if a queen is placed at any row of
        // this column, recursively find all safe row no. for the queen to be placed in further columns too.
        for(int row = 0; row < n; row++) {
            // If hashtables for all 3 directions are 0, means queen can be placed at this position '[row][col]'
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                // Mark the hashtables as 1, so that no queens would be allowed to be kept in their direction
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
                // Backtrack: Remove 'Q' from board and unmark the hashtables
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // The optimal solution is implemented with the help of hashing concept.
    // T.C: O(n!)
    // S.C: O(n^2 + S);   where S = total space for all solutions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;   // 'ans' contains a collection of boards where queens do not attack each other. Return it.
        vector<string> board(n);   // 'board' stores positions of queens in a chess board where they do not attack each other
        string s(n, '.');   // initializaing a string of length 'n' with value '.'
        for(int i = 0; i < n; i++) board[i] = s;   // initializing each element of 'board' with the above string 's'.
        
        // Creating 3 arrays which will be used as hash tables for checking is it safe to keep queen considering the 3 directions:
        // Horizontally towards left, Upwards diagonally towards left and Downwards diagonally towards left, respectively.
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};

int main() {
    int n = 4;
    Solution sol;

    vector<vector<string>> ans1 = sol.solveNQueens_bruteForce(n);
    for(int i = 0; i < ans1.size(); i++) {
        for(int j = 0; j < ans1[i].size(); j++) {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<string>> ans2 = sol.solveNQueens(n);
    for(int i = 0; i < ans2.size(); i++) {
        for(int j = 0; j < ans2[i].size(); j++) {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
