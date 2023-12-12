// Leetcode: 680. Valid Palindrome II  --->   Given a string s, return true if the s can be
// palindrome after deleting at most one character from it. Ex:-
// i/p: "aba",   o/p: true
// i/p: "abca",    o/p: true
// i/p: "abc",   o/p: false


#include <iostream>
#include <algorithm>   // for reverse()
using namespace std;

// T.C: O(n)
// S.C: O(1)
bool checkPalindrome(string s, int i, int j) {
    while(i<j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }

    return true;
}

// leetcode given function
// T.C: O(n)
// S.C: O(1)
bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while(i<j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        } else {
            bool str1 = checkPalindrome(s, i+1, j);   // removing ith character and checking palindrome
            bool str2 = checkPalindrome(s, i, j-1);   // removing jth character and checking palindrome

            return str1 || str2;   // if any of the substring is palindrome, we will return true
        }
    }

    return true;   // if we come here, it means while loop completed its lifetime and thus its an palindrome
}

int main() {
    string s = "cbbcc";

    cout << validPalindrome(s);

    return 0;
}