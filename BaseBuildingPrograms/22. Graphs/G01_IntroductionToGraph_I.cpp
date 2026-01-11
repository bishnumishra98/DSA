// Graph theory: https://www.geeksforgeeks.org/introduction-to-graphs-data-structure-and-algorithm-tutorials/
// Implementation of graph: https://www.youtube.com/watch?v=3oI-34aPMWM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=2

// Graph can be created by any of the below two methods:
// 1) Adjacent matix: O(n^2) space
// 2) Adjacent list: O(n) space

// Input:
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
    int n = 5, m = 6;

    cout << "Enter the 6 pairs of edges of 5 vertices graph:\n";

    vector<vector<int>> adj_mat(n + 1, vector<int>(n + 1, 0));   // for adjacency matrix, create a matrix of size (n + 1)^2
    vector<int> adj_list[n + 1];   // for adjacency list, create 'n + 1' vectors

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // 1) Adjacency matrix for undirected graph
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;   // this statement will be removed in case of directed graph

        // 2) Adjacency list for undirected graph
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);   // this statement will be removed in case of directed graph
    }


    // Printing the adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the adjacency list
    cout << "Adjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : adj_list[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
