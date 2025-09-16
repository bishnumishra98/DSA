// Leetcode: 647. Palindromic Substrings   --->   Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // This function chooses a character (to find no.of odd length palindromes) or a pair of characters (to find no.of
    // even length palindromes) as the centre point, and then goes left and right around the centre to find all
    // palindromes with that centre. It returns the count of palindromes found around that centre.
    // The centre is also included as a palindrome of length 1 if it is really a palindrome.
    int traverseAroundCentre(string &s, int left, int right) {
        int count = 0;   // stores the no.of palindromes

        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;   // found a palindrome, so increase count
            left--;
            right++;
        }

        return count;
    }

public:
    // T.C: O(n^2) + O(n^2) = O(n^2);   where n = s.length()
    // S.C: O(1)
    int countSubstrings(string s) {
        int total = 0;

        for(int i = 0; i < s.length(); i++) {
            total += traverseAroundCentre(s, i, i);   // returns no.of odd length palindromes (ex:- palindrome of length 1, 3, 5, ...)
            total += traverseAroundCentre(s, i, i + 1);   // returns no.of even length palindromes (ex:- palindrome of length 2, 4, 6, ...)
        }

        return total;
    }
};

int main() {
    string s = "abc";

    cout << Solution().countSubstrings(s);

    return 0;
}
