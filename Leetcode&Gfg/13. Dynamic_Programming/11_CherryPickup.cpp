// Leetcode: 741. Cherry Pickup   --->   You are given an n x n grid representing a field of cherries, each cell is one
// of three possible integers.
// • 0 means the cell is empty, so you can pass through,
// • 1 means the cell contains a cherry that you can pick up and pass through, or
// • -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by following the rules below:
// • Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells
//   (cells with value 0 or 1).
// • After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
// • When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
// • If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

// Example 1:
// Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
// Output: 5
// Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.

// Example 2:
// Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
// Output: 0

// Algorithm: As we have to collect cherries from (0, 0) to (n - 1, n - 1) and then return back to (0, 0),
//            we can think of the problem as two robots, one starting from (0, 0) and the other starting
//            from (n - 1, n - 1), and both robots moving towards each other while collecting cherries.
//            This means the same if two robots were moving from (0, 0) to (n - 1, n - 1) simultaneously.
//            We will use two pairs of indices: (i1, j1) for Robot1 and (i2, j2) for Robot2.
//            Each robot can move to 2 possible positions: right or down. For each movement of Robot1, Robot2
//            can move to 2 possible positions. Thus, we will have 2 * 2 = 4 combinations of movements.
//            The 4 combinations of movements for both robots at each step are:
//            1) Robot1 moves down and Robot2 moves down: (i1 + 1, j1) and (i2 + 1, j2)
//            2) Robot1 moves right and Robot2 moves down: (i1, j1 + 1) and (i2 + 1, j2)
//            3) Robot1 moves down and Robot2 moves right: (i1 + 1, j1) and (i2, j2 + 1)
//            4) Robot1 moves right and Robot2 moves right: (i1, j1 + 1) and (i2, j2 + 1)
//            In the above approach, we will have 4^n possible paths to explore, where n is the no.of rows in the grid.
//            Thus, we will have to use a 4D dp table to memoize the results of subproblems.
//            But we can bring the 4D dp table down to a 3D dp table by observing that at any step,
//            i1 + j1 = i2 + j2, so we can compute j2 as follows: j2 = i1 + j1 - i2.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
        int n = grid.size();
        // Base cases:
        // 1) If either robot goes out of bounds, return a very small value to avoid that path being considered.
        // 2) If any of the robots reached the last cell, return the value of that cell.
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;
        if((i1 == n - 1 && j1 == n - 1) || (i2 == n - 1 && j2 == n - 1)) return grid[n - 1][n - 1];
        
        // Explore all possible 4 movements for both robots and find the maximum cherries collected.
        int cherries = -1e8, maxCherries = -1e8;
        int dr1[] = {1, 0, 1, 0};
        int dc1[] = {0, 1, 0, 1};
        int dr2[] = {1, 1, 0, 0};
        int dc2[] = {0, 0, 1, 1};
        for(int i = 0; i < 4; i++) {
            if((i1 == i2) && (j1 == j2)) cherries = grid[i1][j1];   // if robots are at the same cell, only one takes the cherries
            else cherries = grid[i1][j1] + grid[i2][j2];   // else if robots are at different cells, both take the cherries
            cherries += solve(i1 + dr1[i], j1 + dc1[i], i2 + dr2[i], j2 + dc2[i], grid);
            maxCherries = max(maxCherries, cherries);
        }

        return maxCherries;
    }

    // T.C: O(4^n * 4^n) = O(16^n);   where n is the no.of rows in the grid
    // S.C: O(n);   recursion stack space
    int cherryPickup_recursion(vector<vector<int>>& grid) {
        int n = grid.size();
        // If no cherries can be collected, solve() function returns -1e8, so we return 0 in that case.
        return max(0, solve(0, 0, 0, 0, grid));
    }

// ---------------------------------------------------------------------------------------------------

    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        int n = grid.size();
        // Base cases:
        // 1) If either robot goes out of bounds, return a very small value to avoid that path being considered.
        // 2) If any of the robots reached the last cell, return the value of that cell.
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;
        if((i1 == n - 1 && j1 == n - 1) || (i2 == n - 1 && j2 == n - 1)) return grid[n - 1][n - 1];
        
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

        // Explore all possible 4 movements for both robots and find the maximum cherries collected.
        int cherries = -1e8, maxCherries = -1e8;
        int dr1[] = {1, 0, 1, 0};
        int dc1[] = {0, 1, 0, 1};
        int dr2[] = {1, 1, 0, 0};
        int dc2[] = {0, 0, 1, 1};
        for(int i = 0; i < 4; i++) {
            if((i1 == i2) && (j1 == j2)) cherries = grid[i1][j1];   // if robots are at the same cell, only one takes the cherries
            else cherries = grid[i1][j1] + grid[i2][j2];   // else if robots are at different cells, both take the cherries
            cherries += solve(i1 + dr1[i], j1 + dc1[i], i2 + dr2[i], j2 + dc2[i], grid, dp);
            maxCherries = max(maxCherries, cherries);
        }

        dp[i1][j1][i2][j2] = maxCherries;
        return dp[i1][j1][i2][j2];
    }

    // T.C: O(N * M * M) * 4;   where N is the no.of rows and M is the no.of columns in the grid
    // S.C: O(N * M * M) for dp table + O(N) for recursion stack space = O(N * M * M)
    int cherryPickup_memoization_4D(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        return max(0, solve(0, 0, 0, 0, grid, dp));
    }

// ---------------------------------------------------------------------------------------------------

    int solve(int i1, int j1, int i2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // At any step, i1 + j1 = i2 + j2, so we can compute j2 as follows:
        int j2 = i1 + j1 - i2;

        // Base cases:
        // 1) If either robot goes out of bounds, return a very small value to avoid that path being considered.
        // 2) If any of the robots reached the last cell, return the value of that cell.
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e8;
        if((i1 == n - 1 && j1 == n - 1) || (i2 == n - 1 && j2 == n - 1)) return grid[n - 1][n - 1];

        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];

        // Explore all possible 4 movements for both robots and find the maximum cherries collected.
        int cherries = -1e8, maxCherries = -1e8;
        int dr1[] = {1, 0, 1, 0};
        int dc1[] = {0, 1, 0, 1};
        int dr2[] = {1, 1, 0, 0};
        for(int i = 0; i < 4; i++) {
            if((i1 == i2) && (j1 == j2)) cherries = grid[i1][j1];   // if robots are at the same cell, only one takes the cherries
            else cherries = grid[i1][j1] + grid[i2][j2];   // else if robots are at different cells, both take the cherries
            cherries += solve(i1 + dr1[i], j1 + dc1[i], i2 + dr2[i], n, grid, dp);
            maxCherries = max(maxCherries, cherries);
        }

        dp[i1][j1][i2] = maxCherries;
        return dp[i1][j1][i2];
    }
    
    // T.C: O(N * M * M) * 4;   where N is the no.of rows and M is the no.of columns in the grid
    // S.C: O(N * M * M) for dp table + O(N) for recursion stack space = O(N * M * M)
    int cherryPickup_memoization_3D(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(0, 0, 0, n, grid, dp));
    }
};


int main() {
    vector<vector<int>> grid = {{0, 1, -1},
                                {1, 0, -1},
                                {1, 1, 1}};

    Solution sol;
    cout << sol.cherryPickup_recursion(grid) << endl;
    cout << sol.cherryPickup_memoization_4D(grid) << endl;
    cout << sol.cherryPickup_memoization_3D(grid);

    return 0;
}
