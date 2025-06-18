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
//                                   a c e
// Indexes of dp table(col):       0 1 2 3
//                                --------
// Indexes of dp table(row):   0 | 0 0 0 0
//                           a 1 | 0 1 1 1
//                           b 2 | 0 1 1 1
//                           c 3 | 0 1 2 2
//                           d 4 | 0 1 2 2
//                           e 5 | 0 1 2 3
//                     As the memoization was right shifted for tabulation, dp[i][0] and dp[0][j] do not have any
//                     meaning, that's why initialzied to 0. The rest of the table tells the length of LCS.
//                     Lets take dp[4][2] = 2. It means the length of longest common subsequence (LCS) between
//                     s1[1 to 4] and s2[1 to 2], i.e., between "abcd" and "ac" is 2.
//                     A cell(i, j) of the dp table gets filled in either of the two ways:
//                     ● if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1]
//                     ● else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
//                     In tabulation code, i and j both started from 1 and ended at 'm' and 'n' respectively, where
//                     m = s1.length() and n = s2.length(). Thus, if s1[i] was compared s2[j], dp[i + 1][j + 1] was
//                     filled as their output. For example: if s1[0] and s2[0] was compared, its output was filled
//                     in dp[1][1]. If s1[4] and s2[2] was compared, its output was filled in dp[5][3].
//                     Initialize two pointers 'i' and 'j' at index 'm' and 'n', and check from where dp[i][j] was
//                     being filled. It was filled from either of the two ways.
//                     Case I.  if(s1[i - 1] == s2[j - 1]): If s1[i - 1] is equal to s2[j - 1], then it was filled
//                              by adding 1 to the cell at previous row & previous column. 
//                     Case II. if(s1[i - 1] != s2[j - 1]): If s1[i - 1] is not equal to s2[j - 1], then it was filled
//                              from max(cell at previous row & same column, cell at same row & previous column).
//                     For illustration, lets start from the index 'm' and 'n'.
//                             s2    a c e
// Indexes of dp table(col):       0 1 2 3
//                           s1   --------
// Indexes of dp table(row):   0 | 0 0 0 0
//                           a 1 | 0 1 1 1
//                           b 2 | 0 1 1 1
//                           c 3 | 0 1 2 2
//                           d 4 | 0 1 2 2
//                           e 5 | 0 1 2 3
//                     ● We are at dp[5][3]. From where was it filled ? Compare s1[4] and s2[2].
//                       As s1[4] = 'e' and s2[2] = 'e' matches, the value in dp[5][3] came from '1 + dp[4][2]'.
//                     ● Now, we are at dp[4][2]. From where was it filled ? Compare s1[3] and s2[1].
//                       As s1[3] = 'd' and s2[1] = 'c' does not matches, the value in dp[4][2] came from
//                       max of dp[3][2] i.e., 2 and dp[4][1] i.e., 1 which is 2.
//                     ● Now, we are at dp[3][2]. From where was it filled ? Compare s1[2] and s2[1].
//                       As s1[2] = 'c' and s2[1] = 'c' matches, the value in dp[3][2] came from '1 + dp[2][1]'.
//                     ● Now, we are at dp[2][1]. From where was it filled ? Compare s1[1] and s2[0].
//                       As s1[1] = 'b' and s2[0] = 'a' does not matches, the value in dp[2][1] came from
//                       max of dp[1][1] i.e., 1 and dp[2][0] i.e., 0 which is 1.
//                     ● Now, we are at dp[1][1]. From where was it filled ? Compare s1[0] and s2[0].
//                       As s1[0] = 'a' and s2[0] = 'a' matches, the value in dp[1][1] came from '1 + dp[0][0]'.
//                     ● Now we reach dp[0][0]. The point when either 'i' or 'j' reaches 0, we have to stop as
//                       dp[i][0] or dp[0][j] does have any meaning as we have already exhausted one of the strings.
//                     The pattern to observe here is:
//                     dp[0][0] (stop)
//                          \
//                        dp[1][1] (match character 'a')
//                            |
//                        dp[2][1] (no match)
//                             \
//                           dp[3][2] (match character 'c')
//                               |
//                           dp[4][2] (no match)
//                                \ 
//                              dp[5][3] (match character 'e')
//                     Whenever there is a character match, we move diagonally left-up. And whenever there is no match, we
//                     move either towards straight up or straight left whichever is maximum.
//                     Thus, the LCS in the above illustration comes out to be "ace". The steps for this algorithm will be:
//                     1. Generate the tabulated dp table as done in 'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp'.
//                     2. Initialie 'i' and 'j' with s1.length() and s2.length() respectively.
//                     3. Initialize an empty string, lets say named 'ans'. The LCS will be build in this string from back
//                        to front, i.e., first "e" will be stored in 'ans', then "ce", then "ace".
//                     4. While both 'i' and 'j' are greater than 0, compare s1[i - 1] and s2[j - 1]:
//                        Case I.  if(s1[i - 1] == s2[j - 1]):
//                                 If s1[i - 1] is equal to s2[j - 1], then a matching character is found. Hence,
//                                 store the character in 'ans', and then move diagonally left-up, i.e., i--, j--.
//                        Case II. if(s1[i - 1] != s2[j - 1]):
//                                 If s1[i - 1] is not equal to s2[j - 1], then we have to move either towards
//                                 straight left or straight up whichever is maximum. Thus, if(dp[i - 1][j] > dp[i][j - 1]),
//                                 the straight up value is larger, hence move that side, i.e., i--.
//                                 Else straight left is larger, move towards that side, i.e., j--.
//                      When any one of the strings gets exhausted, the loop ends and the LCS is built inside 'ans'.

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
            if(s1[i - 1] == s2[j - 1]) {
                ans = s1[i - 1] + ans;   // prepend character, i.e., building string by inserting characters from back to front
                i--, j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
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
