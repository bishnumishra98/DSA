/*
1. MODULO ARITHMETIC

    I.   Answer of a modulo operation 'a % m' can range from '0' to 'm-1'.

    II.  Generally, to avoid overflow, we have some properties for modulo opeartions:
            i.   (a + b) % m = a % m + b % m
            ii.  a % m - b % m = (a - b) % m
            iii. (a * b) % m = a % m * b % m
            iv.  ((a % m) % m) % m = a % m
*/


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
        

