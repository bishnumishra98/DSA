// BFS Traversal of Tree means to traverse breadth wise, i.e., level order traversal.
// Consider first element of graph be 0, second be 1, and so on. Thus, if number of nodes(V)
// in the graph is 5, the graph elements will be 0, 1, 2, 3 and 4.

// Example 1:
// Input:
// V = 5, E = 4
// adj = {{1,2,3},{},{4},{},{}}
//     0
//    /|\
//   1 2 3
//     |
//     4
// Output: 
// 0 1 2 3 4
// Explanation: 
// 0 is connected to 1 , 2 , 3.
// 1 is connected to none.
// 2 is connected to 4.
// 3 is connected to none.
// 4 is connected to none.
// Thus bfs will be 0 1 2 3 4.

// Example 2:
// Input:
// V = 3, E = 2
// adj = {{1,2},{},{}}
//    0
//   / \
//  1   2
// Output: 
// 0 1 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Algorithm:
// 1. Make a 'vis' array of size as many nodes in the graph with initial values 0, to keep track of nodes visited from adj[] list.
// 2. Initialize another array named 'bfs' to store BFS traversal of nodes of the graph.
// 3. Push the starting node (here 0) into the queue and mark it as visited.
// 3. Dequeue the front node and push it into the 'bfs' array, and push all its neighbours(those who haven't been visited yet)
//    into the queue and mark them too visited.
// 4. Follow the 3rd step until the queue is empty. Return the 'bfs' array.

// T.C: O(n) due to queue, where n = no.of nodes in graph; + O(2*E) due to for loop which traverses all neighbours of each node,
//      where E = no.of edges in graph, 2*E = total degrees in a graph.
//      Overall T.C will be approx O(n+E).
// S.C: O(3n) due to 'vis', 'q' and 'bfs'.
//      Overall S.C will be approx O(n).
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);   // make a 'vis' array to keep track of nodes visited from adj[] list
    queue<int> q;
    q.push(0);   // push the initial starting node 
    vis[0] = 1;   // mark vis[0] as 1, which means 1st element in adj[] list i.e., adj[0] has been visited
    vector<int> bfs;

    // Iterate till the queue is empty
    while(!q.empty()) {
        // Dequeue the front node and push it into the 'bfs' array
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // Traverse all neighbours of front node and store them in queue if they have not been visited yet, and mark them visited.
        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) {
                q.push(neighbour);
                vis[neighbour] = 1;
            }
        }
    }

    return bfs;
}

int main() {
    int V = 5;   // no.of nodes
    //     0
    //    /|\
    //   1 2 3
    //     |
    //     4
    // Adjacent list:
    // 0 -> {1, 2, 3}
    // 1 -> {}
    // 2 -> {4}
    // 3 -> {}
    // 4 -> {}
    vector<int> adj[] = {{1,2,3},{},{4},{},{}};

    vector<int> ans = bfsOfGraph(V, adj);
    for(auto i: ans) cout << i << " ";

    return 0;
}
