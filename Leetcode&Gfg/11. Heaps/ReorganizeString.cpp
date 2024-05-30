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
        for(char c : s) {
            freqMap[c]++;
        }
        
        // Step 2: Create a max heap (priority queue) to store characters based on their frequency
        priority_queue<pair<int, char>> maxHeap;   // intentionally pushing (int, char) so that
        // maxHeap can be created on the basis of 'int', i.e., frequency of character.
        for(auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }
        
        // Step 3: Build the result string
        string result = "";
        pair<int, char> prev = {0, '#'};   // Initialize previous character as a dummy
        
        while(!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            
            result += current.second;   // Append the current character to the result
            
            current.first--;   // Decrease the frequency of the current character
            
            // If the previous character has remaining frequency, push it back to the heap
            if (prev.first > 0) maxHeap.push(prev);
            
            prev = current;   // Update the previous pointer to the current one
        }
        
        // Step 4: If result.size() is smaller than s.size(), the reorganization was not possible
        if(result.size() < s.size()) return "";
        
        return result;   // here result.size() == s.size()
    }
};

int main() {
    string s = "aaabbb";

    Solution sol;
    cout << sol.reorganizeString(s);

    return 0;
}
