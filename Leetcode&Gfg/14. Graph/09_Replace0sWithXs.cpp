// GFG: Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O'
// or a group of 'O' with 'X' that are surrounded by 'X'.
// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below,
//  just above, just left and just right of it.

// Example 1:
// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.

// Example 2:
// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.

// Algorithm: The algorithm is very simple and straight forward. A O or group of Os can only be converted to Xs if none of the Os in
// the group stand on the boundary of matrix.
// 1. Create a 'vis' matrix to keep a track of cells visited.
// 2. Traverse the boundary of matrix(first row, last row, first col, last col) to search for any Os. If found, it is for sure that
//    group of Os belonging to this O cannot be converted to X. Therefore, find its group of Os with the help of dfs traversal and
//    mark the whole group as visited.
// 3. Traverse the mid area(non-boundary area) of the matrix to search for Os. If any such Os found to be unvisited yet, it is for
//    sure that they have no link with the boundary(if they had a link with boundary, they would have been already marked visited
//    during the dfs traversals). Hence such Os can be converted to Xs. Thus, do so and finally return the matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat) {
        vis[row][col] = 1;   // mark the current cell as visited
        int n = mat.size();
        int m = mat[0].size();

        // Traverse in all 4 directions to find neighbouring Os of this cell
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') dfs(nrow, ncol, vis, mat);
        }
    }

public:
    // T.C: O(n*m)
    // S.C: O(n*m)
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int>(m, 0));   // create a 'vis' matrix to track visited cells

        // Traverse the first row and last row to check for any unvisited Os. If found, start dfs from there and mark its whole group visited.
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat);
        }
        for(int j = 0; j < m; j++) {
            if(!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, vis, mat);
        }

        // Traverse the first col and last col to check for any unvisited Os. If found, start dfs from there and mark its whole group visited.
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, vis, mat);
        }

        // If any unvisited Os found in mid area (non-boundary area) of matrix, convert them to Xs
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }

        return mat;
    }
};


int main() {
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'}, 
                                {'X', 'O', 'X', 'X'}, 
                                {'X', 'O', 'O', 'X'}, 
                                {'X', 'O', 'X', 'X'}, 
                                {'X', 'X', 'O', 'O'}};
    int n = mat.size();
    int m = mat[0].size();
    
    Solution sol;
    vector<vector<char>> ans = sol.fill(n, m, mat);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Note: Exact same problem exists in Leetcode: 130. Surrounded Regions
