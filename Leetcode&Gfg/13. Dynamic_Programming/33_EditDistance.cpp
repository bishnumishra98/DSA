// Leetcode: 72. Edit Distance   --->   Given two strings word1 and word2, return the minimum number of
// operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// ● Insert a character
// ● Delete a character
// ● Replace a character
 
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Algorithm: As usual a simple problem. We have to try all possible ways using recursion. Call a function
//            f(i, j) which returns the minimum number of operations required to convert 'word1[0 to i]' to
//            'word2[0 to j]'. Start the function call with the arguments 'm - 1' and 'n - 1' where m and n
//            are the lengths of 'word1' and 'word2' respectively, until either of the words gets exhausted. 
//            1. Base case: There can be simple two base cases. Order of base cases won't matter here:
//               I.  if 'i' goes negative: It means the 'word1' got exhausted, but there may be still some
//                                         length of 'word2' left to be traversed yet. In that case, to convert
//                                         'word1' which is essentially now an empty string into 'word2', it
//                                         would take 'x' no.of insert operations, where x = word2[0 to j].length()
//                                         i.e., return 'j + 1' steps.
//               II. if 'j' goes negative: It means the 'word2' got exhausted, but there may be still some
//                                         length of 'word1' left to be traversed yet. In that case, to convert
//                                         'word1' into 'word2' which is essentially now an empty string, it
//                                         would take 'x' no.of delete operations, where x = word1[0 to i].length()
//                                         i.e., return 'i + 1' steps.
//               If both and 'i' and 'j' becomes negative(-1) at the same step, it means 'word1' has been completely
//               converted to 'word2'. Hence 0 steps should be returned. And this case will be handled by the
//               above case I or case II (whichever you write first) only, so no need to write it explicitly.
//            2. Recursive relation: At any pair of (i, j), there can be only cases:
//               I.  if(word1[i] == word2[j]): If character at 'i'th index of 'word1' is equal to character at 'j'th
//                                             index of 'word2', no operations are to be performed, just move ahead,
//                                             i.e., call f(i - 1, j - 1).
//               II. if(word1[i] != word2[j]): If character at 'i'th index of 'word1' is not equal to character at
//                                             'j'th index of 'word2', there can be either of the three operations
//                                             we can perform. But we have to return the path from where we obtain
//                                             the least number of operations.
//                                             i.   Insert operation: If we insert a character in 'word1' at an index
//                                                                    right of 'i' that equals to the character in
//                                                                    'word2' at 'j'th index, a matching character is
//                                                                    hypothetically thought to be present at 'i + 1'th
//                                                                    index of 'word1' and 'j'th index of 'word2'. Then,
//                                                                    we have to go towards left for both 'words' so
//                                                                    that next characters can be compared. Thus, add
//                                                                    1 to this step as we perfomed an insert operation
//                                                                    and call the next function for f(i, j - 1).
//                                             ii.  Delete operation: If we delete a character from 'i'th position of
//                                                                    'word1', we have to next compare 'i - 1'th index
//                                                                    of 'word1' with 'j'th index of 'word2'. Thus, add
//                                                                    1 to this step as we performed a delete operation
//                                                                    and call the next function for f(i - 1, j).
//                                             iii. Replace operation: If we replace a character from 'i'th index of
//                                                                     'word1' so that it becomes equal to 'j'th index
//                                                                     of 'word2', we have to next compare 'i - 1'th
//                                                                     index of 'word1' with 'j - 1'th index of 'word2'.
//                                                                     Thus add 1 to this step as we performed a replace
//                                                                     operation and call the next function for
//                                                                     f(i - 1, j - 1).
//                                             At the end, return the path from which gives the least no.of operations.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string& word1, string& word2) {
        // Base cases
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(word1[i] == word2[j]) return solve(i - 1, j - 1, word1, word2);

        // int insertOperation = 1 + solve(i, j - 1, word1, word2);
        // int deleteOperation = 1 + solve(i - 1, j, word1, word2);
        // int replaceOperation = 1 + solve(i - 1, j - 1, word1, word2);
        // return min(insertOperation, min(deleteOperation, replaceOperation));
        return 1 + min(solve(i, j - 1, word1, word2), min(solve(i - 1, j, word1, word2), solve(i - 1, j - 1, word1, word2)));
    }

    // T.C: O(3^m * 3^n);   where m = word1.length(), n = word2.length()
    // S.C: O(m + n)
    int minDistance_recursion(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        return solve(m - 1, n - 1, word1, word2);
    }

// ----------------------------------------------------------------------------------------------------

    int solve(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
        // Base cases
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = 1 + min(solve(i, j - 1, word1, word2, dp),
                            min(solve(i - 1, j, word1, word2, dp),
                                solve(i - 1, j - 1, word1, word2, dp)));
    }

    // T.C: O(m * n);   where m = word1.length(), n = word2.length()
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    int minDistance_memoization(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, word1, word2, dp);
    }

// ----------------------------------------------------------------------------------------------------

    int solve_rightShifted(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
        // Base cases considering 1 based indexing
        //     a  b  c  d
        // -1  0  1  2  3   ---> earlier
        //  0  1  2  3  4   ---> after right shifting
        if(i == 0) return j;   // 'j + 1'th index becomes 'j'th index after the string right shifted by 1 index
        if(j == 0) return i;   // 'i + 1'th index becomes 'i'th index after the string right shifted by 1 index

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i - 1] == word2[j - 1]) return dp[i][j] = solve_rightShifted(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = 1 + min(solve_rightShifted(i, j - 1, word1, word2, dp),
                            min(solve_rightShifted(i - 1, j, word1, word2, dp),
                                solve_rightShifted(i - 1, j - 1, word1, word2, dp)));
    }

    // T.C: O(m * n);   where m = word1.length(), n = word2.length()
    // S.C: O(m * n) for dp table + O(m + n) for recursion stack space = O(m * n)
    int minDistance_memoization_rightShifted(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));   // one more column is required after right shift
        return solve_rightShifted(m, n, word1, word2, dp);
    }

// ----------------------------------------------------------------------------------------------------

    // This is based on 'minDistance_memoization_rightShifted()' function
    // T.C: O(m * n);   where m = word1.length(), n = word2.length()
    // S.C: O(m * n)
    int minDistance_tabulation(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int j = 0; j <= n; j++) dp[0][j] = j;
        for(int i = 0; i <= m; i++) dp[i][0] = i;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }

        return dp[m][n];
    }

// ----------------------------------------------------------------------------------------------------

    // T.C: O(m * n);   where m = word1.length(), n = word2.length()
    // S.C: O(n)
    int minDistance_tabulation_SO(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);

        for(int j = 0; j <= n; j++) prev[j] = j;

        for(int i = 1; i <= m; i++) {
            // As because 'dp[i][0] = i' in tabulation. So 0th column of every row has value 'i'.
            // Hence, every row we visit will have first cell with value of 'i', i.e., its row number.
            curr[0] = i;
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) curr[j] = prev[j - 1];
                else curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
            }
            prev = curr;
        }

        return prev[n];
    }
};

int main() {
    string word1 = "horse", word2 = "ros";

    cout << Solution().minDistance_recursion(word1, word2) << endl;
    cout << Solution().minDistance_memoization(word1, word2) << endl;
    cout << Solution().minDistance_memoization_rightShifted(word1, word2) << endl;
    cout << Solution().minDistance_tabulation(word1, word2) << endl;
    cout << Solution().minDistance_tabulation_SO(word1, word2) << endl;

    return 0;
}
