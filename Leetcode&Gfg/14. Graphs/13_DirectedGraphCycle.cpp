// GFG: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// Example 1:
// Input:
// 0 --> 1 --> 2 --> 3
//             |     /\
//            \/     |
//             5 --> 4
// Output:
// 0

// Example 2:
// Input:
// 0 --> 1 --> 2 --> 3
//             /\    |
//             |    \/
//             5 <-- 4
// Output:
// 1

// Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

// Algorithm:
// 1. Create two arrays of size as many nodes in the graph. The first array 'vis' keeps the track of nodes visited. And the array
//    'pathVis' keeps a track of the current path we are following.
// 2. Start DFS traversal from a node and mark it visited in both 'vis' and 'pathVis' arrays.
// 3. DFS traverse all its neighbours which are unvisited yet. If no cycle found at the end of a path, backtrack and unmark
//    'pathVis' for that node and return false stating that no cycle found in the path from this node.
// 4. In the other case, if a neighbour comes out to be visited, check its equivalent 'pathVis' array. If 'pathVis' is unvisited
//    for this node, it means we are about to visit the neighbour node for the second time via a different path.
//    But if 'pathVis' is marked visited in this case, it means we are about to visit the neighbour once again via the same path,
//    which signifies that a cycle is present in this path. Thus, return true in this case.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkForCycle_dfs(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;   // mark the current node as visited
        pathVis[node] = 1;   // mark the current node as path visited

        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) {
                if(checkForCycle_dfs(neighbour, adj, vis, pathVis) == true) return true;
            } else {
                if(pathVis[neighbour]) return true;
            }
        }

        pathVis[node] = 0;   // backtrack and unmark pathVis for this node
        return false;
    }

public:
    // T.C: O(V+E);   where V: vertices, E: edges
    // S.C: O(V+E)
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};

        // Check cycle for all components of graph
        for(int i = 0; i < V; i++) {
            // If node 'i' is unvisited yet, start DFS from there for this particular component
            if(!vis[i]) {
                if(checkForCycle_dfs(i, adj, vis, pathVis) == true) return true;   // if cycle found, return true
            }
        }

        return false;   // if no cycle found for whole graph, return false
    }
};


int main() {
// 0 --> 1 --> 2 --> 3
//             /\    |
//             |    \/
//             5 <-- 4

    // Adjacency list
    // 0 -> {1}
    // 1 -> {2}
    // 2 -> {3}
    // 3 -> {4}
    // 4 -> {5}
    // 5 -> {2}
    int V = 6;
    vector<int> adj[V] = {{1}, {2}, {3}, {4}, {5}, {2}};

    Solution sol;
    cout << sol.isCyclic(V, adj);

    return 0;
}
