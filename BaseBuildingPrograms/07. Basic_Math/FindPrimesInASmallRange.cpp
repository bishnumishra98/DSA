// Understand SieveOfEratosthenes and SieveOfEratosthenesOptimised before solving this problem

// Problem: Given two integers left and right, return a list of all integers in the range
// [left, right] inclusive that are prime. You may return the answer in any order.

// Example 1:
// Input: left = 10, right = 20
// Output: [11,13,17,19]

// Example 2:
// Input: left = 2, right = 17
// Output: [2,3,5,7,11,13,17]

#include <iostream>
#include <vector>
using namespace std;

// Algorithm: This problem can be solved in simple 2 step approach:
// 1. Create a sieveArray from 0 to right.
// 2. Mark all elements from 0 to left - 1 as false, i.e., composite.
// 3. Return the sieveArray.

// T.C: O(sqrt(right) + left);   as the first loop runs from 'i=2' to 'i*i<=right'.
// And the The second loop runs from 'i=0' to 'i<=left'
// S.C: O(right);   as the function creates a vector of size 'right+1'
vector<bool> createSieveArray_smallRange(int left, int right) {
    vector<bool> sieve(right + 1, true);

    sieve[0] = sieve[1] = false;

    for(int i = 2; i * i <= right; i++) {
        if(sieve[i]) {
            int j = i * i;
            while(j <= right) {
                sieve[j] = false;   // marking mutiples of i as composite
                j = j + i;
            }
        }
    }

    // Marking all elements of sieve till left as composite
    for(int i = 0; i < left; i++) {
        sieve[i] = false;
    }

    return sieve;
}

int main() {
    int left = 2, right = 17;

    vector<bool> sieve = createSieveArray_smallRange(left, right);

    for(int i = 0; i < sieve.size(); i++) {
        if(sieve[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
