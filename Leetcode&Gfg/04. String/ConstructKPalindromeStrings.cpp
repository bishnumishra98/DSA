// Leetcode: 1400. Construct K Palindrome Strings   --->   Given a string s and an integer k, return true if you can use
// all the characters in s to construct k palindrome strings or false otherwise.

// Example 1:
// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

// Example 2:
// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.

// Example 3:
// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   n = length of string
    // S.C: O(1);   as the frequency array is of fixed size 26 
    bool canConstruct(string s, int k) {
        // For a string to be a palindrome, at most one character can have an odd frequency (center of the palindrome).
        // The rest must have even frequencies.
        // To construct k palindromes, the number of characters with odd frequencies should be less than or equal to k.
        
        if(s.length() < k) return false;

        // Frequency array to count character frequencies
        int freq[26] = {0};
        
        // Count frequencies of each character in the string
        for(int i = 0; i < s.length(); i++) freq[s[i] - 'a']++;

        // Count characters with odd frequencies
        int oddFreq = 0;
        for(int i = 0; i < 26; i++) if(freq[i] & 1) oddFreq++;

        return oddFreq <= k ? true : false;
    }
};

int main() {
    Solution sol;
    string s = "annabelle";
    int k = 2;
    cout << sol.canConstruct(s, k);

    return 0;
}
