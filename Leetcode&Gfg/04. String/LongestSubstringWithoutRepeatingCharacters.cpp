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

// Optimal algorithm: Two pointer with Sliding Window
// Intuition: We can use two pointers to represent a window in the string. We can use a hash map to store the last
// occurrence of each character. We can move the right pointer to expand the window and update the last occurrence
// of the character at the right pointer. If the character at the right pointer has already occurred in the current
// window, we can move the left pointer to the right of the last occurrence of that character. We can keep track of
// the maximum length of the window during the process.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(256) = O(1)
    int lengthOfLongestSubstring_bruteforce(string s) {
        int n = s.length();

        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            // Hashset to keep a track of uniqueness of characters between jth and ith index.
            // Initially no character occured yet, hence we keep all value of characters as false.
            vector<bool> hashset(256, false);
            hashset[s[i]] = true;   // s[i] appeared once, so mark it true
            int len = 1;   // length of substring is initially 1 due to ith character itself
            for(int j = i + 1; j < n; j++) {
                if(hashset[s[j]]) break;   // if s[j] already occurred, j doesn't moves any further, so break out of inner loop
                hashset[s[j]] = true;   // s[j] appeared once, so mark it true
                len = j - i + 1;   // length of substring between jth and ith index
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }

// -----------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(256) = O(1)
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;   // {character -> it's index in s}
        int maxLen = 0;

        int i = 0, j = 0;
        while(j < n) {
            // If s[j] already occurred in current window [i, j-1], then move i to the right of the last occurrence of s[j]
            // ● Why mp[s[j]] >= i ?
            //  Because, if mp[s[j]] < i, then it means s[j] occurred before the current window [i, j-1],
            //  and thus we don't need to move i.
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }
            int len = j - i + 1;
            maxLen = max(maxLen, len);
            mp[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};


int main() {
    string s = "abcabcbb";

    cout << Solution().lengthOfLongestSubstring_bruteforce(s) << endl;
    cout << Solution().lengthOfLongestSubstring(s);

    return 0;
}
