#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(1)
bool checkPalindromeString(string str) {
    int len = str.length();
    int i = 0, j = len - 1;

    // palindrome string logic
    while(i<j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string str = "obboa";

    if(checkPalindromeString(str)) {
        cout << "Palindrome";
    } else {
        cout << "Not a palindrome";
    }

    return 0;
}