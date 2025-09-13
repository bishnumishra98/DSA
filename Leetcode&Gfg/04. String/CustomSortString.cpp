// Leetcode: 791. Custom Sort String   --->   You are given two strings order and s. All the
// characters of order are unique and were sorted in some custom order previously. Permute the
// characters of s so that they match the order that order was sorted.

// Example 1:
// Input: order = "cba", s = "abcd"
// Output: "cbad"

// Example 2:
// Input: order = "cbafg", s = "abcd"
// Output: "cbad"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n + m);   n = length of string s, m = length of string order
    // S.C: O(m);   where m = order.size()
    string customSortString(string order, string s) {
        // Frequency of characters in s
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;

        string result = "";

        // Step 1: Add chars according to 'order'
        for(char c : order) {
            while(freq[c] > 0) {
                result.push_back(c);
                freq[c]--;
            }
        }

        // Step 2: Add remaining chars not in 'order'
        for(char c : s) {
            while(freq[c] > 0) {
                result.push_back(c);
                freq[c]--;
            }
        }

        return result;
    }
};


int main() {
    string order = "cbafg", s = "abcd";

    cout << Solution().customSortString(order, s);
    
    return 0;
}
