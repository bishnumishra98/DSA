// Leetcode: 69. Sqrt(x)   --->   Given a non-negative integer x, return the square root of x rounded down to the
// nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.
// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
// Example 1:
// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

// Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
};


int main() {
    int n = 8;
    cout << "Square root of " << n << " is: " << Solution().mySqrt(n);

    return 0;
}
