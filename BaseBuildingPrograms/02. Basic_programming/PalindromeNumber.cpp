#include <iostream>
using namespace std;

// T.C: O(log10(n))
// S.C: O(1)
bool checkPalindromeNumber(int n) {
    int num = n;   // making a backup of 'n' in 'num' variable
    int bit, ans = 0;   // 'bit' and 'ans' will be used to reverse 'n'

    // Reverse the number 'n' and store it in 'ans'
    while(n) {   // while n is not equal to zero
        bit = n % 10;   // store unit's place of n in 'bit'
        ans = (ans * 10) + bit;   // build the reverse number in 'ans'
        n = n / 10;   // remove unit's place of n
    }

    // if 'ans' == 'num', it is a palaindrome(return true), else return false.
    if(ans == num) return true;
    else return false;
}

int main() {
    int n = 212;

    if(checkPalindromeNumber(n)) cout << "Palindrome number";
    else cout << "Not a Palindrome number";

    return 0;
}
