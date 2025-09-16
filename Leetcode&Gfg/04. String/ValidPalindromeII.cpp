// Leetcode: 680. Valid Palindrome II  --->   Given a string s, return true if the s can be palindrome after
// deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

// Algorithm: Extremely simple.
// As we are allowed to delete at most one character, if a mismatch happens:
// ● Skip s[left] and check if remaining substring is palindrome.
// ● Skip s[right] and check if remaining substring is palindrome.
// If either works, return true. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            // If a mismatch happens, try skipping either s[left] or s[right] and check if remaining substring is palindrome.
            if(s[left] != s[right]) return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    string s = "abca";

    cout << Solution().validPalindrome(s);

    return 0;
}
