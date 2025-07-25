// GFG: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:
// Input:
//      0 --> 1
//            |
//            \/
//  --> 3 <-- 2
// | __ |
//
// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:
// Input:
// 0 --> 1
//       |
//       \/
//       2
// Output: 0
// Explanation: no cycle in the graph

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V
// denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the
// given directed graph contains a cycle or not.
// In the adjacency list adj, element adj[i][j] represents an edge from i to j.

// Algorithm: There is an extremely simple logic to detect cycle in a graph. Find the topological sort of the given graph
//            using Kahn's algorithm. If the array containing topological sort elements is smaller in size than the
//            no. of nodes in graph, there is a cycle present in the graph.
// IMPORTANT: Keep in mind to use only Kahn's algo to find the linear sequence.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(V+E)
    // S.C: O(V+E)
    bool isCyclic(int V, vector<int> adj[]) {
        int inDegree[V] = {0};

        // Count the indegree of all nodes
        for(int i = 0; i < V; i++) {
            for(int neighbour: adj[i]) inDegree[neighbour]++;
        }

        queue<int> q;
        // Push the nodes with inDegree initially as 0, in the queue
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        // vector<int> ans;   // no need to create 'ans' as we don't need to store the linear sequence. Just make a count variable.
        int count = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            // Once this node is popped out from queue, increase count by 1, and also reduce the inDegree of all its adjacent node by 1.
            count++;

            for(int neighbour: adj[front]) {
                inDegree[neighbour]--;
                // After reducing inDegree of its adjacent nodes, if any node's inDegree becomes 0, push that node inside the queue.
                if(inDegree[neighbour] == 0) q.push(neighbour); 
            }
        }

        if(count < V) return true;   // if count < V, it means a cycle is present in graph, else this graph is acyclic
        else return false;
    }
};


int main() {
    //      0 --> 1
    //            |
    //            \/
    //  --> 3 <-- 2
    // | __ |

    int V = 4;
    vector<int> adj[V] = {{1}, {2}, {3}, {3}};
    cout << Solution().isCyclic(V, adj);

    return 0;
}
