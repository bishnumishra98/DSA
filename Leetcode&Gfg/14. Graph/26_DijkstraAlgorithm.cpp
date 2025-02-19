// Dijkstra Algorithm is a famous algorithm to find the shortest path from a source vertex to all other vertices in a graph.
// It is a greedy algorithm and works for both directed and undirected graphs. It is used to find the shortest path from
// a source vertex to all other vertices in a graph. It is based on the principle of relaxation, where the shortest path
// for all vertices is updated if a shorter path is found. It is used in various applications like GPS, network routing,
// and traffic control systems. This algorithm can be implemented using various data structures like arrays, queues,
// priority queues, and sets. But most efficient implementation is using priority queue and set.
// Note that Dijkstra Algorithm works only for graphs with non-negative edge weights. If the graph contains negative edge
// weights, then Bellman-Ford Algorithm is used.


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

// Algorithm (priority queue):
// 1. a) Create a priority queue (min-Heap) 'pq' to store the pair of integers. The first integer will store the distance of
//       the node from the source vertex and the second integer will store the node number.
//    b) Create a vector 'dist' of size equal to the number of vertices in the graph and initialize all the elements with INT_MAX.
// 2. Push the pair {0, src} in the priority queue. This means that the distance of the source vertex from itself is 0.
// 3. Initialize the distance of the source vertex from itself as 0 in the 'dist' vector.
// 4. Run a while loop until the priority queue is not empty. Dequeue the front element of the priority queue and store the
//    distance in 'dis' and the node number in 'node'.
// 5. Traverse through all the adjacent nodes of the current node and update the distance of the adjacent node if the new
//    distance is less than the previous distance.
// 6. Push the pair {dist[adjNode], adjNode} in the priority queue. Repeat the above steps 4-6 until the priority queue is empty.
// 7. Return the 'dist' vector.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(E * log(V));   where E = no.of edges, V = no.of vertices
    // S.C: O(V)
    vector<int> dijkstra_priorityQueue(vector<vector<pair<int, int>>> &adj, int src) {
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

// ---------------------------------------------------------------------------------------------------------------

    // T.C: 
    // S.C:  
    vector<int> dijkstra_set(vector<vector<pair<int, int>>> &adj, int src) {

    }
};


int main() {
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int src = 2;

    vector<int> ans = Solution().dijkstra_priorityQueue(adj, src);
    for(auto it: ans) {
        cout << it << " ";
    }

    return 0;
}
