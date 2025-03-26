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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(ElogV);   where E = no.of edges, V = no.of vertices
    // S.C: O(V)
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);   // node -> {neighbour, weight}
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int start = 0;
        int end = n-1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // {distance, node}
        vector<int> dist(n, 1e9), ways(n, 0);   // distance, ways vectors to track least distance and no.of ways to reach a node
        pq.push({0, start});
        dist[0] = 0;
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjDis = it.second;
                
                if(dis + adjDis < dist[adjNode]) {   // this is the first time we are visiting this node
                    dist[adjNode] = dis + adjDis;
                    ways[adjNode] = ways[node];
                    pq.push({dis + adjDis, adjNode});
                } else if(dis + adjDis == dist[adjNode]) {   // we have already visited this node
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
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
