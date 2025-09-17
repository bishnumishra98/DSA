// Leetcode: 49. Group Anagrams   --->   Given an array of strings strs, group the anagrams together. You can
// return the answer in any order.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation:
// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Bruteforce algorithm: It is very simple. First understand this problem: 'Leetcode&Gfg\04. String\ValidAnagram.cpp'.

// Optimal algorithm: It's also simple. The idea is to create a unique key for each group of anagrams, and then use
//                    that key to group the anagrams together in a hash map. Later we can extract all the groups from
//                    the hash map and return them as a vector of vectors.
// 1. Create a frequency array of size 26 (for each character in the alphabet) for each string.
// 2. Use this frequency array to create a unique key for each group of anagrams. For example, the string "bad" will
//    have a frequency array like [1, 1, 0, 1, 0, ...0s]. And the key for it can be like "#1#1#0#1#0...0s".
//    Note: We have used "#" to create key because if we don't use it, then the key for two different strings can also
//          become same and hence, they both will be grouped together which is wrong; for example: try out making key for
//          ["bdddddddddd","bbbbbbbbbbc"], and you will see that both will have same key "0101000...". Hence, they will be
//          grouped together which is wrong.
//          On the other hand, if we use a "#" after every frequency, then the keys will be like "#0#1#0#10#0#0#..." and
//          "#0#10#1#0#0#0..." respectively which are different, thus they will be grouped separately which is correct.
// 3. Use an unordered_map to map each key to a vector of strings that are anagrams of each other.
//    Example:
//    KEY (string)    |   VALUE (vector of strings)
//    -----------------------------------------------
//    #1#1#0#2#0...   |   abdd, badd, dbad
//    #1#0#1#1#0...   |   acd, adc, cad
//
// 4. Finally, extract all the groups from the unordered_map and return them as a vector of vectors.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);   // to store frequency of characters; example: 0: 1, 1: 3 means 'a' occurs once, 'b' occurs 3 times and so on.

        for(char ch: s) freq[ch - 'a']++;   // increment frequency for characters in s.
        for(char ch: t) freq[ch - 'a']--;   // decrement frequency for characters in t.

        // If both strings are anagrams, frequency of all characters should be zero.
        for(int it: freq) if(it != 0) return false;
        return true;
    }

public:
    // T.C: O(n^2 * m);   where n = strs.size() and m = length of the longest string in strs
    // S.C: O(n)
    vector<vector<string>> groupAnagrams_bruteforce(vector<string>& strs) {
        set<vector<string>> st;   // to store only unique groups

        for(int i = 0; i < strs.size(); i++) {
            vector<string> group = {strs[i]};   // let the current string be the first member of it's anagram group
            for(int j = 0; j < strs.size(); j++) {
                if(i == j) continue;   // do not check anagram of the string with itself
                if(isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                }
            }
            sort(group.begin(), group.end());
            st.insert(group);
        }

        vector<vector<string>> ans(st.begin(), st.end());
        return ans;
    }

// ------------------------------------------------------------------------------------------------------------

    // T.C: O(n * m);   where n = strs.size() and m = length of the longest string in strs
    // S.C: O(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s: strs) {
            vector<int> freq(26, 0);
            for(char ch: s) freq[ch - 'a']++;

            // Build key from frequency array
            string key;
            for(int count: freq) key += "#" + to_string(count);

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it: mp) ans.push_back(move(it.second));   // move() is optional, but it avoids copying of vector and thus is faster
        return ans;
    }
};


int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans1 = Solution().groupAnagrams_bruteforce(strs);
    for(auto it1: ans1) {
        for(auto it2: it1) cout << it2 << " ";
        cout << "; ";
    }

    cout << endl;

    vector<vector<string>> ans2 = Solution().groupAnagrams(strs);
    for(auto it1: ans2) {
        for(auto it2: it1) cout << it2 << " ";
        cout << "; ";
    }

    return 0;
}
