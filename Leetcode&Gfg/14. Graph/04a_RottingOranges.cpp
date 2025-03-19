// Leetcode: 994. Rotting Oranges   --->   You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],
//                [1,1,0],
//                [0,1,1]]
// Output: 4

// Example 2:
// Input: grid = [[2,1,1],
//                [0,1,1],
//                [1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Algorithm: Here we need to find out minimum time to rot all oranges. In this problem, only a BFS algorithm will work.
// ➤ Why BFS is suitable here ?
//    BFS naturally processes nodes level by level (in this case, time or minutes) in all directions. It is ideal for spreading
//    processes, such as rotting oranges. BFS allows for simultaneous updates in all four directions, making it perfect for
//    scenarios where multiple changes can occur at once (e.g., multiple fresh oranges becoming rotten simultaneously).
// ➤ Why DFS fails here ?
//    DFS explores as far as possible along a branch before backtracking. This does not align with the need to spread out in
//    all directions at each step. DFS does not process nodes at the same level simultaneously, which is required for
//    calculating the time for simultaneous rotting of oranges.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m*n);   where m and n are no.of rows and cols in grid respectively
    // S.C: O(m*n);   due to the queue in the worst case
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Queue structure: {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;

        // Push all rotten oranges inside queue. Along with it, also count no.of fresh oranges.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({{i, j}, 0});
                if(grid[i][j] == 1) freshOranges++;
            }
        }

        int timePassed = 0;   // time needed to rot oranges
        int orangesRotten = 0;   // no.of oranges that were fresh initially but have been rotten

        // BFS traversal to rot all oranges
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            timePassed = max(timePassed, time);

            // Traverse 4 neighbours of current cell. If they are fresh, rot them, push them in queue and increase 'orangesRotten'.
            int r[] = {-1, 0, 1, 0};
            int c[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int nrow = row + r[i];
                int ncol = col + c[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});   // increase time while pushing neighbour in queue. In
                    // this way, every orange that got rotten also carries the time instance when it got rotten.
                    orangesRotten++;
                }
            }
        }

        // If all fresh oranges have been rotten, return the total time needed for them to rot;
        // else return -1 indicating all fresh oranges couldn't be rotten.
        if(freshOranges == orangesRotten) return timePassed;
        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {{2, 1, 1},
                                {1, 1, 0},
                                {0, 1, 1}};
    Solution sol;
    cout << sol.orangesRotting(grid);

    return 0;
}
