// Leetcode: 2325. Decode the Message   --->   You are given the strings key and message, which represent a cipher key
// and a secret message, respectively. The steps to decode message are as follows:
// 1. Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
// 2. Align the substitution table with the regular English alphabet.
// 3. Each letter in message is then substituted using the table.
// 4. Spaces ' ' are transformed to themselves.
// ● For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet),
//   we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
//   Return the decoded message.

// Example 1:
// t h e q u i c k b r o w n f x j m p s v l a z y d g
// a b c d e f g h i j k l m n o p q r s t u v w x y z
// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// Output: "this is a secret"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

// Example 2:
// e l j u x h p w n y r d g t q k v i s z c f m a b o
// a b c d e f g h i j k l m n o p q r s t u v w x y z
// Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
// Output: "the five boxing wizards jump quickly"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".

// Problem link: https://leetcode.com/problems/decode-the-message/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(key + message)
    // S.C: O(1);   as unordered_map will store at max 26 characters
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char i = 'a';

        // Create the mapping of {secret_char: normal_char}
        for(char ch: key) {
            if(ch != ' ' && mp.find(ch) == mp.end()) {   // only consider non-space characters and map their first occurrence
                mp[ch] = i;
                i++;
            }
        }

        string result = "";
        // Decode the message using the mapping
        for(char ch: message) {
            if(ch == ' ') result.push_back(' ');
            else result.push_back(mp[ch]);
        }

        return result;
    }

// ------------------------------------------------------------------------------------------------------------

    // More optimised code (using vector instead of unordered_map)
    // T.C: O(key + message)
    // S.C: O(1);   as vector will store at max 26 characters
    string decodeMessage_arrayMethod(string key, string message) {
        vector<char> mp(26, '0');   // secret_char: normal_char; example:- 19: a, 7: b, etc., which means 't': 'a', 'h': 'b', etc.
        char i = 'a';

        // Build mapping
        for(char ch : key) {
            if(ch != ' ' && mp[ch - 'a'] == '0') {
                mp[ch - 'a'] = i;
                i++;
            }
        }

        string result = "";
        // Decode the message using the mapping
        for(char ch : message) {
            if(ch == ' ') result.push_back(' ');
            else result.push_back(mp[ch - 'a']);
        }

        return result;
    }
};


int main() {
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    cout << Solution().decodeMessage(key, message) << endl;
    cout << Solution().decodeMessage_arrayMethod(key, message);

    return 0;
}
