// Non-square matrices typically require additional space to transpose, but
// square matrices can be transposed in-place, i,e., in constant space complexity.

#include <iostream>
#include <vector>
using namespace std;

void printSquareVector(const vector<vector<int>>& v) {
    int row = v.size();
    int col = v[0].size();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// T.C: O(n2);   where n = no.of rows or columns 
// S.C: O(1)
void transposeSquareVector(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    for(int i = 0; i < row; i++) {
        for(int j = i; j < col; j++) {   //  note to start j from i, not from 0. Reason is mentioned in 07a.
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

    transposeSquareVector(matrix);
    printSquareVector(matrix);
    
    return 0;
}
