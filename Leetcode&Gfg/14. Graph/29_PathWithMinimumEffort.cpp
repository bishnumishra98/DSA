// GFG: Path With Minimum Effort   --->   You are a hiker preparing for an upcoming hike. You are given heights[][],
// a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated
// in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
// You can move up, down, left, or right, and you wish to find the route with minimum effort.
// Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Example 1:
// Input:
// row = 3
// columns = 3 
// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 
// 2
// Explaination: 
// The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the
// route 1->2->2->2->5, where the maximum absolute difference is 3.

// Example 2:
// Input:
// row = 2
// columns = 2 
// heights = [[7,7],[7,7]]
// Output: 
// 0
// Explaination: 
// Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes
// intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the
// top-left cell to the bottom-right cell.

// Algorithm:
// 1. Create a priority queue of pairs of integers and a pair of integers.
// 2. Create a 2D vector of integers to store the minimum effort required to reach a cell.
// 3. Initialize the priority queue with the top-left cell and the minimum effort required to reach that cell.
// 4. Create two arrays to store the row and column directions.
// 5. While the priority queue is not empty, pop the top element from the priority queue.
// 6. If the current cell is the bottom-right cell, return the minimum effort required to reach that cell.
// 7. Iterate over the four directions and calculate the new row and column.
// 8. If the new row and column are within the bounds and the new effort is less than the minimum effort required to reach
//    that cell, update the minimum effort required to reach that cell and push the new cell into the priority queue.
// 9. Return 0 if the bottom-right cell is unreachable.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n*m*log(n*m))
    // S.C: O(n*m)
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;

            for(int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    int newdiff = max(diff, abs(heights[newr][newc] - heights[row][col]));
                    if(newdiff < dist[newr][newc]) {
                        dist[newr][newc] = newdiff;
                        pq.push({newdiff, {newr, newc}});
                    }
                }
            }
        }

        return 0;   // unreachable
    }
};


int main() {
    int rows = 3, columns = 3;
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;
    cout << obj.MinimumEffort(rows, columns, heights) << endl;

    return 0;
}
