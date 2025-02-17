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

// Algorithm: The algorithm might look complex, but actually it is not. We shall follow the brute force approach. It is
//            just an extension of the previous problem. The only difference is that we have to return all the valid words
//            that come in the path while building the targetWord from the startWord.
// 1. a) Create a queue 'q' to store word sequences, i.e., {vector<string>} in order to facilitate BFS.
//    b) Create a set 'st' and store all elements of wordList in it. This is made to make search faster.
//    c) Create a vector<string> 'usedOnLevel' to store all the words that are used on a particular level. This is made to
//       erase all the words that are used on the previous level from the set.
//    d) Create a vector<vector<string>> 'ans' to store all the shortest word sequences that come in the path while
//       building the endWord.
// 2. Push the startWord in the queue. Also, store the startWord in 'usedOnLevel'.
// 3. Dequeue the front element of queue and the store the word sequence in a vector of string 'seq'. Then pop the queue.
// 4. If the length of the word sequence, i.e., seq.size() is greater than the level, then increment the level and erase all
//    the words from the set that were used on the previous level. Note that, on level 1, word sequence length will be 1,
//    on level 2, word sequence length will be 2 and so on.
// 5. Get the last word from the current word sequence and store it in 'word'.
// 6. If 'word' is equal to 'endWord', then we have finally reached our target. So now check if the word belongs to the
//    part of a shortest sequence or not. This can be checked via checking if the 'ans' is empty or not.
//    Case A: If ans is empty, it means this is the first word sequence that reaches the endWord. Since we are
//            performing a level-wise BFS, the first sequence to reach endWord will always be the shortest one.
//            Thus, definitely add this sequence to ans.
//    Case B: If ans is not empty, then check the size of the first sequence of ans, i.e., ans[0]. ans[0].size()
//            gives the length of the shortest sequence stored in ans so far. If the length of the current sequence
//            'seq.size()' matches the length of the shortest sequence, add this sequence too in the ans.
// 7. Alter every letter of the word and check if it matches with any word in the set 'st'. If it does, then add it
//    in the current sequence 'seq' and push the updated sequence in the queue. Then pop this word out from the
//    sequence 'seq' so that we can try adding some other word to the sequence instead of this word. Finally, push
//    this word in the 'usedOnLevel' vector.
//    Repeat the above steps 3-7 until the queue is empty.
// 8. Return the ans.


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
            vector<string> seq = q.front();   // 'seq' is the current sequence of words in this level
            q.pop();
            
            // beginWord is considered level 1. In level 2, there will be 2 words, in level 3, there will be 3 words and so on.
            // Thus, if we are on a new level, seq.size() will be greater than level. In this case, erase all words from the
            // set that were used on the previous level.
            if(seq.size() > level) {
                level++;
                for(auto it: usedOnLevel) {
                    st.erase(it);
                }
            }

            string word = seq.back();   // 'word' is the last string in the sequence in current level

            // If endWord is reached, then check if the word belongs to the part of a shortest sequence or not.
            // If it does, then add it to the ans.
            if(word == endWord) {
                if(ans.size() == 0) {
                    ans.push_back(seq);
                } else if(ans[0].size() == seq.size()) {
                    ans.push_back(seq);
                }
            }
            
            // Traverse through entire word and change each letter at a time and check if it is present in the set.
            // If its present, then add it in the current sequence 'seq' and push the updated sequence in the queue.
            // Then pop this word out from the sequence 'seq' so that we can try adding some other word to the sequence
            // instead of this word. Finally, push this word in the 'usedOnLevel' vector.
            for(int i = 0; i < word.size(); i++) {
                char letter = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(st.find(word) != st.end()) {
                        seq.push_back(word);
                        q.push(seq);
                        seq.pop_back();
                        usedOnLevel.push_back(word);   // store the word that is used on this level
                    }
                }
                word[i] = letter;   // revert back the word to its original state
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
