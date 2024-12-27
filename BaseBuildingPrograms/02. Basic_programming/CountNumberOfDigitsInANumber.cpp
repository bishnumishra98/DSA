#include <iostream>
#include <cmath>   // for log
using namespace std;

// T.C: O(logn)   base 10
// S.C: O(1)
int countNumberOfDigits_approach1(int n) {
    int digits = 0;
    while(n) {
        digits++;
        n = n / 10;
    }

    return digits;
}

// T.C: O(logn)   base 10
// S.C: O(1)
int countNumberOfDigits_approach2(int n) {
    if(n == 0) {
        return 1;
    }

    if(n < 0) {
        n = -n;   // because log does not works on -ve numbers
    }

    int ans = log(n) / log(10);   // or use 'log10(n)' directly.
    // Note that log returns float value, but store its integer part
    return ans + 1;
}


int main() {
    int n = -125;

    // cout << "No.of digits: " << countNumberOfDigits_approach1(n);

    cout << "No.of digits: " << countNumberOfDigits_approach2(n);

    return 0;
}