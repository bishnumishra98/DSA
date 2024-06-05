// Leetcode 1268. Search Suggestions System   --->   You are given an array of strings products and a string searchWord.
// Design a system that suggests at most three product names from products after each character of searchWord is typed.
// Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix
// return the three lexicographically minimums products.
// Return a list of lists of the suggested products after each character of searchWord is typed.

// Example 1:
// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
// Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

// Example 2:
// Input: products = ["havana"], searchWord = "havana"
// Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
// Explanation: The only word "havana" will be always suggested while typing the search word.

// This problem is a continuation of 'BaseBuildingPrograms\20. Trie\T02_SearchSuggestionFromWord.cpp'.

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char val;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char val) {
            this->val = val;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

class Solution {
public:
    // Function to insert a word into the Trie
    void insertWordInTrie(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(!root->children[index]) {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        } else {
            child = root->children[index];
        }
        insertWordInTrie(child, word.substr(1));
    }

    // Helper function to store strings from the Trie into the results vector
    void storeString(TrieNode* root, vector<string>& ans, string& searchString, string& prefix) {
        // Base case: if the current node is a terminal node, add the word formed so far into the 'ans'
        if(root->isTerminal == true) ans.push_back(prefix + searchString);

        // Traverse all possible children nodes
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(ans.size() >= 3) return;  // If we already have 3 suggestions, stop further processing
            int index = ch - 'a';
            TrieNode* next = root->children[index];
            if(next != NULL) {
                // If a child node exists at the current index
                searchString.push_back(ch);  // Add the character to the current searchString
                // Recursive call to explore the child node
                storeString(next, ans, searchString, prefix);
                // Backtrack: remove the character after returning from the recursion
                searchString.pop_back();
            }
        }
    }

    // Function to get suggestions from the Trie based on the input prefix
    vector<vector<string>> getSuggestions(TrieNode* root, string input) {
        vector<vector<string>> output;
        TrieNode* prev = root;
        string inputhelper = "";

        // Iterate through each character of the input string
        for(int i = 0; i < input.length(); i++) {
            char lastchar = input[i];
            int index = lastchar - 'a';
            TrieNode* curr = prev->children[index];

            // If no child node exists, break the loop
            if(curr == NULL) {
                break;
            } else {
                vector<string> nicheKaAns;
                inputhelper.push_back(lastchar);
                string dummy = "";
                storeString(curr, nicheKaAns, dummy, inputhelper);  // Pass 'inputhelper' as the prefix and 'dummy' as the current word being formed
                output.push_back(nicheKaAns);
                prev = curr;  // Move to the next node
            }
        }
        return output;
    }

    // Main function to get suggested products based on the search word
    // T.C: O(N*L) + O(S);   where N = no.of words and L is average length of each word, S = length of 'searchWord'
    // S.C: O(N*L) + O(S)
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Creating a Trie data structure from the elements of 'products'
        TrieNode* root = new TrieNode('-');
        for(string s : products) {
            insertWordInTrie(root, s);
        }

        // Get suggestions based on the search word
        vector<vector<string>> ans = getSuggestions(root, searchWord);
        // Ensure the output has the same length as the searchWord by adding empty lists if necessary
        while(ans.size() < searchWord.length()) {
            ans.push_back({});
        }
        return ans;
    }
};

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";

    Solution sol;
    vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
