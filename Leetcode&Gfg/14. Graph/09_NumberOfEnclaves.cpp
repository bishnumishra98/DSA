// GFG: You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off
// the boundary of the grid.
// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:
// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3
// Explanation:
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
// The highlighted cells represents the land cells.

// Example 2:
// Input:
// grid[][] = {{0, 0, 0, 1},
//             {0, 1, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 1},
//             {0, 1, 1, 0}}
// Output:
// 4
// Explanation:
// 0 0 0 1
// 0 1 1 0
// 0 1 1 0
// 0 0 0 1
// 0 1 1 0
// The highlighted cells represents the land cells.

// Your Task:
// You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid
// as the input parameter and returns an integer, denoting the number of land cells.

// Algorithm: Exactly same as '09_Replace0sWithXs.cpp'. Only 1s that have no link with boundary are the ones from where we cannot
// walk off the boundary of the grid. So count the no.of such 1s.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // Traverse in all 4 directions to find neighbouring 1s of this cell
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) dfs(nrow, ncol, vis, grid);
        }
    }

public:
    // T.C: O(n*m)
    // S.C: O(n*m)
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));   // to track the cells visited

        // Traverse the boundaries(first row, last row, first column & last column) to search for 1s. If found any,
        // its whole group needs to be marked visited as we can walk off the boundary from there.
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) dfs(0, j, vis, grid);
        }
        for(int j = 0; j < m; j++) {
            if(!vis[n - 1][j] && grid[n - 1][j] == 1) dfs(n - 1, j, vis, grid);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) dfs(i, 0, vis, grid);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][m - 1] && grid[i][m - 1] == 1) dfs(i, m - 1, vis, grid);
        }

        // Traverse the mid area of grid to count the unvisited 1s. They are the land cells from where we cannot walk off the boundary.
        int enclaves = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 0; j < m - 1; j++) {
                if(!vis[i][j] && grid[i][j] == 1) enclaves++;
            }
        }

        return enclaves;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};

    cout << sol.numberOfEnclaves(grid);

    return 0;
}
