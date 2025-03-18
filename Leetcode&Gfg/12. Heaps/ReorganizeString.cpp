// Leetcode: 767. Reorganize String   --->   Given a string s, rearrange the characters of s so that any two adjacent characters
// are not the same. Return any possible rearrangement of s or return "" if not possible.

// Example 1:
// Input: s = "aab"
// Output: "aba"

// Example 2:
// Input: s = "aaab"
// Output: ""

// Algorithm:
// 1. Create a maxHeap of (character, frequency). You can use custom data-type or pair to store elements in heap.
// 2. Define a comparator to make maxHeap on the basis of frequency of characters. Or simply insert elements in heap
//    in (frequency, character) sequence, so that elements are compared on the basis of frequency by default.
// 3. Once maxHeap is ready, pop first two elements from heap, push them into the string 'ans' and decrease their
//    frequency by 1. Two elements can be popped from heap by making a while loop: 'while(maxHeap.size() > 1)'.
// 4. Even after decrement of their frequency, if it is greater than 0; push that element back into the maxHeap.
// 5. After coming out of while loop, the heap may contain one last element(a character with its frequency). Pop
//    this element, push into the string and decrement its frequency by 1. If even after decrementing frequency of
//    the last character, it's frequency is not yet 0, it means this character still needs to be pushed into the string
//    making it occur side by side. Thus, this character can no further be pushed into the string and the required
//    rearrangement of the given string is not possible. Thus, return a blank string.
//    And if its frequency is 0, then well and good; all characters have been pushed into the string. Return the string.

#include <bits/stdc++.h>
using namespace std;

// Custom data-type using struct
class Info {
    public:
        char ch;
        int count;

        // Default constructor
        Info() : ch('\0'), count(0) {}

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
    // T.C: O(n)
    // S.C: O(n)
    string reorganizeString(string s) {
        int freq[26] = {0};   // creating a 'freq' array for storing frequency of alphabets. 0 index
        // represents 'a', and freq[0] represents frequency of 'a'. Same applies for other elements too.

        // Counting frequency of all characters at keeping it inside 'freq' array
        for(int i=0; i<s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Create a maxHeap(character, frequency)
        priority_queue<Info, vector<Info>, Compare> maxHeap;
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                // Info temp;
                // temp.ch = i + 'a';
                // temp.count = freq[i];
                // The above 3-step initialization of 'temp' can be done in 1 step like this:
                Info temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";   // the reorganised string will be build in 'ans'

        // maxHeap.size() should be greater than 1, because we have to insert 2 elements at a time into the heap.
        // Suppose we were inserting only 1 element at a time in the maxHeap, then it may be a probability that after
        // pushing highest frequency character in string and decrementing the frequency of that character, it is still
        // the highest occurring element. Thus, the same character gets inserted in the heap and again it becomes the top
        // element of maxHeap. In this case, the next character to be inserted in the string would be again that same
        // character that was pushed last time. Hence, two same characters would come side by side. To avoid this problem,
        // we push the highest and second highest occurring elements from the maxheap into the string at a time, so that
        // no two same characters gets pushed inside the string side by side.
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.ch);
            first.count--;
            ans.push_back(second.ch);
            second.count--;

            if(first.count > 0) maxHeap.push(first);
            if(second.count > 0) maxHeap.push(second);
        }

        // After coming out of while loop, maxHeap may have one element left in it, as the above loop runs for only 'maxHeap.size() > 1'
        if(maxHeap.size() == 1) {
            Info last = maxHeap.top();
            maxHeap.pop();
            ans.push_back(last.ch);   // pushing the last character into string
            last.count--;
            // If even after decrementing count of last character, it's count is not yet 0, it means this
            // character still needs to be pushed into the string making it occur side by side. Thus,
            // rearrangement of the given string was impossible. Thus, return blank string.
            if(last.count > 0) return "";
        }
        
        return ans;   // string formed, return it.
    }
};

int main() {
    string s = "aaabbb";

    Solution sol;
    cout << sol.reorganizeString(s);

    return 0;
}
