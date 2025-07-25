// Problem link: https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

// GFG: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph
// is labelled with a distinct integer in the range 0 to V - 1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from
// that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:
// Input:
//  _____________
// |             |
// |  --> 0 ---> 1
// | |    |      |
// | |    \/     \/   6
//  -|--> 2 <--- 3
//   |____|______|
//        |
//        \/
//        5 <-- 4
// Output:
// 2 4 5 6
// Explanation:
// The given graph is shown above. Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them. 
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// Example 2:
// Input:
//  0 --> 1
// /\     |
//  |     |
//  2 <---
//  |
// \/
//  3
// Output:
// 3
// Explanation:
// Only node 3 is a terminal node, and every path starting at node 3 leads to node 3.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an
// integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

// Algorithm: The algo is pretty simple. If there is a cycle present in the graph, all nodes in that cycle and all nodes
//            pointing to any of the nodes of that cycle will not be a part of safe nodes. Except such nodes, all others
//            will be safe nodes. Try out yourself with a pen paper if you don't believe.
//            Thus, we will just do some minor modification to '13_DirectedGraphCycle.cpp' code.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkForCycle_dfs(int node, vector<int> adj[], int vis[], int pathVis[], int checkSafeNodes[]) {
        vis[node] = 1;   // mark the current node as visited
        pathVis[node] = 1;   // mark the current node as path visited

        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) {
                if(checkForCycle_dfs(neighbour, adj, vis, pathVis, checkSafeNodes) == true) return true;
            } else {
                if(pathVis[neighbour]) return true;
            }
        }

        // If program comes here, it means no cycle was found the current node. Thus, mark it safe.
        checkSafeNodes[node] = 1;
        pathVis[node] = 0;   // backtrack and unmark pathVis for this node
        return false;
    }

public:
    // T.C: O(V+E)
    // S.C: O(V+E)
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        vector<int> safeNodes;   // all safe nodes will be stored in this data-structure
        int checkSafeNodes[V] = {0};   // helps to keep a track to nodes that are safe. Initially all nodes are unsafe.

        // Check cycle for all components of graph
        for(int i = 0; i < V; i++) {
            // If node 'i' is unvisited yet, start DFS from there for this particular component
            if(!vis[i]) {
                checkForCycle_dfs(i, adj, vis, pathVis, checkSafeNodes);
            }
        }

        // Traverse all nodes populate 'safeNodes' array with safe nodes
        for(int i = 0; i < V; i++) {
            if(checkSafeNodes[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

int main() {
//  _____________
// |             |
// |  --> 0 ---> 1
// | |    |      |
// | |    \/     \/   6
//  -|--> 2 <--- 3
//   |____|______|
//        |
//        \/
//        5 <-- 4
    int V = 7;
    vector<int> adj[V] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> ans = Solution().eventualSafeNodes(V, adj);
    for(auto it: ans) cout << it << " ";

    return 0;
}
