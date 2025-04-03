// Leetcode: 1319: Number of Operations to Make Network Connected   --->   There are n computers numbered from 0 to n - 1
// connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection
// between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected
// computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not
// possible, return -1.

// Example 1:
// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Example 2:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2

// Example 3:
// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

// Algorithm: Extremely simple.
// 1. Create a disjoint set for all vertices of the graph.
// 2. If number of edges given in the input is less than vertices - 1, then connecting all vertices is not possible,
//    i.e., connecting all components is impossible. Thus, to connect n components, we need atleast n - 1 edges.
//    So, if number of edges is less than vertcies - 1, return -1 stating that connection is impossible.
// 3. Traverse all the edges given the input and merge the connected vertices into single component.
// 4. Finally, count the number of different components in the graph and store it in a variable say 'comp'.
// 5. To connect 'comp' number of components, 'comp - 1' edges will be required. Thus, return 'comp - 1'.

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
    // T.C: O(n)
    // S.C: O(n)
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;   // we need at least n-1 edges to connect all nodes
        
        DisjointSet ds(n);

        for(auto& it: connections) {
            int u = it[0];
            int v = it[1];
            ds.unionByRank(u, v);   // merge components
        }

        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findParent(i) == i) comp++;
        }

        return comp - 1;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};

    cout << Solution().makeConnected(n, connections);

    return 0;
}
