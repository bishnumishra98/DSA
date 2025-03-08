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

// Algorithm:
// 1. Create a queue and push the source cell into the queue with distance 0. We are following Djiakstra's algorithm only,
//    but we do not require a priority queue as we are not updating the distance of a cell if it is already visited. We
//    are updating the distance of a cell only if it is not visited. So, we can use a normal queue.
// 2. Create a 2D array dist[][] of size n*m and initialize it with 1e9. This array will store the minimum distance of
//    each cell from the source cell.
// 3. Initialize the distance of the source cell as 0 in the dist[][] array.
// 4. Run a loop until the queue is not empty.
// 5. Pop the front element of the queue and store it in a variable it.
// 6. Extract the distance, row, and column of the cell from the variable it.
// 7. Run a loop from i = 0 to 3. In each iteration, calculate the new row and column of the cell by adding dr[i] and dc[i] to
//    the current row and column respectively. dr[] and dc[] are arrays that store the change in row and column respectively
//    to move in all four directions.
// 8. Check if the new row and column are within the matrix bounds and the cell is not visited and the cell is not blocked.
//    If all the conditions are satisfied, then update the distance of the new cell as dis + 1 and push the new cell into the
//    queue.
// 9. If the new cell is the destination cell, then return the distance of the new cell.
// 10. If the destination cell is not reached, then return -1.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*m)
    // S.C: O(n*m)
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
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
                    dist[newr][newc] = dis + 1;
                    if(newr == destination.first && newc == destination.second) return dis + 1;
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
