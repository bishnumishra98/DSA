// • The Floyd-Warshall Algorithm is a graph algorithm used to find the shortest paths between all pairs of vertices in
//   a weighted graph. Unlike Dijkstra's or Bellman-Ford algorithm which are single source shortest path algorithms, it
//   is used to find shortest paths between all pairs of vertices, that's why it is also known as multisource shortest
//   path algorithm.

// • It cannot be used directly on undirected graphs. To use it, we have to convert undirected graph to directed graph.
//   For example, if there is an edge between u and v in an undirected graph, it can be represented as a directed graph
//   like an edge directed from u and v and viceversa, i.e., u -> v, v -> u.

// • The algorithm requires an adjacency matrix as input and modifies it in place to compute the shortest path matrix.
//   The algorithm works by iteratively considering each vertex as an intermediate point and updating the shortest path
//   between every pair of vertices based on whether the path through the intermediate vertex offers a shorter route.
//   It uses a dynamic programming approach and is represented by a 2D matrix, where the element at dist[i][j] holds the
//   shortest distance from vertex i to vertex j.

// • Floyd-Warshall can handle graphs with negative weight edges.

// • It can also be used to detect negative weight cycles in a graph. If the final distance matrix contains any element
//   where the distance from a vertex to itself is negative, i.e., dist[i][i] < 0, it indicates the presence of a negative
//   weight cycle in the graph.

// • It is often used in applications such as network routing, finding the transitive closure of a graph, and detecting
//   cycles in a graph.


// GFG: Floyd Warshall   --->   The problem is to find the shortest distances between every pair of vertices in a
// given edge-weighted directed graph. The graph is represented as an adjacency matrix. mat[i][j] denotes the weight
// of the edge from i to j. If mat[i][j] = -1, it means there is no edge from i to j.
// Note: Modify the distances for every pair in place.

// Example 1:
// Input: mat = [[0, 25], [-1, 0]]
// Output: [[0, 25], [-1, 0]]
// Explanation: The shortest distance between every pair is already given(if it exists).

// Example 2:
// Input: mat = [[0, 1, 43],[1, 0, 6], [-1, -1, 0]]
// Output: [[0, 1, 7], [1, 0, 6], [-1, -1, 0]]
// Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.

// Problem link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
    }
};

int main() {
    vector<vector<int>> mat = {{0, 1, 43},{1, 0, 6}, {-1, -1, 0}};

    Solution().shortestDistance(mat);

    return 0;
}
