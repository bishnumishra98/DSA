// No.of incoming paths to a node is its "indegree". For example: Consider the graph
// 5 --> 0 <-- 4
// |           |
// \/          \/
// 2 --> 3 <-- 1
// Its adjacency list will be:
// 0 -> {}
// 1 -> {3}
// 2 -> {3}
// 3 -> {}
// 4 -> {0, 1}
// 5 -> {0, 2}
// Just, count how many times a node occurs in anyone's adjacency list. that will be its degree.
// Indegree of 0: 2
// Indegree of 1: 1
// Indegree of 2: 1
// Indegree of 3: 2
// Indegree of 4: 0
// Indegree of 5: 0

// Algorithm: We will be using BFS algo to find a linear sequence in topological sort. This algorithm is called "Kahn's algorithm".
// 1. Find out indegrees of all nodes in the graph.
// 2. There will atleast one node in a DAG with indegree 0. Push such nodes in a queue.
// 3. Dequeue the front element of queue and print it. Then reduce the indegree of all neighbour nodes present in this
//    element's adjacent list by 1.
// 4. Next, push the nodes in the queue whose indegree became 0. Continue the process until queue is empty. 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// T.C: O(V+E)
    // S.C: O(V+E)
	vector<int> topoSort(int V, vector<int> adj[]) {
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

        vector<int> ans;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            // Once this node is popped out from queue, store it in an array, and also reduce the inDegree of all its adjacent node by 1.
            ans.push_back(front);

            for(int neighbour: adj[front]) {
                inDegree[neighbour]--;
                // After reducing inDegree of its adjacent nodes, if any node's inDegree becomes 0, push that node inside the queue.
                if(inDegree[neighbour] == 0) q.push(neighbour); 
            }
        }

        return ans;
	}
};

int main() {
// 1 --> 0 <-- 3
//       /\
//       |
//       2
    int V = 4;
    vector<int> adj[V] = {{}, {0}, {0}, {0}};

    Solution sol;
    vector<int> ans = sol.topoSort(V, adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
