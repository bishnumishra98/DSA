// Leetcode: 121. Best Time to Buy and Sell Stock   --->   You are given an array prices where prices[i] is the
// price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the
// future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:
// 1 <= prices.length <= 10^5
// 0 <= prices[i] <= 10^4

// Algorithm: Extremely simple problem. Infact dynamic programming is not even required for this problem. It falls
//            under the tag of 'Dynamic Programming' because we are remembering previous states.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(1)
    int maxProfit_bruteforce(vector<int>& prices) {
        int maxProfit = 0;

        for(int i = 0; i < prices.size() - 1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }

// --------------------------------------------------------------------------------------------------------------

    // Optimal approach: The idea is to keep a track of lowest buying price of the stock and calculate the profit
    //                   at each step. Store the maximum profit encountered so far. If the current price is lower than
    //                   the lowest buying price, update the lowest buying price. This way we ensure that we are always
    //                   buying at the lowest price and selling at the current price to maximize profit.
    // T.C: O(n)
    // S.C: O(1)
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - buyPrice;
            maxProfit = max(maxProfit, profit);
            buyPrice = min(buyPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << Solution().maxProfit_bruteforce(prices) << endl;
    cout << Solution().maxProfit(prices);

    return 0;
}
