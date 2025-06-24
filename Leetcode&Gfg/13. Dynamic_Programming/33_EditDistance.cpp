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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    int minDistance_recursion(string word1, string word2) {
        
    }
};

int main() {
    string word1 = "horse", word2 = "ros";

    cout << Solution().minDistance_recursion(word1, word2) << endl;

    return 0;
}
