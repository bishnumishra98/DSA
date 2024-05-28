// Leetcode: 767. Reorganize String   --->   Given a string s, rearrange the characters of s so that any two adjacent characters
// are not the same. Return any possible rearrangement of s or return "" if not possible.

// Example 1:
// Input: s = "aab"
// Output: "aba"

// Example 2:
// Input: s = "aaab"
// Output: ""

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    string reorganizeString(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Step 2: Create a max heap (priority queue) to store characters based on their frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }
        
        // Step 3: Build the result string
        string result = "";
        pair<int, char> prev = {0, '#'};  // Initialize previous character as a dummy
        
        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            
            // Append the current character to the result
            result += current.second;
            
            // Decrease the frequency of the current character
            current.first--;
            
            // If the previous character has remaining frequency, push it back to the heap
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            
            // Update the previous character to the current one
            prev = current;
        }
        
        // Step 4: Check if the reorganization is valid
        if (result.size() < s.size()) {
            return "";
        }
        
        return result;
    }
};

int main() {
    string s = "aab";

    Solution sol;
    cout << sol.reorganizeString(s);

    return 0;
}
