// GFG: Maximum Connected group   --->   You are given a square binary grid. A grid is considered binary
// if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1.
// You need to find the largest group of connected  1's. Two cells are said to be connected if both are
// adjacent(top, bottom, left, right) to each other and both have the same value.

// Example 1:
// Input: grid = [1, 1]
//               [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]

// Example 2:
// Input: grid = [1, 0, 1]
//               [1, 0, 1]
//               [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0, 1},
                                {1, 0, 1},
                                {1, 0, 1}};
    
    Solution obj;
    int result = obj.MaxConnection(grid);
    cout << result;

    return 0;
}
