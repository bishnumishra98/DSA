// DFS Traversal of Graph means to traverse depth wise, i.e., depth order traversal.
// Consider first element of graph be 0, second be 1, and so on. Thus, if number of nodes(n)
// in the graph is 5, the graph elements will be 0, 1, 2, 3 and 4.

// Example 1:
// Input: n = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
//      0
//     /|\
//    2 3 1
//    |
//    4
// Output: 0 2 4 3 1
// Explanation: 
// 0 is connected to 2, 3, 1.
// 1 is connected to 0.
// 2 is connected to 0 and 4.
// 3 is connected to 0.
// 4 is connected to 2.
// So starting from 0, it will go to 2 then 4, and then 3 and 1.
// Thus dfs will be 0 2 4 3 1.

// Example 2:
// Input: n = 4, adj = [[1,3], [2,0], [1], [0]]
//      0
//     / \
//    1   3
//     \
//      2
// Output: 0 1 2 3
// Explanation:
// 0 is connected to 1 , 3.
// 1 is connected to 0, 2. 
// 2 is connected to 1.
// 3 is connected to 0. 
// So starting from 0, it will go to 1 then 2 then back to 0 then 0 to 3.
// Thus dfs will be 0 1 2 3.

// Algorithm:
// 1. Make a 'vis' array of size as many nodes in the graph with initial values 0, to keep track of nodes visited from adj[] list.
// 2. Initialize another array named 'dfs' to store DFS traversal of nodes of the graph.
// 3. Call a recursive function with root node initially, to populate 'dfs' array. The function algorithm is:
//    i.  Mark the current node as visited in the 'vis' array, so that it is not tarversed again in future; and push the
//        current node in the 'dfs' array.
//    ii. With the help of adj[] list, traverse the neighbours of current node if they haven't been visited yet.
// 4. At the end of recursion, 'dfs' array will be populated with DFS traversal of graph. Thus, return it.

#include <iostream>
#include <vector>
using namespace std;

void dfsTraversal(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfs) {
    vis[node] = 1;   // mark the current node as visited
    dfs.push_back(node);   // push the current node in 'dfs'
    // Traverse all neighbours of current node if they haven't been visited yet
    for(int neighbour: adj[node]) {
        if(!vis[neighbour]) dfsTraversal(neighbour, adj, vis, dfs);
    }
}

// T.C: O(n) due initialization of the vis + O(2*E) due to for loop which traverses all neighbours of each node,
//      where E = no.of edges in graph, 2*E = total degrees of graph, i.e., sum of neighbours of all nodes
//      Overall, T.C: O(n+E)
// S.C: O(n) for 'dfs' + O(n) for 'vis' + O(n) for recursive stack space.
//      Overall, S.C: O(n)
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);   // make a 'vis' array to keep track of nodes visited from adj[] list
    vector<int> dfs;   // this data structure will store the dfs traversal of this graph
    dfsTraversal(0, adj, vis, dfs);   // '0' is the root node passed to the dfsTraversal() function
    return dfs;
}

int main() {
    int n = 5;   // no.of nodes
    vector<int> adj[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
//      0
//     /|\
//    2 3 1
//    |
//    4

    vector<int> ans = dfsOfGraph(n, adj);
    for(auto i: ans) cout << i << " ";

    return 0;
}
