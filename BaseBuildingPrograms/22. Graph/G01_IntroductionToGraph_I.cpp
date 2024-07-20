// Graph theory: https://www.geeksforgeeks.org/introduction-to-graphs-data-structure-and-algorithm-tutorials/
// Implementation of graph: https://www.youtube.com/watch?v=3oI-34aPMWM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=2

// Input:
// 5 6
// 1 2
// 1 3
// 2 4
// 3 4 
// 3 5 
// 4 5
// Graph:
// Number of nodes, n = 5
// Number of edges, m = 6
// 1 --- 3
// |     |\
// |     | 5
// |     |/
// 2 --- 4


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   // n is no.of nodes, while m is no.of edges

    cout << "Enter m pairs of edges:\n";

    int adj_mat[n+1][n+1];   // for adjacency matrix
    vector<int> adj_list[n+1];   // for adjacency list

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // 1) Adjacency matrix for undirected graph
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;   // this statement will be removed in case of directed graph

        // 2) Adjacency list for undirected graph
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    return 0;
}
