// leetcode: 221. Maximal Square   --->   Given an m x n binary matrix filled with 0's and 1's,
// find the largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4

// Example 2:
// Input: matrix = [["0","1"],["1","0"]]
// Output: 1

// Example 3:
// Input: matrix = [["0"]]
// Output: 0

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxSide) {
    // base case
    if(i >= row || j>=col) {
        return 0;
    }

    // exploring all 3 directions(right, diagonal, right)
    int right = solve(matrix, i+1, j, row, col, maxSide);
    int diagonal = solve(matrix, i+1, j+1, row, col, maxSide);
    int down = solve(matrix, i, j+1, row, col, maxSide);

    // check if we can build square from current position
    if(matrix[i][j] == '1') {
        // '1 + ...' in the equation of 'side' is for counting the '1' on which we are standing,
        // as '1' itself forms a unit, i.e. 1 side of a square.
        // We are taking minimum of right, diagonal and down because we don't want to form a square
        // if the solve() function has returned '0' from any of the 3 directions. Illustration:
        // Consider a matrix: m[3][3] = {
        //                       {1, 1, 1},
        //                       {1, 1, 1},
        //                       {1, 1, 0}
        //                    };
        // In the above example, if we are standing at m[0][0], we get 2 from right, 1 from diagonal,
        // and 2 from down. So, side = 1 + min(right, diagonal, down) = 1 + 1 = 2 units.
        int side = 1 + min(right, min(diagonal, down));
        maxSide = max(maxSide, side);   // storing the longest side we get from all recursive calls
        return side;

    } else {
        // as square cannot be made if we are standing at '0', so we return '0' to solve()
        return 0;
    }
}

// T.C: O(m*n);   where m & n = no.of rows & columns
// S.C: O(m*n)
int maximalSquare(vector<vector<char>>& matrix) {
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxSide = INT_MIN;
    int side = solve(matrix, i, j, row, col, maxSide);
    return maxSide*maxSide;   // returning maximum area of square found in the matrix
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalSquare(matrix);

    return 0;
}