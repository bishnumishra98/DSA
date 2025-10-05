// Leetcode 3. Longest Substring Without Repeating Characters   --->   Given a string s, find the length
// of the longest substring without duplicate characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_bruteforce(string s) {
        int n = s.length();

        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            // Hashset to keep a track of uniqueness of characters between jth and ith index.
            // Initially no character occured yet, hence we keep all value of characters as false.
            vector<bool> hashset(256, false);
            int len = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[j] == false) {
                    s[j] = true;
                    len = j - i + 1;
                }
                maxLen = max(maxLen, len);
            }
        }
    }

// -----------------------------------------------------------------------------------------------

    int lengthOfLongestSubstring(string s) {
        
    }
};

int main() {
    string s = "abcabcbb";

    cout << Solution().lengthOfLongestSubstring_bruteforce(s) << endl;
    // cout << Solution().lengthOfLongestSubstring(s);

    return 0;
}
