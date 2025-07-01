// Leetcode: 123. Best Time to Buy and Sell Stock III   --->   You are given an array prices where prices[i] is
// the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at
// the same time. You must sell before buying again.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// Algorithm: This is just an extension of the previous problem '39_BestTimeToBuyAndSellStockII.cpp'.
//            It is also a very simple problem. Here you just need to add an extra argument in the recursive
//            function calls, that is 'capacity'. 'capacity' is the number of times we are allowed to make
//            the transactions (2 in this problem).
//            The 'capacity' will only decrease by 1 when a complete transaction is over i.e., when the stock
//            that you are holding is sold.
//            And also an additioal base case will be required, if 'capacity' is 0, return 0 stating that no
//            more profit can be made further as the transaction limit has been reached. Make sure to write
//            this base case as the first base case.
//            And as one more variable is added, we will require a 3D dp this time to memoize the recursive code.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n, int capacity) {
        // Base case:
        if(capacity == 0 || index == n) return 0;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, capacity),
                        0 + solve(index + 1, 1, prices, n, capacity));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, prices, n, capacity - 1),   // sold, so capacity decreases
                        0 + solve(index + 1, 0, prices, n, capacity));
        }

        return profit;
    }

    // T.C: O(2^n);   because at each step we have two choices either take the stock or not take the stock
    // S.C: O(n) recursion stack space
    int maxProfit_recursion(vector<int>& prices) {
        int n = prices.size();
        int capacity = 2;
        return solve(0, 1, prices, n, capacity);
    }

// -------------------------------------------------------------------------------------------------------

    int solve(int index, int buy, vector<int>& prices, int n,vector<vector<vector<int>>>& dp, int capacity) {
        if(capacity == 0 || index == n) return 0;

        if(dp[index][buy][capacity] != -1) return dp[index][buy][capacity];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, dp, capacity),
                        0 + solve(index + 1, 1, prices, n, dp, capacity));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, prices, n, dp, capacity - 1),
                        0 + solve(index + 1, 0, prices, n, dp, capacity));
        }

        return dp[index][buy][capacity] = profit;
    }

    // T.C: O(n * 2 * 3) = O(6n)
    // S.C: O(n * 2 * 3) for dp table + O(n) for recursion stack space = O(7n)
    int maxProfit_memoization(vector<int>& prices) {
        int n = prices.size();
        int capacity = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(capacity + 1, -1)));
        return solve(0, 1, prices, n, dp, capacity);
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(6n)
    // S.C: O(6n)
    int maxProfit_tabulation(vector<int>& prices) {
        int n = prices.size();
        int capacity = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(capacity + 1, 0)));

        // Base case is optional because all cells are already initialized with 0.

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {   // or, for(int j = 0; j <= 1; j++)
                for(int k = capacity; k >= 0; k--) {   // or, for(int k = 0; k <= capacity; k++)
                    if(j == 1){
                        profit = max(-prices[i] + dp[i + 1][0][capacity], 0 + dp[i + 1][1][capacity]);
                    } else {
                        profit = max(prices[i] + dp[i + 1][1][capacity - 1], 0 + dp[i + 1][0][capacity]);
                    }
                    dp[i][j][capacity] = profit;
                }
            }
        }

        return dp[0][1][0];
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(2n)
    // S.C: O(2) = O(1)
    int maxProfit_tabulation_SO(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {   // or, for(int j = 0; j <= 1; j++)
                if(j == 1){
                    profit = max(-prices[i] + next[0], 0 + next[1]);
                } else {
                    profit = max(prices[i] + next[1], 0 + next[0]);
                }
                curr[j] = profit;
            }
            next = curr;
        }

        return next[1];
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << Solution().maxProfit_recursion(prices) << endl;
    cout << Solution().maxProfit_memoization(prices) << endl;
    cout << Solution().maxProfit_tabulation(prices) << endl;
    // cout << Solution().maxProfit_tabulation_SO(prices);

    return 0;
}
