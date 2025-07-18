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

class Solution {
public:
    // T.C: O(abs(dividend) / abs(divisor))
    // S.C: O(1)
    int divide_bruteforce(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;

        // If we convert the negative value '-2147483648' to its absolute value,
        // its value will become outside the range of a 32-bit signed integer '2147483647'. 
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

// -----------------------------------------------------------------------------------------------------------------

    // Optimal algorithm:
    // 1. Convert both dividend and divisor to their absolute values for easier handling. Keep track of the final sign based
    //    on the original signs of dividend and divisor.
    // 2. Initialize the quotient as 0.
    // 3. Loop while the dividend is greater than or equal to the divisor:
    //    i.   Find the maximum power such that divisor × 2^(power + 1) (i.e., d << (power + 1) is less than or equal to the
    //         current dividend. This is the biggest chunk we can subtract from n.
    //    ii.  Subtract divisor × 2^power from the dividend, i.e., (n -= d << power).
    //    iii. Add 2^power (i.e., 1 << power) to the quotient.
    // 4. Return the final result with correct sign.

    // ● Dry run for dividend = 43, divisor = 3
    //
    // | Step | n  | power | chunk (d * 2^power) | quotient    | n -= chunk   |
    // | ---- | -- | ----- | ------------------- | ----------- | ------------ |
    // | 1    | 43 | 3     | 24                  | 2^3 = 8     | 43 - 24 = 19 |
    // | 2    | 19 | 2     | 12                  | 2^2 = 4     | 19 - 12 = 7  |
    // | 3    | 7  | 1     | 6                   | 2^1 = 2     | 7 - 6 = 1    |
    //                                         Total =   14
    //                                  Thus, 43 / 3 =   14

    // T.C: O(logN);   where N = abs(dividend)
    // S.C: O(1)
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;

        // Convert both dividend and divisor to positive integers
        long long n = abs((long)dividend), d = abs((long)divisor);

        long long quotient = 0;
        // Perform the division: repeatedly subtract multiples of divisor from dividend until dividend becomes less than divisor.
        while(n >= d) {
            int power = 0;

            // Find the highest power of divisor upto which we can go
            while(n >= (d << (power + 1))) power++;   // while(n >= (d * pow(2, power + 1))) power++;

            // Reduce the dividend with 'd * 2^power'
            n -= d << power;   // n -= d * pow(2, power);

            // Add 2^highest_power in quotient in cumulative way
            quotient += 1 << power;   // quotient += pow(2, power);
        }

        // Return the result with the appropriate sign.
        return quotient * sign;
    }
};


int main() {
    int dividend = 7, divisor = -3;
    cout << Solution().divide_bruteforce(dividend, divisor) << endl;
    cout << Solution().divide(dividend, divisor);

    return 0;
}
