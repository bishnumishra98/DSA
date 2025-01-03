// GFG: An extension of the problem '24_WordLadderI.cpp'. Here we don't need to return the no.of steps, but we have to
// return all valid words that come in the path while building the targetWord from the startWord.

// Example 1:
// Input:
// startWord = "der", targetWord = "dfs",
// wordList = {"des","der","dfr","dgt","dfs"}
// Output:
// der dfr dfs
// der des dfs
// Explanation:
// The length of the smallest transformation is 3. And the following are the only two ways to get to targetWord:-
// "der" -> "des" -> "dfs".
// "der" -> "dfr" -> "dfs".

// Example 2:
// Input:
// startWord = "gedk", targetWord = "geek", 
// wordList = {"geek", "gefk"}
// Output:
// "gedk" -> "geek"

// Your Task:
// You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord,
// targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence
// from startWord to targetWord.
// Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};

int main() {
    string startWord = "der", targetWord = "dfs";
    vector<string> wordList = {"des","der","dfr","dgt","dfs"};

    vector<vector<string>> ans = Solution().findSequences(startWord, targetWord, wordList);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
