// Leetcode: 1910. Remove All Occurrences of a Substring   --->   Given two strings s and part, perform the
// following operation on s until all occurrences of the substring part are removed:
// ● Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

// Example 1:
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

// Example 2:
// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".

// Problem link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

#include <bits/stdc++.h>
using namespace std;

// INFO:
// ● s.find(part) → gives the index of the leftmost occurrence (or npos if not found).
//   Example:
//   string s = "daabcbaabcbc";
//   string part = "abc";
//   cout << s.find(part);   // o/p: 2

// ● s.erase(index, length) → removes 'length' characters from 's' starting at 'index'.
//   Example:
//   string s = "daabcbaabcbc";
//   s.erase(2, 3);   // Removes 3 characters starting from index 2
//   cout << s;       // o/p: "dabbaabcbc"


class Solution {
public:
    // T.C: O(n * m);   where n = s.length(), m = part.length()
    // S.C: O(1)
    string removeOccurrences(string s, string part) {
        // Keep removing part from s until part is not found in s
        while(s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << Solution().removeOccurrences(s, part);

    return 0;
}
