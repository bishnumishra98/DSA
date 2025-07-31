// Leetcode: 54. Spiral Matrix   --->   Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// 1 2 3
// 4 5 6
// 7 8 9
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Algorithm: Algo is very easy and logical.
// 1. If you observe carefully, you will find that we re following a pattern to traverse in spiral path.
//    Traverse 0th row, then traverse last column, then traverse last row, then traverse 0th column,
//    traverse 1st row, then traverse 2nd last column, then traverse 2nd last row, then traverse 1st column,
//    and so on. We shall traverse this pattern until all elements of matrix have been printed.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m * n);   where m = no.of rows and n = no.of columns respectively
    // S.C: O(m * n)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();   // no.of rows
        int n = matrix[0].size();   // no.of columns
        int total = m * n;   // total no.of elements in matrix
        int startRow = 0;
        int endRow = m - 1;
        int startCol = 0;
        int endCol = n - 1;

        vector<int> ans;
        while(ans.size() < total) {
            // Print starting row: fixed row, varying column
            for(int j = startCol; j <= endCol && ans.size() < total; j++) {
                ans.push_back(matrix[startRow][j]);
            }
            startRow++;   // for next iteration, startRow should be incremented by 1

            // Print ending column: varying row, fixed column
            for(int i = startRow; i <= endRow && ans.size() < total; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;   // for next iteration, endCol should be decremented by 1

            // Print ending row: fixed row, varying column
            for(int j = endCol; j >= startCol && ans.size() < total; j--) {
                ans.push_back(matrix[endRow][j]);
            }
            endRow--;   // for next iteration, endRow should be decremented by 1

            // Print starting column: varying row, fixed column
            for(int i = endRow; i >= startRow && ans.size() < total; i--) {
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;   // for next iteration, startCol should be incremented by 1
        }

        return ans;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<int> ans = Solution().spiralOrder(matrix);
    for(int it: ans) cout << it << " ";

    return 0;
}
