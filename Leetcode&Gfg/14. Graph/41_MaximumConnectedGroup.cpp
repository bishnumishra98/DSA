// GFG: Maximum Connected group   --->   You are given a square binary grid. A grid is considered binary
// if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1.
// You need to find the largest group of connected  1's. Two cells are said to be connected if both are
// adjacent(top, bottom, left, right) to each other and both have the same value.

// Example 1:
// Input: grid = [1, 1]
//               [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]

// Example 2:
// Input: grid = [1, 0, 1]
//               [1, 0, 1]
//               [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]

// Algorithm:

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if (root_u == root_v) return;

        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution {
public:
    // T.C: O(n^2)   for the grid traversal
    // S.C: O(n^2)   for the disjoint set
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union adjacent 1's in the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int i = 0; i < 4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Check the largest possible connected component
        int maxSize = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;   // skip cells that are already 1
                set<int> uniqueComponents;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int i = 0; i < 4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        int adjNodeNo = newRow * n + newCol;
                        uniqueComponents.insert(ds.findParent(adjNodeNo));
                    }
                }

                int sizeTotal = 0;
                for (auto it : uniqueComponents) {
                    sizeTotal += ds.size[it];
                }
                maxSize = max(maxSize, sizeTotal + 1);
            }
        }

        // Check the maximum size of all existing components
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxSize = max(maxSize, ds.size[ds.findParent(cellNo)]);
        }

        return maxSize;
    }
};


int main() {
    vector<vector<int>> grid = {{1, 0, 1},
                                {1, 0, 1},
                                {1, 0, 1}};

    Solution obj;
    cout << obj.MaxConnection(grid);
    
    return 0;
}
