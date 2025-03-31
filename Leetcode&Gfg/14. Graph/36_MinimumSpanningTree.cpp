// Q) What is a Spanning Tree ?
// A) There can be multiple spanning trees for a graph. If a graph has V vertices, a Spanning Tree of a graph is a subgraph that:
//    • Includes all V vertices of the original graph.
//    • Contains exactly V − 1 edges.
//    • Does not contain any cycles (it’s a tree).
//    • Maintains the connectivity of the graph.

// Q) What is Minimum Spanning Tree ?
// A) A Minimum Spanning Tree (MST) is a spanning tree of a weighted graph that has the smallest possible sum of edge weights
//    among all spanning trees of the graph.
//    There can be more than one MST for a graph if multiple spanning trees have the same total edge weight.


// GFG: Minimum Spanning Tree   --->   Given a weighted, undirected, and connected graph with V vertices and E edges,
// your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.
// The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.
// Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer
// denoting the weight of the edge.

// Example 1:
// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1
// Output: 4

// Example 2:
// Input:
// 2 1
// 0 1 5
// Output: 5

// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Algorithm to find the sum of edges in the Minimum Spanning Tree (MST) using Prim's Algorithm: It is a greedy approach.
// 1. i.  Create a min-heap (priority queue) 'pq' that stores {edgeWeight, node} pairs.
//    ii. Create a visited array of size 'V' to track which nodes are included in the MST.
// 2. Push the initial edge with node {0, 0} into the priority queue, meaning:
//    - Start from node 0, and the cost to include it in the MST is 0.
// 3. Initialize 'sum' = 0 (this will store the total weight of the MST).
// 4. While 'pq' is not empty:
//    i.   Extract the {edgeWeight, node} from the top of 'pq', then pop it. Extracting edgeWeight 'ew' and node 'n' from
//         the 'pq' means that node 'n' is being added to the MST with an edge of weight 'ew' from some already included
//         node in the MST.
//    ii.  If the node is already visited, skip it (continue).
//    iii. Otherwise, mark it as visited and add the 'edgeWeight' to 'sum'.
//    iv.  Traverse all adjacent nodes of this node:
//         - Extract {adjNode, weight} from the adjacency list.
//         - If 'adjNode' is not yet visited, push {weight, adjNode} into 'pq'.
// 5. At the end, return 'sum'.

// Algorithm to build the Minimum Spanning Tree (MST) using Prim's Algorithm: Almost same as above algorithm.
// 1. i.   Create a min-heap (priority queue) 'pq' that stores {edgeWeight, node, parent}.
//    ii.  Create a visited array of size 'V' to track which nodes are included in the MST.
//    iii. Create a 'result' array to store and return the built MST in the order {parent, node edgeWeight}. 
// 2. Push the initial node 0 with weight 0 and parent -1 (no parent for the starting node) into the 'pq'.
// 3. While 'pq' is not empty:
//    i.   Extract edgeWeight, node and parent from top element of 'pq'. Then pop the top element.
//    ii.  If the node is already visited, skip it (continue).
//    iii. Otherwise, mark it as visited.
//    iv.  If the node has a parent, add the edge with edgeWeight to the MST 'result' array ({parent, node, edgeWeight}).
//    v.   Traverse all adjacent nodes of this node:
//         - Extract {adjNode, weight} from the adjacency list.
//         - If 'adjNode' is not yet visited, push {adjWeight, adjNode, node} into 'pq'.
// 5. At the end, return 'result'.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(ElogE) + O(ElogE) = O(ElogE)
    // S.C: O(E)
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // {edgeWeight, node}
        vector<int> vis(V, 0);

        pq.push({0, 0});   // start with node 0 and an initial edge weight of 0
        int sum = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;

            vis[node] = 1;
            sum+= wt;

            for(auto it: adj[node]) {
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }

// -------------------------------------------------------------------------------

    // T.C: O(ElogE);   where E = no.of edges
    // S.C: O(V + E);   where V = no.of vertices
    vector<vector<int>> buildMST(int V, vector<vector<int>> adj[]) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;   // {edgeWeight, node, parent}
        vector<int> vis(V, 0);   // Visited array to track visited nodes
        vector<vector<int>> result;   // To store the MST edges {parent, node edgeWeight}

        // Push the initial node with weight 0 and parent -1 (no parent for the starting node)
        pq.push({0, 0, -1}); // {edgeWeight, node, parent}

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int edgeWeight = get<0>(it);
            int node = get<1>(it);
            int parent = get<2>(it);
            
            // Skip if the node is already visited
            if (vis[node]) continue;

            // Mark the current node as visited
            vis[node] = 1;

            // If the node has a parent, add the edge to the MST result
            if (parent != -1) {
                result.push_back({parent, node, edgeWeight});
            }

            // Traverse all adjacent nodes
            for (auto &it : adj[node]) {
                int adjNode = it[0];
                int adjWeight = it[1];

                // If the adjacent node is not visited, add it to the priority queue
                if (!vis[adjNode]) {
                    pq.push({adjWeight, adjNode, node});
                }
            }
        }

        return result;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});  // Edge 0 -> 1 with weight 5
    adj[1].push_back({0, 5});  // Edge 1 -> 0 with weight 5
    adj[1].push_back({2, 3});  // Edge 1 -> 2 with weight 3
    adj[2].push_back({1, 3});  // Edge 2 -> 1 with weight 3
    adj[0].push_back({2, 1});  // Edge 0 -> 2 with weight 1
    adj[2].push_back({0, 1});  // Edge 2 -> 0 with weight 1

    cout << Solution().spanningTree(V, adj) << endl;

    vector<vector<int>> mst = Solution().buildMST(V, adj);
    for(int i = 0; i < mst.size(); i++) {
        cout << mst[i][0] << " -> " << mst[i][1] << " with edge weight " << mst[i][2] << endl;
    }

    return 0;
}
