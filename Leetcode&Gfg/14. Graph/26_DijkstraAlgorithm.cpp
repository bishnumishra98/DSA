// GFG: Dijkstra Algorithm   --->   Given a weighted, undirected and connected graph where you have given adjacency list adj.
// You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers
// denoting the shortest distance between each node and source vertex src.
// Note: The Graph doesn't contain any negative weight edge.

// Example 1:
// Input:
// adj = [[[1, 9]], [[0, 9]]], src = 0
// Output:
// [0, 9]
// Explanation:
//    9 (edge weight)
// 0 ------------------ 1
// The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.

// // Example 2:
// Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
// Output: [4, 3, 0]
// Explanation:
//       0
//      / \
//   1 /   \ 6
//    /     \
//   1 ----- 2
//       3
// For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6.
// So, the Shortest path from 2 to 0 is 4.
// The shortest distance from 0 to 1 is 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(adj.size(), INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;

                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int src = 2;

    vector<int> ans = Solution().dijkstra(adj, src);
    for(auto it: ans) {
        cout << it << " ";
    }

    return 0;
}
