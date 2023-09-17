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
void transpose_bruteForce(vector<vector<int>>& matrix) {
    int n = matrix.size();   // no.of rows
    int col = matrix[0].size();   // no.of of elements in each row, i.e, no.of columns
    vector<vector<int>> t_matrix(col, vector<int>(n));   // creates a new 2D vector t_matrix with the dimensions swapped

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    
    matrix = t_matrix;
}

// Optimal solution (brute force)
// T.C: O(n1.5)
// S.C: O(1)
void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // transpose
    for(int i=0; i<n; i++) {
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

    // transpose_bruteForce(matrix);
    transpose(matrix);
    print2DVector(matrix);
    
    return 0;
}