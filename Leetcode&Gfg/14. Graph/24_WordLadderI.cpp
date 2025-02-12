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
// The length of the smallest transformation sequence from "der" to "dfs" is 3 i,e "der" -> "dfr" -> "dfs".

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

// Algorithm: The algorithm might look complex, but actually it is not. We shall follow the brute force approach.
//            Alter one letter from startWord at a time and check if its a valid word in wordList or not. If so, then 
//            increment the count the no.of words(we will call it steps) we are going through from wordList. For example:
// wordList = {"des","der","dfr","dgt","dfs"}
// startWord = "der", targetWord= "dfs"
// The startWord is "der" and we have to make "dfs" by changing one letter at a time and the word formed by changing
// the letter must be a valid word in the wordList. And then we have to return the no.of words we went through from the
// wordList in order to reach the targetWord. Thus, the word path would look like this: 
//          der       ---> step 1
//        /  |  \
//          dfr       ---> step 2
//        /  |  \
//              dfs   ---> step 3
// Thus, it took 3 words to reach from startWord to targetWord there. So return 3. It is obviously that if startWord can
// be converted to targetWord, the minimum no.of words would be 2 (the two words itself).
// 1. a) Create a queue to store {node, steps} pair in order to facilitate BFS.
//    b) Create a set and store all elements of wordList in it. This is made to make search faster.
// 2. Push the startWord with 1 step in the queue.
// 3. Dequeue the front element of queue and start altering first letter of the word with all possible characters from 'a' to 'z',
//    to check if any valid word(a word that exists in the set) can be formed or not. If a valid word is formed, push that word
//    along with the steps(steps will obviously be step+1 now) in the queue. Then erase this word from the set. Continue the
//    process until the targetWord is built. In the worst case, if the queue becomes empty and the targetWord is still not yet
//    built, then the targetWord cannot be built, hence return 0 step.
//    More info: In BFS, we used to create a 'vis' array to keep track of nodes visited, so that we do not visit an already
//               visited node again. Here, we are doing the same using the set.
//               We are deleting the word from set that has been matched during the word buildup process, so that we can keep track
//               of words that are already build, and we do not push it in the queue if the same word is rebuild in further steps.
 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: Average case: O(N*L*26), worst case: O(N*L*26 + N);   where N = wordList.size(), L = average length of each word in wordList
    //      The outer-inner for loops run for L*26 times at max. The queue can have at most N elements so while loop for queue may run
    //      run at most N times. Combining both, we get O(N*L*26). And for search in the set, avg T.C is O(1) and worst is O(n).
    // S.C: O(N+L);   as at max N elements can be stored in the queue and the set. And we use constant extra space for variables
    //      like the current word, which is O(L). Combining all we get O(2N + L) = O(N+L)
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Push the startWord in the queue
        q.push({startWord, 1});
        st.erase(startWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetWord) return steps;   // if the word formed is the targetWord, then return the no.of steps

            // Alter every letter of the word and check if it matches with any word in the wordList
            for(int i = 0; i < word.size(); i++) {   // lets say if word = "der"
                char letter = word[i];   // when i = 0, the letter = 'd'; when i = 1, then letter 'e', when i = 2, then letter = 'r'
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;   // replacing first letter of word with ch(runs from 'a' to 'z'). When ch = 'a', then word = "aer"
                    // If the formed word exists in the set 'st', then push it along with steps in the queue and erase it from the set.
                    if(st.find(word) != st.end()) {
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = letter;   // make sure you revert back the word[i] to its initial letter so that each and every sequence
                                   // can be formed without any missing words. For exmaple: in the end of the above for loop, the
                                  // word formed would be "zer". So we are done with trying out all possible combinations for the
                                 // first letter, now its time to try out all letter combinations for second letter of "der".
                                // Thus, before going back to the outer for loop, revert back the changes you made to the first
                               // letter, i.e., make the word back to "der".

            }
        }

        return 0;   // if program comes here, the targetWord couldn't be built. Thus, return 0 step.
    }
};

int main() {
    vector<string> wordList = {"des","der","dfr","dgt","dfs"};
    string startWord = "der", targetWord= "dfs";

    cout << Solution().wordLadderLength(startWord, targetWord, wordList);

    return 0;
}
