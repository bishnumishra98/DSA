// GFG. Find the number of islands   --->   Given a grid of size n*m (n is the number of rows and m is the
// number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting
// adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// In Leetcode, the same problem is there(Leetcode: 200. Number of Islands), but they have considered that an island is
// surrounded by water and is formed by connecting adjacent lands horizontally or vertically i.e., in 4 directions.

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

// Understand 'NumberOfProvinces.cpp' before this problem. This problem also has a similar approach.
// Algorithm:
// 1. Consider all elements of the grid to be nodes of a graph. For a n*m grid, no.of nodes will also be obviously n*m.
// 2. Make a 2D 'vis' array of size as many nodes in the graph with initial values 0, to keep track of nodes visited from the grid.
// 3. Perform any traversal (DFS or BFS) starting with each element of the grid that contains '1' and is unvisted yet. In the BFS
//    traversal of that node, all its neighbours shall be marked as visited. Thus, the next time a BFS traversal is called, it belongs
//    to a separate component. Thus, count the no.of times the BFS traversal is called, and that is the no. of islands in the grid.
// Considering BFS traversal, follow the same algorithm as we followed for a BFS traversal. The only 2 differences here will be:
// i.  The queue shall be of type <int, int> to store each node of graph, as nodes are represented by {row, col}.
// ii. The neighbours of any node is not provided in any adjacent list. Its neighbours are land('1') found in any of
//     the 8 directions around it. For a node {row, col}, its 8 neighbours can be found in the directions:
//     {row-1, col-1} {row-1, col} {row-1, col+1}               
//     {row, col-1}                {row, col+1}
//     {row+1, col-1} {row+1, col} {row+1, col+1}

// Problem link: 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BFS traversal of grid. It is same as we did in 'BaseBuildingPrograms\22. Graph\G03_BFSTraversalOfGraph.cpp'.
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all 8 neighbours of front node if they are land and not visited yet, and store them in queue and mark them visited.
            // All 8 neighbours of grid[row][col] will be:
            // grid[row-1][col-1]   grid[row-1][col]   grid[row-1][col+1]
            // grid[row][col-1]     "{row, col}"       grid[row][col+1]
            // grid[row+1][col-1]   grid[row+1][col]   grid[row+1][col+1]
            // The above 8 neighbours can be traversed individually or a better crisp way to traverse all of them is via nested for loop:
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int nrow = row + i;
                    int ncol = col + j;
                    // If neighbour is a land and unvisited yet, push neighbour position in the queue and mark neighbour as visited.
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m   // also check that neighbour indices are valid, i.e., within bounds
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }

    // T.C: O(n*m) due to iterating over all the cells in the grid, where n & m are no.of rows & no.of cols in grid respectively
    //      + In the worst case, you may end up visiting all cells of the grid, but each cell is visited exactly once. Thus, at max
    //        the number of operations in BFS traversal will be n*m, which takes O(n*m) time.
    //      Overall, T.C: O(n*m)
    // S.C: O(n*m) due to 'vis' + O(n*m) as the queue in BFS can grow up to O(n*m) size if all cells are part of single island.
    //      Overall, S.C is O(n*m)
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int islands = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    islands++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {{'0','1','1','1','0','0','0'},
                                 {'0','0','1','1','0','1','0'}};
    Solution sol;
    cout << sol.numIslands(grid);

    return 0;
}
