// Leetcode 1976. Number of Ways to Arrive at Destination   --->   You are in a city that consists of n intersections
// numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you
// can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road
// between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel
// from intersection 0 to intersection n - 1 in the shortest amount of time.
// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be
// large, return it modulo 10^9 + 7.

// Example 1:
// Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output: 4
// Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
// The four ways to get there in 7 minutes are:
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

// Example 2:
// Input: n = 2, roads = [[1,0,10]]
// Output: 1
// Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.


// Algorithm: Simple Dijkstra's Algorithm
// Note: Number of ways to reach current node = sum of number of ways to reach the nodes from where the current node came.
//       For example: node1 --- node3 --- node5
//                      |  \               |   \
//                      |    \             |   node7 
//                      |      \           |   /
//                    node2 --- node4 --- node6
//       In the above undirected graph, the number of ways to reach:
//       • ways[node7] = ways[node6] + ways[node5]
//       • ways[node6] = ways[node5] + ways[node4]
//       • ways[node5] = ways[node6] + ways[node3]

// 1. Create an adjacency list of the graph.
// 2. Create a priority queue to store the time and node pair. Initialize the time and ways vectors to track the
//    least time and the number of ways to reach a node.
// 3. Push the start node into the priority queue with time 0 and ways 1.
// 4. Run a while loop until the priority queue is empty.
//    i.   Pop the top element from the priority queue. Extract the time and current node from the top element.
//    ii.  Traverse the adjacency list of the current node. For each neighbour, check if the time taken to reach the neighbour
//         from the current node plus the time to reach the current node is less than the existing time to reach the neighbour.
//         If yes, it means we have found a way to reach the neighbour in a shorter time. So, update the time to reach the
//         neighbour, the number of ways to reach the neighbour and push the neighbour into the priority queue with the
//         updated time. The number of ways to reach the neighbour will be the same as the number of ways to reach the
//         current node as we have arrived at the neighbour with the shortest distance for the first time.
//    iii. Else if the time taken to reach the neighbour is equal to the time taken to reach the current node plus the time
//         taken to reach the neighbour from the current node, it means we have arrived at the neighbour already in the past
//         via any other path. This time, again we are arriving at the neighbour with the same shortest time again but from a
//         different path. In this case, update the number of ways to reach the neighbour by adding the number of ways to
//         reach the current node to its existing number of ways to reach. Modulo the total number of ways to reach the
//         neighbour by 10^9 + 7 to keep the answer within this range.
// 5. Return the number of ways to reach the destination node.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(ElogV);   where E = no.of edges, V = no.of vertices
    // S.C: O(V)
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);   // node -> {neighbour, time}
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int start = 0;
        int end = n - 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // {time, node}
        vector<int> time(n, 1e9), ways(n, 0);   // time, ways vectors to track least time and no.of ways to reach a node

        time[start] = 0;   // time to reach start from itself is 0
        ways[start] = 1;   // we can reach start in only 1 way, i.e., via itself
        pq.push({0, start});

        int mod = (int)(1e9 + 7);   // given in the problem to keep answer within this range

        while(!pq.empty()) {
            int timeTaken = pq.top().first;   // time taken to reach the current node
            int currNode = pq.top().second;
            pq.pop();

            for(auto it: adj[currNode]) {
                int adjNode = it.first;
                int adjtime = it.second;
                
                if(timeTaken + adjtime < time[adjNode]) {   // if a shorter time found to reach 'adjNode', via 'currNode'
                    time[adjNode] = timeTaken + adjtime;
                    ways[adjNode] = ways[currNode];
                    pq.push({timeTaken + adjtime, adjNode});
                } else if(timeTaken + adjtime == time[adjNode]) {   // if adjNode has been arrived again with the same shortest time
                    ways[adjNode] = (ways[adjNode] + ways[currNode]) % mod;
                }
            }
        }

        return ways[end];
    }
};

int main() {
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};

    Solution obj;
    cout << obj.countPaths(n, roads);

    return 0;
}
