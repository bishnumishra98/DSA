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

#include <iostream>
#include <queue>
using namespace std;

string firstNonRepeatingCharacter(string str) {
    int n = str.length();
    string ans(n, ' ');   // initialized a string of length 'n' with spaces
    queue <char> q;
    int freq[26] = {0};   // as there are only 26 alphabets in English
    // int freq[n] = {x}; means initializing 1st element of array with 'x', and rest with '0'.

    for(int i=0; i<n; i++) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        // Process the queue to find the first non-repeating character
        while(!q.empty()) {
            char frontChar = q.front();
            if (freq[frontChar - 'a'] > 1) {
                // If frontChar occurred more than once, remove it from the queue
                q.pop();
            } else {
                // If frontChar occurred only once, i.e., 'freq[frontChar - 'a'] == 1',
                // update the answer and break the loop
                ans[i] = frontChar;
                break;
            }
        }

        // If the queue is empty, set the answer character to '#'
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
