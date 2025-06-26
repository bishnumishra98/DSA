// GFG: Maximize The Cut Segments   --->   Given an integer n denoting the Length of a line segment. You need
// to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z.
// Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum. Return the
// maximum number of cut segments possible.
// Note: if no segment can be cut then return 0.

// Example 1:
// Input: n = 4, x = 2, y = 1, z = 1
// Output: 4
// Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.

// Example 2:
// Input: n = 5, x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.

// Example 3:
// Input: n = 7, x = 8, y = 9, z = 10
// Output: 0
// Explanation: Here the total length is 7, and the cut lengths are 8, 9, and 10. We cannot cut the segment into lengths
// that fully utilize the segment, so the output is 0.

// Constraints
// 1 <= n, x, y, z <= 10^4

// Problem link: https://www.geeksforgeeks.org/problems/cutted-segments1642/1

// Algorithm: Its a very easy problem. You are smart enough to understand the code.
//            If you still need algorithm, quit coding today.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(3^n)
    // S.C: O(n) for recursion stack space
    int maximizeTheCuts_recursion(int n, int x, int y, int z) {
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;   // to avoid infinite recursion

        // Cutting 'x' length from 'n', and leaving the rest on recursion
        int option1 = 1 + maximizeTheCuts_recursion(n - x, x, y, z);

        // Cutting 'y' length from 'n', and leaving the rest on recursion
        int option2 = 1 + maximizeTheCuts_recursion(n - y, x, y, z);

        // Cutting 'z' length from 'n', and leaving the rest on recursion
        int option3 = 1 + maximizeTheCuts_recursion(n - z, x, y, z);

        return max(option1, max(option2, option3));
    }

// -----------------------------------------------------------------------------------------------------------

    int solve(int n, int x, int y, int z, vector<int>& dp) {
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;

        if(dp[n] != -1) return dp[n];

        int option1 = 1 + maximizeTheCuts_recursion(n - x, x, y, z);
        int option2 = 1 + maximizeTheCuts_recursion(n - y, x, y, z);
        int option3 = 1 + maximizeTheCuts_recursion(n - z, x, y, z);

        return dp[n] = max(option1, max(option2, option3));
    }

    // T.C: O(n)
    // S.C: O(n) for dp array + O(n) for recursion stack space = O(n)
    int maximizeTheCuts_memoization(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        return solve(n, x, y, z, dp);
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int maximizeTheCuts_tabulation(int n, int x, int y, int z) {
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            if(i - x >= 0) dp[i] = max(dp[i], 1 + dp[i - x]);
            if(i - y >= 0) dp[i] = max(dp[i], 1 + dp[i - y]);
            if(i - z >= 0) dp[i] = max(dp[i], 1 + dp[i - z]);
        }

        return dp[n] < 0 ? 0 : dp[n];
    }
};


int main() {
    int N = 7;
    int x = 5, y = 5, z = 2;

    cout << Solution().maximizeTheCuts_recursion(N, x, y, z) << endl;
    cout << Solution().maximizeTheCuts_memoization(N, x, y, z) << endl;
    cout << Solution().maximizeTheCuts_tabulation(N, x, y, z) << endl;

    return 0;
}
