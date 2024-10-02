// Algorithm: We can use any approach BFS or DFS. This algorithm illustrates BFS technique.
// 1. a) Create a color array of size as many nodes in the graph, initialized all elements with -1 representing the node is uncolored.
//       We will be using the color conventions 0 and 1 to mark colors in the nodes.
//    b) Create a blank queue.
// 2. Starting with a node, mark it with a color(say 0) and push it inside the queue.
// 3. Dequeue the front element of queue and push its neighbours in the queue if they are yet uncolored. Make sure to color
//    the neighbour with opposite color as that of the current node.
//    Else, if the neighbour of the current element is found to be colored, it means this node was traversed previously via some
//    other path, stating a cycle is present in this graph. Thus, check if the neighbour node's color is same as that of the
//    current node, simply return false stating that this graph is non-bipartite.
// 4. Repeat step 3 until the queue is empty. If the queue becomes empty, it means no two adjacent nodes had the same color.
//    Thus, return true stating that this graph is bipartite.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkBipartite_dfs(int node, int col, vector<int> adj[], int color[]) {
        color[node] = col;   // paint the current node with color 'col'

        // Traverse all neighbours of the current element one by one and if its
        // Case 1: Not colored -> invert color of the neighbour with respect to current node and push it inside the queue
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
