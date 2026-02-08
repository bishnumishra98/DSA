// Leetcode: 1653. Minimum Deletions to Make String Balanced   --->   You are given a string s consisting only of
// characters 'a' and 'b'​​​​.
// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j)
// such that i < j and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.

// Example 1:
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

// Example 2:
// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters.

// Algorithm: It is simple greedy approach. A string is balanced if no 'b' appears before an 'a'.
// So we want all 'a' to appear before all `'b's. Thus, while scanning the string from left to right, we track:
// ● countB = how many 'b' we have seen so far
// ● deletions = minimum deletions needed to make the string balanced up to the current index
// Whenever we see an 'a' after some 'b', we have two choices:
// 1. Delete this 'a', or
// 2. Delete all previous 'b's
//    We greedily pick the cheaper option.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    int minimumDeletions(string s) {
        int countB = 0;   // number of 'b' seen so far
        int deletions = 0;

        for(char c : s) {
            if(c == 'b') {
                countB++;   // number of 'b's till current character
            } else {   // c == 'a'
                // Either delete this 'a' OR delete all previous 'b's
                deletions = min(deletions + 1, countB);
            }
        }

        return deletions;
    }
};


int main() {
    string s1 = "aababbab";

    Solution sol;
    cout << sol.minimumDeletions(s1) << endl;   // o/p: 2

    return 0;
}
