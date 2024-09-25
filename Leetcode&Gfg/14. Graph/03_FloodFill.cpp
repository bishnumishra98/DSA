// Leetcode: 733. Flood fill   --->   An image is represented by an m x n integer grid image where image{i][j]
// represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting
// from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the
// starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those
// pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

// Example 1:
// Input: image = [[1,1,1],
//                 [1,1,0],
//                 [1,0,1]],
// sr = 1, sc = 1, color = 2
// Output: [[2,2,2],
//          [2,2,0],
//          [2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by
// a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Example 2:
// Input: image = [[0,0,0],
//                 [0,0,0]],
// sr = 0, sc = 0, color = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored 0, so no changes are made to the image.

// Algorithm:
// 1. Change the color of the source cell given.
// 2. Traverse BFS or DFS from source cell to change colors of its 4 neighbour cells(up, right, down, left)
//    if they have the same color as the source cell had initially.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, int srcColor, int color, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;   // paint the current cell with given color
        
        /*
        // Paint the 4 neighbours of current cell with 'color' if they have same 'srcColor'
        if(row-1 >= 0 && image[row-1][col] == srcColor) dfs(row-1, col, srcColor, color, image);
        if(col+1 < m && image[row][col+1] == srcColor) dfs(row, col+1, srcColor, color, image);
        if(row+1 < n && image[row+1][col] == srcColor) dfs(row+1, col, srcColor, color, image);
        if(col-1 >= 0 && image[row][col-1] == srcColor) dfs(row, col-1, srcColor, color, image);
        */

        // The above 4 lines of code can be written in a crisp way using a for loop
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == srcColor) dfs(nrow, ncol, srcColor, color, image);
        }
    }

    // T.C: O(n*m);   where n and m are no.of rows and cols in image respectively.
    // S.C: O(n*m)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int srcColor = image[sr][sc];
        if(srcColor == color) return image;   // if the source cell is already same as the given color, return the image unchanged
        dfs(sr, sc, srcColor, color, image);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;

    Solution sol;
    vector<vector<int>> ans = sol.floodFill(image, sr, sc, color);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
