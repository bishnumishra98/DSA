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

// Brute force Algorithm: Very easy. Generate all subsequences of text1 and text2, and find the largest
//                        common subsequence. There will be 2^n subsequences for a string of length 'n'.

// Optimal algorithm: It is simple. Just apply two pointers approach. Initialize two pointers 'i' and 'j'
//                    at the 'n - 1'th index of text1 and text2 respectively, where n = length of text.
//                    Now call a recursive function solve(i, j) that returns the longest common subsequence
//                    between text1 and text2 where matching of characters is being done in the range of
//                    text1[0] to text1[i], and text2[0] to text2[j] respectively.
//                    Start with the last character of text1 and text2 respectively, and go deeper into the
//                    recursion until i or j goes out of bounds, i.e., either of i or j becomes negative.
//                    1. Base case: If either of i or j becomes negative, no further character matching can
//                                  be done. Hence, no more common subsequence can be found. Thus, return 0.
//                    2. Recursive relation: There can be only scenarios that may occur:
//                       I.  text1[i] == text2[j]: If character pointer by 'i' and 'j' are equal, a common 
//                                                 subsequence of length 1 is found. Hence,
//                                                 return 1 + solve(i - 1, j - 1);
//                                                 We are going back to the next index as we have to find the
//                                                 next common subsequence.
//                       II. text1[i] != text2[j]: If character pointer by 'i' and 'j' are unequal, the common
//                                                 subsequence ends here. From here, if we simply move both 'i'
//                                                 and 'j' back to the next index to find the length of next common
//                                                 subsequence, we may miss out on some subsequence that may occur
//                                                 if 'i' remained at same index and only 'j' moved back; or if 'j'
//                                                 remained at same index and only 'i' moved back. Thus, try out
//                                                 both paths and return the path that brings the maximum length of
//                                                 common subsequence, i.e.,
//                                                 return max(solve(i - 1, j), solve(i, j - 1));
//                    The recursive code can be easily converted to memoization code. But converting it further to
//                    tabulation code will not be feasible due to the base case 'if(i < 0 || j < 0) return 0', as
//                    negative index is not possible in arrays in C++. Thus, we must first right shift the logic
//                    of memoization code by 1, then tabulate the memoization logic, i.e., index 'i' and 'j' of the
//                    strings will be considered as 'i + 1' and 'j + 1' index of the strings respectively.

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
    int longestCommonSubsequence_bruteforce(string text1, string text2) {
        vector<string> s1 = allSubsequence(text1);
        vector<string> s2 = allSubsequence(text2);

        int maxLength = 0;
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

// -----------------------------------------------------------------------------------------------------

    int solve(int i, int j, string& text1, string& text2) {
        // Base: If any of the pointers go out of bound
        if(i < 0 || j < 0) return 0;

        // If characters are equal
        if(text1[i] == text2[j]) return 1 + solve(i - 1, j - 1, text1, text2);

        // If characters are unequal
        return max(solve(i - 1, j, text1, text2), solve(i, j - 1, text1, text2));
    }

    // T.C: O(2^m * 2^n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(m + n)   recursive stack space
    int longestCommonSubsequence_recursion(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        return solve(m - 1, n - 1, text1, text2);
    }

// -----------------------------------------------------------------------------------------------------

    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return 1 + solve(i - 1, j - 1, text1, text2, dp);
        return dp[i][j] = max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
    }

    // T.C: O(m * n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(m * n) for dp table + O(m + n) for recursive stack space
    int longestCommonSubsequence_memoization(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, text1, text2, dp);
    }

// -----------------------------------------------------------------------------------------------------

    int solve_rightShifted(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i - 1] == text2[j - 1]) return 1 + solve_rightShifted(i - 1, j - 1, text1, text2, dp);
        return dp[i][j] = max(solve_rightShifted(i - 1, j, text1, text2, dp), solve_rightShifted(i, j - 1, text1, text2, dp));
    }

    // T.C: O(m * n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(m * n) for dp table + O(m + n) for recursive stack space
    int longestCommonSubsequence_memoization_rightShifted(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve_rightShifted(m, n, text1, text2, dp);
    }

// -----------------------------------------------------------------------------------------------------

    // This is inspired by 'longestCommonSubsequence_memoization_rightShifted()' function
    // T.C: O(m * n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(m * n)
    int longestCommonSubsequence_tabulation(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base: If either of the index goes out of bound, we return 0. As its right shifted, out of bound index is 0.
        // for(int j = 0; j <= m; j++) dp[0][j] = 0;
        // for(int i = 0; i <= n; i++) dp[i][0] = 0;
        // But as all elements are already initialized with 0, no need to separately write the above base cases.

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];   // as logic is right shifted, we return indexes 'm' & 'n'
    }

// -----------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m and n are lengths of text1 and text2 respectively
    // S.C: O(n)
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
};


int main() {
    string text1 = "abcde", text2 = "ace";

    cout << Solution().longestCommonSubsequence_bruteforce(text1, text2) << endl;
    cout << Solution().longestCommonSubsequence_recursion(text1, text2) << endl;
    cout << Solution().longestCommonSubsequence_memoization(text1, text2) << endl;
    cout << Solution().longestCommonSubsequence_memoization_rightShifted(text1, text2) << endl;
    cout << Solution().longestCommonSubsequence_tabulation(text1, text2) << endl;
    cout << Solution().longestCommonSubsequence_tabulation_SO(text1, text2);

    return 0;
}
