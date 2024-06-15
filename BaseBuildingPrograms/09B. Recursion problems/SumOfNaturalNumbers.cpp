#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
int sumOfNaturalNumbers(int n) {
    if(n < 0) return -1;

    // base case
    if(n == 1) {
        return 1;
    }

    // recursive relation
    int ans = n + sumOfNaturalNumbers(n-1);

    return ans;
}

int main() {
    int n = 5;   // sum of all natural numbers till n

    cout << sumOfNaturalNumbers(n);

    return 0;
}