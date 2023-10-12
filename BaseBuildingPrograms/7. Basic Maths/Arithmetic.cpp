#include <iostream>
using namespace std;


//  1. MODULO ARITHMETIC

//      I.   Answer of a modulo operation 'a % m' can range from '0' to 'm-1'.

//      II.  Generally, to avoid overflow, we have some properties for modulo opeartions:
//              i.   (a + b) % m = a % m + b % m
//              ii.  a % m - b % m = (a - b) % m
//              iii. (a * b) % m = a % m * b % m
//              iv.  ((a % m) % m) % m = a % m



//  2. EXPONENTIATION (a^b, i.e. a raised to the power of b)

        // T.C: O(b);   due to loop that runs 'b' iterations
        // S.C: O(1)
        int Exponentiation_bruteForce(int a, int b) {
            int ans = 1;
            for(int i=0; i<b; i++) {
                // a^b = a*a*a*a... b times
                ans = ans * a;
            }
            return ans;
        }

        // Fast exponentiation method:
        // Ex: 2^11;    here a=2, b=11
        // Initialize ans with 1.
        // Start with b=10 and keep doing b=b/2 till b>0
        // If b is odd, ans=ans*a; a=a*a;
        // If b is even, a=a*a;
        // In short: 2^11 -> (2^5).2 -> 2^2 -> 2^1

        // T.C: O(logb)
        // S.C: O(1)
        int Exponentiation_fastMethod(int a, int b) {
            int ans = 1;
            while(b > 0) {
                if(b & 1) {   // if b is odd
                    ans = ans * a;
                }
                a = a * a;
                b = b >> 1;   // b = b/2
            }
            return ans;
        }


        int main() {
            int a = 2, b = 11;
            cout << Exponentiation_fastMethod(a, b);
            return 0;
        }
        

