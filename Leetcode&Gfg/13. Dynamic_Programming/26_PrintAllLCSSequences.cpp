// GFG: Print all LCS sequences   --->   You are given two strings s1 and s2. Your task is to print all
// distinct longest common subsequences in lexicographical order.
// Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

// Example 1:
// Input: s1 = "abaaa", s2 = "baabaca"
// Output: ["aaaa", "abaa", "baaa"]
// Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".

// Example 2:
// Input: s1 = "aaa", s2 = "a"
// Output: ["a"]
// Explanation: Length of lcs is 1 and it is "a".

// Problem link: https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

// Brute force Algorithm: Very easy. Generate all subsequences of s1 and s2, and find the largest common
//                        subsequences. There will be 2^n subsequences for a string of length 'n'.        

// Optimal algorithm: One thing to note here is that the optimal solution gives only one LCS, not all.
//                    If you want all LCS, you need to follow brute force approach only.
//                    For this we will require the tabulation table of the previous problem
//                    'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp'.
//                    The dp table for the input text1 = "abcde", text2 = "ace" would look like this:
// 0 0 0 0
// 0 1 1 1
// 0 1 1 1
// 0 1 2 2
// 0 1 2 2
// 0 1 2 3

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

    // T.C: O(2^m + 2^n) + O(2^m * 2^n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(max(m, n))   recursive stack space
    vector<string> allLCS_bruteforce(string &s1, string &s2) {
        vector<string> subsequences1 = allSubsequence(s1);
        vector<string> subsequences2 = allSubsequence(s2);

        set<string> ans;   // to store a lcs only once
        int maxLength= 0;
        for(auto it1: subsequences1) {
            string word1 = it1;   // word from subsequences1
            for(auto it2: subsequences2) {
                string word2 = it2;   // word from s2
                if(word1 == word2) {
                    int length = word1.length();   // or, word2.length()
                    maxLength = max(maxLength, length);
                    if(word1.length() == maxLength) ans.insert(word1);
                } 
            }
        }

        vector<string> lcs(ans.begin(), ans.end());
        return lcs;
    }

// -----------------------------------------------------------------------------------------------------

    string allLCS(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = m, j = n;
        string ans = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans = s1[i - 1] + ans;   // prepend character, i.e., building string by inserting characters from back to front
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return ans;
    }
};


int main() {
    string s1 = "abaaa", s2 = "baabaca";

    Solution sol;
    vector<string> ans = sol.allLCS_bruteforce(s1, s2);
    for(auto it: ans) cout << it << " ";
    cout << endl;

    cout << sol.allLCS(s1, s2);

    return 0;
}
