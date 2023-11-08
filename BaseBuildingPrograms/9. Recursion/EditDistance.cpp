// leetcode: 72. Edit Distance. Given two strings word1 and word2, return the minimum no.of operations
// required to convert word1 to word2. You have the following three operations permitted on a word:
// -> Insert a character
// -> Delete a character
// -> Replace a character

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

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
using namespace std;

int solve(string str1, string str2, int i, int j) {
    // base case
    if(i >= str1.length()) {   // 'str1' exhausted, but there are still characters left in 'str2'.
        // In this case, we just need to insert those chracters at the end of 'str1', in order to
        // convert 'str1' to 'str2'. The count of those many characters are 'str2.length() - j'.
        return str2.length() - j;
    }
    if(j >= str2.length()) {   // 'str2' exhausted, but there are still characters left in 'str1'.
        // In this case, we just need to delete those extra chracters at the end of 'str1', in order
        // to convert 'str1' to 'str2'. The count of those many characters are 'str1.length() - i'.
        return str1.length() - i;
    }

    int no_of_operations = 0;

    if(str1[i] == str2[j]) {
        // if match found, no need to perform any operation; just check next characters from both strings
        no_of_operations = 0 + solve(str1, str2, i+1, j+1);
    } else {   // match not found
        // The recursive relation is illustrated in EditDistance.jpg 
        // insert (we perform 1 operation of insertion, rest will be performed to recursion)
        int path1 = 1 + solve(str1, str2, i, j+1);

        // delete (we perform 1 operation of deletion, rest will be performed to recursion)
        int path2 = 1 + solve(str1, str2, i+1, j);

        // replace (we perform 1 operation of replacement, rest will be performed to recursion)
        int path3 = 1 + solve(str1, str2, i+1, j+1);

        no_of_operations = min(path1, min(path2, path3));
    }

    return no_of_operations;
}


// T.C:
// S.C:
int minDistance(string word1, string word2) {
    int i = 0;
    int j = 0;

    int ans = solve(word1, word2, i, j);
    return ans;
}


int main() {
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2);

    return 0;
}