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

// Algorithm: The algorithm might look complex, but actually it is not. We shall follow the brute force approach. It is just an
//            extension of the previous problem. The only difference is that we have to return all the valid words that come in the
//            path while building the targetWord from the startWord.
// 1. a) Create a queue to store {node, steps} pair in order to facilitate BFS.
//    b) Create a set and store all elements of wordList in it. This is made to make search faster.
// 2. Push the startWord with 1 step in the queue.
// 3. Dequeue the front element of queue and start altering first letter of the word with all possible characters from 'a' to 'z',
//    to check if any valid word(a word that exists in the set) can be formed or not. If a valid word is formed, push that word
//    along with the steps in the queue and erase that word from the set. Continue the process until the queue is empty.
// 4. If the targetWord is found, then return the no.of steps. If not found, return 0.
// 5. If the targetWord is found, then backtrack the path from targetWord to startWord and store all the words in the path in a
//    vector. Return the vector.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(N * M * 26^L), N = no.of words in wordList, M = length of each word, L = length of the word
    // S.C: O(N * M * 26^L)
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            // Erase all words that are already used on previous level
            if(vec.size() > level) {
                level++;
                for(auto it: usedOnLevel) {
                    st.erase(it);
                }
            }

            string word = vec.back();

            if(word == endWord) {
                if(ans.size() == 0) {   // if the ans is empty, then push the first word sequence in the ans
                    ans.push_back(vec);
                } else if(ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                } else {
                    break;
                }
            }

            for(int i = 0; i < word.size(); i++) {
                char letter = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);   // Store the word that is used on this level
                        vec.pop_back();
                    }
                }
                word[i] = letter;
            }
        }

        return ans;
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
        cout << endl;
    }
    cout << endl;

    return 0;
}
