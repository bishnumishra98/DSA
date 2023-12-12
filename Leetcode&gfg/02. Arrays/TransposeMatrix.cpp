// leetcode: 867. Transpose Matrix

#include <iostream>
#include <vector>
using namespace std;

void print2DVector(const vector<vector<int>>& v) {
    for (const auto& row : v) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// Brute force 
// T.C: O(n2)
// S.C: O(n2)
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

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print2DVector(transpose(matrix));
    
    return 0;
}