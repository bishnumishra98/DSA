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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        
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
    if (ans.size() == 1 && ans[0] == -1) {
        cout << "No articulation points found." << endl;
    } else {
        cout << "Articulation points: ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
