// GFG. Find the number of islands   --->   Given a grid of size n*m (n is the number of rows and m is the
// number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting
// adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// In Leetcode, the same problem is there(Leetcode: 200. Number of Islands), but they have considered that an island is
// surrounded by water and is formed by connecting adjacent lands horizontally or vertically i.e., in all 4 directions.

// Example 1:
// Input: grid = {{0,1},
//                {1,0},
//                {1,1},
//                {1,0}}
// Output: 1

// Example 2:
// Input: grid = {{0,1,1,1,0,0,0},
//                {0,0,1,1,0,1,0}}
// Output: 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C:
    // S.C: 
    int numIslands(vector<vector<char>>& grid) {
        
    }
};

int main() {
    vector<vector<char>> grid = {{0,1,1,1,0,0,0},
                                 {0,0,1,1,0,1,0}};
    Solution sol;
    cout << sol.numIslands(grid);

    return 0;
}
