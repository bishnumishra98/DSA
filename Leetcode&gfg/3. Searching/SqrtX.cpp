// Leetcode: 69. Sqrt(x) ---> Given a non-negative integer x, return the square root of x
// rounded down to the nearest integer. Ex:-
// i/p: 64, o/p: 8
// i/p: 68, o/p: 8

// This problem is an implementation of binary search.

#include<iostream>
using namespace std;

// T.C: O(logx)
// S.C: O(1)
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
           // That's why we are storing it, before going to further step. If 'x' was a perfect
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

int main() {
    int n = 64;
    cout << "Square root of " << n << " is: " << mySqrt(n);

    return 0;
}