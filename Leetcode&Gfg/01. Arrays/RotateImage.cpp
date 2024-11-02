// Leetcode: 48. Rotate Image   --->   You are given an n x n 2D matrix representing an image, rotate the image
// by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT
// allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force
    // T.C: O(n^2)
    // S.C: O(n^2)
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

// ------------------------------------------------------------------------------------------------------

    // Optimal solution: Rotate an array by 90° clockwise = (Transpose the array + reverse each row)
    // T.C: O(n^2)
    // S.C: O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 90 deg clockwise rotation means = Transpose + reverse each row

        // Transpose
        // Note: Always remember that in in-place swapping of square matrix, j should start from i, not from 0. Because if
        //       we start j from 0, same elements of matrix gets swapped twice, resulting in no change in original matrix.
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main() {
    vector <vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Solution().rotate_bruteForce(v);
    Solution().rotate(v);

    for(auto it1: v) {
        for(auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
