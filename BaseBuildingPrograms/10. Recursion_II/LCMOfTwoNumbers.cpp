#include <iostream>
using namespace std;

// T.C: O(min(A, B))
// S.C: O(min(A, B))
int gcd(int A, int B) {
    // Euclid's algorithm to find gcd:
    // gcd(a, b) = gcd(a-b, a);   if a>b  (OR) if a>=b
    //           = gcd(b-a, b);   if b>=a (OR) if b>a
    // Note: You can even use '%' instead of '-' in above algorithm.
    // But '%' is computationally more expensive than '-', so we use '-'.

    // base case
    if(A == 0) return B;
    if(B == 0) return A;
    
    // processing
    if(A > B) {
        A = A - B;
    } else {   // if(B >=A)
        B = B - A;
    }
    
    // recursive relation
    gcd(A, B);
}

// T.C: O(min(A, B));   due to gcd()
// S.C: O(min(A, B));   due to gcd()
int lcm(int A, int B) {
    // lcm of 2 no.s = product of two numbers / hcf of 2 no.s
    return (A*B) / gcd(A, B);
}

int main() {
    cout << lcm(26, 40);

    return 0;
}
