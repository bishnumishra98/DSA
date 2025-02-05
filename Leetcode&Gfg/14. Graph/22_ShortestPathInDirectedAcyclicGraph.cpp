// GFG: Given a Directed Acyclic Graph of n vertices from 0 to n-1 and a 2D Integer array(or vector) edges{ ]{ ] of length m,
// where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1
// for that vertex.

// Examples 1:
// Input: n = 4, m = 2, edge = [[0,1,2],[0,2,1]]
// Output: 0 2 1 -1
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1.
//              There is no way we can reach 3, so it's -1 for 3.

// Example 2:
// Input: n = 6, m = 7, edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
// Output: 0 2 3 6 1 5
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
//              Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with
//              edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

// Your Task: You don't need to print or input anything. Complete the function shortest path() which takes an
//            integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as
//            the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

// Algorithm: We have to find shortest path from source 0 to all nodes of the graph. Any topological algoritm DFS or BFS
//            can be applied here.
// 1. Find topological sort for the given weighted DAG. Lets follow DFS technique in this algorithm.
// 2. Post the topo sort, take out the stack elements one by one and relax the edges. Relax the edges means, we need to
//    create a 'dist' array of size as many nodes in the graph, and mark all elements of it as infinity. Then mark the source
//    node as 0 in the 'dist' array, as to reach source node to itself, it takes 0 weight.
// 3. Pop out the top element from the stack, and find out the distance(weight) needed to reach its neighbours and if
//    the distance to reach there comes out to be lesser than the existing distance to reach there, update that value
//    with new shorter distance. Continue the process untill the stack becomes empty. Note that, when you pop out the next
//    node and find distance to reach its neighbour, you have to add up the distance to reach the neighbour from the current
//    node with the already existing distance(weight) required to reach till the current node.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS toposort
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
        vis[node] = 1;

        for(auto it: adj[node]) {
            int neighbour = it.first;   // in adj[node], there are two values {neighbour, edge-weight}
            if(!vis[neighbour]) topoSort(neighbour, adj, vis, st);
        }

        st.push(node);
    }

public:
    // T.C: O(N+M);   topological sorting takes O(N+M) (DFS traversal), and relaxing all the edges also takes O(N+M).
    // S.C: O(N+M)
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src) {
        // Create a graph in the form of an adjacency list like this: node -> {adj_node, weight}, {adj_node, weight}, etc.
        vector<pair<int, int>> adj[N];   // N is no.of nodes from 0 to N-1
        for(int i = 0; i < M; i++) {   // M is the no.of edges, i.e., edges.size()
            // edges is in format -> {N1, N2, weight of edge between N1 & N2}
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Find the topological sort and store the linear sequence in the stack 'st'.
        int vis[N] = {0};   // helper data structure for topo sort
        stack<int> st;   // data structure to store the topo sort
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        
        // Create a 'dist' array to track distance to reach a node from source node, marked all initially with infinity.
        vector<int> dist(N, 1e9);
        dist[src] = 0;   // no need to check distance for source node to reach itself. It will obviously be 0

        while(!st.empty()) {
            // Pop out the top element of stack and traverse its neighbours, and update 'dist' array if a shorter distance is found.
            int node = st.top();
            // cout << "node popped: " << node << endl;
            st.pop();

            for(auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                // Relax the edge: Update the 'dist' array with with smaller values if found.
                // If the distance(dist[node]) to reach the current node + the distance(wt) to reach its neighbour 'v' is less
                // than the already existing distance to reach 'v', then update the distance to reach 'v' as dist[node] + wt.
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        // If its not possible to reach a particular node, mark that node as -1 in the 'dist' array.
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};


int main() {
    int n = 6, m = 7;
    vector<vector<int>> edges = {{0,1,2}, {0,4,1}, {4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}};
    int src = 4;   // this is an addition to the GFG problem. GFG problem wants hardcoded source node as 0.

    vector<int> ans = Solution().shortestPath(n, m, edges, src);
    for(int it: ans) {
        cout << it << " ";
    }

    return 0;
}
