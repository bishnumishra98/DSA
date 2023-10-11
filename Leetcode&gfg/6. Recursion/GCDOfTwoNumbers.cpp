// gfg: GCD of two numbers

#include <iostream>
using namespace std;

// T.C: O(min(A, B))
// S.C: O(min(A, B))
int gcd(int A, int B) { 
    // gcd(a, b) = gcd(a-b, a);   if a>b
    //           = gcd(b-a, b);   if b>=a
    // Note: You can even use '%' instead of '-' in above algorithm.
    // But '%' is computationally more expensive than '-', so we use '-'.

    if(A == 0) return B;   // base condition
    if(B == 0) return A;   // base condition
    
    if(A > B) {
        A = A - B;
    } else {   // if(B >=A)
        B = B - A;
    }
    
    gcd(A, B);   // recursive call
}

int main() {
    cout << gcd(72, 120);

    return 0;
}