// GFG: Minimum number of deletions and insertions   --->   Given two strings s1 and s2. The task is to
// remove or insert the minimum number of characters from/in s1 to transform it into s2. It could be
// possible that the same character needs to be removed from one point of s1 and inserted into another point.

// Example 1:
// Input: s1 = "heap", s2 = "pea"
// Output: 3
// Explanation: 'p' and 'h' deleted from heap. Then, 'p' is inserted at the beginning.

// Example 2:
// Input : s1 = "geeksforgeeks", s2 = "geeks"
// Output: 8
// Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".

// Algorithm: Again, an extremely simple problem. It is just an extension of
//            'Leetcode&Gfg\13. Dynamic_Programming\25_LongestCommonSubsequence.cpp'.
//            The minimum number of deletions and insertions required on string s1 to convert it into s2
//            is (s1.length() - length of LCS) + (s2.length() - length of LCS).
//            This is because the common characters in s1 and s2 is given by finding the longest common
//            subsequence (LCS) between s1 and s2. And once once we know the LCS of s1 and s2, we can
//            just subtract the characters from s1 that is not in LCS, and then add the characters of s2
//            that is not in LCS and easily convert s1 to s2.
//            ● Example: s1 = "heap", s2 = "pea"
//              LCS of s1 and s2 = "ea".
//              Steps to convert s1 to s2: s1 --- deletion ---> lcs --- addition ---> s2
//              Step 1: Convert s1 into lcs, hence delete the characters of s1 that is not in lcs.
//              Step 2: Once lcs in formed, add the characters of s2 which are not a part of lcs.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
    // T.C: O(m * n);   where m and n are lengths of s1 and s2 respectively
    // S.C: O(n)
    int minOperations(string &s1, string &s2) {
        int lcs = longestCommonSubsequence_tabulation_SO(s1, s2);
        int deletions = s1.length() - lcs;
        int additions = s2.length() - lcs;
        return deletions + additions;
    }
};

int main() {
    string s1 = "heap", s2 = "pea";

    cout << Solution().minOperations(s1, s2);

    return 0;
}
