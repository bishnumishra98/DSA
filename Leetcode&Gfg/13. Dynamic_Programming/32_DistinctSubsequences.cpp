// Leetcode: 115. Distinct Subsequences   --->   Given two strings s and t, return the number of distinct
// subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// .... .. dots represents which characters are being considered in building the string

// rabbbit
// .. ....

// rabbbit
// ... ...

// Example 2:
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// .. .   

// babgbag
// ..    .

// babgbag
// .    ..

// babgbag
//   .  ..

// babgbag
//     ...

// Algorithm: It looks difficult, but is actually an easy problem. As we have to find out all distinct
//            subsequences of 's' which equals 't', we have to explore all ways using recursion.
//            Call a function f(i, j) that returns the number of distinct subsequences of s[0 to i]
//            which equals to t[0 to j].
//            In the function call of f(i, j), i starts from s.length() - 1 and j starts from t.length() - 1
//            respectively, until either of the strings gets exhausted as no more comparisons can be done further.
//            1. Base case: There can be two base cases:
//               I.  If 'j' becomes negative: It means the second string 't' is exhausted. If its exhausted,
//                                            it means, all characters of 't' have been already matched with
//                                            some characters of the first string 's'. Thus, a subsequence
//                                            is present in 's' which equals 't'. Hence, return 1.
//               II. If 'i' becomes negative: It means the first string 's' is only exhausted where we were
//                                            supposed to find matching characters of 't'. Thus, 't' is still
//                                            left for matching, and no complete matche was found for it in
//                                            's'. Hence, no subsequence found in 's' that equals to 't', so
//                                            return 0.
//               Note that the order of base cases will matter here because if you write second base first, it
//               may happen that both 'j' and 'i' became negative at the same step. It means a complete match
//               of 't' is found in 's', but since we wrote the second base case first, the program will
//               return 0 stating that no complete match of 't' was found in 's'.
//            2. Recursive relation: There can be only scenarios that may occur:
//               I.  if(s[i] == t[j]): It means the character at 'i'th index in 's' matches with the character
//                                     at 'j'th index in 't'. From here, we can explore two different paths:
//                                     i.  Move back both 'i' and 'j': It means we want to explore the answer
//                                                                     in the portion of strings s[0 to i - 1]
//                                                                     and t[0 to j - 1], i.e., call f(i - 1, j - 1).
//                                     ii. Move back only 'i': It means we want to explore the answer in the
//                                                             portion s[0 to i - 1] and t[0 to j]. It essentially
//                                                             means that we are not interested in matching the
//                                                             'i'th character of 's' with 'j'th character of 't';
//                                                             instead we are looking for any other occurrence of
//                                                             the 'i'th character in the reduced portion of 's'
//                                                             that may match with 'j'th character of 't', i.e.,
//                                                             call f(i - 1, j).
//                                     At the end, return the sum of distinct subsequences obtained by going into
//                                     both the above mentioned paths, i.e., return f(i - 1, j - 1) + f(i - 1, j).
//                                     
//               II. if(s[i] != t[j]): It means the character at 'i'th index in 's' does not matches with the
//                                     character at 'j'th index in 't'. So reduce the search space of 's' keeping
//                                     't' constant. In simple terms, search for the same portion of string
//                                     t[0 to j] in reduced portion of s[0 to i - 1], i.e., return f(i - 1, j).

// ● Tabulation of the memoization: To tabulate the memoized code, we have to right shift the indexes of the
//                                  strings towards right by 1, as base case is based on negative value which
//                                  is naturally not possible to show in tabulation table.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        // Base cases: Note that order of bases is very crucial here
        if(j < 0) return 1;   // if 't' is exhausted, a subsequence has been found in 's'
        if(i < 0) return 0;   // if 's' is exhausted and 't' is still left to be matched with 's',
                             // no subsequence can be found in 's' that equals 't'
        
        if(s[i] == t[j]) return solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
        return solve(i - 1, j, s, t);   // else case, i.e., if(s[i] != t[j])
    }

    // T.C: O(2^m * 2^n);   where m = s.length, n = t.length()
    // S.C: O(m + n);   for recursion stack space
    int numDistinct_recursion(string s, string t) {
        int m = s.length();
        int n = t.length();
        return solve(m - 1, n - 1, s, t);
    }

// ----------------------------------------------------------------------------------------------------

    int solve(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

    // T.C: O(m * n);   where m = s.length, n = t.length()
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    int numDistinct_memoization(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, t, dp);
    }

// ----------------------------------------------------------------------------------------------------

    int solve_rightShifted(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1]) return dp[i][j] = solve_rightShifted(i - 1, j - 1, s, t, dp) + solve_rightShifted(i - 1, j, s, t, dp);
        return dp[i][j] = solve_rightShifted(i - 1, j, s, t, dp);
    }

    // T.C: O(m * n);   where m = s.length, n = t.length()
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    int numDistinct_memoization_rightShifted(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve_rightShifted(m, n, s, t, dp);
    }

// ----------------------------------------------------------------------------------------------------

    // This is based on 'numDistinct_memoization_rightShifted()' function
    // T.C: O(m * n);   where m = s.length, n = t.length()
    // S.C: O(m * n)
    int numDistinct_tabulation(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
    }
};

int main() {
    string s = "rabbbit", t = "rabbit";

    cout << Solution().numDistinct_recursion(s, t) << endl;
    cout << Solution().numDistinct_memoization(s, t) << endl;
    cout << Solution().numDistinct_memoization_rightShifted(s, t) << endl;

    return 0;
}
