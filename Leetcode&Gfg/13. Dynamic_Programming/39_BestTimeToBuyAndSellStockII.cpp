// Leetcode: 122. Best Time to Buy and Sell Stock II   --->   You are given an integer array prices where
// prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the
// stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:
// 1 <= prices.length <= 3 * 10^4
// 0 <= prices[i] <= 10^4

// Algorithm: Its an easy problem. We have to try out all ways of buying and selling stocks using recursion.
//            Call a function f(index, buy) which returns the maximum profit that can be generated till the
//            index 'index', and buy parameter as 'buy'. 'buy' is either 1 which means you are allowed to buy
//            the stock on 'index'th day, or 0 which means are not allowed to buy the stock on 'index'th day,
//            i.e., you are allowed to sell the stock on 'index'th day.
//            Start recursive call initially from the 0th day with the liberty to buy it.
//
//            1. Base case: The base case is extremely straight forward. If the array 'prices' is over, no
//                          more profit can be made. Thus, return 0.
//
//            2. Recursive relation: There are two simple cases:
//
//               I.  If you are allowed to buy the stock, i.e., buy = 1:
//                   If you are allowed to buy the stock, it means you are not holding the stock currently.
//                   In this case, you can either choose to buy the stock on the current day or you can
//                   choose to buy the stock on some other day. The profit till the current day will be
//                   the maximum of either of the two cases.
//                   i.  If you choose to buy the stock on the current day, you loose the liberty to buy it
//                       on the next day, i.e., buy becomes 0. Also if you buy the stock on the current day,
//                       you got an expenditure of prices[index], thus debit this amount and call f(index + 1, 0).
//                   ii. If you choose not to buy the stock on the current day, you still have the liberty to
//                       buy it on the next day, i.e., buy remains 1. Also if you do not buy the stock on the
//                       current day, you did not get any expenditure, thus debit 0 and call f(index + 1, 1).
//
//               II. If you are not allowed to buy the stock, i.e., buy = 0:
//                   If you are not allowed to buy the stock, it means you are holding the stock currently.
//                   In this case, you can either choose to sell the stock on the current day or you can
//                   choose to sell the stock on some other day. The profit till the current day will be
//                   the maximum of either of the two cases.
//                   i.  If you choose to sell the stock on the current day, you get the liberty to buy it
//                       on the next day, i.e., buy becomes 1. Also if you sell the stock on the current day,
//                       you got an income of prices[index], thus credit this amount and call f(index + 1, 1).
//                   ii. If you choose not to sell the stock on the current day, you do not have the liberty to
//                       buy it on the next day as you will be still holding it, i.e., buy remains 0. Also if
//                       you do not sell the stock on the current day, you did not get any income, thus credit
//                       0 and call f(index + 1, 0).
//                   At the end, return the profit generated from the function f(index, buy).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n) {
        // Base case: When array is over, we cannot make any additional profit. Thus, return 0.
        if(index == n) return 0;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n), 0 + solve(index + 1, 1, prices, n));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, prices, n), 0 + solve(index + 1, 0, prices, n));
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
        if(index == n) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index + 1, 0, prices, n, dp), 0 + solve(index + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, prices, n, dp), 0 + solve(index + 1, 0, prices, n, dp));
        }

        return dp[index][buy] = profit;
    }

    // T.C: O(n * 2) = O(2n)
    // S.C: O(n * 2) for dp table + O(n) for recursion stack space = O(2n)
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
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case is optional because all cells are already initialized with 0.

        int profit = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {   // or, for(int j = 0; j <= 1; j++)
                if(j == 1){
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][1];
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
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << Solution().maxProfit_recursion(prices) << endl;
    cout << Solution().maxProfit_memoization(prices) << endl;
    cout << Solution().maxProfit_tabulation(prices) << endl;
    cout << Solution().maxProfit_tabulation_SO(prices);

    return 0;
}
