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

// Custom data type
struct Info {
    char ch;
    int count;

    // Constructor
    Info(char ch, int count) : ch(ch), count(count) {}
};

// Custom comparator for creating maxHeap
class Compare {
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    string reorganizeString(string s) {
        int freq[26] = {0};   // creating a 'freq' array for storing frequency of alphabets. 0 index
        // represents 'a', and freq[0] represents frequency of 'a'. Same applies for other elements too.

        // Counting frequency of all characters at keeping it inside 'freq' array
        for(int i=0; i<s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Create a maxHeap
        priority_queue<Info, vector<Info>, Compare> maxHeap;
        

    }
};

int main() {
    string s = "aaabbb";

    Solution sol;
    cout << sol.reorganizeString(s);

    return 0;
}
