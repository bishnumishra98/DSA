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

// Algorithm: A BFS traversal will work here, because BFS spreads across all direction uniformly.
// 1. Create a 'vis' 2D array to keep a track of cells that have been visited.
// 2. Create a 'dis' 2D array to build the answer and return it. We can even manipulate the input 2D array and return it as the
//    answer, but its a good practice to not alter the given input; that's why create a 'dist' array for returning the answer.
// 3. Create a queue 'q' of type <pair<int, int>, int> to store the cell position and the distance to travel to reach 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // T.C:
    // S.C: 
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));   // to keep track of cells visited
        vector<vector<int>> dis(n, vector<int>(m, 0));   // to build the answer and return
        queue<pair<pair<int, int>, int>> q;   // to store the cell position and the distance to travel to reach 1

        // Traversing each cell, and pushing into queue and marking the cell containing 1 as visited.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[row][col] = steps;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }

        return dis;
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
        cout << endl;
    }

    return 0;
}
