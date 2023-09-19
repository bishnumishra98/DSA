#include <iostream>
using namespace std;

// T.C: O(logn)   base 10
// S.C: O(1)
bool checkPalindromeNumber(int n) {
    int num = n;
    int bit, ans = 0;

    // palindrome number logic
    while(n) {
        bit = n % 10;
        ans = (ans * 10) + bit;
        n = n / 10;
    }
    // comparing value in ans with original number
    if(ans == num) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 212;

    if(checkPalindromeNumber(n)) {
        cout << "Palindrome number";
    } else {
        cout << "Not a Palindrome number";
    }

    return 0;
}