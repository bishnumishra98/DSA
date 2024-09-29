// GFG: Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of
// connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if
// one island is not equal to another (not rotated or reflected).

// Example 1:
// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

// Example 2:
// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal. We have 4 islands, but 2 of them are equal, So we have 3 distinct islands.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes
// the grid as an input parameter and returns the total number of distinct islands.

// Algorithm: Distinct islands are islands that are different in shape. To store only distinct shapes of islands,
// we can store the shapes of all islands in a set. The no.of elements in the set will be the no.of distinct islands.
// All 1s of the island can be traversed using dfs or bfs traversal, but our main challenge is to identify their shapes.
// Shapes can identified using a formula: {row - row0, col - col0}, where wor0 & col0 are base indexes, i.e., indexes from
// where bfs or dfs traversal started. For example:

// {{1, 1, 0, 1, 1}, 
//  {1, 0, 0, 0, 0}, 
//  {0, 0, 0, 1, 1}, 
//  {1, 1, 0, 1, 0}}
// Lets identify the shapes of the top left and bottom right islands. Lets assume our dfs traversal pattern is: UP, RIGHT, DOWN, LEFT.

// 1) Positions of 1s in Island 1 :-
//    (0,0)   (0,1)
//    (1,0)
//    Considering base as (0,0), the shape of the above island stored in the set will be:
//    {(0-0, 0-0), (0-0, 0-1), (0-1, 0-1)}
//    = {(0,0), (0,-1), (-1,-1)}

// 2) Positions of 1s in Island 2 :-
//    (2,3)   (2,4)
//    (3,4)
//    Considering base as (2,3), the shape of the above island stored in the set will be:
//    {(2-2, 3-3), (2-2, 3-4), (2-3, 3-4)}
//    = {(0,0), (0,-1), (-1, -1)}

// Hence, both elements of sets will be identical, so only one of them will be stored in the set promoting unique shape.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& vec, int row0, int col0) {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    // T.C: O(n*m)
    // S.C: O(n*m)
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                } 
            }
        }

        return st.size();
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};

    Solution sol;
    cout << sol.countDistinctIslands(grid);

    return 0;
}
