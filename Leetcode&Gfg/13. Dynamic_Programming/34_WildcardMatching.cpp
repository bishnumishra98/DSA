// Leetcode: 44. Wildcard Matching   --->   Given an input string (s) and a pattern (p), implement wildcard
// pattern matching with support for '?' and '*' where:
// ● '?' Matches any single character.
// ● '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch_recursion(string s, string p) {
        int m = s.length();
        int n = p.length();
    }

// ----------------------------------------------------------------------------------------------------------

    bool isMatch_memoization(string s, string p) {
        int m = s.length();
        int n = p.length();
    }

// ----------------------------------------------------------------------------------------------------------

    bool isMatch_memoization_rightShifted(string s, string p) {
        int m = s.length();
        int n = p.length();
    }

// ----------------------------------------------------------------------------------------------------------

    bool isMatch_tabulation(string s, string p) {
        int m = s.length();
        int n = p.length();
    }

// ----------------------------------------------------------------------------------------------------------

    bool isMatch_tabulation_SO(string s, string p) {
        int m = s.length();
        int n = p.length();
    }

// ----------------------------------------------------------------------------------------------------------

    bool isMatch_tabulation_SO_1D(string s, string p) {
        int m = s.length();
        int n = p.length();
    }
};


int main() {
    string s = "cb", p = "?a";

    cout << Solution().isMatch_recursion(s, p) << endl;

    return 0;
}
