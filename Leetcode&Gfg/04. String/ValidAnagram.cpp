// Leetcode: 242. Valid Anagram   --->   Given two strings s and t, return true if t is an anagram of s,
// and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// ● 1 <= s.length, t.length <= 5 * 10^4
// ● s and t consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn)
    // S.C: O(1)
    bool isAnagram_bruteforce(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

// -------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);   // to store frequency of characters; example: 0: 1, 1: 3 means 'a' occurs once, 'b' occurs 3 times and so on.

        for(char ch: s) freq[ch - 'a']++;   // increment frequency for characters in s.
        for(char ch: t) freq[ch - 'a']--;   // decrement frequency for characters in t.

        // If both strings are anagrams, frequency of all characters should be zero.
        for(int it: freq) if(it != 0) return false;
        return true;
    }
};


int main() {
    string s = "anagram", t = "nagaram";

    cout << Solution().isAnagram_bruteforce(s, t) << endl;
    cout << Solution().isAnagram(s, t);

    return 0;
}
