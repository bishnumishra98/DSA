// Longest Common Substring   --->   You are given two strings s1 and s2. Your task is to find the length of the
// longest common substring among the given strings.

// Example 1:
// Input: s1 = "ABCDGH", s2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" with a length of 4.

// Example 2:
// Input: s1 = "abc", s2 = "acb"
// Output: 1
// Explanation: The longest common substrings are "a", "b", "c" all having length 1.

// Example 3:
// Input: s1 = "YZ", s2 = "yz"
// Output: 0

// Problem link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// Algorithm: This problem is very similar to 'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp'.
//            We can easily solve it by using tabulation table of the previous problem, with some minor changes.
//            The minor change is in the condition when characters do not match.
//            if(s1[i] != s2[j]): If character pointer by 'i' and 'j' are unequal, the common substring ends here.
//                                And substring is continuous in nature, so there is no point of skipping any one
//                                character of each string and going back and checking for match, as we did in the
//                                previous problem of 'LongestCommonSubsequence.cpp'. Thus, we simply set the
//                                value of dp[i][j] to 0, i.e., dp[i][j] = 0; and move on to the next character.
//                                Setting dp[i][j] to 0 means that there is no common substring ending at the
//                                current character of both strings.
//            Illustration: s1 = "ABCDGH", s2 = "ACDGHR"
//                             s2    A C D G H R
// Indexes of dp table(col):       0 1 2 3 4 5 6
//                           s1   --------------
// Indexes of dp table(row):   0 | 0 0 0 0 0 0 0
//                           A 1 | 0 1 0 0 0 0 0
//                           B 2 | 0 0 0 0 0 0 0
//                           C 3 | 0 0 1 0 0 0 0
//                           D 4 | 0 0 0 2 0 0 0
//                           G 5 | 0 0 0 0 3 0 0
//                           H 6 | 0 0 0 0 0 4 0

// Optimal approach: This is one of the rarest problem where brute force is the best solution, lol !!!
//                   It is a reminder that sometimes, the simplest hammer is the best tool for the job. 😄

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m * n);   where m and n are lengths of s1 and s2 respectively
    // S.C: O(m * n)
    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ans = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);   // track the largest value that occured in dp table
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }

// -------------------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m and n are lengths of s1 and s2 respectively
    // S.C: O(n)
    int longestCommonSubstr_SO(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);

        int ans = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return ans;
    }

// -------------------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m and n are lengths of s1 and s2 respectively
    // S.C: O(1)
    int longestCommonSubstr_bruteforce(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
    
        int maxLen = 0;
    
        // Iterate over all starting points in s1
        for(int i = 0; i < m; i++) {
            // Iterate over all starting points in s2
            for(int j = 0; j < n; j++) {
                int length = 0;
    
                // Check for longest substring from current (i, j) pair
                while (i + length < m && j + length < n && s1[i + length] == s2[j + length]) length++;
    
                // Update the maximum length found so far
                maxLen = max(maxLen, length);
            }
        }
    
        return maxLen;
    }
};


int main() {
    string s1 = "ABCDGH", s2 = "ACDGHR";

    cout << Solution().longestCommonSubstr(s1, s2) << endl;
    cout << Solution().longestCommonSubstr_SO(s1, s2) << endl;
    cout << Solution().longestCommonSubstr_bruteforce(s1, s2);

    return 0;
}
