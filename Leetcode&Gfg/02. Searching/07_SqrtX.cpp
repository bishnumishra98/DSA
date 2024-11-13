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
// 1. As square root lies in the range 0 to x, the initial search space will also be the same i.e., start(0) to end(x);
//    and the mid will be as usual (start + end) / 2.
// 2. Consider 'mid' as square root, and check if mid * divisor is greater than, equal to or less than x, until start <= end.
//    CASE I:   If mid * divisor > x, then shift the search space towards left, i.e., end = mid - 1
//    CASE II:  If mid * divisor == x, then the square root is found. Hence, return mid.
//    CASE III: If mid * divisor < x, then store the 'mid' as it can be a potential square root, so store it
//              in any variable say 'ans', so that its value is not lost if loop terminates in next iteration.
//              Then shift the search space towards right, i.e., start = mid + 1.
//              If the loop (start <= end) terminates in the next iteration, the 'ans' will be containing the
//              absolute value of square root. So return 'ans' after the loop ends.
//              Extra info: If x was a perfect square, it was not required to store the 'mid' in any variable, as
//                          the program would have returned the square root from CASE II, before the loop terminates.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(logx)
    // S.C: O(1)
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
};


int main() {
    int n = 8;
    cout << "Square root of " << n << " is: " << Solution().mySqrt(n);

    return 0;
}
