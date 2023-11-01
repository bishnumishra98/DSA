// gfg: Maximize The Cut Segments   --->   Given an integer N denoting the Length of a line segment.
// You need to cut the line segment in such a way that the cut length of a line segment each time is
// either x , y or z. Here x, y, and z are integers. After performing all the cut operations, your
// total number of cut segments must be maximum. Note: if no segment can be cut then return 0.

// Example 1:
// Input:
// N = 4
// x = 2, y = 1, z = 1
// Output: 4
// Explanation: Total length is 4, and the cut lengths are 2, 1 and 1. We can make maximum
// 4 segments each of length 1.

// Example 2:
// Input:
// N = 5
// x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two
// segments of lengths 3 and 2.

// Note: This problem is being solved with recursive for now just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
#include <limits.h>
using namespace std;

// T.C: 3^n
// S.C: O(n)
int maximizeTheCuts(int n, int x, int y, int z) {
    // base case
    if(n == 0) {
        return 0;
    }
    if(n < 0) {
        return INT_MIN;   // to avoid infinite recursion
    }

    // processing
    // cutting 'x' length from 'n', and leaving the rest on recursion
    int option1 = 1 + maximizeTheCuts(n-x, x, y, z);   // recursive relation

    // cutting 'y' length from 'n', and leaving the rest on recursion
    int option2 = 1 + maximizeTheCuts(n-y, x, y, z);   // recursive relation

    // cutting 'z' length from 'n', and leaving the rest on recursion
    int option3 = 1 + maximizeTheCuts(n-z, x, y, z);   // recursive relation

    return max(option1, max(option2, option3));
}

int main() {
    int N = 4;
    int x = 2, y = 1, z = 1;

    cout << maximizeTheCuts(N, x, y, z);

    return 0;
}