// GFG: There are n cities and m edges connected by some number of flights. You are given an array flights where
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
// If there is no such route, return -1.
// Note: The price from city A to B may be different From the price from city B to A.

// Example 1:
// Input:
// n = 4
// flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
// src = 0
// dst = 3
// k = 1
// Output:
// 700
// Explanation:
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Problem link: https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

// Algorithm:
// 1. Create a vector of vectors of pairs of integers 'adj' to store the adjacency list of the graph. The graph is
//    represented as a directed graph where each node is connected to another node with a cost.
// 2. Create a queue of pairs of integers and a pair of integers named 'q', and push the no.f stops, source node and the
//    distance to reach source node in the queue, i.e., q.push({0, {src, 0}}). Note that we will be implementing
//    Djikstra's algorithm only, but a priority queue is not required as we need to visit all the nodes. A queue will work fine.
// 3. Create a vector of integers 'dist' to store the minimum cost required to reach a node. Initialize all the nodes
//    with infinity except the source node, which will have 0 cost.
// 4. While the queue is not empty:
//    i.   Pop the top element from the queue. Extract the stops, node, and cost from it.
//    ii.  If the stops are greater than K, continue to the next iteration.
//    iii. Traverse the adjacency list of the current node and calculate the new cost as the sum of the current cost and
//         the cost of the adjacent node.
//    iv.  If the new cost is less than the cost of the adjacent node and the stops are less than or equal to K, update
//         the cost of the adjacent node and push the stops + 1, adjacent node, and new cost to the queue.
// 5. If the cost of the destination node is infinity, return -1 as the destination node is not reachable.
// 6. Return the cost of the destination node.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n + E);   E = number of edges, i.e., flights.size()
    // S.C: O(n)
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int, int>>> adj(n);   // node -> {adjNode, cost}
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int, int>>> q;   // {stops, {node, dist}}
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // If stops has exceeded the limit, no need to go any other adjacent nodes, i.e., cities.
            if(stops > K) continue;

            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int adjCost = iter.second;
                if(cost + adjCost < dist[adjNode] && stops <= K) {
                    dist[adjNode] = cost + adjCost;
                    q.push({stops + 1, {adjNode, cost + adjCost}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    Solution obj;
    cout << obj.CheapestFLight(n, flights, src, dst, k);

    return 0;
}
