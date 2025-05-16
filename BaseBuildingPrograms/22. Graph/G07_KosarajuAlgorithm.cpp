// Strongly Connected Components (SSC) are are possible only in directed graphs. SSC is the portion of a
// directed graph where every vertex is reachable from every other vertex.
// The algorithm used to find SSCs in a graph is Kosaraju's algorithm, which is a two-pass algorithm.
// The first pass is a depth-first search (DFS) on the original graph to determine the finishing order of vertices.
// The second pass is a DFS on the transposed graph (the graph with all edges reversed) to discover the strongly
// connected components.
// The algorithm has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges.

// Example: {{2, 3}, {0}, {1}, {4}, {}}
//          0 __________
//       /\    |        |
//       |     |        |
//       |     \/       \/
//        /___ 2         3
//       1\              |
//                       |
//                       \/
//                       4

// In the above graph, there are three strongly connected components:
// 1. {0, 1, 2}
// 2. {3}
// 3. {4}


// Problem: Given an adjacency list, adj of Directed Graph, return a list of SSCs in the graph.

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

// Algorithm: 
// 1. Perform a depth-first search (DFS) on the original graph to determine the finishing order of vertices.
// 2. Create a transposed graph (reverse all edges) and perform DFS again in the order of the finishing
//    order obtained from the first DFS. Each DFS call in this step will identify a SSC.

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

    void dfs2(int node, vector<vector<int>> &adjT, vector<bool> &vis, vector<int> &component) {
        component.push_back(node);
        vis[node] = true;
        for(auto it : adjT[node]) {
            if(!vis[it]) {
                dfs2(it, adjT, vis, component);
            }
        }
    }

public:
    vector<vector<int>> kosaraju(vector<vector<int>> &adj) {
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
        vector<vector<int>> scc;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                vector<int> component;
                dfs2(node, adjT, vis, component);
                scc.push_back(component);
            }
        }

        return scc;
    }
};


int main() {
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    vector<vector<int>> ans;
    Solution obj;
    ans = obj.kosaraju(adj);
    for(auto it: ans) {
        for(auto i: it) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
