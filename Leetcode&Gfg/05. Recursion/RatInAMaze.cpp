// GFG: Rat in a Maze Problem - I   --->   Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach
// the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The
// directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix
// represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be
// travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is blocked.

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, string ds, vector<vector<int>> visited) {
        if(i == n-1 && j == n-1) {
            ans.push_back(ds);
            return;
        }

        // To get strings inside 'ans' in sorted order, we will follow the direction: D -> L -> R -> U
        // Down
        if(i+1<n && visited[i+1][j]==0 && m[i+1][j]==1) {
            visited[i][j] = 1;
            solve(i+1, j, m, n, ans, ds+'D', visited);
            visited[i][j] = 0;   // backtracking
        }

        // Left
        if(j-1>=0 && visited[i][j-1]==0 && m[i][j-1]==1) {
            visited[i][j] = 1;
            solve(i, j-1, m, n, ans, ds+'L', visited);
            visited[i][j] = 0;   // backtracking
        }

        // Right
        if(j+1<n && visited[i][j+1]==0 && m[i][j+1]==1) {
            visited[i][j] = 1;
            solve(i, j+1, m, n, ans, ds+'R', visited);
            visited[i][j] = 0;   // backtracking
        }

        // Up
        if(i-1>=0 && visited[i-1][j]==0 && m[i-1][j]==1) {
            visited[i][j] = 1;
            solve(i-1, j, m, n, ans, ds+'U', visited);
            visited[i][j] = 0;   // backtracking
        }
    }

    // T.C: O(4^(n^2))
    // S.C: O(n^2);   due to maximum depth of recursive stack
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(m[0][0] == 1) solve(0, 0, m, n, ans, "", visited);   // if m[0][0] is 1, then only we can proceed to build the paths
        if(ans.empty()) ans = {"-1"};   // return "-1" if no path exists
        return ans;
    }

// ----------------------------------------------------------------------------------------------------------------------------

    void solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, string ds, vector<vector<int>> visited, int di[], int dj[]) {
        if(i == n-1 && j == n-1) {
            ans.push_back(ds);
            return;
        }

        string dir = "DLRU";
        for(int index=0; index<4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && visited[nexti][nextj]==0 && m[nexti][nextj]==1) {
                visited[i][j] = 1;
                solve(nexti, nextj, m, n, ans, ds+dir[index], visited, di, dj);
                visited[i][j] = 0;   // backtracking
            }
        }
    }

    // T.C: O(4^(n^2))
    // S.C: O(n^2);   due to maximum depth of recursive stack
    vector<string> findPath_4loopsin1(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) solve(0, 0, m, n, ans, "", visited, di, dj);
        if(ans.empty()) ans = {"-1"};
        return ans;
    }
};

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1}, 
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    int n = 4;
    
    Solution sol;
    vector<string> ans1 = sol.findPath(m, n);
    for(string s: ans1) cout << s << endl;
    cout << endl;
    vector<string> ans2 = sol.findPath_4loopsin1(m, n);
    for(string s: ans2) cout << s << endl;

    return 0;
}
