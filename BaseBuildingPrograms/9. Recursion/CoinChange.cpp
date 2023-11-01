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

// Note: This problem is being solved with recursive for now just to understand recursion better.
// But optimal approach will be solved by dynamic programming.


#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int>& coins, int amount) {
    //base case
    if(amount == 0 ) {
        return 0;
    }

    if(amount < 0 )
        return INT_MAX;

    int mini = INT_MAX;
    
    for(int i=0; i<coins.size(); i++) {
        int coin = coins[i];

        //current coin ko sirf tabhi use krenge jab uski value <= amount hogi 
        if(coin <= amount) {
            int recAns = solve(coins, amount - coin);
            if(recAns != INT_MAX){
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }    
        }
        
    }
    return mini;
}

// T.C: O(n^m);   where n = coins.size(), and m = amount
// S.C: O(n)
int coinChange(vector<int>& coins, int amount) {
    int ans = solve(coins, amount);
    return ((ans == INT_MAX) ? -1 : ans);
}

int main() {
    vector <int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount);

    return 0;
}