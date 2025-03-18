// GFG: Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle
// or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
// Cycle can be anywhere; in a solo graph or in any of the components of graph. Thus, check all components of graph for cycle.

// Example 1:
// Input:  
// V = 5
// adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
// Output: 1
// Explanation:
//   1 --- 2
//  / \     \
// 0   4 --- 3
// 1->2->3->4->1 is a cycle.

// Example 2:
// Input: 
// V = 4
// adj = {{}, {2}, {1, 3}, {2}}
// Output: 0
// Explanation:
//    0
// 1 --- 2
//      /
//     3
// No cycle in the graph.

// Intuition: Select a source node and start BFS traversal from it. In the BFS traversal, if
//            two separate branches meet at the same node, it means the graph has a loop.

// Algorithm:
// 1. Define a queue and a visited array(to keep track of nodes visited, so that we do not traverse any same node).
// 2. Mark the first node as visited and push it in the queue along with its parent node. While pushing the first node,
//    its parent can be considered as -1.
// 3. Dequeue the front node of the queue, traverse the neighbours of this node, similarly mark them visited and push
//    them in the queue along with their parent, if they are not yet visited. Perform this in a loop until queue is empty.
//    If the neighbour of the node is already visited, there can be two cases:
//    i.  The neighbour is marked visited because the current node came after traversing it, i.e., the neighbour is nothing,
//        but the current node's parent. In this case, no need to traverse this neighbour, just move to the next neighbour.
//    ii. The neighbour is marked visited and the current node didn't came from it, i.e., the neighbour isn't current node's parent.
//        This can only happen if someone else has visited that neighbour before the current node. It means the neighbour of the
//        current node was someone else's neighbour too. Due to this, two different paths met at the same node, signifying a cycle.

// Example:
//   0 --- 1 --- 2
//    \         /
//     4 ----- 3

// Adjacent list:
// 0 -> {1, 4}
// 1 -> {0, 2}
// 2 -> {1, 3}
// 3 -> {2, 4}
// 4 -> {3, 0}

// Illustration:
// 1. Starting from 0, we mark vis[0] and push {0, -1} in queue.
// 2. Dequeue 0 from queue. It has two neighbours 1 and 4. Traverse them one by one. Mark vis[1] and push {1, 0} in queue.
//    Then mark vis[4] and push {4, 0} in queue.
// 3. Dequeue 1 from queue. It has two neighbours 0 and 2. 0 is already visited and 1 itself came from 0, so traverse only 2.
//    Mark vis[2] and push {2, 1} in queue.
// 4. Dequeue 4 from queue. It has two neighbours 0 and 3. 0 is alreday visited and 4 itself came from 0, so traverse only 3.
//    Mark vis[3] and push {3, 4} in queue.
// 5. Dequeue 2 from queue. It has two neighbours 1 and 3. 1 is already visited and 2 itself came from 1. Then coming to 3,
//    3 is also already marked visited but 2 did not come from 3. This means someone else visited 3 before 2 (4 visited 3
//    in the last step). This signifies a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;   // <src, parent>
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto neighbour: adj[node]) {
                if(!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                } else if(neighbour != parent) return true;
            }
        }
        return false;
    }

    // T.C: O(V + 2E);   where V = no.of nodes in graph and E = no.of edges in graph, 2*E = total degrees of graph
    // S.C: O(V)
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // Checking cycles in all components of graph using for loop
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detectCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};

    cout << sol.isCycle(V, adj);

    return 0;
}
