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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C:
    // S.C:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
    }

// -------------------------------------------------------------------------------

    // T.C:
    // S.C:
    vector<vector<int>> buildMST(int V, vector<vector<int>> adj[]) {
        
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
