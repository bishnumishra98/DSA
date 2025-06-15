// Leetcode: Longest Common Subsequence   --->   Given two strings text1 and text2, return the length of their
// longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none)
// deleted without changing the relative order of the remaining characters.
// ● For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:
// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Example 3:
// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Brute force Algorithm: Generate all subsequences of text1 and text2, and find the largets common subsequence.
//                        There will be 2^n subsequences for a string of length 'n'.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findSubsequence(int i, string word, vector<string>& ans, string ds) {
        if(i == word.length()) {
            ans.push_back(ds);
            return;
        }

        int ch = word[i];

        // Case 1: Including the character 'ch' in 'ds' building
        ds.push_back(ch);
        findSubsequence(i + 1, word, ans, ds);
        ds.pop_back();

        // Case 2: Excluding the character 'ch' in 'ds' building
        findSubsequence(i + 1, word, ans, ds);
    }

    vector<string> allSubsequence(string text1) {
        vector<string> ans;
        string ds = "";
        findSubsequence(0, text1, ans, ds);
        return ans;
    }

    // T.C: O(2^n1 + 2^n2);   where n1 and n2 are lengths of text1 and text2 respectively
    // S.C: O(n)   recursive stack space
    int longestCommonSubsequence_bruteforce(string text1, string text2) {
        vector<string> s1 = allSubsequence(text1);
        vector<string> s2 = allSubsequence(text2);

        int maxLength= 0;
        for(auto it1: s1) {
            string word1 = it1;   // word from s1
            for(auto it2: s2) {
                string word2 = it2;   // word from s2
                if(word1 == word2) {
                    int length = word1.length();   // or, word2.length()
                    maxLength = max(maxLength, length);
                } 
            }
        }

        return maxLength;
    }

// -------------------------------------------------------------------------------------------

    // T.C: 
    // S.C: 
    int longestCommonSubsequence(string text1, string text2) {
        
    }
};

int main() {
    string text1 = "abcde", text2 = "ace";

    cout << Solution().longestCommonSubsequence_bruteforce(text1, text2) << endl;

    return 0;
}
