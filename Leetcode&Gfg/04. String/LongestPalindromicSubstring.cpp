// Leetcode: 5. Longest Palindromic Substring   --->   Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Tip: Understand this problem first: 'Leetcode&Gfg\04. String\PalindromicSubstrings.cpp'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to expand around the center and return palindrome length
    int traverseAroundCentre(string &s, int left, int right) {
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;   // length of palindrome
    }

    // T.C: O(n^2)
    // S.C: O(1)
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";

        int start = 0, maxLen = 1;

        for(int i = 0; i < n; i++) {
            int len1 = traverseAroundCentre(s, i, i);   // odd length
            int len2 = traverseAroundCentre(s, i, i + 1);   // even length
            int len = max(len1, len2);

            if(len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;   // calculate starting index
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    string s = "babad";

    cout << Solution().longestPalindrome(s) << endl;

    return 0;
}
