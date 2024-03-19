#include <iostream>
#include <vector>
using namespace std;

void print2DVector(const vector<vector<int>>& v) {
    for(const auto& row : v) {
        for(int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// Brute force 
// T.C: O(n2)
// S.C: O(n2)
void transpose2DVector_bruteForce(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();   // no.of of elements in each row, i.e., no.of columns
    vector<vector<int>> t_matrix(col, vector<int>(row));   // creates a new 2D vector named 't_matrix' with the dimensions swapped

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    
    matrix = t_matrix;
}

// Optimal solution
// T.C: O(n2)
// S.C: O(1)
void transpose2DVector(vector<vector<int>>& matrix) {
    int row = matrix.size();
    
    for(int i=0; i<row; i++) {
        for(int j=i; j<matrix[i].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // transpose2DVector_bruteForce(matrix);
    transpose2DVector(matrix);
    print2DVector(matrix);
    
    return 0;
}
