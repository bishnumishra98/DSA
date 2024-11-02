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
    // T.C: O(n^2)
    // S.C: O(n^2)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();   // no.of rows
        int col = matrix[0].size();   // no.of of elements in each row, i.e, no.of columns
        vector<vector<int>> t_matrix(col, vector<int>(n));   // creates a new 2D vector t_matrix with the dimensions swapped

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < col; j++) {
                t_matrix[j][i] = matrix[i][j];
            }
        }
        
        return t_matrix;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<vector<int>> ans = Solution().transpose(matrix);
    for(auto it1: ans) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
