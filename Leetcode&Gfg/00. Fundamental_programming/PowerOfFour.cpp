// Leetcode: 342. Power of Four   --->   Given an integer n, return true if it is a power of four. Otherwise, return false.
// An integer n is a power of four, if there exists an integer x such that n == 4x.

// Example 1:
// Input: n = 16
// Output: true

// Example 2:
// Input: n = 5
// Output: false

// Example 3:
// Input: n = 1
// Output: true

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(1)
    // S.C: O(1)
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

int main() {
    int n = 16;

    cout << Solution().isPowerOfFour(n);

    return 0;
}
