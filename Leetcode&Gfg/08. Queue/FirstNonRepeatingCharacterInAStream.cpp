// GFG: Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n),
//      find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

// Example 1:
// Input: s = "aabc"
// Output: a#bb
// Explanation: 
// At i=0 ("a"): First non-repeating character is 'a'.
// At i=1 ("aa"): No non-repeating character, so '#'.
// At i=2 ("aab"): First non-repeating character is 'b'.
// At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'. 

// Example 2:
// Input: s = "bb" 
// Output: "b#" 
// Explanation: 
// At i=0 ("b"): First non-repeating character is 'b'.
// At i=1 ("bb"): No non-repeating character, so '#'.

// Problem link: https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Algorithm: It is very simple.
// The idea is to maintain a group of characters in the queue which have appeared only once. To know the
// uniqueness of a character, keep a track of their frequency in a 'freq' vector.
// If the front element of the queue is found to appear more than once, never allow it to stay in the queue
// in the currrent iteration as well as in any other future iterations.
// So for every ith character, the front element of the queue acts as the first non-repeating character
// till ith character.


#include <bits/stdc++.h>
using namespace std;

// T.C: O(n)
// S.C: O(1)
string firstNonRepeatingCharacter(string str) {
    vector<int> freq(26, 0);   // frequency of each lowercase letter
    queue<char> q;   // store characters in order of arrival
    string ans;

    for(char ch: str) {
        int idx = ch - 'a';
        freq[idx]++;   // increment frequency
        q.push(ch);   // push this character into queue

        // Remove characters from the front of the queue which have frequency more than 1, because 'q' is
        // supposed to store only characters that have appeared only once, i.e., characters with frequency 1.
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // If queue is empty, no unique character is found; thus append '#'; else append front character
        if(q.empty()) ans.push_back('#');
        else ans.push_back(q.front());
    }

    return ans;
}

int main() {
    string str = "aabac";
    cout << firstNonRepeatingCharacter(str);

    return 0;
}
