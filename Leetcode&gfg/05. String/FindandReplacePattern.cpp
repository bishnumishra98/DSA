// Leetcode: 890. Find and Replace Pattern   --->   Given a list of strings words and a string pattern,
// return a list of words[i] that match pattern. You may return the answer in any order.

// Example 1:
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

// Example 2:
// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]

// Tip: Understand 'Leetcode: 2325. Decode the Message' first.

// Approach :-
// We will create a mapping for pattern, then create mapping for each element of 'word' and compare
// it with 'pattern's' mapping. If they both are matching, return that element.

#include <iostream>
#include <vector>
using namespace std;

void printvector(vector <string>& str) {
    for(auto element: str) {
        cout << element << " ";
    }
}

// createMapping() function takes a string and changes it to its equivalent 'abc...' pattern.
// This mapping process is called normalization.
// T.C: O(n);   where n is str.size()
// S.C: O(300) = O(1);
void createMapping(string& str) {
    char start = 'a';
    char mapping[300] = {0};   // initializing all characters of 'str' by 0

    // creating a mapping for 'str'
    for(auto ch: str) {
        if(mapping[ch] == 0) {
            mapping[ch] = start;
            start++;
        }
    }

    // normalizing string, i.e replacing all characters of string 'str' by pattern 'abc...'
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        str[i] = mapping[ch];
    }
}

// leetcode given function
// T.C: O(m*n);   where m = no.of elements in 'words' vector, n = average length of the words.
// S.C: O(m`+n);    where m` = no.of elements in 'ans' vector
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    // normalizing pattern
    createMapping(pattern);

    vector <string> ans;

    for(string element: words) {
        string temp = element;

        createMapping(temp);   // normalizing 'temp'

        if(temp == pattern) {
            ans.push_back(element);
        }
    }

    return ans;
}

int main() {
    vector <string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    vector <string> v;

    v = findAndReplacePattern(words, pattern);

    printvector(v);

    return 0;
}
