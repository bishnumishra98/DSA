// GFG: Disarrangement of balls   --->    You are given n balls numbered from 1 to n and there are n baskets
// numbered from 1 to n in front of you. The ith basket is meant for the ith ball. Calculate the number of ways
// in which no ball goes into its respective basket.
// Note: The answer will always fit into a 32-bit integer.

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: For two balls {1, 2}, there is only one possible derangement {2, 1}.

// Example 2:
// Input: n = 3
// Output: 2
// Explanation: For three balls {1, 2, 3}, there are two possible derangements {3, 1, 2} and {2, 3, 1}.

// Constraints:
// 1 ≤ n ≤ 12

// Problem link: https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

// Algrithm: It is a simple combinatorial problem that can be solved using recursion.
//           Lets say we have 'n' balls and 'n' baskets. The first ball can go into any of the (n - 1) baskets
//           encept its own. Thus, we have (n - 1) choices for the first ball to go into any of the (n - 1) baskets,
//           and the recursive relation to derange 'n' balls into 'n' baskets comes out to be:
//           (n - 1) * (number of ways to derange (n - 1) balls and (n - 1) baskets).
//           The number of ways to derange (n - 1) balls and (n - 1) baskets can be calculated using the same logic,
//           but we need to consider two cases for the first ball's placement:
//           Lets say we placed the first ball into 'i'th basket, then then we have two choices:
//           1. If the 'i'th ball goes into the first ball's basket, then 2 balls (1st ball and 'i'th ball) are
//              already placed. Hence, we are left with (n - 2) balls and (n - 2) baskets to derange.
//           2. If the 'i'th ball does not goes into the first ball's basket, then we have (n - 1) balls and
//              (n - 1) baskets to derange.
//           Thus, number of ways to derange 'n - 1' balls and 'n - 1' baskets is sum of both the above cases.
//           Hence, the final recursive relation becomes:
//           D(n) = (n - 1) * (D(n - 2) + D(n - 1))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(2^n)
    // S.C: O(n) for recursion stack space
    int countDer_recursion(int n) {
        // Base cases:
        // 1) If there is only 1 ball, it cannot be placed in its own basket, so there are 0 ways to derange it.
        // 2) If there are 2 balls, they can only be placed in each other's baskets, so there is 1 way to derange them.
        if(n == 1) return 0;   // D(1) = 0
        if(n == 2) return 1;   // D(2) = 1

        return (n - 1) * (countDer_recursion(n - 2) + countDer_recursion(n - 1));
    }

// -------------------------------------------------------------------------------------------------------

    int solve(int n, vector<int>& dp) {
        if(n == 1) return 0;
        if(n == 2) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = (n - 1) * (solve(n - 2, dp) + solve(n - 1, dp));
    }

    // T.C: O(n)
    // S.C: O(n) for dp array + O(n) for recursion stack space = O(n)
    int countDer_memoization(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int countDer_tabulation(int n) {
        if(n <= 1) return 0;
        if(n == 2) return 1;

        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
        }

        return dp[n];
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(1)
    int countDer_tabulation_SO(int n) {
        if(n <= 1) return 0;
        if(n == 2) return 1;

        int prev2 = 0;
        int prev = 1;
        
        for(int i = 3; i <= n; i++) {
            int curr = (i - 1) * (prev2 + prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};


int main() {
    int n = 3;

    cout << Solution().countDer_recursion(n) << endl;
    cout << Solution().countDer_memoization(n) << endl;
    cout << Solution().countDer_tabulation(n) << endl;
    cout << Solution().countDer_tabulation_SO(n) << endl;

    return 0;
}
