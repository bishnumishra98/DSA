// There is a string containing a stream. Return first non-repeating character in the stream.
// If no non-repeating character is found in the stream, return #.

// Example 1:
// Input:
// ababc
// Output:
// aab#c
// Explanation:
// For 'a', first non-repeating character is 'a'.
// For 'ab', first non-repeating character is 'a'.
// For 'aba', first non-repeating character is 'b'.
// For 'abab', first non-repeating character is '#'.
// For 'ababc', first non-repeating character is 'c'.

// Algorithm:
// 1) Take one character at a time from the string, increase its count in the 'freq' array,
//    and push it into the queue.
// 2) Process the queue:
//    i.   While the queue is not empty, continuously check if the front character of the queue
//         occurred only once in the string according to the 'freq' array. If it occurred only
//         once, store it in the 'ans' string and break out of the loop.
//    ii.  If the front character occurred more than once, pop it out from the queue until an
//         element comes to the front of the queue, which occurred only once according to
//         the 'freq' array.
//    iii. If the queue becomes empty during the popping process, store '#' in 'ans'.

// Q) Why we used queue in this question ?
// A) Because with the help of a queue data structure, we can iterate elements from L to R in
//    a string/array. Further, queue will help us keep a track of unique characters of string.

#include <iostream>
#include <queue>
using namespace std;

// T.C: O(n)
// S.C: O(1)
string firstNonRepeatingCharacter(string str) {
    int n = str.length();
    string ans(n, ' ');   // initialized a string of length 'n' with spaces
    queue <char> q;
    int freq[26] = {0};   // as there can be only 26 alphabets in English
    // int freq[n] = {x}; means initializing 1st element of array with 'x', and rest with '0'.

    for(int i=0; i<n; i++) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        // Process the queue to find the first non-repeating character
        while(!q.empty()) {
            char frontChar = q.front();
            if(freq[frontChar - 'a'] > 1) {
                // If frontChar occurred more than once, remove it from the queue
                q.pop();
            } else {
                // If frontChar occurred only once, i.e., 'freq[frontChar - 'a'] == 1',
                // update the 'ans' and break the loop
                ans[i] = frontChar;
                break;
            }
        }

        // If the queue is empty, set the ans[i] character to '#'
        if(q.empty()) {
            ans[i] = '#';
        }
    }

    return ans;
}

int main() {
    string str = "ababc";
    cout << firstNonRepeatingCharacter(str);

    return 0;
}
