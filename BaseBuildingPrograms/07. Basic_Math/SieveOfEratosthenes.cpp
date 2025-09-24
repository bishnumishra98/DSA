// The Sieve of Eratosthenes is an algorithm for finding all prime numbers up to a given limit.
// It is a very efficient algorithm, and it is still widely used today. Let's say given input is n.

// The algorithm states that :-
// 1. Create an array 'sieve' of size n + 1, and mark all of them as prime, i.e., true. sieve[0] represents 0,
//    sieve[1] represents 1, and so on.
// 2. Iterate starting from 2 to n, mark all the numbers that come in the table of 2 as composite, i.e., false.
// 3. Repeat the above step till n, only for numbers that are marked prime.
// 4. In the end of the loop, elements still marked as prime are the prime numbers in the range 2 to n.

#include <iostream>
#include <vector>
using namespace std;

// Here, createSieveArray() is a function that takes n as a parameter, and returns a sieve array,
// which contains the information of prime numbers from 0 to n.
// T.C: O(nlog(logn))
// S.C: O(n);   as the function creates a vector of size 'n+1'
vector<bool> createSieveArray(int n) {
    vector<bool> sieve(n + 1, true);   // all elements of sieve array contains true in the beginning

    // sieve[0] and sieve[1] will be treated as 0 and 1 respectively. So marking them false, i.e., composite.
    sieve[0] = sieve[1] = false;

    for(int i = 2; i <= n; i++) {
        if(sieve[i] == true) {   // sieve[2] will be true only, so we will enter the loop
            int j = i * 2;   // storing 2nd multiple of i inside j. Note that 1st multiple of a number is the number itself.

            while(j <= n) {
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

    for(int i = 0; i <= n; i++) {
        if(sieve[i]) {   // sieve[i] contains true if i is prime number
            cout << i << " ";
        }
    }

    return 0;
}
