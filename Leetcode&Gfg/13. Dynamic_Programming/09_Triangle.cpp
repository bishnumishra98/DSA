// Leetcode: 120. Triangle   --->   Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i
// on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:
// Input: triangle = [[-10]]
// Output: -10

// Algorithm: In the previous problems, we have solved recursion from fixed ending point to fixed starting point.
//            But here we can have variable ending point, thus it is preferable to solve the problem using
//            recursion from the given fixed starting point to the ending point. Overall, its an easy problem.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle) {
        int n = triangle.size();   // no.of rows in triangle
        // if(j >= triangle[i].size()) return 1e9;
        // The condition 'j >= triangle[i].size()' is optional because:
        // 1. As it's a triangle, every row has one more value than the previous row. When the program reaches the
        //    last row, it returns from there itself. Therefore, a call with 'j + 1' will never go out of bound.


        if(i == n - 1) return triangle[i][j];   // if you reach any value in the last row, return that value

        // Movements allowed only in 2 directions: bottom (next row, same column) and right diagonal (next row, next column)
        int bottom = triangle[i][j] + solve(i + 1, j, triangle);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle);

        return min(bottom, diagonal);
    }

    // T.C: O(2^(n - 1));   where n is the no.of rows in the triangle
    // S.C: O(n);   recursion stack space
    int minimumTotal_recursion(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }

// ------------------------------------------------------------------------------------------------

    int minimumTotal_memoization(vector<vector<int>>& triangle) {
        
    }

// ------------------------------------------------------------------------------------------------

    int minimumTotal_tabulation(vector<vector<int>>& triangle) {
        
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal_recursion(triangle) << endl;

    return 0;
}
