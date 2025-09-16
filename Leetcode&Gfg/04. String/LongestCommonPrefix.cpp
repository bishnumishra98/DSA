// Leetcode: 14. Longest Common Prefix   --->   Write a function to find the longest common prefix string amongst
// an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Algorithm: It is very simple.
// 1. Take the first string as the initial prefix.
// 2. Compare this prefix with every other string. Shorten the prefix by one character each time until it matches
//    the start of each string.
// 3. If prefix becomes empty → return "".


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n * m);   where n = strs.length(), and m = length of shortest string in strs
    // S.C: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string prefix = strs[0];   // take first string as initial prefix

        for(int i = 1; i < strs.size(); i++) {
            // Reduce prefix by one character until it matches the start of strs[i]
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);   // shorten prefix by one character
                if(prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    cout << Solution().longestCommonPrefix(strs);

    return 0;
}
