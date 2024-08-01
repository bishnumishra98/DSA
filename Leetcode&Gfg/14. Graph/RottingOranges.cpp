// Leetcode: 994. Rotting Oranges   --->   You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],
//                [1,1,0],
//                [0,1,1]]
// Output: 4

// Example 2:
// Input: grid = [[2,1,1],
//                [0,1,1],
//                [1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Algorithm: Here we need to find out minimum time to rot all oranges. In this problem, only a BFS algorithm will work.
// ➤ Why BFS is suitable here ?
//    BFS naturally processes nodes level by level (in this case, time or minutes) in all directions. It is ideal for spreading
//    processes, such as rotting oranges. BFS allows for simultaneous updates in all four directions, making it perfect for
//    scenarios where multiple changes can occur at once (e.g., multiple fresh oranges becoming rotten simultaneously).
// ➤ Why DFS fails here ?
//    DFS explores as far as possible along a branch before backtracking. This does not align with the need to spread out in
//    all directions at each step. DFS does not process nodes at the same level simultaneously, which is required for
//    calculating the time for simultaneous rotting of oranges.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    int orangesRotting(vector<vector<int>>& grid) {
        
    }
};

int main() {

    return 0;
}
