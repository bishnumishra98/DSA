// Leetcode: 1092. Shortest Common Supersequence   --->   Given two strings str1 and str2, return the shortest
// string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results
// in the string s.

// Example 1:
// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

// Example 2:
// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

// Algorithm: It is an extension of the problem 'Leetcode&Gfg\13. Dynamic_Programming\26_PrintAllLCSSequences.cpp'.

// One thing we know for sure is that the length of the longest common subsequence (LCS) for the strings str1
// and str2 lies at last cell of the dp table, i.e., dp[m][n] where m = str1.length() and n = str2.length().
// We also know that every cell of the dp table can be filled from either of the two ways.
// Case I.  if(s1[i - 1] == s2[j - 1]): If s1[i - 1] is equal to s2[j - 1], then it was filled by adding 1
//          to the cell at previous row & previous column. 
// Case II. if(s1[i - 1] != s2[j - 1]): If s1[i - 1] is not equal to s2[j - 1], then it was filled from max
//          (cell at previous row & same column, cell at same row & previous column).

// Now begin the travel from last cell of the dp table and move until any one if the strings gets exhausted.
// The only difference here from the previous problem will be that in the previous problem we were storing
// the characters only before going towards diagonally left-up. But here, we will be storing characters
// from either of the two strings at every step we move forward.

//                           str2    c a b
// Indexes of dp table(col):       0 1 2 3
//                         str1   --------
// Indexes of dp table(row):   0 | 0 0 0 0
//                           a 1 | 0 0 1 1
//                           b 2 | 0 0 1 2
//                           a 3 | 0 0 1 2
//                           c 4 | 0 1 1 2
// ● We are at dp[4][3]. From where was it filled ? Compare str1[3] and str2[2]. As str1[3] = 'c' and
//   str2[2] = 'b' does not matches, the value in dp[4][3] came from max of dp[3][3] i.e., 2 and
//   dp[4][2] i.e., 1 which is 2. Thus, we move to dp[3][3].
// ● Now we are at dp[3][3], it means 'c' from str1 went out of scope now. We will now by able to compare
//   at max "aba" and "cab" from str1 and str2 respectively. As 'c' from str1 went out of scope, add it
//   into a string lets sya named 'ans'.
//   Now the same question arises, from where was dp[3][3] was filled ? Compare str1[2] and str2[2].
//   As str1[2] = 'a' and str2[2] = 'b' does not matches, the value in dp[3][3] came from max of
//   dp[2][3] i.e., 2 and dp[3][2] i.e., 1 which is 2. Thus, we move to dp[2][3].
// ● Now we are at dp[2][3], it means 'a' from str1 also went out of scope now. Thus, add it to the 'ans'.
//   Now the same question arises, from where was dp[2][3] was filled ? Compare str1[1] and str2[2].
//   As str1[1] = 'b' and str2[2] = 'b' matches, the value in dp[2][3] came from '1 + dp[1][2]'.
//   Thus, we move to dp[1][2].
// ● Now we are at dp[1][2], it means 'b' which was common in both str1 and str2 went out of scope. Thus,
//   add 'b' to the 'ans' only once as we are supposed to find the supersequence, so only one 'b' can be used
//   to build the same character in both the child strings str1 and str2 respectively.
//   Now the same question arises, from where was dp[1][2] was filled ? Compare str1[0] and str2[1].
//   As str1[0] = 'a' and str2[1] = 'a' matches, the value in dp[1][2] came from '1 + dp[0][1]'.
//   Thus, we move to dp[0][1].
// ● Now we are at dp[0][1], it means 'a' from str1 also went out of scope now. Thus add it to the 'ans'. As
//   str1 got exhausted here, stop the traversal as at 0th row or 0th column of dp table, the values are invalid.
// ● Post this, there can be any one string left to be traversed yet. In this case, str2 was left to be traversed
//   yet. Thus, simply put all the left out characters from str2 into 'ans'.
// ● At the end, the supersequence is built inside 'ans', but in reverse order as we started dp traversal from
//   dp[m][n] towards dp[0][0]. Hence, reverse the 'ans' and return.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(m * n) for dp table computation + O(m + n) for supersequence reconstruction = O(m * n)
    // S.C: O(m * n) for dp table
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = m, j = n;
        string ans = "";

        // Traverse the dp table from bottom-right to top-left and build the supersequence in 'ans'
        // by adding characters from either of the two strings at every step.
        while (i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];   // or, ans += str2[j - 1];
                i--, j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        // If str1 is left to be traversed, add its characters to 'ans'
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        // If str2 is left to be traversed, add its characters to 'ans'
        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());   // reverse the 'ans' as we started from bottom-right of dp table
        return ans;
    }
};

int main() {
    string str1 = "abac", str2 = "cab";

    cout << Solution().shortestCommonSupersequence(str1, str2);

    return 0;
}
