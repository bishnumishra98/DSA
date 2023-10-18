// Understand SieveOfEratosthenes and SieveOfEratosthenesOptimised before solving this problem

#include <iostream>
#include <vector>
using namespace std;

// This problem can be solved in simple 2 step approach:
// 1) Create a sieveArray from 0 to right.
// 2) Mark all elements from 0 to left as false, i.e composite; and return the array.

// T.C: O(sqrt(right) + left);   as the first loop runs from 'i=2' to 'i*i<=right'.
// And the The second loop runs from 'i=0' to 'i<=left'
// S.C: O(right);   as the function creates a vector of size 'right+1'
vector<bool> createSieveArray_smallRange(int left, int right) {
    vector <bool> sieve(right+1, true);

    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<=right; i++) {
        if(sieve[i] == true) {
            int j = i*i;
            while(j<=right) {
                sieve[j] = false;   // marking mutiples of i as composite
                j = j + i;
            }
        }
    }

    // marking all elements of sieve till left as composite
    for(int i=0; i<=left; i++) {
        sieve[i] = false;
    }

    return sieve;
}

int main() {
    int left = 27, right = 97;

    vector<bool> sieve = createSieveArray_smallRange(left, right);

    for(int i=0; i<sieve.size(); i++) {
        if(sieve[i]) {   // sieve[i] contains true if i is prime number
            cout << i << " ";
        }
    }
    return 0;
}
