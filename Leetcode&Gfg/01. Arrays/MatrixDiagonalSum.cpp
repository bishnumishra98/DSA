// leetcode: 1572. Matrix Diagonal Sum   --->   Given a square matrix mat, return the sum of the matrix diagonals.
// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal
// that are not part of the primary diagonal.

// Example 1:
// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.

// Example 2:
// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8

// Example 3:
// Input: mat = [[5]]
// Output: 5

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int pds = 0;   // pds = primaryDiagonalSum
        int sds = 0;   // sds = secondaryDiagonalSum
        int n = mat.size();

        for(int i = 0; i < n; i++) {
            pds += mat[i][i];
            sds += mat[i][n - i - 1];
        }

        // For n * n matrix, if n is an odd number, we need to subtract the middle element as it has been counted twice.
        return (n & 1) ? pds + sds - mat[n / 2][n / 2] : pds + sds;
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << Solution().diagonalSum(matrix);
    
    return 0;
}
