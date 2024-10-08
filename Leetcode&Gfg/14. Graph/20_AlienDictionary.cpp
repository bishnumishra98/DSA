// GFG: Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
// Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1
// if the order of string returned by the function is correct else 0 denoting incorrect string returned.

// Examples 1:
// Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
// Output: 1
// Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa"
//              comes before "abcd", therefore 'b' is before 'a' in output. Similarly we can find other orders.

// Example 2:
// Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
// Output: 1
// Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes
//              before "aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    string findOrder(string dict[], int n, int k) {
        
    }
};

int main() {
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    return 0;
}
