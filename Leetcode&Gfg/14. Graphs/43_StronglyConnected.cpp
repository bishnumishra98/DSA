// GFG: Strongly Connected   --->   Given an adjacency list, adj of Directed Graph, Find the number of
// strongly connected components in the graph.

// Example 1:
// Input: adj[][] = [[2, 3], [0], [1], [4], []]
// Output: 3
// Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

// Example 2:
// Input: adj[][] = [[1], [2], [0]]
// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.

// Example 3:
// Input: adj[][] = [[1], []]
// Output: 2

// Algorithm: This problem is an application of Kosaraju's algorithm for finding strongly connected components (SCCs)
//            in a directed graph.
//            The algorithm consists of two main steps:
//            1. Perform a depth-first search (DFS) on the original graph to determine the finishing order of vertices.
//            2. Create a transposed graph (reverse all edges) and perform DFS again in the order of the finishing
//               order obtained from the first DFS. Each DFS call in this step will identify a SSC.
//            The number of times we perform DFS in the second step gives us the number of SSCs.

// Problem link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs1(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs1(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>> &adjT, vector<bool> &vis) {
        vis[node] = true;
        for(auto it : adjT[node]) {
            if(!vis[it]) {
                dfs2(it, adjT, vis);
            }
        }
    }

public:
    // T.C: O(V + E);   where V = number of vertices and E = number of edges
    // S.C: O(V)
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        stack<int> st;

        // Step 1: Perform DFS on the original graph and fill the stack with finishing order
        for(int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }

        // Step 2.a: Create the transposed graph
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++) {
            vis[i] = false;   // resetting visited array for second DFS
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 2.b: Perform DFS on the transposed graph in the order of finishing times
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfs2(node, adjT, vis);
            }
        }

        return scc;
    }
};


int main() {
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    cout << Solution().kosaraju(adj);

    return 0;
}
