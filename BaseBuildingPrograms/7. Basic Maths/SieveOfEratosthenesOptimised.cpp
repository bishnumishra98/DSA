// The Sieve of Eratosthenes is an algorithm for finding all prime numbers up to a given limit.
// It is a very efficient algorithm, and it is still widely used today. Let's say given input is n.

// The algorithm states that :-
// 1) Create an array of size n, and mark all of them as prime, i.e true.
// 2) Iterate starting from 2 to n, mark all the numbers that comes in table of 2 as composite, i.e false.
// 3) Repeat step 2 till n, only for numbers that are marked prime.
// 4) In the end of the loop, elements still marked as prime are the prime numbers in the range 2 to n.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Here, createSieveArray() is a function that takes n as a parameter, and returns a sieve array.
// Here, a sieve array is known as an array containing 'n+1' elements indexed from 0 to n,
// all marked as false, except the ones present at prime indexes. Ex:- Elements at 0th, 1st,
// 4th, etc indexes contain false, while elements at 2nd, 3rd, 5th, etc indexes contain true.
// T.C: O(nlog(logn))
// S.C: O(n)
vector<bool> createSieveArray(int n) {
    vector<bool> sieve(n+1, true);   // all elements of sieve array contains true in the beginning

    // sieve[0] and sieve[1] will be treated as 0 and 1 respectively. So marking them false, i.e composite.
    sieve[0] = sieve[1] = false;

    // Optimization 2: inner loop will never run more than √n times due to optimization 1,
    // so there is no need of running the outer loop from 2 to n unnecessarily.
    for(int i=2; i*i<=n; i++) {
    
        if(sieve[i] == true) {   // sieve[2] will be true only, so we will enter the loop
            // Optimization 1:  // we will start marking numbers as composite from i*i because numbers
            // less than i*i will already be marked by numbers less than i. For ex:- 2 will mark
            // 2, 4, 6, etc. as composite. So there is no need to mark 6 explicitly as composite from 3.
            int j = i * i;
            
            while(j<=n) {
                sieve[j] = false;   // marking multiples of i as composite, i.e false
                j = j + i;   // here j = 3rd, 4th, ... last multiple of i uptil n
            }
        }
    }

    return sieve;   // sieve contains elements marked as true whose indexes are prime numbers
}

int main() {
    int n = 23;

    vector<bool> sieve = createSieveArray(n);

    for(int i=0; i<=n; i++) {
        if(sieve[i]) {   // sieve[i] contains true if i is prime number
            cout << i << " ";
        }
    }

    return 0;
}