// Leetcode: 890. Find and Replace Pattern   --->   Given a list of strings words and a string pattern,
// return a list of words[i] that match pattern. You may return the answer in any order.

// Example 1:
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

// Example 2:
// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]

// Tip: Understand 'Leetcode&Gfg\04. String\DecodeTheMessage.cpp' first.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string decodeKey(string key) {
        // // Method 1: Using unordered_map
        // unordered_map<char, char> mp;
        // char i = 'a';
        // for(char ch: key) {
        //     if(mp.find(ch) == mp.end()) {
        //         mp[ch] = i;
        //         i++;
        //     }
        // }

        // string result = "";
        // for(char ch: key) result.push_back(mp[ch]);
        // return result;


        // Method 2 (faster): Using vector instead of unordered_map
        vector<char> mp(26, '0');
        char i = 'a';

        for(char ch: key) {
            if(mp[ch - 'a'] == '0') {
                mp[ch - 'a'] = i;
                i++;
            }
        }

        string result = "";
        for(char ch: key) result.push_back(mp[ch - 'a']);
        return result;
    }

public:
    // T.C: O(pattern) + O(n * m);   where n = words.size() and m = average length of each word
    // S.C: O(1);   as unordered_map/vector will store at max 26 characters
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string decodedPattern = decodeKey(pattern);

        vector<string> result;
        for(string word: words) {
            if(decodeKey(word) == decodedPattern) result.push_back(word);
        }

        return result;
    }
};


int main() {
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    vector<string> ans = Solution().findAndReplacePattern(words, pattern);
    for(auto i: ans) cout << i << " ";

    return 0;
}
