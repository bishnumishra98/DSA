// This problem is an extension of Leetcode: 29. Divide Two Integers
// Solve this problem after you completed Binary Search module.

// Example 1:
// Input:
// dividend = 22, divisor = 3, precision = 3
// Output:
// 7.33

// This problem is solved using implementation of binary search, and search space concept.

#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(dividend == INT_MIN && divisor == 1) return INT_MIN;

    int sign = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;

    long long abs_dividend = abs(dividend);
    long long abs_divisor = abs(divisor);

    long long start = 0;
    long long end = abs_dividend;
    long long mid = start + (end - start)/2;
    long long ans = 0;

    while(start <= end) {
        if(mid * abs_divisor > abs_dividend) end = mid - 1;
        else if(mid * abs_divisor == abs_dividend) return mid * sign;
        else if(mid * abs_divisor < abs_dividend) {
            ans = mid;
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans * sign;
}

// T.C: O(precision*log(dividend))
// S.C: O(1)
double divide_decimal(int dividend, int divisor, int precision) {
    double quot = divide(dividend, divisor);   // getting the nearest integer quotient in 'quot'
    
    double step = 1;

    for(int i = 0; i < precision; i++) {
        step = step / 10;   // 'step' will decrease by a factor of 10 in each iteration (for ex: 0.1, 0.01, 0.001)
        double j = quot;

        while(j * divisor <= dividend) {
            quot = j;
            j += step;
        }
    }

    return quot;
}


int main() {
    int dividend = 22, divisor = 3, precision = 2;
    cout << "ans: " << divide_decimal(dividend, divisor, precision);

    return 0;
}
