// GFG: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// Example 1:
// Input:
// 0 --> 1 --> 2 --> 3
//             |     /\
//            \/     |
//             5 --> 4
// Output:
// 1

// Example 2:
// Input:
// 0 --> 1 --> 2 --> 3
//             |     |
//            \/    \/
//             5 --> 4
// Output:
// 0

// Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

// Algorithm:
// 1. Create 


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
    // T.C: O(V + E);   where V: vertices, E: edges
    // S.C: O(2V) = O(V);   for vis and pathVis arrays
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
    //             |     |
    //            \/    \/
    //             5 --> 4

    // Adjacency list
    // 0 -> {1}
    // 1 -> {2}
    // 2 -> {3, 5}
    // 3 -> {4}
    // 4 -> {}
    // 5 -> {4}
    int V = 6;
    vector<int> adj[V] = {{1}, {2}, {3, 5}, {4}, {}, {4}};

    Solution sol;
    cout << sol.isCyclic(V, adj);

    return 0;
}
