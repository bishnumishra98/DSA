// Problem link: https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

// GFG: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph
// is labelled with a distinct integer in the range 0 to V - 1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from
// that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:
// Input:
//  _____________
// |             |
// |  --> 0 ---> 1
// | |    |      |
// | |    \/     \/   6
//  -|--> 2 <--- 3
//   |____|______|
//        |
//        \/
//        5 <-- 4
// Output:
// 2 4 5 6
// Explanation:
// The given graph is shown above. Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them. 
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// Example 2:
// Input:
//  0 --> 1
// /\     |
//  |     |
//  2 <---
//  |
// \/
//  3
// Output:
// 3
// Explanation:
// Only node 3 is a terminal node, and every path starting at node 3 leads to node 3.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an
// integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

// Algorithm:
// 1. Reverse direction of all the edges in the graph. Thus, any node now with a indegree of 0 was actually a terminal node.
// 2. Now follow simple topological sort method (kahn's algorithm) to remove edges from graph. So first get all the nodes
//    with indegree 0, push into the queue. Dequeue the front element, print it, and push its adjacent nodes in the queue
//    with indegree 0. Continue the process untill the queue becomes empty.
//    At the end, all nodes connected or a part of cycle remains as it is and do not get pushed in queue. Hence, all safe
//    nodes have been printed or stored in any array, whatever you want.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(V+E) + O(VlogV) due to sorting adjRev
    // S.C: O(V+E) + O(V) due to adjRev = O(V+E)
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Create an adjacency list with reversed edges and count indegree of all nodes of the new graph formed
        vector<int> adjRev[V];
        int inDegree[V] = {0};
        for(int i = 0; i < V; i++) {
            for(int neighbour: adj[i]) {
                // Initial edge direction: i -> neighbour
                // What we have to make ?: neighbour -> i
                adjRev[neighbour].push_back(i);
                inDegree[i]++;   // as neighbour points to i, thus indegree of i will increment
            }
        }

        // Push all nodes with indegree 0 in the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        // Dequeue the front element of queue, store it in 'safeNodes' array; then reduce indegree of adjacent nodes
        // of that front element, as the edge between the neighbour and front element is supposed to be removed. Push
        // neighbours of front element having indegree 0, in the queue. Continue the process until queue becomes empty.
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(int neighbour: adjRev[node]) {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }

        // Sort the 'safeNodes' array and return.
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

int main() {
//  _____________
// |             |
// |  --> 0 ---> 1
// | |    |      |
// | |    \/     \/   6
//  -|--> 2 <--- 3
//   |____|______|
//        |
//        \/
//        5 <-- 4
    int V = 7;
    vector<int> adj[V] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> ans = Solution().eventualSafeNodes(V, adj);
    for(auto it: ans) cout << it << " ";

    return 0;
}
