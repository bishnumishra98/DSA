// Leetcode: 1192. Critical Connections in a Network   --->   There are n servers numbered from 0 to n - 1
// connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi]
// represents a connection between servers ai and bi. Any server can reach other servers directly or
// indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

// Example 1:
// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Example 2:
// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> ans;
    Solution obj;
    ans = obj.criticalConnections(n, connections);
    for(auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "]\n";
    }

    return 0;
}
