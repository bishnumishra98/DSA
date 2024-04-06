// Leetcode: 204. Count Primes   --->    Given an integer n, return
// the number of prime numbers that are strictly less than n.
// Example 1:
// Input: n = 10
// Output: 4

// Example 2:
// Input: n = 0
// Output: 0

// Example 3:
// Input: n = 1
// Output: 0

// Constraints: 0 <= n <= 5 * 10^6


#include <iostream>
#include <vector>
using namespace std;

// Almost similar to 'BaseBuildingPrograms\07. Basic_Maths\SieveOfEratosthenesOptimised.cpp'.

// T.C: O(nlog(logn))
// S.C: O(n)
int countPrimes(int n) {
    if(n <= 2) return 0;   // as prime numbers should be strictly less than n

    vector <bool> sieve(n, true);   // by default all numbers are prime

    sieve[0] = sieve[1] = false;   // mark sieve[0] and sieve[1] as false, i.e., marking 0 and 1 as composite

    for(int i=2; i*i<n; i++) {
        if(sieve[i]) {   // if its a prime number, mark its multiples as composite
            int j = i * i;
            while(j < n) {
                sieve[j] = false;
                j = j + i;   // j started from i*i, and going to next multiple of i
            }
        }
    }

    // The sieve of primes is ready. Thus, count how many are primes.
    int count = 0;
    for(int i=0; i<n; i++) {
        if(sieve[i]) count++;
    }

    return count;
}

int main() {
    int n = 23;
    cout << countPrimes(n);
    
    return 0;
}
