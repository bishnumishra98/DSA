// GFG: Bellman-Ford   --->   Given a weighted and directed graph of v vertices and edges, Find the shortest distance
// of all the vertex's from the source vertex, src and return a list of integers where the ith integer denotes the
// distance of the ith node from the source node. If a vertices can't be reach from the s then mark the distance as 10^8.
// Note: If there exist a path to a negative weighted cycle from the source node then return {-1}.

// Example 1:
// Input: edges = {[0,1,9]], src = 0
// Output: [0, 9]
// Explanation: Shortest distance of all nodes from source is printed.

// Example 2:
// Input: edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2
// Output: [1, 6, 0]
// Explanation: For nodes 2 to 0, we can follow the path: 2-0. This has a distance of 1. For nodes 2 to 1, we can
// follow the path: 2-0-1, which has a distance of 1+5 = 6.

// Problem link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
    }
};

int main() {
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};
    int src = 2;
    int V = 3;   // number of vertices

    vector<int> ans = Solution().bellmanFord(V, edges, src);
    for(auto it: ans) cout << it << " ";

    return 0;
}
