// Given a non-negative integer x, return the square root of x rounded down to the user defined 
// no.of nearest decimal point. Ex:-
// i/p: 64, 0,  o/p: 8
// i/p: 68, 3,  o/p: 8.246

// This problem is an extension of Leetcode: 69. Sqrt(x) ---> Given a non-negative integer x,
// return the square root of x rounded down to the nearest integer. Ex:-
// i/p: 64, o/p: 8
// i/p: 68, o/p: 8

// This problem is an implementation of binary search, and search space concept.

// integer answer function
int mySqrt(int x) {
    int start = 0;
    int end = x;   // Our search space is going to be from start, i.e. 0 to end, i.e. x.
    long long mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {
        if((mid*mid) == x) {   // if mid is the answer
            return mid;
        } else if((mid*mid) < x) {   // store ans and go to right
            // if '(mid*mid) < x', then 'mid' may be a potential answer for square root of x.
           // That's why we are storing its value before going to further step. If 'x' was a perfect
          // square, then storing 'mid' was not necessary. Dry run for better understanding.
            ans = mid;
            start = mid + 1;
        } else {   // go to left
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }

    return ans;
}

#include<iostream>
using namespace std;

// T.C: O(precision*logn)
// S.C: O(1)
double mySqrt_Decimal(int n, int precision) {
    double ans = mySqrt(n);   // getting the integer answer in 'ans'
    
    double step = 1;

    for(int i=0; i<precision; i++) {
        step = step / 10;
        double j = ans;

        while(j*j <= n) {
            ans = j;
            j += step;
        }
    }

    return ans;
}


int main() {
    int n = 68;
    int DecimalPointPrecision = 6;
    cout << "Square root of " << n << " is: " << mySqrt_Decimal(n, DecimalPointPrecision);

    return 0;
}