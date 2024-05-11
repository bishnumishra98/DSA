// Fibonacci Series: 0 1 1 2 3 5 8 13 21 ...
// F(n) = F(n-1) + F(n-2), for n > 1.

#include <bits/stdc++.h>
using namespace std;

// Return nth number of fibonacci series
// i) Iterative approach
int fibo_ite(int n) {
    int n0 = 0;
    int n1 = 1;

    if(n == 0) return n0;
    if(n == 1) return n1;

    int n2;
    for(int i=1; i<n; i++) {
        n2 = n1 + n0;
        n0 = n1;
        n1 = n2;
    }

    return n2;
}

// Return nth number of fibonacci series
// ii) Recursive approach
int fibo_rec(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo_rec(n-1) + fibo_rec(n-2);
}

// print the first n numbers of fibonacci series
// i) Iterative approach
void printFiboSeries_ite(int n) {
    if(n <= 0) return;

    if(n==1) cout << "0";
    else if(n==2) cout << "0 1";
    else {
        cout << "0 1";
        int n1 = 0;
        int n2 = 1;
        for(int i=2; i<n; i++) {
            int n3 = n2 + n1;
            cout << " " << n3;
            n1 = n2;
            n2 = n3;
        }
    }
}

// print the first n numbers of fibonacci series
// ii) Recursive approach
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
    cout << fibo_ite(7);   // o/p: 13
    cout << endl;
    cout << fibo_rec(7);   // o/p: 13
    cout << endl;

    // print the first 6 numbers of fibonacci series
    printFiboSeries_ite(6);
    cout << endl;
    printFiboSeries_rec(6);

    return 0;
}
