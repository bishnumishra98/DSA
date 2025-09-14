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

// Approach:-
// 1) Store elements a, b, c, d, etc mapped to indexes t, h, e, q, etc, in a mapping array;
//    where t, h, e, q, etc are elements of keys.
// 2) Store elements from mapping array in a string 'ans' corresponding to indexes of v, k, b, s, etc,
//    where v, k, b, s, etc are elements of message. Then return the 'ans'.

#include <iostream>
using namespace std;

// T.C: O(n);   where n is message.size()
// S.C: O(n)
string decodeMessage(string key, string message) {
    // Creating mapping --->
    char start = 'a';
    char mapping[300] = {0};   // Initializing all elements of array with 0, i.e., '\0' null character.
    // Later, elements of this array will be a, b, c, d, etc. And indexes of this array
    // will be the letters of 'key'. It will be used to map indexes 'key' to elements 'abcd'.

    // for(int i=0; i<key.size(); i++) {
    //     char ch = key[i];
           // rest body
    // }
    // The same above code can be written using foreach loop :-
    // for(auto ch: key) {
           // rest body
    // }

    for(auto ch: key) {
        if(ch != ' ' && mapping[ch] == 0) {   // ch != ' ' ensures no spaces
            // are put inside mapping array. 'mapping[ch] == 0' ensures once an
            // element is given a key, no same key should get a chance to
            // become an index in mapping array. That's why element should be 0 in
            // mapping[ch] to become eligible to get an index.
            mapping[ch] = start;
            start++;
        }
    }


    // using mapping --->
    string ans;

    for(auto ch: message) {
        if(ch == ' ') {
            ans.push_back(' ');   // if there is a space in 'message', push a space in 'ans' too. 
        } else {
            char decoded = mapping[ch];   // each 'decoded' variable will represent
                                         //  meaning of each character in 'message'.
            ans.push_back(decoded);
        }
    }

    return ans;
}


int main() {
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    cout << decodeMessage(key, message);

    return 0;
}
