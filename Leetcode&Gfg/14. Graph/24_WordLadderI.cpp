// GFG: Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths.
// Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:
// -> A word can only consist of lowercase characters.
// -> Only one letter can be changed in each transformation.
// -> Each transformed word must exist in the wordList including the targetWord.
// -> startWord may or may not be part of the wordList
// Note: If no possible way to transform sequence from startWord to targetWord return 0

// Example 1:
// Input:
// wordList = {"des","der","dfr","dgt","dfs"}
// startWord = "der", targetWord= "dfs",
// Output:
// 3
// Explanation:
// The length of the smallest transformation
// sequence from "der" to "dfs" is 3
// i,e "der" -> "dfr" -> "dfs".

// Example 2:
// Input:
// wordList = {"geek", "gefk"}
// startWord = "gedk", targetWord= "geek", 
// Output:
// 2
// Explanation:
// gedk -> geek

// Example 3:
// Input: 
// wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
// startWord = "toon", targetWord= "plea",
// Output: 7 
// Explanation:
// toon -> poon -> poin -> poie -> plie -> plee -> plea 
 
// Your Task:
// You don't need to read or print anything, Your task is to complete the function wordLadderLength() which takes
// startWord, targetWord and wordList as input parameter and returns the length of the shortest transformation
// sequence from startWord to targetWord. If not possible return 0.

// Algorithm: 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C:
    // S.C: 
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
    }
};

int main() {

    return 0;
}
