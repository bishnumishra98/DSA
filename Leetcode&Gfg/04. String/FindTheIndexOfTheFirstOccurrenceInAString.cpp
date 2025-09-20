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

// -------------------------------------------------------------------------

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

};

int main() {
    string haystack = "sudbutsad", needle = "sad";

    cout << Solution().strStr_abstracted(haystack, needle) << endl;
    cout << Solution().strStr_bruteforce(haystack, needle);

    return 0;
}
