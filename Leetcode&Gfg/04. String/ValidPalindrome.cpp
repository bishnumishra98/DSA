// Leetcode: 125. Valid Palindrome   --->   A phrase is a palindrome if, after converting all uppercase letters
// into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAlphaNumeric(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
        return false;
    }

public:
    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            // Skip non-alphanumeric characters
            if(!isAlphaNumeric(s[left])) {
                left++;
                continue;
            } 
            if(!isAlphaNumeric(s[right])) {
                right--;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";

    cout << Solution().isPalindrome(s);

    return 0;
}
