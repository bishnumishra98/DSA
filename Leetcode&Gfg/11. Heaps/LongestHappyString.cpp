// Leetcode: 1405. longest Happy String   --->   A string s is called happy if it satisfies the following conditions:
// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings,
// return any of them. If there is no such string, return the empty string "".

// Example 1:
// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

// Example 2:
// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C:
    // S.C: 
    string longestDiverseString(int a, int b, int c) {
        // Create a max heap to store the counts of 'a', 'b', and 'c'
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
        
        string result = "";
        pair<int, char> prev = {0, '#'};  // Initialize previous character
        
        while(!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            
            // Append current character to result
            if(result.size() >= 2 && result[result.size() - 1] == current.second && result[result.size() - 2] == current.second) {
                if(maxHeap.empty()) break;   // If no alternative, stop
                auto next = maxHeap.top();
                maxHeap.pop();
                
                result += next.second;
                next.first--;
                if(next.first > 0) maxHeap.push(next);
                
                maxHeap.push(current);  // Put the current back for future consideration
            } else {
                result += current.second;
                current.first--;
                if(current.first > 0) maxHeap.push(current);
            }
        }
        
        return result;
    }
};

int main() {
    int a = 1, b = 1, c = 7;
    Solution sol;
    cout << sol.longestDiverseString(a, b, c);
    return 0;
}
