// GFG: Rod Cuttting   --->    Given a rod of length n inches and an array price[], where price[i] denotes the value
// of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling
// the pieces.
// Note: n = size of price, and price[] is 1-indexed array.

// Example 1:
// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

// Example 2:
// Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
// Output: 24
// Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

// Example 3:
// Input: price[] = [3]
// Output: 3
// Explanation: There is only 1 way to pick a piece of length 1.

// Constraints:
// 1 ≤ price.size() ≤ 10^3
// 1 ≤ price[i] ≤ 10^6

// Problem link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

// Algorithm: It is just the same problem as 'Leetcode&Gfg\13. Dynamic_Programming\23_KnapsackWithDuplicateItems.cpp'.
//            For example: price[] = {2,   5,   7,   8,   10}. Maximum sum of rod lengths we can take = price.size() = 5
//                            Index:  0    1    2    3    4
//                       Rod length:  1    2    3    4    5
//            We can take any lengths to make 5, like a combination of length 1, 1, 1, 1 and 1, i.e., price obtained
//            in this case would be price[0] + price[0] + price[0] + price[0] + price[0] = 2 + 2 + 2 + 2 + 2 = 10.
//            Another combination can be rod length 2 and 3, i.e., price[1] + price[2], and we will obtain a sum
//            of 5 + 7 = 12. There can be many more combinations, and we will find that 12 is the maximum price we
//            can obtain. And this is the value we must return.
//            The problem is same as knapsack with unlimited item supply, where capacity is price.size(), value of
//            items are given by price[] array, and weight of items are given by (index + 1) value.
//            Hence, call a recursive function solve(i, capacity) which returns the maximum amount possible to be
//            made till the index 'i', with a capacity 'capacity'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int capacity, vector<int>& price) {
        if(i == 0) {
            // At 0th index, rod length is 1. Thus, we return a value of '(capacity / 1) * price[0]'.
            // If capacity becomes 0, automatically '(0 / 1) * price[0]' will return 0.
            return capacity * price[0];
        }

        // At the current index, we have only two choices:
        // 1) Take the current rod with length 'i + 1'
        int take = INT_MIN;   // initially initialzed to 'INT_MIN', so that if 'i + 1 > capacity', the current rod cannot be taken
        if(i + 1 <= capacity) take = price[i] + solve(i, capacity - (i + 1), price);

        // 2) Not take the rod
        int notTake = 0 + solve(i - 1, capacity, price);

        return max(take, notTake);
    }

    // T.C: Exponential, i.e., much greater than O(2^n);   because there can be cases that we are standing at same index even after next function call
    // S.C: O(n);   recursion stack space
    int cutRod_recursion(vector<int> &price) {
        int n = price.size();
        return solve(n - 1, n, price);   // solve(n - 1, capacity, price)
    }

// -----------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------------------------
};

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << Solution().cutRod_recursion(price) << endl;

    return 0;
}