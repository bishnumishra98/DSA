// Leetcode: 28. Find the Index of the First Occurrence in a String   --->   Given two strings
// needle and haystack, return the index of the first occurrence of needle in haystack, or -1
// if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Optimal algorithm: First go through 'Leetcode&Gfg\04. String\LongestHappyPrefix.cpp'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n * m)
    // S.C: O(1)
    int strStr_abstracted(string haystack, string needle) {
        size_t index = haystack.find(needle);
        return(index == string::npos) ? -1 : (int)index;
    }

// ----------------------------------------------------------------------------------------------

    // T.C: O(n * m)
    // S.C: O(1)
    int strStr_bruteforce(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        for(int i = 0; i <= m - n; i++) {
            for(int j = 0; j < n; j++) {
                // If characters don't match, start with next character in haystack
                if(haystack[i + j] != needle[j]) break;
                // If needle is fully traversed, it means the needle is found starting at index 'i'
                if(j == n - 1) return i;
            }
        }

        return -1;
    }

// ----------------------------------------------------------------------------------------------

    // Function to fill the LPS (Longest Prefix Suffix) array for the needle
    void lpsFind(vector<int>& lps, string s) {
        int n = s.size();

        int prefix = 0;
        int suffix = 1;

        while(suffix < n) {
            if(s[prefix] == s[suffix]) {
                lps[suffix] = prefix + 1;
                prefix++;
                suffix++;
            } else {
                if(prefix == 0) {
                    lps[suffix] = 0;
                    suffix++;
                } else {   // if(prefix != 0)
                    prefix = lps[prefix - 1];
                }
            }
        }
    }

    // Optimal Approach: Using KMP Algorithm
    // Video link: https://www.youtube.com/watch?v=6gQR8TaFXMw&t=2687s
    // T.C: O(m + n);   where m = length of haystack and n = length of needle
    // S.C: O(n)
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        vector<int> lps(n, 0);   // longest prefix suffix array for needle
        lpsFind(lps, needle);   // fill the lps array for needle

        int i = 0;   // for haystack
        int j = 0;   // for needle
        while(i < m && j < n) {
            if(haystack[i] == needle[j]) {   // if characters match, move both pointers ahead
                i++;
                j++;
            } else {   // if characters don't match
                if(j == 0) {   // if j is already at the start of needle, move i ahead
                    i++;
                } else {   // if j is not at the start of needle, move j to the previous longest prefix suffix position
                    j = lps[j - 1];
                }
            }

            if(j == n) return i - n;   // needle is found
        }

        return -1;   // needle is not found
    }
};


int main() {
    string haystack = "sudbutsad", needle = "sad";

    cout << Solution().strStr_abstracted(haystack, needle) << endl;
    cout << Solution().strStr(haystack, needle);

    return 0;
}
