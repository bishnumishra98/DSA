// Algorithm: We can use any approach BFS or DFS. This algorithm illustrates DFS technique.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkBipartite_dfs(int node, int col, vector<int> adj[], int color[]) {
        color[node] = col;   // paint the current node with color 'col'

        // Traverse all neighbours of the current element one by one and if its
        // Case 1: Not colored -> invert color of the neighbour with respect to current node and call the dfs function again
        // Case 2: Colored -> if the color of neighbour is same as current node, return false stating non-bipartite graph
        for(int neighbour: adj[node]) {
            if(color[neighbour] == -1) {
                if(checkBipartite_dfs(neighbour, !col, adj, color) == false) return false;
            } else {
                if(color[neighbour] == col) return false;   // if neighbour and current node have same color, return false
            }
        }

        return true;   // return true stating that the graph component is bipartite
    }

public:
    // T.C: O(n)   same as DFS traversal
    // S.C: O(n)   same as DFS traversal
	bool isBipartite(int V, vector<int> adj[]){
	    int color[V];   // creating an array to track the colors of all nodes
        for(int i = 0; i < V; i++) color[i] = -1;   // setting initial color for all nodes as -1

        // Check bipartite nature for all components of graph
        for(int i = 0; i < V; i++) {
            // If the current node is uncolored, start DFS traversal for this component. Start with initial node's color as 0.
            if(color[i] == -1) {
                if(checkBipartite_dfs(i, 0, adj, color) == false) return false;
            }
        }

        // If program comes here, it means the whole graph is bipartite, thus return true.
        return true;
	}
};

int main() {
    // Graph:
    // 0 -- 1
    // |    |
    // 3 -- 2
    // |
    // 4
    int V = 5;  // number of vertices
    vector<int> adj[V] = {{1, 3}, {0, 2}, {1, 3}, {0, 4}, {3}};

    Solution sol;
    cout << sol.isBipartite(V, adj);

    return 0;
}
