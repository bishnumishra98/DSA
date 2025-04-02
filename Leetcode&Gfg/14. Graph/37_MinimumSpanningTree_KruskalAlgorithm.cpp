// GFG: Minimum Spanning Tree   --->   Given a weighted, undirected, and connected graph with V vertices and E edges,
// your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.
// The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.
// Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer
// denoting the weight of the edge.

// Example 1:
// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
// Output: 4

// Example 2:
// Input:
// 2 1
// 0 1 5
// Output: 5

// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Algorithm to find the sum of edges in the Minimum Spanning Tree (MST) using Kruskal's Algorithm:
// 1. i.   Create an edge list from the adjacency list in the format {edgeWeight, node, adjNode}.
//    ii.  Sort the edges in ascending order of edgeWeight.
// 2. Initialize a Disjoint Set of size as many vertices in the graph, to manage connected components.
// 3. Initialize 'sum' = 0 (this will store the total weight of the MST).
// 4. Traverse through sorted edges:
//    - If the edge connects two different components (i.e., findParent(u) != findParent(v)),  
//      add the edge weight to 'sum' and perform a union operation to merge the components.
// 5. At the end, return 'sum'.

// Algorithm to build the Minimum Spanning Tree (MST) using Kruskal's Algorithm: Almost same as above
// 1. i.   Create an edge list from the adjacency list in the format {edgeWeight, node, adjNode}.
//    ii.  Sort the edges in ascending order of weight.
// 2. Initialize a Disjoint Set of size as many vertices in the graph, to manage connected components.
// 3. Initialize 'result' array to store the MST edges {parent, node, edgeWeight}.
// 4. Traverse through sorted edges:
//    - If the edge connects two different components (i.e., findParent(u) != findParent(v)),  
//      add {parent, node, edgeWeight} to 'result' and perform a union operation to merge the components.
// 5. At the end, return 'result'.


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
    // T.C: O(ElogE);   where E = no.of edges
    // S.C: O(V + E);   where V = no.of vertices
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int adjWeight = it[1];
                int node = i;
                edges.push_back(make_tuple(adjWeight, node, adjNode));
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int sum = 0;
        for(auto it: edges) {
            int wt = get<0>(it);
            int u = get<1>(it);
            int v = get<2>(it);

            if(ds.findParent(u) != ds.findParent(v)) {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }

        return sum;
    }

// -------------------------------------------------------------------------------

    // T.C: O(ElogE);   where E = no.of edges
    // S.C: O(V + E);   where V = no.of vertices
    vector<vector<int>> buildMST(int V, vector<vector<int>> adj[]) {
        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int adjWeight = it[1];
                int node = i;
                edges.push_back(make_tuple(adjWeight, node, adjNode));
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        vector<vector<int>> result;   // to store the MST edges {parent, node edgeWeight}

        for(auto it: edges) {
            int wt = get<0>(it);
            int u = get<1>(it);
            int v = get<2>(it);

            if(ds.findParent(u) != ds.findParent(v)) {
                result.push_back({u, v, wt});
                ds.unionByRank(u, v);
            }
        }

        return result;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});  // Edge 0 -> 1 with weight 5
    adj[1].push_back({0, 5});  // Edge 1 -> 0 with weight 5
    adj[1].push_back({2, 3});  // Edge 1 -> 2 with weight 3
    adj[2].push_back({1, 3});  // Edge 2 -> 1 with weight 3
    adj[0].push_back({2, 1});  // Edge 0 -> 2 with weight 1
    adj[2].push_back({0, 1});  // Edge 2 -> 0 with weight 1

    cout << Solution().spanningTree(V, adj) << endl;

    vector<vector<int>> mst = Solution().buildMST(V, adj);
    for(int i = 0; i < mst.size(); i++) {
        cout << mst[i][0] << " -> " << mst[i][1] << " with edge weight " << mst[i][2] << endl;
    }

    return 0;
}
