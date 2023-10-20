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

// Thus, we have to apply a different approach. Let's consider a range of 110 to 130 for
// better understanding. Here, L=110 and R=130. The sieve of numbers representing 110, 111,
// 112, ..., 130 shall be called segmented sieve. The approach states that:

// 1) Generate all primes responsible to mark the segmented sieve(110-130). The base primes will be the
// prime numbers in the sieve of 0 to √R, i.e. 0 to √130, i.e. 0 to 11 in this case. So base primes in
// this sieve are {2, 3, 5, 7, 11}. These will help in marking composite numbers in segmented sieve.

// 2) Find first index to start marking composite indexes in segmented sieve using the formula:-
// first_mul = first_mul < L ? first_mul + prime : first_mul
// We will pick each base prime number at a time and start marking its multiples as false, i.e. composite
// in 'segmented sieve'. Example:-

// When base prime = 2, the first index to start marking = (L/prime)*prime = (110/2)*2 = 110.
// Thus, 2 will mark 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130 as false i.e. composite.

// When base prime = 3, the first index to start marking = (L/prime)*prime = (110/3)*3 = 108.
// As 108<L, so the first index to start marking = 108 + prime = 108 + 3 = 111
// Thus, 3 will mark 111, 114, 117, 120, 123, 126, 129 as false i.e. composite.

// When base prime = 5, the first index to start marking = (L/prime)*prime = (110/5)*5 = 110.
// Thus, 5 will mark 110, 115, 120, 125, 130 as false i.e. composite.

// When base prime = 7, the first index to start marking = (L/prime)*prime = (110/7)*7 = 105.
// As 105<L, so the first index to start marking = 105 + prime = 105 + 7 = 112
// Thus, 7 will mark 112, 119, 126 as false i.e. composite.

// When base prime = 11, the first index to start marking = (L/prime)*prime = (110/11)*11 = 110.
// Thus, 11 will mark 110, 121 as false i.e. composite.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// creates sieve from 0 to n
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

// T.C: O(R + sqrt(R) - L)
// S.C: O(R + sqrt(R) - L)
vector<bool> createSieveArray_largeRange(int L, int R) {
    // Getting prime marking array to be used to mark primes in segmented sieve.
    vector<bool> sieve = createSieveArray(sqrt(R));   // if R=130, sieve = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1}, contains 11+1 elements

    vector<int> basePrimes;

    for (int i = 0; i < sieve.size(); i++) {
        if(sieve[i]) {
            basePrimes.push_back(i);   // basePrimes = {2, 3, 4, 5, 11}
        } 
    }

    vector<bool> segSieve(R-L+1, true);   // segSieve has R-L+1, i.e. 130-110+1, i.e. 21 elements
    if ((L == 0) || (L == 1)) {
        segSieve[L] = false;
    }

    for (auto prime : basePrimes) {
        int first_mul = (L / prime) * prime;
        first_mul = first_mul < L ? first_mul + prime : first_mul;
        int j = max(first_mul, prime * prime);   // Remember SieveOfEratosthenesOptimised, j can start from i*i, that's why here we are doing prime*prime. 
        while (j<=R) {
            segSieve[j-L] = false;   // Indexes of 'segSieve' will obviously start from 0, not from 110.
            // So doing 'j-L'. j is multples 110, 111, ... which corresponds to 0, 1, .... indexes respectively.
            j += prime;
        }
    }

    return segSieve;
}

int main() {
    int left = 110000000, right = 110000100;

    vector<bool> segsieve = createSieveArray_largeRange(left, right);

    for (int i=0; i<segsieve.size(); i++) {
        if(segsieve[i]) {
            cout << left + i << " ";
        }
    }

    return 0;
}