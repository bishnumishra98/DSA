// leetcode: 322. Coin Change   --->   You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made
// up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Example 3:
// Input: coins = [1], amount = 0
// Output: 0

// Algorithm: This is also a simple problem. Greedy won't work due to lack of uniformity. Thus, try out all
//            possible ways using recursion.

//            Call a function solve(i, amount) which returns the minimum number of coins required to build the
//            amount from index 0 to index 'i'. Call the recursive function solve() from the last coin of
//            given input coins array and go deeper into the recursive tree until index 0.
//            1. The base cases of the recursion will be at index 0:
//               i)  If the current amount is divisible by denomination of the 0th coin, we will just return
//                   the number of coins needed to make that amount, i.e.,
//                   if(amount % coins[0] == 0) return amount / coins[0];
//               ii) If the current amount is not divisible by denomination of the 0th coin, we cannot make that
//                   amount. Thus, in this case return a large value like 1e9, so that it is never included
//                   while considering minimum number of coins. Note that returning 1e9 instead of INT_MAX
//                   is safer, because in anytime in the program something gets added to INT_MAX, you will get
//                   signed integer overflow error.
//            2. The recursive body will have only two simple take, not take options. At index 'i', you have only
//               two choices:
//               I)  Take the coin: If value of coin at 'i'th index is less than equal to the current amount,
//                                  take this coin, add 1 to the count and call recursion for next index with
//                                  decremented amount, i.e., 1 + solve(i - 1, amount - coins[i]);
//                                  BIG MISTAKE: ALERT !!!
//                                  The above equation would be correct if the number of coins were not unlimited.
//                                  But as the supply of coins are infinite, we do not move to next index with
//                                  decremented amount as it may happen that we can still use the same coin
//                                  multiple times to build the amount, i.e., the correct recursive equation will be:
//                                  1 + solve(i - 1, amount - coins[i]);
//                                  The point when this coin will no longer be considered is the point when amount
//                                  becomes greater than the coin's denomination, and in this case the program will
//                                  automatically go to the next line of code, i.e., the case when we do not take the coin.
//               II) Not take the coin: If you choose to not take the current coin, just call recursion for next index
//                                      with the amount, i.e., 0 + solve(i - 1, amount);
//            3. At the end, return the minimum value obtained from both the paths (take and not take).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& coins, int amount) {
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;   // don't return INT_MAX, otherwise 1 + INT_MAX will give signed integer overflow
        }

        // At the current index, we have two choices only:
        // 1. Take the coin
        int take = INT_MAX;   // initialized to 'INT_MAX' so that it is not considered if coins[i] > amount
        if(coins[i] <= amount) take = 1 + solve(i, coins, amount - coins[i]);

        // 2. Not take the coin
        int notTake = 0 + solve(i - 1, coins, amount);

        return min(take, notTake);
    }

    // T.C: Much greater than O(2^n);   because there can be cases that we are standing at same index even after
    // S.C: O(amount);   recursion stack space
    int coinChange_recursion(vector<int>& coins, int amount) {
        int n = coins.size();   // no.of coins
        int ans = solve(n - 1, coins, amount);
        if(ans >= 1e9) return -1;   // if its not possible to build the amount, the value of 'ans' will be '1e9'
        return ans;
    }

// --------------------------------------------------------------------------------------------------------

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX;
        if(coins[i] <= amount) take = 1 + solve(i, coins, amount - coins[i], dp);
        int notTake = 0 + solve(i - 1, coins, amount, dp);

        return dp[i][amount] = min(take, notTake);
    }

    // T.C: O(n*amount)
    // S.C: O(n*amount) for dp array + O(amount) for recursion stack space = O(n*amount)
    int coinChange_memoization(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n*amount)
    // S.C: O(n*amount)
    int coinChange_tabulation(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: At 0th index, if amount is divisible by denomination of 0th coin, store the number of coins
        //            required to make the amount, which is amount / denomination of 0th coin.
        //            Else if amount is not divisible by denomination of 0th coin, store '1e9' so that it is never
        //            included while considering minimum number of coins.
        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = 1e9;
        }

        // Fill rest of the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + dp[i][j - coins[i]];
                int notTake = 0 + dp[i - 1][j];

                dp[i][j] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }

// --------------------------------------------------------------------------------------------------------

    // T.C: O(n*amount)
    // S.C: O(amount)
    int coinChange_tabulation_SO(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0) prev[j] = j / coins[0];
            else prev[j] = 1e9;
        }

        // Fill rest of the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + curr[j - coins[i]];
                int notTake = 0 + prev[j];

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};


int main() {
    vector <int> coins = {1, 2, 5};
    int amount = 11;

    Solution sol;
    cout << sol.coinChange_recursion(coins, amount) << endl;
    cout << sol.coinChange_memoization(coins, amount) << endl;
    cout << sol.coinChange_tabulation(coins, amount) << endl;
    cout << sol.coinChange_tabulation_SO(coins, amount);

    return 0;
}
