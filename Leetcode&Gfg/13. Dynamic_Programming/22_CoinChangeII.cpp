// Leetcode: 518. Coin Change II   --->   You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by
// any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Example 2:
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.

// Example 3:
// Input: amount = 10, coins = [10]
// Output: 1

// Algorithm: Again a simple problem. Its just a variant of 'Leetcode&Gfg\13. Dynamic_Programming\19_CoinChange.cpp'.
//            In that problem, we were asked to return the minimum number of coins needed to build the amount,
//            but here we are asked to return the number of ways to build the amount.
//            The algorithm almost remains the same, with some minor changes.
//            Start with the last coin and amount and go deeper into the recursive tree until 0th coin is reached.
//            1. Base case: If you reach 0th coin, and the 0th coin is divisible by amount, then the amount can be
//                          build. Thus return 1 stating that one path is found to build the amount, else return 0.
//            2. Recursive relation: There are only two choices in hand:
//                                   I.  Take the coin: Initially initialize to zero, as we assume no paths have
//                                                      been discovered yet to build the amount. If denomination
//                                                      of the coin is less than the amount, call the function
//                                                      with the same coin and decremented amount, as the same
//                                                      coin can be taken multiple times to build the amount,
//                                                      i.e., call solve(i, amount - coins[i]).
//                                   II. Not take the coin: If you choose not to take this coin, go to next index
//                                                          with the same amount, i.e., call solve(i - 1, amount)
//                                   At the end, just return the number of ways to build the amount from both ways,
//                                   i.e., sum of take and not take paths.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& coins, int amount) {
        if(i == 0) {
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }

        int take = 0;
        if(coins[i] <= amount) take = solve(i, coins, amount - coins[i]);
        int notTake = solve(i - 1, coins, amount);

        return take + notTake;
    }

    // T.C: Exponential, i.e., much greater than O(2^n);   because there can be cases that we are standing at same index even after next function call
    // S.C: O(amount);   recursion stack space
    int change_recursion(int amount, vector<int>& coins) {
        int n = coins.size();   // no.of coins
        return solve(n - 1, coins, amount);
    }

// --------------------------------------------------------------------------------------------------------

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(i == 0) {
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 0;
        if(coins[i] <= amount) take = solve(i, coins, amount - coins[i], dp);
        int notTake = solve(i - 1, coins, amount, dp);

        return dp[i][amount] = take + notTake;
    }

    // T.C: O(n*amount)
    // S.C: O(n*amount) for dp array + O(amount) for recursion stack space = O(n*amount)
    int change_memoization(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, coins, amount, dp);
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n*amount)
    // S.C: O(n*amount)
    int change_tabulation(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: At 0th index, if 0th coin is divisible by amount, store 1 denoting that 1 way is found
        //            to build the amount, else store 0.
        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0) dp[0][j] = 1;
            else dp[0][j] = 0;
        }

        // Fill rest of the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];
                int notTake = dp[i - 1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n*amount)
    // S.C: O(amount)
    int change_tabulation_SO(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case: At 0th index, if 0th coin is divisible by amount, store 1 denoting that 1 way is found
        //            to build the amount, else store 0.
        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0) prev[j] = 1;
            else prev[j] = 0;
        }

        // Fill rest of the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int take = 0;
                if(coins[i] <= j) take = curr[j - coins[i]];
                int notTake = prev[j];

                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};


int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << Solution().change_recursion(amount, coins) << endl;
    cout << Solution().change_memoization(amount, coins) << endl;
    cout << Solution().change_tabulation(amount, coins) << endl;
    cout << Solution().change_tabulation_SO(amount, coins);

    return 0;
}
