// GFG: Given a Directed Acyclic Graph of n vertices from 0 to n-1 and a 2D Integer array(or vector) edges{ ]{ ] of length m,
// where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1
// for that vertex.

// Examples 1:
// Input: n = 4, m = 2, edge = [[0,1,2],[0,2,1]]
// Output: 0 2 1 -1
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1.
//              There is no way we can reach 3, so it's -1 for 3.

// Example 2:
// Input: n = 6, n = 7, edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
// Output: 0 2 3 6 1 5
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
//              Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with
//              edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

// Your Task: You don't need to print or input anything. Complete the function shortest path() which takes an
//            integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as
//            the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C:
    // S.C:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
    }
};

int main() {
    int n = 6, m = 7;
    vector<vector<int>> edges = {{0,1,2}, {0,4,1}, {4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}};

    vector<int> ans = Solution().shortestPath(n, m, edges);
    for(int it: ans) {
        cout << it << " ";
    }

    return 0;
}
