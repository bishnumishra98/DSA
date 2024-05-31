// Leetcode: 1405. longest Happy String   --->   A string s is called happy if it satisfies the following conditions:
// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings,
// return any of them.

// Example 1:
// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

// Example 2:
// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.

// Algorithm: Exactly similar to 'Leetcode&Gfg\11. Heaps\ReorganizeString.cpp'.

#include <bits/stdc++.h>
using namespace std;

// Custom data-type using struct
class Info {
    public:
        char ch;
        int count;
        // Default constructor not required as objects can be initialzied directly with arguments.
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
        /*
        // Making maxHeap using custom data-type
        priority_queue<Info, vector<Info>, Compare> maxHeap;
        if(a > 0) {
            Info temp('a', a);
            maxHeap.push(temp);
        }
        if(b > 0) {
            Info temp('b', b);
            maxHeap.push(temp);
        }
        if(c > 0) {
            Info temp('c', c);
            maxHeap.push(temp);
        }
        */

        // Making maxHeap using pair(int, char). Keeping first element of pair as 'int'
        // gives an advantage of not making custom comparator to create the maxHeap.
        priority_queue<pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push(make_pair(a, 'a'));
        if(b > 0) maxHeap.push(make_pair(b, 'b'));
        if(c > 0) maxHeap.push(make_pair(c, 'c'));

        string ans = "";
        while(maxHeap.size() > 1) {
            auto firstElement = maxHeap.top();
            maxHeap.pop();
            auto secondElement = maxHeap.top();
            maxHeap.pop();

            // If frequency of firstElement is greater than equal to 2, it can be inserted atmost 2 times side by side
            if(firstElement.first >= 2) {
                ans.push_back(firstElement.second);   // push this character in string 'ans' 2 times
                ans.push_back(firstElement.second);
                firstElement.first -= 2;   // decrement frequency of this character by 2
            } else {   // Frequency of firstElement is 1
                ans.push_back(firstElement.second);   // push this character in string 'ans' only once
                firstElement.first -= 1;   // decrement frequency of this character by 1
            }

            // If frequency of secondElement is greater than equal to 2, and greater than equal to
            // frequency of firstElement, it can be inserted atmost 2 times side by side.
            if(secondElement.first >= 2 && secondElement.first >= firstElement.first) {
                ans.push_back(secondElement.second);   // push this character in string 'ans' 2 times
                ans.push_back(secondElement.second);
                secondElement.first -= 2;   // decrement frequency of this character by 2
            } else {   // Frequency of secondElement is 1
                ans.push_back(secondElement.second);   // push this character in string 'ans' only once
                secondElement.first -= 1;   // decrement frequency of this character by 1
            }

            // If frequency of 'firstElement' is greater than 0, insert this element back to maxHeap
            if(firstElement.first > 0) maxHeap.push(firstElement);
            // If frequency of 'secondElement' is greater than 0, insert this element back to maxHeap
            if(secondElement.first > 0) maxHeap.push(secondElement);
        }

        // It may be a possibility, that is still 1 element left in maxHeap
        if(maxHeap.size() == 1) {
            auto lastElement = maxHeap.top();   // 'pair<int, char>' can also be written instead of 'auto'
            maxHeap.pop();

            // If frequency of lastElement is greater than equal to 2, it can be inserted atmost 2 times side by side
            if(lastElement.first >= 2) {
                ans.push_back(lastElement.second);   // push this character in string 'ans' 2 times
                ans.push_back(lastElement.second);
            } else {   // Frequency of lastElement is 1
                ans.push_back(lastElement.second);   // push this character in string 'ans' only once
            }
        }

        return ans;   // longest possible string formed. Return it.
    }
};

int main() {
    int a = 1, b = 1, c = 7;
    Solution sol;
    cout << sol.longestDiverseString(a, b, c);
    return 0;
}
