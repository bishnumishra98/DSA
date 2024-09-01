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

// Intuition: Select a source node and start DFS traversal from it. In the DFS traversal,
//            if you reach the same node that has already been visited, the graph has a loop.

// Example:
//   0 --- 1 --- 2
//    \         /
//     4 ----- 3
//    /
//   5

// Adjacent list:
// 0 -> {1, 4}
// 1 -> {0, 2}
// 2 -> {1, 3}
// 3 -> {2, 4}
// 4 -> {5, 3, 0}
// 5 -> {4} 

// Illustration:
// 1. DFS(0, -1): Starting from 0, we mark vis[0] and call DFS for 1. Pass its parent 0 along with it.
// 2. DFS(1, 0): Mark vis[1] and call DFS for 2 along with its parent 1.
// 3. DFS(2, 1): Mark vis[2] and call DFS for 3 along with its parent 2.
// 4. DFS(3, 2): Mark vis[3] and call DFS for 4 along with its parent 3.
// 5. DFS(4, 3): Mark vis[4] and call DFS for 5 along with its parent 4.
// 6. DFS(5, 4): Mark vis[5] and its neighbour is 4, but 4 is already visited and also its parent, i.e., 5 came from 4.
//               Thus, no more neighbours are there for 5, thus no more DFS calls. Thus, return false signifying no cycle found.
// 7. Program gets back to DFS(4, 3). 3 is also marked visited and also its parent, i.e., 4 came from 3. Thus, traverse to its
//    next neighbour 0. 0 is also marked visited, but 0 is not 4's parent. This means 0 was already visited and we came back to 0.
//    This means a cycle is present in graph. Thus, DFS(0, 4) is never called and DFS(4, 3) returns true signifying a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // The DFS function that will be called recursively. It returns true if a cycle is found.
    bool detectCycle(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        for(auto neighbour: adj[node]) {
            if(!vis[neighbour]) {
                if(detectCycle(neighbour, node, adj, vis)) return true;
            }
            else if(neighbour != parent) return true;
        }
        return false;
    }

    // T.C: O(V + 2E);   where V = no.of nodes in graph and E = no.of edges in graph, 2*E = total degrees of graph
    // S.C: O(V)
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // Checking cycles in all components of graph using for loop
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detectCycle(i, -1, adj, vis)) return true;   // initially start with node as 0 and its parent -1.
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
