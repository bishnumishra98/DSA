// Leetcode: 44. Wildcard Matching   --->   Given an input string (s) and a pattern (p), implement wildcard
// pattern matching with support for '?' and '*' where:
// ● '?' Matches any single character.
// ● '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Algorithm: This is also a simple recursive problem if you think carefully. Call a function f(i, j) which returns
//            if the string 's' matches the pattern 'p' or not, where string ranges from s[0 to i] and pattern
//            ranges from p[0 to j]. Pass initial arguments (m - 1, n - 1) to the function, where m and p are lengths
//            of 's' and 'p' respetively.
//            1. Base case: There can be multiple base cases for it:
//               I.   if(i < 0 && j < 0): If both 'i' and 'j' reaches -1, it means both are exhausted. Hence the
//                                        pattern matching is successful. Thus, return true.
//               II.  if(i < 0 && j >= 0): If 's' has exhausted, but pattern still exists, there can few subcases:
//                    i.  if(p[0 to j]) contains atleast one non '*' character: If the left over pattern contains
//                                                                              atleast one non '*' character, then
//                                                                              the pattern matching was unsuccessful,
//                                                                              thus return false.
//                    ii. if(p[0 to j]) contains all '*': If the left over pattern contains all '*', then all of them
//                                                        can be considered as empty string. Thus, we can return
//                                                        true stating that patttern matching is successful.
//                    
//               III. if(i >= 0 && j < 0): If 's' is still left yet, but the pattern 'p' already got exhausted, then
//                                         pattern matching is again unsuccessful, thus return false.
//            2. Recursive relation: There can multiple recursive relations for it:
//               I.  if(s[i] == p[j] || p[j] == '?'): If character at 's[i]' matches the character at 'p[j]', or even
//                                                    if p[j] is a '?', we can say its a character match. Thus, call
//                                                    the next recursive function by moving 'i' and 'j' pointers,
//                                                    i.e., return f(i - 1, j - 1).
//               II. if(p[j] == '*'): If character at 'p[j]' is '*', then we can either consider it as an empty string
//                                    or we can consider it as some subsequence that matches character by character
//                                    with 's'. If we consider 'p[j]' as an empty string, move 'j' index keeping
//                                    'i' as its place, i.e., return f(i, j - 1). If we consider 'p[j]' as some
//                                    subsequence that matches with 's' character by character, consider calling the
//                                    recursive function by moving 'i' by one character, keeping 'j' constant so that
//                                    each character of 's' can be matched with '*' of 'p', i.e., return f(i - 1, j).
//               III. If none of the cases matches: If none of the above two cases matches, return false stating that
//                                                  character at 's[i]' and character at 'p[j]' cannot be matched by
//                                                  any means.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, string& s, string& p) {
        // Base cases:
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) {
            for(int index = 0; index <= j; index++) if(p[index] != '*') return false;
            return true;   // if p[0 to j] contains all '*', return true
        }
        if(i >= 0 && j < 0) return false;

        if(s[i] == p[j] || p[j] == '?') return solve(i - 1, j - 1, s, p);
        if(p[j] == '*') {
            // Either consider '*' as empty string or as some subsequence that matches with 's'
            return solve(i, j - 1, s, p) || solve(i - 1, j, s, p);
        }
        return false;
    }

    // T.C: O(2^(m + n));   where m and n are lengths of 's' and 'p' respectively
    // S.C: O(m + n) for recursion stack space
    bool isMatch_recursion(string s, string p) {
        int m = s.length();
        int n = p.length();
        return solve(m - 1, n - 1, s, p);
    }

// ----------------------------------------------------------------------------------------------------------

    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) {
            for(int index = 0; index <= j; index++) if(p[index] != '*') return false;
            return true;
        }
        if(i >= 0 && j < 0) return false;

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        if(p[j] == '*') return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        return dp[i][j] = false;
    }

    // T.C: O(m * n)
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    bool isMatch_memoization(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }

// ----------------------------------------------------------------------------------------------------------

    bool solve_rightShifted(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) {
            for(int index = 1; index <= j; index++) if(p[index - 1] != '*') return false;
            return true;
        }
        if(i > 0 && j == 0) return false;

        if(s[i - 1] == p[j - 1] || p[j - 1] == '?') return dp[i][j] = solve_rightShifted(i - 1, j - 1, s, p, dp);
        if(p[j - 1] == '*') return dp[i][j] = solve_rightShifted(i, j - 1, s, p, dp) || solve_rightShifted(i - 1, j, s, p, dp);
        return dp[i][j] = false;
    }

    // T.C: O(m * n)
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    bool isMatch_memoization_rightShifted(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve_rightShifted(m , n, s, p, dp);
    }

// ----------------------------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(m * n)
    bool isMatch_tabulation(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for(int j = 1; j <= n; j++) {
            bool flag = true;
            for(int index = 1; index <= j; index++) {
                if(p[index - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i = 1; i <= m; i++) dp[i][0] = false;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else dp[i][j] = false;
            }
        }

        return dp[m][n];
    }

// ----------------------------------------------------------------------------------------------------------

    // T.C: O(m * n)
    // S.C: O(n)
    bool isMatch_tabulation_SO(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<bool> curr(n + 1, false), prev(n + 1, false);

        // Base cases: The third base case will be written inside nested for loops because 0th column of every row is
        //             supposed to be false. Every new row is denoted by 'curr', hence 'curr[0] = false' for every row.
        prev[0] = true;
        for(int j = 1; j <= n; j++) {
            bool flag = true;
            for(int index = 1; index <= j; index++) {
                if(p[index - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i <= m; i++) {
            curr[0] = false;   // the 3rd base case
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') curr[j] = prev[j - 1];
                else if(p[j - 1] == '*') curr[j] = curr[j - 1] || prev[j];
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[n];
    }
};


int main() {
    string s = "cb", p = "?a";

    cout << Solution().isMatch_recursion(s, p) << endl;
    cout << Solution().isMatch_memoization(s, p) << endl;
    cout << Solution().isMatch_memoization_rightShifted(s, p) << endl;
    cout << Solution().isMatch_tabulation(s, p) << endl;
    cout << Solution().isMatch_tabulation_SO(s, p);

    return 0;
}
