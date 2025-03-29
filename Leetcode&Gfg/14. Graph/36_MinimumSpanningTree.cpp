// Q) What is a Spanning Tree ?
// A) There can be multiple spanning trees for a graph. If a graph has V vertices, a Spanning Tree of a graph is a subgraph that:
//    • Includes all V vertices of the original graph.
//    • Contains exactly V − 1 edges.
//    • Does not contain any cycles (it’s a tree).
//    • Maintains the connectivity of the graph.

// Q) What is Minimum Spanning Tree ?
// A) A Minimum Spanning Tree (MST) is a spanning tree of a weighted graph that has the smallest possible sum of edge weights
//    among all spanning trees of the graph.
//    There can be more than one MST for a graph if multiple spanning trees have the same total edge weight.


// GFG: Minimum Spanning Tree   --->   Given a weighted, undirected, and connected graph with V vertices and E edges,
// your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.
// The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.
// Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer
// denoting the weight of the edge.

// Example 1:
// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
// Output: 4

// Example 2:
// Input:
// 2 1
// 0 1 5
// Output: 5

// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
    }
};

int main() {

}