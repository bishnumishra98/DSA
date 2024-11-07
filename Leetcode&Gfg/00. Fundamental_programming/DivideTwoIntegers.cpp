// Leetcode: 29. Divide Two Integers   --->   Given two integers dividend and divisor, divide two integers without
// using multiplication, division, and mod operator.
// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would
// be truncated to 8, and -2.7335 would be truncated to -2.
// Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer
// range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1,
// and if the quotient is strictly less than -231, then return -231.

// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.


#include <bits/stdc++.h>
using namespace std;

// Algorithm: 


class Solution {
public:
    // T.C: O(dividend)
    // S.C: O(1)
    int divide_bruteforce(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;   // edge case

        int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;

        long long abs_divisor = abs(divisor);
        long long abs_dividend = abs(dividend);
        long long sum = abs_divisor;
        int quotient = 0;        

        // Check how many divisors are required to make dividend or just less than dividend. That many divisors is the value of quotient.
        while(sum <= abs_dividend) {
            quotient++;
            sum += abs_divisor;
        }

        return quotient * sign;
    }

// ---------------------------------------------------------

    // Algorithm: 
    // T.C:
    // S.C:
    int divide(int dividend, int divisor) {
        
    }
};


int main() {
    int dividend = 7, divisor = -3;
    cout << Solution().divide_bruteforce(dividend, divisor) << endl;
    // cout << Solution().divide(dividend, divisor);

    return 0;
}
