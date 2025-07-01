// Leetcode: 309. Best Time to Buy and Sell Stock with Cooldown   --->   You are given an array prices where
// prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one
// and sell one share of the stock multiple times) with the following restrictions:
// ● After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Example 2:
// Input: prices = [1]
// Output: 0

// Algorithm: This is also just an extension of the previous problem '39_BestTimeToBuyAndSellStockII.cpp'.
//            It is also a very simple problem. The only difference in this problem is that we are not allowed
//            to buy the stock on 'i + 1'th day, if we sold it on 'i'th day, i.e., there has to be a cooldown
//            period of atleast 1 day. The algorithm is exactly the same as in the previous problem, the
//            difference is that after selling the stock, we will call the recursive function with the parameter
//            as 2 days ahead. One more difference will be in the base case. Earlier the base case was
//            if(index == n), but here as we are jumping to 'index + 2', it may happen that we land on the index
//            'n + 1'. Thus, to avoid any error, write if(index >= n).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n) {
        // Base case: When array is over, we cannot make any additional profit. Thus, return 0.
        if(index >= n) return 0;   // due to 'index + 2', we can go to 'n + 1' also, thus instead of '==', write '>='

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n), 0 + solve(index + 1, 1, prices, n));
        } else {
            profit = max(prices[index] + solve(index + 2, 1, prices, n),   // moving 2 days ahead after selling
                        0 + solve(index + 1, 0, prices, n));
        }

        return profit;
    }

    // T.C: O(2^n);   because at each step we have two choices either take the stock or not take the stock
    // S.C: O(n) recursion stack space
    int maxProfit_recursion(vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, prices, n);
    }

// -------------------------------------------------------------------------------------------------------

    int solve(int index, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if(index >= n) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, dp), 0 + solve(index + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[index] + solve(index + 2, 1, prices, n, dp), 0 + solve(index + 1, 0, prices, n, dp));
        }

        return dp[index][buy] = profit;
    }

    // T.C: O(n * 2) = O(2n)
    // S.C: O(n * 2) for dp table + O(n) for recursion stack space = O(3n)
    int maxProfit_memoization(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp);
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(2n)
    // S.C: O(2n)
    int maxProfit_tabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));   // rows must be 'n + 2' because we are dealing with dp[i + 2][...]

        // Base case is optional because all cells are already initialized with 0.

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 1){
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    profit = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][1];
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(2n)
    // S.C: O(6) = O(1)
    int maxProfit_tabulation_SO(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0), nextToNext(2, 0);

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 1){
                    profit = max(-prices[i] + next[0], 0 + next[1]);
                } else {
                    profit = max(prices[i] + nextToNext[1], 0 + next[0]);
                }
                curr[j] = profit;
            }
            nextToNext = next;
            next = curr;
        }

        return next[1];
    }
};


int main() {
    vector<int> prices = {1, 2, 3, 0, 2};

    cout << Solution().maxProfit_recursion(prices) << endl;
    cout << Solution().maxProfit_memoization(prices) << endl;
    cout << Solution().maxProfit_tabulation(prices) << endl;
    cout << Solution().maxProfit_tabulation_SO(prices);

    return 0;
}
