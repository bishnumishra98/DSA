#include <iostream>
using namespace std;

// Euclid's algorithm to find gcd:
// ● gcd(A, B) = gcd(A - B, B) if A > B
// ● gcd(A, B) = gcd(A, B - A) if B > A
// ● If A = B, then gcd(A, B) = A or B, anything works
// ● gcd(A, 0) = A
// ● gcd(0, B) = B

// T.C: O(min(A, B))
// S.C: O(min(A, B))   due to recursion stack space
int gcd(int A, int B) {
    // Base cases
    if(B == 0) return A;
    if(A == 0) return B;

    if(A == B) return A;
    else if(A > B) return gcd(A - B, B);
    else return gcd(A, B - A);   // if(B > A)
}

// T.C: O(min(A, B));   due to gcd()
// S.C: O(min(A, B));   due to gcd()
int lcm(int A, int B) {
    // lcm of 2 no.s = product of two numbers / hcf of 2 no.s
    return (A * B) / gcd(A, B);
}

int main() {
    cout << lcm(4, 6);

    return 0;
}
