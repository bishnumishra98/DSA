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
        // As it's a triangle, every row has one more value than the previous row. When the program reaches the
        // last row, it returns from there itself. Therefore, a call with 'j + 1' will never go out of bound.


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

    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if(i == n - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int bottom = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

        dp[i][j] = min(bottom, diagonal);
        return dp[i][j];
    }

    // T.C: O(n^2);   where n is the no.of rows in the triangle
    // S.C: O(n^2) for dp array + O(n) for recursion stack space = O(n^2)
    int minimumTotal_memoization(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }

// ------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(n^2)
    int minimumTotal_tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill the last row of dp with the values of the last row of triangle
        for(int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        
        // Fill the dp table from bottom to top (except the last row)
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int bottom = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(bottom, diagonal);
            }
        }
        
        return dp[0][0];   // the minimum path sum will be at the top of the triangle
    }

// ------------------------------------------------------------------------------------------------

    // T.C: O(n^2)
    // S.C: O(n)
    int minimumTotal_tabulation_SO(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);   // to store the previous row's results

        // Fill the last row of prev with the values of the last row of triangle
        for(int j = 0; j < n; j++) {
            prev[j] = triangle[n - 1][j];
        }

        // Fill the dp table from bottom to top (except the last row)
        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);   // to store the current row's results
            for(int j = 0; j <= i; j++) {
                int bottom = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                curr[j] = min(bottom, diagonal);
            }
            prev = curr;   // move to the next row
        }

        return prev[0];   // the minimum path sum will be at the top of the triangle
    }
};


int main() {
    Solution sol;

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal_recursion(triangle) << endl;
    cout << sol.minimumTotal_memoization(triangle) << endl;
    cout << sol.minimumTotal_tabulation(triangle) << endl;
    cout << sol.minimumTotal_tabulation_SO(triangle);

    return 0;
}
