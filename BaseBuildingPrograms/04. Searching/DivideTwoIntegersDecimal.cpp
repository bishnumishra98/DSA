// Divide Two Integers ---> Given two integers
// dividend and divisor, divide two integers without using multiplication, division, and
// mod operator. Return the quotient rounded down to the user defined no.of decimal point.
// Ex:- i/p: 100, 30, 3,    o/p: 3.333

// This problem is an extension of Leetcode: 29. Divide Two Integers ---> Given two integers
// dividend and divisor, divide two integers without using multiplication, division, and
// mod operator. Return the integral part of quotient after dividing dividend by divisor.

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

// integer quotient function
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

// T.C: O(precision*log(dividend))
// S.C: O(1)
double divide_Decimal(int dividend, int divisor, int precision) {
    double quot = divide(dividend, divisor);   // getting the nearest integer quotient in 'quot'
    
    double step = 1;

    for(int i=0; i<precision; i++) {
        step = step / 10;
        double j = quot;

        while(j*divisor <= dividend) {
            quot = j;
            j += step;
        }
    }

    return quot;
}


int main() {
    int dividend = 100, divisor = 30, precision = 3;
    cout << divide_Decimal(dividend, divisor, precision);

    return 0;
}