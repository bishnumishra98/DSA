// Leetcode 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance   --->   There are n cities
// numbered from 0 to n-1. Given the array edges where edges{i] = {fromi, toi, weighti] represents a bidirectional and
// weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most
// distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has
// the greatest number.

// Example 2:
// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 2 for each city are:
// City 0 -> [City 1] 
// City 1 -> [City 0, City 4] 
// City 2 -> [City 3, City 4] 
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3] 
// The city 0 has 1 neighboring city at a distanceThreshold = 2.

// Algorithm: Extremely simple.
// This problem can be solved using two approaches: the Floyd Warshall algorithm or Dijkstra's algorithm. 
// Floyd Warshall is suitable for finding the shortest distances between all pairs of cities, 
// while Dijkstra's is a single-source shortest path algorithm that needs to be applied to all cities to achieve the same result.

// For now, we will stick to the Floyd Warshall algorithm as it efficiently computes the shortest paths for all city pairs.
// Steps to solve the problem using Floyd Warshall:
// 1. Initialize a 2D matrix (dist) where dist[i][j] represents the shortest distance between city i and city j.
//    i.   Set dist[i][j] to the edge weight for directly connected cities.
//    ii.  Set dist[i][j] to INT_MAX if cities i and j are not directly connected.
//    iii. Set dist[i][i] to 0 as the distance from a city to itself is always 0.
// 2. Use three nested loops to apply the Floyd Warshall algorithm:
//    i.   Iterate through each intermediate city k.
//    ii.  Update the shortest paths between all city pairs (i, j) considering k as an intermediate city.
//    iii. If the path from i to k and k to j is shorter than the current path from i to j, update dist[i][j].
// 3. After computing the shortest paths, iterate over all cities to calculate the number of reachable neighbors for each city:
//    - A neighbor is considered reachable if the shortest distance from the current city to that neighbor is less than or
//      equal to the threshold distance.
// 4. Find the city with the smallest number of reachable neighbors.
//    - If there are multiple cities with the same number of reachable neighbors, choose the city with the largest index.
// 5. Return the city that satisfies the above conditions.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^3)
    // S.C: O(n^2)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Creating the initial 2D matrix for Floyd Warshall algorithm
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto it: edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;   // setting the distance from a city to itself to 0

        // Creating the final matrix containing shortest distance between each pair of cities
        for(int k = 0; k < n ; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Initialize variables to track the city with the smallest number of neighbors
        int cityCount = n;   // track the minimum number of reachable cities
        int cityNo = -1;   // track the city number with the smallest count of reachable cities

        // Iterate over all cities to count reachable neighbors within the threshold distance
        for(int city = 0; city < n; city++) {
            int count = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) count++;
            }

            // If a smaller count found, update the 'cityCount' with this value, and also update the 'cityNo'
            if(count <= cityCount) {
                cityCount = count;
                cityNo = city;
            }
        }

        return cityNo;
    }

// --------------------------------------------------------------------------------------------------

    // T.C: O(n * (n + e)logn);   where n = no.of vertices, e = no.of edges
    // S.C: O(n^2 + e)
    int findTheCity_Dijkstra(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Creating the adjacency list
        vector<vector<pair<int,int>>> adj(n);   // {node} -> {adjNode, distance}
        for(auto it:edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        // 2D distance matrix to store shortest paths from each city to every other city
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) dist[i][i] = 0;   // setting the distance from a city to itself to 0

        // Priority queue for Dijkstra's algorithm to process nodes based on their current distance (min-heap)
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;   // {distance, node}

        // Apply Dijkstra's algorithm for each city as the source
        for(int i = 0; i < n; i++) {
            pq.push({0, i});   // start with distance 0 for the current source city 'i'
            while(!pq.empty()) {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it: adj[node]) {
                    int adjNode = it.first;
                    int adjWeight = it.second;
                    // Relaxation step: Update the shortest distance from city 'i' to city 'adjNode' if a better path is found
                    if(dis + adjWeight < dist[i][adjNode]) {
                        dist[i][adjNode] = dis + adjWeight;
                        pq.push({dist[i][adjNode], adjNode});
                    }
                }
            }
        }

        // Initialize variables to track the city with the smallest number of neighbors
        int cityCount = n;   // track the minimum number of reachable cities
        int cityNo = -1;   // track the city number with the smallest count of reachable cities

        // Iterate over all cities to count reachable neighbors within the threshold distance
        for(int city = 0; city < n; city++) {
            int count = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) count++;
            }

            // If a smaller count found, update the 'cityCount' with this value, and also update the 'cityNo'
            if(count <= cityCount) {
                cityCount = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int distanceThreshold = 2;

    cout << Solution().findTheCity(n, edges, distanceThreshold) << endl;
    cout << Solution().findTheCity_Dijkstra(n, edges, distanceThreshold);

    return 0;
}
