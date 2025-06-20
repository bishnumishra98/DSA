// Leetcode: 1312. Minimum Insertion Steps to Make a String Palindrome   --->   Given a string s. In one step
// you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:
// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.

// Example 2:
// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

// Example 3:
// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// Algorithm: Extremely simple problem. It is just an extension of the previous problem
//            'Leetcode&Gfg\13. Dynamic_Programming\28_LongestPalindromicSubsequence.cpp'.
//            Minimum insertion steps to make a string palindrome is nothing but equal to
//            string.length() - longestPalindromeSubseq(string).

// ● Why the algorithm works ?
//   Lets take an example s = "leetcode".
//   The longest palindromic subsequence (LPS) of the string 's' will be of length 3. Example: "eee", "ete",
//   "ece", "eoe" and "ede".
//   Consider any one of the LPS, lets say "eee". Now we know that "eee" is a part of LPS, hence other
//   characters like 'l', 't', 'c', 'o' and 'd' will not be a part of LPS.
//   Thus, to make the whole string 's' a palindrome, we must keep intact "eee" as base of the palindrome
//   and fill rest of the character's ('l', 't', 'c', 'o' and 'd') duplicates in between them.
//   For example: l  e  e  t  c  o  d  e
//                   /\ /\             /\
//                    |  |              |
//   Keep the three 'e's intact at their place. Now to make the string a palindrome, add the duplicates
//   of 'l', 't', 'c', 'o' and 'd' wherever needed. Thus, the string now becomes:
//   l  e  e  t  c  o  d  o  c  t  e  e  l
//      /\ /\                        /\
//       |  |                         |
//    Hence, after placing exactly non LPS characters number of duplicates to the original string, we can
//    easily make any string a plaindrome. And this is the least number of insertions we need to make
//    to a string to make it palindrome. You may try out this technique with some other examples too.
//    Always the minimum insertion steps to make a string a palindrome will be the number of non LPS
//    characters in the string (characters of string which are not a part of LPS).

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence_tabulation_SO(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n];
    }

    // 'Leetcode&Gfg\13. Dynamic_Programming\28_LongestPalindromicSubsequence.cpp' code:
    int longestPalindromeSubseq(string s) {
        string s_reversed = s;
        reverse(s_reversed.begin(), s_reversed.end());
        return longestCommonSubsequence_tabulation_SO(s, s_reversed);
    }

public:
    // T.C: O(n^2);   where n = s.length()
    // S.C: O(n)
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};

int main() {
    string s = "leetcode";

    cout << Solution().minInsertions(s);

    return 0;
}
