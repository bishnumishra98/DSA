// GFG: You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex
// and if it is unreachable to reach any vertex, then return -1 for that vertex.

// Example 1:
// Input:
// n = 9, m = 10
// edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4

// Example 2:
// Input:
// n = 4, m = 2
// edges=[[1,3],[3,0]] 
// src=3
// Output:
// 1 1 -1 0

// Algorithm: We will follow a BFS algorithm here. Note that weight of every edge is 1 in this problem. The algorithm is
//            somewhat similar to previous problem, but much easier than the previous problem.
// 1. a) Create an adjacency list for the undirected graph from the given edges.
//    b) Create a queue to store nodes in order to facilitate BFS.
//    c) Create a 'dist' array initialized all elements with infinity to keep a track of shortest distance from source.
// 2. Push the source node in the queue and mark its distance in the 'dist' array as 0 as the source node is obviously
//    0 distance away from it.
// 3. Dequeue the front element of the queue and traverse its neighbours. Increment distance value by 1 on reaching
//    the neighbour, and check if the distance to reach neighbour is shorter than the existing distance to reach
//    neighbour present in the 'dist' array. If it is, then update the 'dist' array with the shorter distance found.
//    Also, push that neighbour in the queue. Continue this process until the queue becomes empty.
//    Finally, the shortest distance of all nodes has been built inside the 'dist' array, so return it.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(V+2E) or O(N+2M)
    // S.C: O(V+2E) or O(N+2M)
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];   // creating an adjacency list to store a graph
        queue<int> q;   // creating a queue to facilitate BFS traversal
        vector<int> dist(N, 1e9);   // creating a 'dist' array initialized all elements with infinity to keep track of shortest distance

        // Build the adjacent node list from the given edges
        for(int i = 0; i < M; i++) {   // M is nothing but no.of edges in graph, i.e., edges.size()
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        q.push(src);   // pushing the source node in queue
        dist[src] = 0;   // mark dist[src] as 0

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // Traverse neighbours of the current node and update the 'dist' array and push them in the queue
            // if a shorter distance is found to reach the neighbour than the existing distance to reach neighbour.
            for(int neighbour: adj[node]) {
                if(dist[node] + 1 < dist[neighbour]) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        // If a node is unreachable, mark it as -1.
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};


int main() {
    int n = 9, m = 10;
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int src = 0;

    vector<int> ans = Solution().shortestPath(edges, n, m, src);
    for(int it: ans) cout << it << " ";

    return 0;
}
