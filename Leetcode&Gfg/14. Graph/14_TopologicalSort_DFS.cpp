// GFG: Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j
// such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find
// any valid topological sorting of the graph.
// In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

// Example 1:
// Input:
// 1 --> 0 <-- 3
//       /\
//       |
//       2
// Output:
// 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output
// would be 1 for all test cases. One possible Topological order for the graph is 3, 2, 1, 0.

// Example 2:
// Input:
// 5 --> 0 <-- 4
// |           |
// \/          \/
// 2 --> 3 <-- 1
// Output:
// 1
// Explanation:
// The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output
// would be 1 for all test cases. One possible Topological order for the graph is 5, 4, 2, 1, 3, 0.

// General knowledge: Topological sorting is only possible in a DAG (Directed Acyclic Graph), because in a DAG, since
//                    there are no cycles, we are guaranteed that there is always at least one vertex with no incoming
//                    edges (indegree of 0). This vertex can safely be placed at the beginning of the topological order.

// Algorithm: Its a very simple intuitive algorithm. We will be using a DFS algorithm here.
// 1. a) Initialize a visited vector(helper for DFS) with 0(unmarked) to keep a track of nodes visited in the graph.
//    b) Initialize an empty stack.
// 2. Start DFS traversal from a node and when you reach the end of a path, while returning back to the parent function,
//    store that node in stack. In this way, in the end, the node from where you started will be at the top of stack.
// 3. Pop out elements from stack and print it. It will represent the topological order of graph, as all nodes which
//    pointed to their neighbours are stacked up above their neighbours.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, int vis[], stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;   // mark the current node as visited

        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) dfs(neighbour, vis, st, adj);
        }

        // While returning from DFS call, store the node in the stack
        st.push(node);
    }

public:
	// T.C: O(V+E)
    // S.C: O(V+E)
	vector<int> topoSort(int V, vector<int> adj[]) {
	    int vis[V] = {0};
        stack<int> st;

        // Traverse all nodes of graph and do DFS traversal for all components of graph
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, vis, st, adj);
        }

        vector<int> ans;
        // The topological order is stored in the stack
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
	}
};

int main() {
// 1 --> 0 <-- 3
//       /\
//       |
//       2
    int V = 4;
    vector<int> adj[V] = {{}, {0}, {0}, {0}};
    // vector<int> adj[V] = {{1, 4}, {2}, {3}, {}, {2, 5}, {3}};

    Solution sol;
    vector<int> ans = sol.topoSort(V, adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
