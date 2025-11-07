// Find x to the power n, where x and n can be positive or negative integers.

// Example 1:
// Input: x = 10, n = 3
// Output: 1000

// Example 2:
// Input: x = 10, n = -2
// Output: 0.01

// Example 3:
// Input: x = -10, n = 2
// Output: 100

// Example 4:
// Input: x = -10, n = -2
// Output: 0.01

// Algorithm: We will use the concept of divide and conquer to solve this problem.
// If n is positive:
// ▪ If n is even, then x^n = x^(n/2) * x^(n/2)
// ▪ If n is odd, then x^n = x^(n/2) * x^(n/2) * x
// ▪ If n is 0, then x^n = 1

// If n is negative:
// ▪ If n is even, then x^n = x^(n/2) * x^(n/2)
// ▪ If n is odd, then x^n = (x^(n/2) * x^(n/2)) / x
// ▪ If n is 0, then x^n = 1

#include <iostream>
using namespace std;

// This code works for only positive values of x and n.
// T.C: O(logn)
// S.C: O(logn)   due to recursive stack space
int xToThePowern_positive(int x, int n) {
    if(n == 0) return 1;
    
    int ans = xToThePowern_positive(x, n / 2);
    if(n & 1) {   // if n is odd
        ans = ans * ans * x;
    } else {   // if n is even
        ans = ans * ans;
    }
    
    return ans;
}


// This code works for both positive and negative values of x and n.
// T.C: O(logn)
// S.C: O(logn)   due to recursive stack space
double xToThePowern(int x, int n) {
    if(n == 0) return 1.0;

    double ans = xToThePowern(x, n / 2);
    if(n & 1) {
        if(n > 0) return ans * ans * x;
        else return (ans * ans) / x;   // handle negative power
    } else {
        return ans * ans;
    }
}


int main() {
    int x1 = 10;
    int n1 = 3;
    cout << xToThePowern_positive(x1, n1) << endl;   // o/p: 1000

    int x2 = 10;
    int n2 = -2;
    cout << xToThePowern(x2, n2) << endl;   // o/p: 0.01

    int x3 = -10;
    int n3 = 2;
    cout << xToThePowern(x3, n3) << endl;   // o/p: 100

    int x4 = -10;
    int n4 = -2;
    cout << xToThePowern(x4, n4);   // o/p: 0.01

    return 0;
}
