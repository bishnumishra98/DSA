// Leetcode: 547. Number of Provinces   --->   There are n cities. Some of them are connected, while some are not.
// A province is a group of connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are connected,
// and isConnected[i][j] = 0 otherwise. Return the total number of provinces.

// Example 1:
// 1 --- 2
//    3
// Input: isConnected = [[1,1,0],
//                       [1,1,0],
//                       [0,0,1]]
// Output: 2

// Example 2:
// 1     2
//    3
// Input: isConnected = [[1,0,0],
//                       [0,1,0],
//                       [0,0,1]]
// Output: 3

// Algorithm: It is very easy and simple problem.
// 1. As adjacent matrix is given as input, first convert it to adjacent list.
// 2. Make a 'vis' array of size as many nodes in the graph with initial values 0, to keep track of nodes visited from adj[] list.
// 3. Perform any traversal DFS or BFS on each node of graph if it is not visited yet, using a loop. All nodes belonging to one
//    component will be marked as visited in the DFS or BFS traversal in one iteration. Thus, the next time an already visited node
//    comes in the loop, it will not be allowed to perform any DFS or BFS traversal. DFS or BFS traversal shall only be only
//    allowed to perform for a node which is not yet visited which means this node is not a part of the last DFS traversal. Hence,
//    it means this node belongs to another component or province. So, keep a track of no.of times the DFS or BFS traversal is
//    made throughout the entire loop, and that is the number of components or provinces in the given graph.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS traversal of graph. Well, we do not require to print or store the dfs traversal in this problem.
    void dfsTraversal(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) dfsTraversal(neighbour, adj, vis);
        }
    }

    // T.C: O(n^2) for converting into adjacent list + O(n + E) for DFS traversal = O(n^2)
    // S.C: O(n) for 'adj' + O(n) for 'vis' + O(n) for recursion stack = O(n)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        // Convert adjacent matrix to adjacent list
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {   // 'i != j' to ensure there is no self nodes
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);   // make a 'vis' array to keep track of nodes visited from adj[] list
        int provinces = 0;   // to keep a count of provinces by checking the no.of times the if(!vis[i]) condition is executed

        // Traverse all nodes of graph
        for(int i=0; i<n; i++) {
            if(!vis[i]) {   // if() will be true, only if the node 'i' is not visited yet
                provinces++;
                dfsTraversal(i, adj, vis);
            }
        }

        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    Solution sol;
    cout << sol.findCircleNum(isConnected);

    return 0;
}
