// Leetcode: 125. Valid Palindrome   --->   A phrase is a palindrome if, after converting all
// uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads
// the same forward and backward. Ex:-
// i/p: "A man, a plan, a canal: Panama",   o/p: true
// i/p: " ",    o/p: true
// i/p: "race a horse",   o/p: false

// T.C:
// S.C:
#include <iostream>
#include <algorithm>   // for reverse()
using namespace std;

string removeNonAlphaNumericCharacters(string s) {
    string str = "";

    // removing all alphanumeric characters from string
    for(int i=0; i<s.size(); i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            str.push_back(s[i]);
        }
    }

    return str;
}

bool isPalindrome(string s) {
    string str = removeNonAlphaNumericCharacters(s);

    // lowering the string
    for(int i=0; i<str.size(); i++) {
        if(toupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    // checking if its palindrome
    string temp = str;
    reverse(str.begin(), str.end());   // reversing 'str'

    return (temp == str);   // if(temp==str), then return true, else return false
    
    // // The same thing can be done using compare(). This functions returns 0 if two strigs are equal.
    // if(str.compare(temp) == 0) {
    //     return true;
    // } else {
    //     return false;
    // }
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    cout << isPalindrome(s);

    return 0;
}