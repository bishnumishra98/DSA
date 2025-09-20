// Leetcode 1392. Longest Happy Prefix   --->   A string is called a happy prefix if is a non-empty prefix which
// is also a suffix (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

// Example 1:
// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel").
// The largest prefix which is also suffix is given by "l".

// Example 2:
// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

// Algorithm: It is based on Knuth-Morris-Pratt algorithm, popularly know as KMP algorithm.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);   // longest prefix-suffix array

        int len = 0;   // length of previous longest prefix-suffix
        int i = 1;

        while(i < n) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];   // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return s.substr(0, lps[n - 1]);   // longest prefix-suffix
    }
};

int main() {
    string s = "ababab";

    cout << Solution().longestPrefix(s);

    return 0;
}
