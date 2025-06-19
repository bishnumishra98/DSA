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
//                             s2    a c e
// Indexes of dp table(col):       0 1 2 3
//                           s1   --------
// Indexes of dp table(row):   0 | 0 0 0 0
//                           a 1 | 0 1 1 1
//                           b 2 | 0 1 1 1
//                           c 3 | 0 1 2 2
//                           d 4 | 0 1 2 2
//                           e 5 | 0 1 2 3
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m * n);   where m and n are lengths of text1 and text2 respectively
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
};

int main() {
    string s1 = "ABCDGH", s2 = "ACDGHR";

    cout << Solution().longestCommonSubstr(s1, s2) << endl;

    return 0;
}
