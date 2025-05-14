// GFG: Maximum Stone Removal   --->   Given an 2D array of non-negative integers stones[][] where stones[i] = [xi, yi]
// represents the location of the ith stone on a 2D plane, the task is to return the maximum possible number of stones
// that you can remove.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Note: Each coordinate point may have at most one stone.

// Example 1:
// Input: stones[][] = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
// Output:5
// Explanation:
// One way to remove 5 stones is as follows:
// 1. Remove stone [2, 2] because it shares the same row as [2, 1].
// 2. Remove stone [2, 1] because it shares the same column as [0, 1].
// 3. Remove stone [1, 2] because it shares the same row as [1, 0].
// 4. Remove stone [1, 0] because it shares the same column as [0, 0].
// 5. Remove stone [0, 1] because it shares the same row as [0, 0].
// Stone [0, 0] cannot be removed since it does not share any row/column with another stone still on the plane.

// Example 2:
// Input: stones[][] = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
// Output: 3
// Explanation: 
// One way to remove 3 stones is as follows:
// 1. Remove stone [2, 2] because it shares the same row as [2, 0].
// 2. Remove stone [2, 0] because it shares the same column as [0, 0].
// 3. Remove stone [0, 2] because it shares the same row as [0, 0].
// Stones [0, 0] and [1, 1] cannot be removed since they do not share any row/column with another stone still on the plane.

// Problem link: https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

// Algorithm: As we are supposed to remove maximum number of stones only from the row or column where already
//            atleast one stone is present, we can use the disjoint set data structure to solve this problem.
//            But the catch is that we will not consider the stones as nodes in the disjoint set; instead we will
//            consider the rows and columns as nodes in the disjoint set.
// 1. Create a disjoint set of size (maxRow + maxCol + 2) where maxRow and maxCol are the maximum row and column
//    indices in the stones array. The row no.s will start from 0 to maxRow and the columns will start from
//    (maxRow + 1) to (maxRow + maxCol + 1), i.e., lets say there is a 5*4 grid with rows 0 to 4, and columns 0 to 3,
//    so its disjoint set will be of size 4 + 3 + 2 = 9. And rows will be labelled as 0, 1, 2, 3, 4 and columns will
//    be labelled as 5, 6, 7, 8.
// 2. Traverse the stones array and compute the label of row and column coordinates of each stone. Then union the
//    row and column of each stone in the disjoint set. For example, for a 5*4 grid, if a stone is present at (0, 0),
//    we will union the node 0 (label of row 0) and node 5 (label of column 0) in the disjoint set.
//    This will create a disjoint set of all the connected components, i.e., we will get unqiue components of the grid.
// 3. 
// 

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if(root_u == root_v) return;

        if(size[root_u] < size[root_v]) {
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0, maxCol = 0;
        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);   // +2 for 0-based indexing
        unordered_map<int, int> stoneNodes;
        for(auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;   // count of the number of unique components
        for(auto it: stoneNodes) {
            if(ds.findParent(it.first) == it.first) cnt++;
        }

        return n - cnt;
    }
};

int main() {
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int n = stones.size();

    Solution sol;
    cout << sol.maxRemove(stones, n);

    return 0;
}
