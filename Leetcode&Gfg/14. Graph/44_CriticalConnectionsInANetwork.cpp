// ● What are bridges in a graph ?
//   A bridge in a graph is an edge that, when removed, increases the number of connected components in the graph.
//   In other words, a bridge is an edge that, if removed, would disconnect the graph into separate parts.

// ● How to find bridges in a graph ?
//   To find bridges in a graph, the most commonly used algorithm is Tarjan's Bridge-Finding Algorithm.
//   This algorithm is efficient, running in O(V + E) time using Depth-First Search (DFS), where
//   V is the number of vertices and E is the number of edges in the graph.

// ● What is Tarjan's Bridge-Finding Algorithm ?
//   Tarjan's Bridge-Finding Algorithm is a depth-first search (DFS) based algorithm that finds all the bridges
//   in a graph. It uses the concept of discovery and low values to identify bridges.
//   The discovery time of a vertex is the time when it is first visited during the DFS traversal.
//   The low value of a vertex is the lowest discovery time reachable from that vertex.
//   The algorithm maintains two arrays: disc[] and low[].
//   The disc[] array stores the discovery time of each vertex.
//   The low[] array stores the lowest discovery time reachable from each vertex.

// ● How Tarjan's Bridge-Finding Algorithm works ?
//   The algorithm works as follows:
//   1. Initialize the disc[] and low[] arrays to -1 for all vertices.
//   2. Perform a DFS traversal of the graph.
//   3. For each vertex, update its discovery time and low value.
//   4. For each adjacent vertex, check if it is visited.
//      ▸ If it is not visited, recursively call the DFS function for that vertex.
//        ▪ After returning from the recursive call, update the low value of the current vertex.
//        ▪ If the low value of the adjacent vertex is greater than the discovery time of the current vertex,
//          then the edge between the current vertex and the adjacent vertex is a bridge.
//      ▸ If the adjacent vertex is already visited and is not the parent of the current vertex,
//        update the low value of the current vertex to the minimum of its low value and the discovery time
//        of the adjacent vertex.
//   5. After the DFS traversal, all the bridges will be identified.
//   The algorithm is efficient and can be implemented using a single DFS traversal of the graph.


// Leetcode: 1192. Critical Connections in a Network   --->   There are n servers numbered from 0 to n - 1
// connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi]
// represents a connection between servers ai and bi. Any server can reach other servers directly or
// indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

// Example 1:
// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Example 2:
// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
    }
};


int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> ans;
    Solution obj;
    ans = obj.criticalConnections(n, connections);
    for(auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "]\n";
    }

    return 0;
}
