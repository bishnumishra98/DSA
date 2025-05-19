// ● What is an articulation point in a graph ?
//   An articulation point (or cut vertex) in a graph is a vertex that, when removed along with its edges,
//   increases the number of connected components in the graph. In other words, removing an articulation point
//   disconnects the graph into separate components.

// GFG: Articulation Point-I   --->   Given an undirected connected graph with V vertices and adjacency list adj.
// You are required to find all the vertices removing which (and edges through it) disconnects the graph into
// 2 or more components and return it in sorted manner.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1:
// Input:
// 1 --- 0
// |
// 4 --- 3
//  \   /
//    2
// Output: {1, 4}
// Explanation: Removing the vertex 1 will discconect the graph as-
//   0
//     3
//   / |
//  4--2

// Removing the vertex 4 will disconnect the graph as-
//   0  3
//   |  |
//   1  2

// Your Task:
// You don't need to read or print anything. Your task is to complete the function articulationPoints() which
// takes V and adj as input parameters and returns a list containing all the vertices removing which turn the
// graph into two or more disconnected components in sorted order. If there are no such vertices then returns
// a list containing -1.

// Problem link: https://www.geeksforgeeks.org/problems/articulation-point-1/1

// Algorithm: The algorithm to find articulation points in a graph is similar to the one used for finding bridges.
// It uses a depth-first search (DFS) approach to traverse the graph and identify articulation points.
// The key idea is to maintain two arrays: disc[] and low[].
// The disc[] array stores the discovery time of each vertex.
// The low[] array stores the lowest discovery time reachable from each vertex except the parent vertex and
// visited vertices.

// The algorithm works as follows:
// 1. Initialize the disc[] and low[] arrays to -1 for all vertices.
// 2. Perform a DFS traversal of the graph.
// 3. For each vertex, update its discovery time and low value.
// 4. For each adjacent vertex, check:
//    ▸ If it is not visited, recursively call the DFS function for that vertex.
//      ▪ After returning from the recursive call, update the low value of the current vertex. The value of
//        low is the minimum of the current low value and the low value of the adjacent vertex.
//      ▪ If the low value of the adjacent vertex is greater than or equal to the discovery time of the current
//        vertex and the parent is not -1, then the current vertex is an articulation point.
//    ▸ If the adjacent vertex is already visited, update the low value of the current vertex to the minimum
//      of low value of the current vertex and the low value of the adjacent vertex.
// 5. After the DFS traversal, all the articulation points will be identified.
// 6. Return the list of articulation points.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 0;   // timer to keep track of discovery time

    void dfs(int node, int parent, vector<int> &disc, vector<int> &low, vector<int> adj[], vector<bool> &articulationPoints) {
        disc[node] = low[node] = timer;
        timer++;
        int children = 0;   // to count the number of children of the current node

        for(auto it: adj[node]) {
            if(it == parent) continue;   // skip the parent node
            if(disc[it] == -1) {   // if the adjacent node is not visited
                children++;   // increment the number of children for the current node
                dfs(it, node, disc, low, adj, articulationPoints);
                low[node] = min(low[node], low[it]);

                // If the lowest reachable vertex from the adjacent node is greater than or equal to the
                // discovery time of the current node, then the current node is an articulation point.
                if(low[it] >= disc[node] && parent != -1) {
                    articulationPoints[node] = true;
                }
            } else {   // if the adjacent node is already visited
                low[node] = min(low[node], disc[it]);
            }
        }

        // If the current node is root and has more than one child, then it is an articulation point.
        // This is because if we remove the root node, all its children will be disconnected from each other.
        if(children > 1 && parent == -1) {
            articulationPoints[node] = true;
        }
    }

public:
    // T.C: O(V + 2E);   where V is the number of vertices and E is the number of edges
    // S.C: O(V)
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> articulationPoints(V, false);
        
        for(int i = 0; i < V; i++) {
            if(disc[i] == -1) {
                dfs(i, -1, disc, low, adj, articulationPoints);   // dfs(node, parent, disc, low, adj, articulationPoints)
            }
        }

        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(articulationPoints[i]) {
                ans.push_back(i);
            }
        }
        if(ans.empty()) return {-1};   // if no articulation points found, return -1
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {4};
    adj[2] = {3, 4};
    adj[3] = {2, 4};
    adj[4] = {2, 3};

    Solution obj;
    vector<int> ans = obj.articulationPoints(V, adj);
    for(auto it: ans) cout << it << " ";

    return 0;
}
