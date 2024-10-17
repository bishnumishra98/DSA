// Fibonacci Series: 0 1 1 2 3 5 8 13 21 ...
// F(n) = F(n-1) + F(n-2), for n > 1.

#include <bits/stdc++.h>
using namespace std;

// Return nth number of fibonacci series
// i) Iterative approach
// T.C: O(n)
// S.C: O(1)
int fibo_ite(int n) {
    int n1 = 0;   // Initializing first element of fibonacci series
    int n2 = 1;   // Initializing second term of fibonacci series

    if(n <= 0) return 0;   // n <= 0 is invalid, so return 0
    if(n == 1) return n1;   // 1st element of fibonacci series is n1
    if(n == 2) return n2;   // 2nd element of fibonacci series is n2

    // Initializing 'n3' that will store sum of last two elements of the series
    int n3;   
    for(int i=3; i<=n; i++) {   // Iterating from the 3rd term to the nth term
        n3 = n2 + n1;   // n3 is sum of n2 and n1
        n1 = n2;   // Updating value of n1 with n2
        n2 = n3;   // Updating value of n2 with n3
    }

    return n3;   // return the nth number of fibonacci series that is stored in n3
}

// Return nth number of fibonacci series
// ii) Recursive approach
// T.C: O(2^n)
// S.C: O(n)
int fibo_rec(int n) {
    if(n<=0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;
    return fibo_rec(n-1) + fibo_rec(n-2);
}

// print the first n numbers of fibonacci series
// i) Iterative approach
// T.C: O(n)
// S.C: O(1)
void printFiboSeries_ite(int n) {
    if(n <= 0) return;

    if(n==1) cout << "0";
    else if(n==2) cout << "0 1";
    else {
        cout << "0 1";
        int n1 = 0;
        int n2 = 1;
        for(int i=3; i<=n; i++) {
            int n3 = n2 + n1;
            cout << " " << n3;
            n1 = n2;
            n2 = n3;
        }
    }
}

// print the first n numbers of fibonacci series
// ii) Recursive approach
// T.C: O(n)
// S.C: O(n)
void printFiboSeries_rec(int n, int n1 = 0, int n2 = 1) {
    if (n <= 0) return;
    if (n == 1) {
        cout << n1;
        return;
    }
    cout << n1 << " ";
    printFiboSeries_rec(n - 1, n2, n1 + n2);
}

int main() {
    // Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 ...

    // print the 7th number of fibonacci series
    cout << fibo_ite(7);   // o/p: 8
    cout << endl;
    cout << fibo_rec(7);   // o/p: 8
    cout << endl;

    // print the first 6 numbers of fibonacci series
    printFiboSeries_ite(6);
    cout << endl;
    printFiboSeries_rec(6);

    return 0;
}
