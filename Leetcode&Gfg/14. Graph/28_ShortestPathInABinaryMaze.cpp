// GFG: Shortest Distance in Binary Maze   --->   Given a n * m matrix grid where each element can either be 0 or 1.
// You need to find the shortest distance between a given source cell to a destination cell. The path can only be
// created out of a cell if its value is 1. 
// If the path is not possible between source cell and destination cell, then return -1.
// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent
// if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The
// source and destination cell are based on the zero based indexing. The destination cell should be 1.

// Example 1:
// Input:
// grid[][] = {{1, 1, 1, 1},
//             {1, 1, 0, 1},
//             {1, 1, 1, 1},
//             {1, 1, 0, 0},
//             {1, 0, 0, 1}}
// source = {0, 1}
// destination = {2, 2}
// Output:
// 3
// Explanation:
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 1
// The highlighted part in the matrix denotes the 
// shortest path from source to destination cell.

// Example 2:
// Input:
// grid[][] = {{1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 0},
//             {1, 0, 1, 0, 1}}
// source = {0, 0}
// destination = {3, 4}
// Output:
// -1
// Explanation:
// The path is not possible between source and 
// destination, hence return -1.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a
// 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance
// between source and destination cell.

// Problem link: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

// Algorithm:
// 1. Create a queue and push the distance 0 with source cell coordinates. We are following Djiakstra's algorithm only,
//    but we do not require a priority queue as we are not updating the distance of a cell if it is already visited. We
//    are updating the distance of a cell only if it is not visited. So, we can use a normal queue.
// 2. Create a 2D array dist[][] of size n*m and initialize it with 1e9. This array will store the minimum distance of
//    each cell from the source cell.
// 3. Initialize the distance of the source cell as 0 in the dist[][] array.
// 4. Run a loop until the queue is not empty.
//    i.   Pop the front element of the queue and store it in a variable it.
//    ii.  Extract the distance, row, and column of the cell from the variable it.
//    iii. Move in all four directions: up, right, bottom and left. And check if the coordinates are within the matrix bounds
//         and the cell is not blocked, and the new distance is less than the previous distance. If all the conditions are
//         satisfied, then do the following:
//         a) If the new cell is the destination cell, then straight away return the distance + 1 and the function ends here.
//         b) Update the distance of the new cell in the dist[][] array as distance + 1, and push the updated distance and
//            the coordinates of the new cell in the queue.
// 5. If the destination cell is not reached, then return -1.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*m)
    // S.C: O(n*m)
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();

        // Edge case: If the source is the destination
        if (source == destination) {   // source.first == destination.first && source.second == destination.second
            if (grid[source.first][source.second] == 1) return 0;
            else return -1;   // if the source/destination cell is blocked
        }

        queue<pair<int, pair<int, int>>> q;   // queue to store the distance and the cell coordinates
        q.push({0, {source.first, source.second}});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));   // to store the minimum distance of each cell from the source
        dist[source.first][source.second] = 0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1
                && dis + 1 < dist[newr][newc]) {
                    if(newr == destination.first && newc == destination.second) return dis + 1;
                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    
    Solution obj;
    cout << obj.shortestPath(grid, source, destination);

    return 0;
}
