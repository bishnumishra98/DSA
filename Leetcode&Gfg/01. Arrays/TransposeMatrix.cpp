// leetcode: 867. Transpose Matrix   --->   Given a 2D integer array matrix, return the transpose of matrix.
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

// Example 2:
// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m*n)
    // S.C: O(m*n)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> t_matrix(cols, vector<int> (rows));   // create a 2D vector with the dimensions swapped

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                t_matrix[j][i] = matrix[i][j];   // t_matrix[i][j] = matrix[j][i] will give
                // heap buffer overflow error for non-square matrix, because rows no.of rows
                // does not exists in t_matrix. Hence, always write t_matrix[j][i] = matrix[i][j].
            }
        }

        return t_matrix;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6}};

    vector<vector<int>> ans = Solution().transpose(matrix);
    for(auto it1: ans) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
