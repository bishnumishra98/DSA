// Given a non-negative integer x, return the square root of x rounded down to the user defined 
// no.of decimal point. Ex:-
// i/p: 64, 0,  o/p: 8
// i/p: 68, 3,  o/p: 8.246

// This problem is an extension of Leetcode: 69. Sqrt(x) ---> Given a non-negative integer x,
// return the square root of x rounded down to the nearest integer. Ex:-
// i/p: 64, o/p: 8
// i/p: 68, o/p: 8

#include<iostream>
using namespace std;

// integer square-root function
int mySqrt(int x) {
    int start = 0;
        int end = x;
        long long mid = start + (end - start)/2;
        int ans = -1;

        while(start <= end) {
            if(mid * mid > x) end = mid - 1;
            else if(mid * mid == x) return mid;
            else if(mid * mid < x) {
                ans = mid;
                start = mid + 1;
            }
                
            mid = start + (end - start) / 2;
        }

        return ans;
}


// T.C: O(precision * logn)
// S.C: O(1)
double mySqrt_Decimal(int n, int precision) {
    double sqrt = mySqrt(n);   // getting the nearest integer square-root in 'sqrt'
    
    double step = 1;

    // The number of times this loop runs is the number of precisions we get
    for(int i = 0; i < precision; i++) {
        step = step / 10;   // step size: in each iteration, step size will be 0.1, 0.01, 0.001, and so on.
        double j = sqrt;
        // sqrt of 68 came out to be 8. So try adding 0.1, and sqrt becomes 8.1. Again try adding 0.1, now sqrt becomes 8.2,
        // again try adding 0.1, now sqrt would become 8.3, but 8.3 * 8.3 is greater than 68, so exit the loop and sqrt remians 8.2.
        // Now in next iteration, add 0.01 to 8.2, and sqrt becomes 8.11. Again add 0.01 to 8.11, and sqrt becomes 8.12, and so on.
        while(j * j <= n) {
            sqrt = j;
            j += step;
        }
    }

    return sqrt;
}


int main() {
    int n = 68;
    int DecimalPointPrecision = 6;
    cout << "Square root of " << n << " is: " << mySqrt_Decimal(n, DecimalPointPrecision);

    return 0;
}
