#include <iostream>
using namespace std;

// We can use two pointer approach to find a palindrome string
// T.C: O(n)
// S.C: O(1)
bool checkPalindromeString(string str) {
    int i = 0;   // i points to first index of 'str'
    int j = str.length() - 1;   // j points to last index of 'str'

    // Increment i by 1, and decrement j by 1 on each iteration,
    // until i crosses or meets j. On each iteration, check if 
    // str[i] and str[j] are not equal, then it is not a
    // palindrome string. Thus, return false.
    while(i < j) {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
        
    // If program comes out of while loop, it is a palindrome.
    // Thus, return true.
    return true;
}

int main() {
    string str = "obkbo";
    if(checkPalindromeString(str)) cout << "Palindrome";
    else cout << "Not a palindrome";
    return 0;
}
