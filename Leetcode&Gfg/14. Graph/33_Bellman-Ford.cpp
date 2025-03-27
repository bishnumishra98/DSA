// • The Bellman-Ford algorithm is a graph algorithm used to find the shortest paths from a single source vertex
//   to all other vertices in a directed weighted graph. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs
//   with negative weight edges, making it suitable for more general cases. It cannot be used directly on undirected
//   graphs. To use it, we have to convert undirected graph to directed graph. For example, if there is an edge between
//   u and v in an undirected graph, it can be represented as a directed graph like u -> v, v -> u.

// • According to this algorithm, for a graph containing n vertices, n−1 iterations of edge relaxation are sufficient to
//   ensure that the shortest paths from the source vertex to all other vertices are computed correctly.

// • It can also be used to detect negative weight cycles in a graph. Even after n - 1 iterations, if the edges of the
//   graph are getting relaxed, it means a negative weight cycle is present in the graph.

// • It is used in network routing protocols like RIP (Routing Information Protocol).


// GFG: Bellman-Ford   --->   Given a weighted and directed graph of v vertices and edges, Find the shortest distance
// of all the vertex's from the source vertex, src and return a list of integers where the ith integer denotes the
// distance of the ith node from the source node. If a vertices can't be reach from the s then mark the distance as 10^8.
// Note: If there exist a path to a negative weighted cycle from the source node then return {-1}.

// Example 1:
// Input: edges = {[0,1,9]], src = 0
// Output: [0, 9]
// Explanation: Shortest distance of all nodes from source is printed.

// Example 2:
// Input: edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2
// Output: [1, 6, 0]
// Explanation: For nodes 2 to 0, we can follow the path: 2-0. This has a distance of 1. For nodes 2 to 1, we can
// follow the path: 2-0-1, which has a distance of 1+5 = 6.

// Problem link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Algorithm: Extremely simple.
// 1. Create a 'dist' array of size as many vertices(V) in the graph, and initialize all elements with infinity.
// 2. Mark dist[src] as 0.
// 3. Relax all the edges 'V - 1' times using a loop.
// 4. Check for negative cycles by once more relaxing the edges. If relaxation happens, it means the graph had
//    negative weight cycles.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(V * E);   where V = no.of vertices, E = no.of edges
    // S.C: O(V)
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);   // given in the problem to consider unreachable vertices as 10^8
        dist[src] = 0;

        // Relax all edges 'V - 1' times
        for(int i = 0; i < V - 1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
            }
        }

        // Vth relaxation to check negative cycles
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
        }

        return dist;
    }
};

int main() {
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};
    int src = 2;
    int V = 3;   // number of vertices

    vector<int> ans = Solution().bellmanFord(V, edges, src);
    for(auto it: ans) cout << it << " ";

    return 0;
}
