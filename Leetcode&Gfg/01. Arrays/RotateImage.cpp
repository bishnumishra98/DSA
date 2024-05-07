// Leetcode: 48. Rotate Image

#include <iostream>
#include <vector>
#include <algorithm>   // for reverse() function
using namespace std;

void print2DVector(const vector<vector<int>>& v) {
    for (const auto& row : v) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// Brute Force
// T.C: O(n2)
// S.C: O(n2)
void rotate_bruteForce(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> arr(n, vector<int>(n, 0));   // Initialize arr with the same dimensions as matrix

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = matrix[n-j-1][i];
        }
    }

    matrix = arr;
}

// Optimal solution: Rotate an array by 90° clockwise = (Transpose the array + reverse each row)
// T.C: O(n2)
// S.C: O(1)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // transpose
    for(int i=0; i<n; i++) {
        for(int j=i; j<matrix[i].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector <vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // rotate_bruteForce(v);
    rotate(v);
    print2DVector(v);

    return 0;
}