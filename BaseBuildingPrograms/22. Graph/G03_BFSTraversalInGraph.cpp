// BFS Traversal of Tree means to traverse breadth wise, i.e., level order traversal.

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

// T.C:
// S.C: 
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);   // push the initial starting node 
    vector<int> bfs;

    // Iterate till the queue is empty 
    while(!q.empty()) {
        // Get the topmost element in the queue 
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // Traverse for all its neighbours 
        for(auto it : adj[node]) {
            if(!vis[it]) {   // if the neighbour has previously not been visited, store in Q and mark as visited 
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main() {
    int V = 5;   // no.of nodes
    vector<int> adj[] = {{1,2,3},{},{4},{},{}};

    vector<int> ans = bfsOfGraph(V, adj);
    for(auto i: ans) cout << i << " ";

    return 0;
}
