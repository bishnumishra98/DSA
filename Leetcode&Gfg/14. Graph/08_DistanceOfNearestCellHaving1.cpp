// GFG: Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell. The distance is
// calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2,
// j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

// Example 1:
// Input: 
// grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
// Output: 
// {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
// Explanation: 
// The grid is-
// 0 1 1 0
// 1 1 0 0
// 0 0 1 1
// - 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0)
// and (1,1) respectively.

// Example 2:
// Input: 
// grid = {{1,0,1},{1,1,0},{1,0,0}}
// Output: 
// {{0,1,0},{0,0,1},{0,1,2}}
// Explanation: 
// The grid is-
// 1 0 1
// 1 1 0
// 1 0 0
// - 0's at (0,1), (1,2), (2,1) and (2,2) are at a  distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C:
    // S.C: 
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 1, 0},
                                {1, 1, 0, 0},
                                {0, 0, 1, 1}};

    vector<vector<int>> v = sol.nearest(grid);

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
    }

    return 0;
}
