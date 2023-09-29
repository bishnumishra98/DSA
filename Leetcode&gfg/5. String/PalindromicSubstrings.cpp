// Leetcode: 647. Palindromic Substrings   --->   Given a string s, return the no.of palindromic substrings in it.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


#include <iostream>
using namespace std;

// T.C: O(n/2);   where n is length of string
// S.C: O(1)
int expand(string str, int i, int j) {
    int count = 0;

    // Fountain approach. i and j will jump to previous and next indexes respectively. If s[i] == s[j], count++.
    while(i>=0 && j<str.size() && str[i] == str[j]) {
        count++;
        i--;
        j++;
    }

    return count;
}

// leetcode given function
// T.C: O(n);   where n is length of string
// S.C: O(1)
int countSubstrings(string s) {
    int totalSubstrings = 0;

    for(int i=0; i<s.size(); i++) {
        // 'odd' means no.of odd length substrings for ith position
        int odd = expand(s, i, i);
        
        // 'even' means no.of even length substrings for ith position
        int even = expand(s, i, i+1);

        totalSubstrings = totalSubstrings + odd + even;
    }
    
    return totalSubstrings;
}

int main() {
    string s = "abc";

    cout << countSubstrings(s);

    return 0;
}