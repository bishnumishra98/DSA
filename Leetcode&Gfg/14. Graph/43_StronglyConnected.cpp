// GFG: Strongly Connected   --->   Given an adjacency list, adj of Directed Graph, Find the number of
// strongly connected components in the graph.

// Example 1:
// Input: adj[][] = [[2, 3], [0], [1], [4], []]
// Output: 3
// Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

// Example 2:
// Input: adj[][] = [[1], [2], [0]]
// Output: 1
// Explanation: All of the nodes are connected to each other. So, there's only one SCC.

// Example 3:
// Input: adj[][] = [[1], []]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kosaraju(vector<vector<int>> &adj) {
                
    }
};


int main() {
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    cout << Solution().kosaraju(adj);

    return 0;
}
