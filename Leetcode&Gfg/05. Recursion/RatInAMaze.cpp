// GFG: Rat in a Maze   --->   Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal
// is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down),
// 'L' (left), 'R' (right).
// The matrix contains only two possible values:
// ● 0: A blocked cell through which the rat cannot travel.
// ● 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at
// (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only
// move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.
// Note: Return the final result vector in lexicographically smallest order.

// Example 1:
// Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed
//              in sorted order we get DDRDRR DRDDRR.

// Example 2:
// Input: maze[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell (1, 1) is blocked.

// Example 3:
// Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void solve(int i, int j, vector<vector<int>>&maze, int n, vector<string>& ans, string ds, vector<vector<bool>> visited) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(ds);
            return;
        }

        // To get strings inside 'ans' in sorted order, we will follow the direction: D -> L -> R -> U
        // Down
        if(i + 1 < n && maze[i + 1][j] == 1 && visited[i + 1][j] == 0) {
            visited[i][j] = true;
            solve(i + 1, j, maze, n, ans, ds + 'D', visited);
            visited[i][j] = false;   // backtracking
        }

        // Left
        if(j - 1 >= 0 && maze[i][j - 1] == 1 && visited[i][j - 1] == 0) {
            visited[i][j] = true;
            solve(i, j - 1, maze, n, ans, ds + 'L', visited);
            visited[i][j] = false;   // backtracking
        }

        // Right
        if(j + 1 < n && maze[i][j + 1] == 1 && visited[i][j + 1] == 0) {
            visited[i][j] = true;
            solve(i, j + 1, maze, n, ans, ds + 'R', visited);
            visited[i][j] = false;   // backtracking
        }

        // Up
        if(i - 1 >= 0 && maze[i - 1][j] == 1 && visited[i - 1][j] == 0) {
            visited[i][j] = true;
            solve(i - 1, j, maze, n, ans, ds + 'U', visited);
            visited[i][j] = false;   // backtracking
        }
    }

    // T.C: O(4^(n^2))
    // S.C: O(n^2);   due to maximum depth of recursive stack
    vector<string> ratInMaze_expanded(vector<vector<int>>&maze) {
        int n = maze.size();
        string ds = "";   // temporary string to store one path
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if(maze[0][0] == 1) solve(0, 0, maze, n, ans, ds, visited);   // if maze[0][0] is 1, then only we can proceed to build the paths
        return ans;
    }

// ----------------------------------------------------------------------------------------------------------------------------

    void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, string ds, vector<vector<bool>> visited, vector<int>& di, vector<int>& dj) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(ds);
            return;
        }

        string dir = "DLRU";
        for(int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && maze[nexti][nextj] == 1 && visited[nexti][nextj] == false) {
                visited[i][j] = true;
                solve(nexti, nextj, maze, n, ans, ds + dir[index], visited, di, dj);
                visited[i][j] = false;   // backtracking
            }
        }
    }

    // T.C: O(4^(n^2))
    // S.C: O(n^2);   due to maximum depth of recursive stack
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // Directions       D       L     R       U
        // i-coordinate     i + 1   i     i       i + 1
        // j-coordinate     j       j     j + 1   j
        vector<int> di = {1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};
        string ds = "";
        if(maze[0][0] == 1) solve(0, 0, maze, n, ans, ds, visited, di, dj);
        return ans;
    }
};


int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    
    Solution sol;

    vector<string> ans1 = sol.ratInMaze_expanded(maze);
    for(string path : ans1) cout << path << " ";

    cout << endl;

    vector<string> ans2 = sol.ratInMaze(maze);
    for(string path : ans2) cout << path << " ";

    return 0;
}
