// Leetcode: 714. Best Time to Buy and Sell Stock with Transaction Fee   --->   You are given an array prices
// where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay
// the transaction fee for each transaction.
// Note:
// ● You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// ● The transaction fee is only charged once for each stock purchase and sale.
 

// Example 1:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// Example 2:
// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

// Algorithm: Again a joke problem. Again the same extension of the problem '39_BestTimeToBuyAndSellStockII.cpp'.
//            Again an extremely simple problem. Here a transaction fee has to be paid while selling a stock.
//            So just deduct the transaction fee from the profit when you sell the stock.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n, int fee) {
        // Base case: When array is over, we cannot make any additional profit. Thus, return 0.
        if(index == n) return 0;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, fee), 0 + solve(index + 1, 1, prices, n, fee));
        } else {
            profit = max(prices[index] - fee + solve(index + 1, 1, prices, n, fee),   // just deduct the transaction fee while selling the stock
                        0 + solve(index + 1, 0, prices, n, fee));
        }

        return profit;
    }

    // T.C: O(2^n);   because at each step we have two choices either take the stock or not take the stock
    // S.C: O(n) recursion stack space
    int maxProfit_recursion(vector<int>& prices, int fee) {
        int n = prices.size();
        return solve(0, 1, prices, n, fee);
    }

// -------------------------------------------------------------------------------------------------------

    int solve(int index, int buy, vector<int>& prices, int n, vector<vector<int>>& dp, int fee) {
        if(index == n) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, dp, fee), 0 + solve(index + 1, 1, prices, n, dp, fee));
        } else {
            profit = max(prices[index] - fee + solve(index + 1, 1, prices, n, dp, fee),
                        0 + solve(index + 1, 0, prices, n, dp, fee));
        }

        return dp[index][buy] = profit;
    }

    // T.C: O(n * 2) = O(2n)
    // S.C: O(n * 2) for dp table + O(n) for recursion stack space = O(3n)
    int maxProfit_memoization(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp, fee);
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(2n)
    // S.C: O(2n)
    int maxProfit_tabulation(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case is optional because all cells are already initialized with 0.

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 1){
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    profit = max(prices[i] - fee + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][1];
    }

// -------------------------------------------------------------------------------------------------------

    // T.C: O(2n)
    // S.C: O(4) = O(1)
    int maxProfit_tabulation_SO(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 1){
                    profit = max(-prices[i] + next[0], 0 + next[1]);
                } else {
                    profit = max(prices[i] - fee + next[1], 0 + next[0]);
                }
                curr[j] = profit;
            }
            next = curr;
        }

        return next[1];
    }
};


int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << Solution().maxProfit_recursion(prices, fee) << endl;
    cout << Solution().maxProfit_memoization(prices, fee) << endl;
    cout << Solution().maxProfit_tabulation(prices, fee) << endl;
    cout << Solution().maxProfit_tabulation_SO(prices, fee);

    return 0;
}
