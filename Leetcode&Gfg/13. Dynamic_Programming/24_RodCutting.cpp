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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod_recursion(vector<int> &price) {
        
    }
};

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << Solution().cutRod_recursion(price) << endl;

    return 0;
}