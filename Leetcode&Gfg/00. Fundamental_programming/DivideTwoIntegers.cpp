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
    // T.C: O(dividend)
    // S.C: O(1)
    int divide_bruteforce(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;   // edge case

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

// ---------------------------------------------------------

    // Illustration:
    // For any pair of dividend and divisor, first find the highest power of 2 upto which we can go. For example:
    //    If dividend = 22, divisor = 3, we can go max till 2 to the power 3.
    //    3 * 2^0 = 3   ->   dividend left = 22 - 3 = 19   ->   quotient = 1
    //    3 * 2^1 = 6   ->   dividend left = 19 - 6 = 13   ->   quotient = 2
    //    3 * 2^3 = 12  ->   dividend left = 13 - 12 = 1   ->   quotient = 4
    //    Thus, we cannot go beyond divisor * 2 to the power 3. And total quotient = 1 + 2 + 4 = 7. Thus, 22 divided
    //    by 3 gives quotient 7.

    // Algorithm:
    // 1. Loop while dividend is greater than divisor, and subtract 'divisor * 2^highest_power', from the dividend.
    //    And keep adding powers of 2 in a variable that will be quotient. Hence, in the next iteration, the dividend
    //    gets reduced by 'divisor * 2^highest_power'. Note that 2^power can be wriiten as 1 << power.
    // 2. At the end of loop, whatever is the quotient, return it with correct sign.

    // T.C: O((logN)^2)
    // S.C: O(1)
    int divide(int dividend, int divisor) {
        // Handle the case where dividend is equal to divisor
        if (dividend == divisor) return 1;

        long long int quotient = 0;
        int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1;

        // Convert both dividend and divisor to positive integers
        long long int n = abs(dividend), d = abs(divisor);

        // Perform the division: repeatedly subtract multiples of divisor from dividend until dividend becomes less than divisor.
        while(n >= d) {
            int power = 0;

            // Find the highest power of divisor upto which we can go
            while(n >= (d << (power + 1))) power++;   // while(n >= (d * pow(2, power+1))) power++;

            // Add 2^highest_power in quotient in cumulative way
            quotient += 1 << power;   // quotient += pow(2, power);

            // Reduce the dividend with 'd * 2^power'
            n -= d << power;   // n -= d * pow(2, power);
        }

        // Handle overflow case
        if(quotient == (1 << 31) && sign == 1) return INT_MAX;   // if(quotient == pow(2, 31) && sign == 1) return INT_MAX;
        if(quotient == (1 << 31) && sign == -1) return INT_MIN;   // if(quotient == pow(2, 31) && sign == -1) return INT_MIN;

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
