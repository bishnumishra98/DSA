// GFG: Shortest Path in Weighted undirected graph   --->   You are given a weighted undirected graph having
// n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between
// the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element
// is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return
// a list containing a single element -1.
// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the
// weight of that edge.
// Note: The driver code here will first check if the weight of the path returned is equal to the sum of the
// weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the
// list contains only a single element (-1) it will simply output -1.
// Problem link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

// Example 1:
// Input:
// n = 5, m = 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output:
// 1 4 3 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5.

// Example 2:
// Input:
// n = 2, m = 1, edges = [[1, 2, 2]]
// Output: 1 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2.

// Example 3:
// Input: n = 2, m = 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.

// Algorithm:
// 1.  Create an adjacency list 'adj' of size n+1.
// 2.  Traverse through the edges and add the edges in the adjacency list.
// 3.  a) Create a priority queue 'pq' to store the pair of integers. The first integer will store the distance of the
//        node from the source vertex and the second integer will store the node number.
//     b) Create a vector 'dist' of size n+1 and initialize all the elements with INT_MAX.
//     c) Create a vector 'parent' of size n+1 and initialize all the elements with -1.
// 4.  Push the pair {0, 1} in the priority queue. This means that the distance of the source vertex from itself is 0.
// 5.  Initialize the distance of the source vertex from itself as 0 in the 'dist' vector and the parent of the source
//     vertex as itself.
// 6.  Run a while loop until the priority queue is not empty. Dequeue the front element of the priority queue and store
//     the distance in 'dis' and the node number in 'node'.
// 7.  Traverse through all the adjacent nodes of the current node and update the distance of the adjacent node if the new
//     distance is less than the previous distance.
// 8.  Push the pair {dist[adjNode], adjNode} in the priority queue. Repeat the above steps 6-8 until the priority queue
//     is empty. If the distance of the destination node is INT_MAX, return {-1}.
// 9.  Create a vector 'path' and initialize 'node' as n.
// 10. Traverse through the parent array and add the nodes in the 'path' vector until the parent of the node is itself.
// 11. Reverse the 'path' vector and return the 'path' vector.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(E * log(V));   where E = no.of edges, V = no.of vertices
    // S.C: O(V)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);   // node -> {adjNode, edgeWeight}
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);

        pq.push({0, 1});
        dist[1] = 0;
        parent[1] = 1;

        while(!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if(dist[n] == INT_MAX) return {-1};

        vector<int> path;
        int node = n;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};


int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> ans = Solution().shortestPath(n, m, edges);
    int sum = 0;
    for(int i: ans) {
        cout << i << " ";
        sum += i;
    }

    return 0;
}
