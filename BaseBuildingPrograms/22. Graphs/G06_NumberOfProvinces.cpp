// Leetcode: 547. Number of Provinces   --->   There are n cities. Some of them are connected, while some are not.
// A province is a group of connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are connected,
// and isConnected[i][j] = 0 otherwise. Return the total number of provinces.

// Example 1:
// 1 --- 2
//    3
// Input: isConnected = [[1,1,0],
//                       [1,1,0],
//                       [0,0,1]]
// Output: 2

// Example 2:
// 1     2
//    3
// Input: isConnected = [[1,0,0],
//                       [0,1,0],
//                       [0,0,1]]
// Output: 3

// Algorithm: It is very easy and simple problem already solved using traversal technique in
// 'Leetcode&Gfg\14. Graph\01_NumberOfProvinces.cpp' Here we will solve the same problem using Disjoint set.

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
    // T.C: O(V^2);   where V = no.of cities, i.e., isConnected.size()
    // S.C: O(V)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();   // number of cities or vertices in graph
        DisjointSet ds(V);

        // Traverse the matrix and merge connected cities or components
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1) ds.unionByRank(i, j);
            }
        }

        // Count the number of nodes which are parent of itself. Such nodes are unique root nodes, i.e., root of
        // an isolated component. Thus, number of such nodes means number of isolated components or number of provinces.
        int provinces = 0;
        for(int i = 0; i < V; i++) {
            if(ds.findParent(i) == i) provinces++;
        }

        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    Solution sol;
    cout << sol.findCircleNum(isConnected);

    return 0;
}
