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
// 1. i)   Create a 'vis' 2D array to keep a track of cells that have been visited.
//    ii)  Create a 'dis' 2D array to build the answer and return it. We can even manipulate the input 2D array and return it as the
//         answer, but its a good practice to not alter the given input; that's why create a 'dist' array for returning the answer.
//    iii) Create a queue 'q' of type <pair<int, int>, int> to store the cell positions and the steps to travel to reach there.
// 2. Initially, push cell position of the cells containing 1 along with their steps to travel to reach 1(which will be 0 obviously),
//    in the queue. Also, mark all of them visited in the 'vis' matrix.
// 3. Dequeue the front element, and store the value of step in the 'dis' matrix in that element's position.
// 4. Traverse all neighbours of the current element in all 4 directions. If the neighbour is unvisited, do the same, i.e.,
//    push their position in queue along with steps required to reach there, and mark them visited.
// 5. Follow steps 3 and 4 until the queue is empty, and the answer will be built inside 'dis' matrix. Return it.

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

        // Traversing each cell, push its position into the queue 'q' and mark them visited if they contain 1.
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

            dis[row][col] = steps;   // store the value of step for this element in the 'dis' matrix

            // Traverse all neighbours of the current element in all 4 directions. If the neighbour is unvisited,
            // push their position in queue along with steps required to reach there, and mark them visited.
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol] = 1;
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

// Follow-up: Same question is in Leetcode: 542. 01 Matrix. Just its opposite varient, i.e.,
//            you are asked to find distance of nearest cell having 0.
