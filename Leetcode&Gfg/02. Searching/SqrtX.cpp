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

// Algorithm: We will implementation binary search with search space concept. Algorithm is very simple:
// 1. As quotient lies in the range 0 to x, the initial search space will also be the same i.e., start(0) to end(x);
//    and the mid will be as usual (start + end) / 2.
// 2. Consider 'mid' as quotient, and check if mid * divisor is greater than, equal to or less than x, until start <= end.
//    CASE I:   If mid * divisor > x, then shift the search space towards left, i.e., end = mid - 1
//    CASE II:  If mid * divisor == x, then the quotient is found. Hence, return mid.
//    CASE III: If mid * divisor < x, then store the 'mid' as it can be a potential quotient, so store it
//              in any variable say 'ans', so that its value is not lost if loop terminates in next iteration.
//              Then shift the search space towards right, i.e., start = mid + 1.
//              If the loop (start <= end) terminates in the next iteration, the 'ans' will be containing the
//              absolute value of quotient. So return 'ans' after the loop ends.
//              Extra info: If x was a perfect square, it was not required to store the 'mid' in any variable, as
//                          the program would have returned the quotient from CASE II, before the loop terminates.

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
