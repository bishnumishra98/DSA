// THIS PROBLEM IS A CLASSICAL BIT MANIPULATION PROBLEM 'Leetcode&Gfg\00. Fundamental_programming\DivideTwoIntegers.cpp',
// BUT IT CAN ALSO BE SOLVED USING BINARY SEARCH PROVIDED A RULE SHALL BE BREAKED AS WE USE MULTIPLICATION IN BINARY SEARCH.

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


#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

// Algorithm: We will implementation binary search with search space concept. Algorithm is very simple:
// 1. As quotient lies in the range 0 to dividend, the initial search space will also be the same i.e., start(0) to end(dividend);
//    and the mid will be as usual (start + end) / 2.
// 2. Consider 'mid' as quotient, and check if mid * divisor is greater than, equal to or less than dividend, until start <= end.
//    CASE I:   If mid * divisor > dividend, then shift the search space towards left, i.e., end = mid - 1
//    CASE II:  If mid * divisor == dividend, then the quotient is found. Hence, return mid.
//    CASE III: If mid * divisor < dividend, then store the 'mid' as it can be a potential quotient, so store it
//              in any variable say 'ans', so that its value is not lost if loop terminates in next iteration.
//              Then shift the search space towards right, i.e., start = mid + 1.
//              If the loop (start <= end) terminates in the next iteration, the 'ans' will be containing the
//              absolute value of quotient. So return 'ans' after the loop ends.
//              Extra info: If dividend was a perfect square, it was not required to store the 'mid' in any variable, as
//                          the program would have returned the quotient from CASE II, before the loop terminates.


class Solution {
public:
    // T.C: O(log(dividend))
    // S.C: O(1)
    int divide(int dividend, int divisor) {
        // If we convert the negative value '-2147483648' to its absolute value,
        // its value will become outside the range of a 32-bit signed integer '2147483647'. 
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        int sign = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;

        // Making sure our binary search algorithm gets only positive integers
        long long abs_dividend = abs(dividend);
        long long abs_divisor = abs(divisor);

        // Binary search algorithm:
        long long start = 0;
        long long end = abs_dividend;
        long long mid = start + (end - start)/2;
        long long ans = 0;

        while(start <= end) {
            if(mid * abs_divisor > abs_dividend) end = mid - 1;
            else if(mid * abs_divisor == abs_dividend) return mid * sign;   // returning quotient with correct sign
            else if(mid * abs_divisor < abs_dividend) {
                ans = mid;
                start = mid + 1;
            }

            mid = start + (end - start) / 2;
        }

        return ans * sign;   // returning quotient with correct sign
    }
};


int main() {
    int dividend = 7, divisor = -3;
    cout << Solution().divide(dividend, divisor);

    return 0;
}
