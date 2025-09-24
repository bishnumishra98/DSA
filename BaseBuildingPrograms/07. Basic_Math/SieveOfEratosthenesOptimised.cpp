#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// T.C: O(nlog(logn))
// S.C: O(n);   as the function creates a vector of size 'n+1'
vector<bool> createSieveArray(int n) {
    vector<bool> sieve(n + 1, true);

    sieve[0] = sieve[1] = false;

    // Optimization 2: Inner loop will never run more than √n times due to optimization 1.
    // Inshort, we are never going to check any value of i where i * i is greater than n. So,
    // there is no need of running the outer loop from 2 to n unnecessarily.
    for(int i = 2; i * i <= n; i++) {   // or, for(int i = 2; i <= sqrt(n); i++) {
    
        if(sieve[i] == true) {
            // Optimization 1: We will start marking numbers as composite from i * i instead of i * 2.
            // This is because all the smaller multiples of i will already be marked as composite
            // by smaller prime numbers. For example, if i = 5, then 2nd multiple of 5 is 10, which
            // will already be marked as composite by 2. Similarly, 3rd multiple of 5 is 15, which
            // will already be marked as composite by 3. So, there is no need to start from i * 2.
            int j = i * i;
            
            while(j <= n) {   // this loop runs <= √n times due to optimization 1. For example,
                             // for n = 23, we will enter this loop only twice (for i = 4 and 9).
                sieve[j] = false;
                j = j + i;
            }
        }
    }

    return sieve;   // sieve contains elements marked as true whose indexes are prime numbers
}

int main() {
    int n = 23;

    vector<bool> sieve = createSieveArray(n);

    for(int i = 0; i <= n; i++) {
        if(sieve[i]) {   // sieve[i] contains true if i is prime number
            cout << i << " ";
        }
    }

    return 0;
}
