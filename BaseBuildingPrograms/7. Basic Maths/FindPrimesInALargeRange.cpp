// Understand SieveOfEratosthenes and SieveOfEratosthenesOptimised before solving this problem

// The stack sizes in memory is typically between 1MB to 8MB.

// Thus, if we create a 10^6 size array of type double, it would occupy 8,000,000 bytes, i.e 8MB of space.
// So allocating this huge size array in our program may result in stack overflow error.

// Here is a table summarizing the practical limits on the maximum size of an array in Linux,
// for both 32-bit and 64-bit systems:

// Data type	         Scope	      32-bit system	    64-bit system
// -------------------------------------------------------------------
// int, double, char  	 Global	      10^6	            10^7
// bool	                 Global	      10^6	            10^8
// int, double, char  	 Function	  10^6	            10^6
// bool	                 Function	  10^6	            10^7

// It is important to note that these are just practical limits. In some cases, it may be
// possible to create larger arrays, but this may require special techniques or privileges.


// Thus, it is not possible to find primes if the range is large, i.e >=10^6.

// Thus, we have to apply a different approach.



#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> createSieveArray(int n) {
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for (int i=2; i*i<=n; i++) {
        if (sieve[i] == true) {
            int j = i * i;
            while (j<=n) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    return sieve;
}

// T.C:
// S.C:
vector<bool> createSieveArray_largeRange(int L, int R) {
    // Getting prime marking array to be used to mark primes in segmented sieve.
    vector<bool> sieve = createSieveArray(sqrt(R));

    vector<int> basePrimes;

    for (int i = 0; i < sieve.size(); i++) {
        if(sieve[i]) {
            basePrimes.push_back(i);
        } 
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1) {
        segSieve[0] = false;
    }

    for (auto prime : basePrimes) {
        int first_mul = (L / prime) * prime;
        first_mul = first_mul < L ? first_mul + prime : first_mul;
        int j = max(first_mul, prime * prime);
        while (j<=R) {
            segSieve[j-L] = false;
            j += prime;
        }
    }
    
    return segSieve;
}

int main() {
    int left = 110, right = 130;

    vector<bool> segsieve = createSieveArray_largeRange(left, right);

    for (int i=0; i<segsieve.size(); i++) {
        if(segsieve[i]) {
            cout << left + i << " ";
        }
    }

    return 0;
}