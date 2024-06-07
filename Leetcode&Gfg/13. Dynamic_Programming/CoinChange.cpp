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
// PATTERN: Exploring all possible ways

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
// S.C: O(n)
int coinChange_recursion(vector<int>& coins, int amount) {
    int ans = solve(coins, amount);
    return ((ans == INT_MAX) ? -1 : ans);
}

// --------------------------------------------------------------------------------------------------------





int main() {
    vector <int> coins = {1, 2, 5};
    int amount = 11;

    cout << "coinChange_recursion: " << coinChange_recursion(coins, amount) << endl;

    return 0;
}