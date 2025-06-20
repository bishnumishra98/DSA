// Leetcode: 516. Longest Palindromic Subsequence   --->   Given a string s, find the longest palindromic
// subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without
// changing the order of the remaining elements.

// Example 1:
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Algorithm: It is an extremely simple problem. We just have to find the length of longest palindromic subsequence.
//            It is an extension of the problem 'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp'.
//            As palindrome is a string which reads the same if reversed, we are going to use a genius trick to find
//            the longest palindromic subsequence.
//            Lets say if given input string is s1, then save a copy of the reversed string as lets say s2.
//            Now just find the length of longest common subsequence between s1 and s2, and that's nothing but the
//            length of longest palindromic subsequence of s1(and even s2).

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp' code:
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

public:
    // T.C: O(n * n) + O(n) for reversing the string =  O(n^2);   where n = s.length()
    // S.C: O(n)
    int longestPalindromeSubseq(string s) {
        string s_reversed = s;
        reverse(s_reversed.begin(), s_reversed.end());
        return longestCommonSubsequence_tabulation_SO(s, s_reversed);
    }
};

int main() {
    string s = "bbbab";

    cout << Solution().longestPalindromeSubseq(s);

    return 0;
}
