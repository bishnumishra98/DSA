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

// Algorithm:
// 1. Create a directed graph consisting of alphabets as nodes, from the given string array input. Using kahn's algorithm,
//    build a topological sorted array/string from the nodes. This topological sorted array/string represents the
//    the order of characters in the alien language.

// -> How to create nodes from the given input string ?
// -> Consider the string array:
//    s1: baa
//    s2: abcd
//    s3: abca
//    s4: cab
//    s5: cad
//    Here we have have to compare two strings at a time.
//    ◆ Consider s1 and s2, in "baa" and "abcd", we can clealy observe that alphabet 'b' comes before alphabet 'a'.
//       Thus, there will be an edge between the two alphabets where b points to a, i.e., b -> a.
//    ◆ Consider s2 ans s3, in "abcd" and "abca", the differntiating factor is 'd' and 'a'; which means 'd' comes before 'a'.
//       Thus, there will be an edge between the two alphabets where 'd' points to 'a', i.e., d -> a.
//    ◆ Consider s3 ans s4, in "abca" and "cab", we can clealy observe that alphabet 'a' comes before alphabet 'c'.
//       Thus, there will be an edge between the two alphabets where a points to c, i.e., a -> c.
//    ◆ Consider s4 ans s5, in "cab" and "cad", the differntiating factor is 'b' and 'd'; which means 'b' comes before 'd'.
//       Thus, there will be an edge between the two alphabets where 'b' points to 'd', i.e., b -> d.
//    Thus, our final graph would look like this:
//    b --> a --> c
//    |     /\
//    \/    |
//    d ----


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
    int n = 5;
    int k = 4;

    cout << Solution().findOrder(dict, n, k);

    return 0;
}
