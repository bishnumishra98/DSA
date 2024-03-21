// Leetcode: 204. Count Primes   --->    Given an integer n, return the number of prime numbers
// that are strictly less than n.
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

// The Sieve of Eratosthenes is an algorithm for finding all prime numbers up to a given limit.
// It is a very efficient algorithm, and it is still widely used today. Let's say given input is n.

// The algorithm states that :-
// 1) Create an array of size n, and mark all of them as prime, i.e true.
// 2) Iterate starting from 2 to n, mark all the numbers that comes in table of 2 as composite, i.e false.
// 3) Repeat step 2 till n, only for numbers that are marked prime.
// 4) In the end of the loop, elements still marked as prime are the prime numbers in the range 2 to n. So,
//    keep a count of those numbers, and return the count.

// leetcode given function
// T.C: O(n*log(logn))
// S.C: O(n)
int countPrimes(int n) {
    if(n<=1) return 0;

    vector <bool> prime(n, true);   // initializing n length vector with all element's value as true;
                                   // i.e all numbers are marked prime by default

    // prime[0] and prime[1] will be treated as 0 and 1 respectively. So marking them false, i.e composite.
    prime[0] = prime[1] = false;

    int count = 0;

    // We have to find count of primes numbers strictly less than 'n'.
    // So, we will iterate from 2 to 'n-1'.
    for(int i=2; i<n; i++) {
        if(prime[i]) {
            count++;   // increase 'count', if prime number found at ith index, i.e., prime[i] = true

            int j = 2 * i;   // storing 2nd multiple of i inside j. Note that 1st multiple of a number is the number itself.
            while(j<n) {
                prime[j] = false;   // marking multiples of i as composite, i.e false
                j += i;   // here j = 3rd, 4th, ... last multiple of i uptil n-1
            }
        }
    }
    // Note: If we were asked to find count till 'n', then prime would be of size 'n+1', and
    // for and while loop would have have conditions as 'i<=n' and 'j<=n' respectively.

    return count;
}

int main() {
    int n = 23;
    cout << countPrimes(n);
}
