// GFG: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// Example 1:
// Input:
// 0 --> 1 --> 2 --> 3
//             |     /\
//            \/     |
//             5 --> 4
// Output:
// 1

// Example 2:
// Input:
// 0 --> 1 --> 2 --> 3
//             |     |
//            \/    \/
//             5 --> 4
// Output:
// 0

// Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

// Algorithm:


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    bool isCyclic(int V, vector<int> adj[]) {
        
    }
};

int main() {
    // 0 --> 1 --> 2 --> 3
    //             |     /\
    //            \/     |
    //             5 --> 4

    // Adjacency list
    // 0 -> {1}
    // 1 -> {2}
    // 2 -> {3, 5}
    // 3 -> {}
    // 4 -> {3}
    // 5 -> {4}
    int V = 6;
    vector<int> adj[V] = {{1}, {2}, {3, 5}, {}, {3}, {4}};

    Solution sol;
    cout << sol.isCyclic(V, adj);

    return 0;
}
