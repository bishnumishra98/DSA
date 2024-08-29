// GFG: Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle
// or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
// Cycle can be anywhere; in a solo graph or in any of the components of graph. Thus, check all components of graph for cycle.

// Example 1:
// Input:  
// V = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
// Output: 1
// Explanation:
//   1 --- 2
//  / \     \
// 0   4 --- 3
// 1->2->3->4->1 is a cycle.

// Example 2:
// Input: 
// V = 4
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation:
//    0
// 1 --- 2
//      /
//     3
// No cycle in the graph.

// Algorithm using BFS:
// Intuition: Select a source node and start BFS traversal from it. In the BFS traversal, if
//            two separate branches meet at the same node, it means the graph has a loop.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto neighbour: adj[node]) {
                if(!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                } else if(parent != neighbour) return true;
            }
        }
        return false;
    }

    // T.C:
    // S.C: 
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // Checking cycles in all components of graph using for loop
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detectCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};

    cout << sol.isCycle(V, adj);

    return 0;
}
