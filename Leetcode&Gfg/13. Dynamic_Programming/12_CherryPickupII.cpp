// Leetcode: 1463. Cherry Pickup II   --->   You are given a rows x cols matrix grid representing a field of cherries
// where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
// You have two robots that can collect cherries for you:
// • Robot #1 is located at the top-left corner (0, 0), and
// • Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:
// • From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// • When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// • When both robots stay in the same cell, only one takes the cherries.
// • Both robots cannot move outside of the grid at any moment.
// • Both robots should reach the bottom row in grid.

// Example 1:
// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.

// Example 2:
// Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
// Output: 28
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
// Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
// Total of cherries: 17 + 11 = 28.

// Algorithm: As we have two fixed starting points, but variable ending points, we will start recursion from the
//            starting points, i.e., (0, 0) and (0, cols - 1) and move downwards to the last row.
//            To track movements of both robots, we must have two pair of indices: (i1, j1) and (i2, j2) for Robot1 and Robot2.
//            But as at every step, both robots move to the next row, we can use a single index 'i' for both robots. Thus,
//            we will have (i, j1) for Robot1 and (i, j2) for Robot2.
//            Each robot can move to 3 possible positions in the next row, i.e., (i + 1, j1 - 1), (i + 1, j1), (i + 1, j1 + 1).
//            Thus, to explore all possible paths, we will try all combinations of movements for both robots. For each
//            movement of Robot1, there are 3 possible movements of Robot2, or vice versa). Thus, we will have 3 * 3 = 9
//            combinations of movements for both robots at each step.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j1, int j2, int row, int col, vector<vector<int>>& grid) {
        // Base cases:
        // 1) If either robot goes out of bounds, return a very small value to avoid that path being considered.
        // 2) If we are at the last row, there can be two scenarios:
        //    a) If both robots are at the same cell, return the value of that cell.
        //    b) If robots are at different cells, return the sum of both cells.
        if(j1 < 0 || j2 < 0 || j1 >= col || j2 >= col) return -1e8;
        if(i == row - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        // Explore all possible 9 movements for both robots and find the maximum cherries collected.
        int maxCherries = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int cherries;
                if(j1 == j2) cherries = grid[i][j1];   // if both robots are at the same cell, only one can pick the cherries
                else cherries = grid[i][j1] + grid[i][j2];   // if robots are at different cells, both can pick cherries
                cherries += solve(i + 1, j1 + dj1, j2 + dj2, row, col, grid);   // move to the next row
                maxCherries = max(maxCherries, cherries);   // update the maximum cherries collected
            }
        }

        return maxCherries;
    }

    // T.C: O(3^n * 3^n) = O(9^n);   where n is the no.of rows in the grid
    // S.C: O(n);   recursion stack space
    int cherryPickup_recursion(vector<vector<int>>& grid) {
        int row = grid.size();   // no.of rows in grid
        int col = grid[0].size();   // no.of columns in grid
        return solve(0, 0, col - 1, row, col, grid);
    }

// ---------------------------------------------------------------------------------------

    int solve(int i, int j1, int j2, int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j2 < 0 || j1 >= col || j2 >= col) return -1e8;
        if(i == row - 1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxCherries = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int cherries;
                if(j1 == j2) cherries = grid[i][j1];
                else cherries = grid[i][j1] + grid[i][j2];
                cherries += solve(i + 1, j1 + dj1, j2 + dj2, row, col, grid, dp);
                maxCherries = max(maxCherries, cherries);
            }
        }

        dp[i][j1][j2] = maxCherries;
        return dp[i][j1][j2];
    }

    // T.C: O(N * M * M) * 9;   where N is the no.of rows and M is the no.of columns in the grid
    // S.C: O(N * M * M) for dp table + O(N) for recursion stack space = O(N * M * M)
    int cherryPickup_memoization(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return solve(0, 0, col - 1, row, col, grid, dp);
    }

// ---------------------------------------------------------------------------------------

    // T.C: O(N * M * M) * 9;   where N is the no.of rows and M is the no.of columns in the grid
    // S.C: O(N * M * M)
    int cherryPickup_tabulation(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

        // Fill the last row of dp table
        for(int j1 = 0; j1 < col; j1++) {
            for(int j2 = 0; j2 < col; j2++) {
                if(j1 == j2) dp[row - 1][j1][j2] = grid[row - 1][j1];
                else dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
            }
        }

        // Fill the dp table from bottom to top
        for(int i = row - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < col; j1++) {
                for(int j2 = 0; j2 < col; j2++) {
                    int maxCherries = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int cherries;
                            if(j1 == j2) cherries = grid[i][j1];
                            else cherries = grid[i][j1] + grid[i][j2];
                            if(j1 + dj1 >= 0 && j1 + dj1 < col && j2 + dj2 >= 0 && j2 + dj2 < col)
                                cherries += dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                cherries += -1e8;   // if out of bounds, add a very small value to avoid that path being considered
                            maxCherries = max(maxCherries, cherries);
                        }
                    }

                    dp[i][j1][j2] = maxCherries;
                }
            }
        }

        return dp[0][0][col - 1];   // return the maximum cherries collected starting from (0, 0) and (0, col - 1)
    }

// ---------------------------------------------------------------------------------------

    // T.C: O(N * M * M) * 9;   where N is the no.of rows and M is the no.of columns in the grid
    // S.C: O(M * M)
    int cherryPickup_tabulation_SO(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> prev(col, vector<int>(col, 0));   // to store the previous row's results

        // Fill the last row of prev with values of last row of grid
        for(int j1 = 0; j1 < col; j1++) {
            for(int j2 = 0; j2 < col; j2++) {
                if(j1 == j2) prev[j1][j2] = grid[row - 1][j1];
                else prev[j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
            }
        }

        // Fill the dp table from bottom to top
        for(int i = row - 2; i >= 0; i--) {
            vector<vector<int>> cur(col, vector<int>(col, 0));   // to store the current row's results
            for(int j1 = 0; j1 < col; j1++) {
                for(int j2 = 0; j2 < col; j2++) {
                    int maxCherries = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int cherries;
                            if(j1 == j2) cherries = grid[i][j1];
                            else cherries = grid[i][j1] + grid[i][j2];
                            if(j1 + dj1 >= 0 && j1 + dj1 < col && j2 + dj2 >= 0 && j2 + dj2 < col)
                                cherries += prev[j1 + dj1][j2 + dj2];
                            else
                                cherries += -1e8;   // if out of bounds, add a very small value to avoid that path being considered
                            maxCherries = max(maxCherries, cherries);
                        }
                    }

                    cur[j1][j2] = maxCherries;
                }
            }
            prev = cur;   // update prev to current row's results
        }

        return prev[0][col - 1];   // return the maximum cherries collected starting from (0, 0)
    }
};


int main() {
    vector<vector<int>> grid = {{3, 1, 1},
                                {2, 5, 1},
                                {1, 5, 5},
                                {2, 1, 1}};
    
    cout << Solution().cherryPickup_recursion(grid) << endl;
    cout << Solution().cherryPickup_memoization(grid) << endl;
    cout << Solution().cherryPickup_tabulation(grid) << endl;
    cout << Solution().cherryPickup_tabulation_SO(grid);

    return 0;
}
