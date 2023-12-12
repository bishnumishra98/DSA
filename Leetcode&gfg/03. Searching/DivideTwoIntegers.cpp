// Leetcode: 29. Divide Two Integers ---> Given two integers dividend and divisor,
// divide two integers without using multiplication, division, and mod operator.
// Return the integral part of quotient after dividing dividend by divisor.

// Constraints -> -2^31 <= dividend, divisor <= 2^31 - 1, divisor != 0

// This problem is an implementation of binary search, and search space concept.

#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

int correctSign(int dividend, int divisor) {
    if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) {
        return -1;
    }
    return 1;
}

// Leetcode given function
// T.C: O(log(dividend))
// S.C: O(1)
int divide(int dividend, int divisor) {
    // If we convert the negative value '-2147483648' to its absolute value,
   // its value will become outside the range of a 32-bit signed integer '2147483647'. 
    if((dividend == INT_MIN) && (divisor==-1)) {
        return INT_MAX;
    } else if((dividend == INT_MIN) && (divisor==1)) {
        return INT_MIN;
    }

    int sign = correctSign(dividend, divisor);

    // making sure our binary search algorithm gets only positive integers
    long long long_dividend = abs(dividend);
    long long long_divisor = abs(divisor);

    long long start = 0;
    long long end = long_dividend;   // Our search space is going to be from start to end.
    long long mid = start + (end - start)/2;   // consider mid as quotient.
    long long ans = -1;

    while(start <= end) {
        if((mid*long_divisor) == long_dividend) {   // if mid is the quotient
            return mid*sign;
        } else if((mid*long_divisor) < long_dividend) {   // store ans and go to right
            ans = mid;   // if '(mid*long_divisor) < long_dividend', then 'mid' may be a potential
            // answer for quotient. That's why we are storing its value before going to
           // further step. If 'long_dividend' was a perfect square, then storing 'mid' was not
          // necessary. Dry run for better understanding.
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans*sign;   // returning the answer with correct sign
}


int main() {
    int dividend = 2147483647, divisor = 2;
    cout << divide(dividend, divisor);

    return 0;
}