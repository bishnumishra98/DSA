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

// Algorithm: Similar to 'Leetcode&Gfg\11. Heaps\ReorganizeString.cpp'.

#include <bits/stdc++.h>
using namespace std;

// Custom data-type using struct
class Info {
    public:
        char ch;
        int count;
        // Default constructor not required as we will initialize object directly with arguments.
        // Parameterized constructor
        Info(char ch, int count) {
            this->ch = ch;
            this->count = count;
        }
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
    // T.C:
    // S.C: 
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, Compare> maxHeap;

    }
};

int main() {
    int a = 1, b = 1, c = 7;
    Solution sol;
    cout << sol.longestDiverseString(a, b, c);
    return 0;
}
