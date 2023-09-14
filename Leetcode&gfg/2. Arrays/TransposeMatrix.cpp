// leetcode: 867. Transpose Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int row = matrix.size();   // no.of rows
    int col = matrix[0].size();   // no.of of elements in each row, i.e, no.of columns
    vector<vector<int>> t_matrix(col, vector<int>(row));   // creates a new 2D vector t_matrix with the dimensions swapped

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    
    return t_matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
    };

    vector<vector<int>> t_matrix = transpose(matrix);

    // Printing the vector
    for (int i = 0; i < t_matrix.size(); i++) {   // matrix.size() gives number of rows
        for (int j = 0; j < t_matrix[i].size(); j++) {   // matrix[i].size() gives number of elements in ith row i.e, no.of columns in matrix
            cout << t_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}