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


// T.C: O(precision*logn)
// S.C: O(1)
double mySqrt_Decimal(int n, int precision) {
    double sqrt = mySqrt(n);   // getting the nearest integer square-root in 'sqrt'
    
    double step = 1;

    for(int i = 0; i < precision; i++) {
        step = step / 10;
        double j = sqrt;

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
