// Leetcode: 2325. Decode the Message   --->   You are given the strings key and message, which
// represent a cipher key and a secret message, respectively. Return the decoded message.

// Example 1:
// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// Output: "this is a secret"
// thequickbrownfxjmpsvlazydg
// abcdefghijklmnopqrstuvwxyz
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

// Approach:-
// 1) Store elements a, b, c, d, etc mapped to indexes t, h, e, q, etc, in a mapping array;
//    where t, h, e, q, etc are elements of keys.
// 2) Store elements from mapping array in a string 'ans' corresponding to indexes of v, k, b, s, etc,
//    where v, k, b, s, etc are elements of message. Then return the 'ans'.

#include <iostream>
using namespace std;

// T.C: O(n);   where n is message.size()
// S.C: O(n);   where n is message.size()
string decodeMessage(string key, string message) {
    // Creating mapping --->
    char start = 'a';
    char mapping[300] = {0};   // Initializing all elements of array with 0, i.e '\0' null character.
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