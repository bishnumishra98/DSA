// leetcode: 322. Coin Change   --->   You are given an integer array coins representing coins
// of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of
// money cannot be made up by any combination of the coins, return -1.

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

// Note: This problem was solved with recursion, but now we will solve it by optimal approach with dynamic programming.
// DP PATTERN: Explore all possible ways

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int>& coins, int amount) {
    // Base case: if the amount is negative, it's not possible to form this amount with the given coins
    if (amount < 0) return INT_MAX;

    // Base case: if the amount is 0, no coins are needed to make this amount
    if (amount == 0) return 0;

    // Initialize the minimum number of coins needed to a large value
    int mini = INT_MAX;

    // Loop through each coin in the list of coins
    for (int i = 0; i < coins.size(); i++) {
        // Recursively solve for the amount minus the current coin
        int ans = solve(coins, amount - coins[i]);

        // If the result is not INT_MAX, it means a valid solution was found
        if (ans != INT_MAX) {
            // Update the minimum number of coins needed
            mini = min(mini, 1 + ans);   // Already 1 coin used, then searching the minimum no.of coins
                                        // for rest of the amount left. That's why wrote '1 + ans'.
        }
    }

    // Return the minimum number of coins needed to make the given amount
    return mini;
}

// T.C: O(n^m);   where n = coins.size(), and m = amount
// S.C: O(m)
int coinChange_recursion(vector<int>& coins, int amount) {
    int ans = solve(coins, amount);
    return ((ans == INT_MAX) ? -1 : ans);
}

// --------------------------------------------------------------------------------------------------------

int solve(vector<int>& coins, int amount, vector<int>& dp) {
    // Base case: if the amount is negative, it's not possible to form this amount with the given coins
    if (amount < 0) return INT_MAX;

    // Base case: if the amount is 0, no coins are needed to make this amount
    if (amount == 0) return 0;

    // Initialize the minimum number of coins needed to a large value
    int mini = INT_MAX;

    // If answer for minimum no.of coins required for building this 'amount' is already present in 'dp' array, return it.
    if(dp[amount] != -1) return dp[amount];

    // Loop through each coin in the list of coins
    for (int i = 0; i < coins.size(); i++) {
        // Recursively solve for the amount minus the current coin
        int ans = solve(coins, amount - coins[i], dp);

        // If the result is not INT_MAX, it means a valid solution was found
        if (ans != INT_MAX) {
            // Update the minimum number of coins needed
            mini = min(mini, 1 + ans);   // Since we are using 1 coin, then searching the minimum
            // no.of coins for the rest amount, add 1 to the result of the subproblem.
        }
    }

    dp[amount] = mini;   // store the minimum no.of coins required for building this 'amount' in dp[amount]
    return dp[amount];   // Return the minimum number of coins needed to make the given amount
}

// T.C: O(n*amount);    because each amount from 1 to amount is computed once, and for each amount, we consider all n coins.
// S.C: O(amount)
int coinChange_memoization(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = solve(coins, amount, dp);
    return ((ans == INT_MAX) ? -1 : ans);
}

// --------------------------------------------------------------------------------------------------------

// T.C: O(n*amount);    because each amount from 1 to amount is computed once, and for each amount, we consider all n coins.
// S.C: O(amount)
int coinChange_tabulation(vector<int>& coins, int amount) {
    // Step 1: Create a dp array of size 'amount + 1' with initial values 'INT_MAX'
    vector<int> dp(amount + 1, INT_MAX);

    // Step 2: Fill initial data in dp according to the base case.
    // Base case: if the amount is 0, no coins are needed to make this amount
    dp[0] = 0;

    // Step 3: Fill the rest of the dp array using iteration.
    // Building answers for coins required to build values from 1 to amount.
    for (int val = 1; val <= amount; val++) {
        // Loop through each coin in the list of coins
        for (int i = 0; i < coins.size(); i++) {
            // If val is greater than or equal to coins[i], we can consider this coin
            if (val - coins[i] >= 0) {
                // Solve for the amount minus the current coin
                int ans = dp[val - coins[i]];

                // If the ans is not INT_MAX, it means a valid solution was found
                if (ans != INT_MAX) {
                    // Update the dp value for the current amount
                    dp[val] = min(dp[val], 1 + ans);
                }
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means we couldn't form the amount with given coins
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


int main() {
    vector <int> coins = {1, 2, 5};
    int amount = 11;

    cout << "coinChange_recursion: " << coinChange_recursion(coins, amount) << endl;
    cout << "coinChange_memoization: " << coinChange_memoization(coins, amount) << endl;
    cout << "coinChange_tabulation: " << coinChange_tabulation(coins, amount) << endl;
    // Space optimization is not possible in this problem because the solution to each subproblem(amount)
    // depends on previous subproblems, which require access to the whole array of amounts.

    return 0;
}
