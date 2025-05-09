// GFG: Number Of Islands   --->   You are given a n,m which means the row and column of the 2D matrix and an array of
// size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally,
// the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator
// has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island.
// Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

// Example 1:
// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}
// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011

// Example 2:
// Input: n = 4
// m = 5
// k = 4
// A = {{0,0},{1,1},{2,2},{3,3}}
// Output: 1 2 3 4
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  10000
//     00000
//     00000
//     00000
// 2.  10000
//     01000
//     00000
//     00000
// 3.  10000
//     01000
//     00100
//     00000
// 4.  10000
//     01000
//     00100
//     00010

// Your Task:
// You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an
// integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a
// 2D array of size k denoting  the number of operators.

// Problem link: https://www.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

// Algorithm: The approach is quiet simple.
//            In the n * m 2D matrix, consider the first cell to be node 0 and the last cell to be node (n * m) - 1.
//            Thus, the cells will be labelled as follows:
//            0 1 2 3 4
//            5 6 7 8 9
//            10 11 12 13 14
//            15 16 17 18 19
//            The formula to convert a cell (row, col) to a node number is: nodeNo = no.of_col * row_no + col_no
// 1. Create a Disjoint Set Union (DSU) data structure to keep track of the connected components in the matrix.
// 2. Create a 2D visited matrix to track which cells have been turned into land. Initialize all cells to false (water).
// 3. Initialize a counter to keep track of the number of islands (connected components) in the matrix. Set it to 0 initially.
// 4. For each operation (i.e., a cell to convert from water to land):
//    a. If the cell is already land, the island count doesn't change. So simply push the current count to the result
//       and continue to the next iteration. Otherwise, mark it as land and increment the count.
//    b. Convert the cell (row, col) to a unique node number using the formula: nodeNo = no.of_col * row_no + col_no
//    c. Check all 4 adjacent cells (up, down, left, right) to see if they are also land. If they are, union them with the
//       current cell and decrement the island count.
// 5. After processing each operation, append the current number of islands to the result array.
// 6. Return the result array.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if(root_u == root_v) return;
        else if(rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if(rank[root_v] < rank[root_u]) {
            parent[root_v] = root_u;
        } else {
            parent[root_u] = root_v;
            rank[root_v]++;
        }
    }
};

class Solution {
public:
    // T.C: O(k * 4) = O(k);   where k is the number of operations
    // S.C: O(n * m)   for the visited matrix and O(n * m) for the disjoint set
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<bool>> vis(n, vector<bool>(m, false));   // 2D visited matrix to track which cells have been turned into land
        int cnt = 0;   // number of islands
        vector<int> ans;   // result array to store island count after each operation
    
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        // Process each operator (i.e., a cell to convert from water to land)
        for(auto& it : operators) {
            int row = it[0];
            int col = it[1];
            
            // If this cell is already land, island count doesn't change. So simply push the current count to the result
            // and continue to the next iteration. Otherwise, mark it as land and increment the count.
            if(vis[row][col]) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = true;
            cnt++;
    
            int nodeNo = m * row + col;   // Unique 1D ID for the cell in DSU (nodeNo = no.of_col * row_no + col_no)
            
            // Check all 4 adjacent cells (up, down, left, right) to see if they are also land
            // If they are, union them with the current cell and decrement the island count
            for(int i = 0; i < 4; i++) {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                if(adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m && vis[adjRow][adjCol]) {
                    int adjNodeNo = m * adjRow + adjCol;

                    // If the adjacent land cell belongs to a different island, merge them and decrement the count
                    if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo)) {
                        ds.unionByRank(nodeNo, adjNodeNo);
                        cnt--;   // two islands merged, so reduce count
                    }
                }
            }

            ans.push_back(cnt);   // append the current number of islands to the result
        }
    
        return ans;
    }
};


int main() {
    int n = 4, m = 5, k = 4;
    vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    
    Solution obj;
    vector<int> result = obj.numOfIslands(n, m, operators);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
