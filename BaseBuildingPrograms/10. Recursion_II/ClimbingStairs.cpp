// leetcode: 70. Clibing Stairs   --->   You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top ?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Algorithm: Think from top to bottom. If we are at step 'n', we can at max come down to 'n-1'th step or 'n-2'th step.
//            This means that no.of ways for step 'n' depends on no.of ways for step 'n-1' and 'n-2'.
//            Thus, recursive relation for climbing n stairs will be: f(n) = f(n-1) + f(n-2).

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
using namespace std;

int climbStairs(int n) {
    // Base case
    if(n <= 2) return n;

    // recursive relation
    int ans = climbStairs(n-1) + climbStairs(n-2);

    return ans;
}

int main() {
    int n = 4;

    cout << climbStairs(n);

    return 0;
}