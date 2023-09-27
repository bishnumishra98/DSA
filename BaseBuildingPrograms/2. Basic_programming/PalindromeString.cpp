#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(1)
bool checkPalindromeString(string str) {
    int i = 0;
    int j = str.length() - 1;

    // palindrome string logic
    while(i<j) {
        if(str[i] == str[j]) {
            i++;
            j--;
        } else {
            return false;
        }
        
    }
    return true;
}

int main() {
    string str = "obkbo";

    if(checkPalindromeString(str)) {
        cout << "Palindrome";
    } else {
        cout << "Not a palindrome";
    }

    return 0;
}