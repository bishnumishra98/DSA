// leetcode: 867. Transpose Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    

}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
    };

    transpose(matrix);

    // Printing the vector
    for (int i = 0; i < matrix.size(); i++) {   // matrix.size() gives number of rows
        for (int j = 0; j < matrix[i].size(); j++) {   // matrix[i].size() gives number of elements in ith row i.e, no.of columns in matrix
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}