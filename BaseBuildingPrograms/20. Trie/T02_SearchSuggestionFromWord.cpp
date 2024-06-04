// Given a Trie containing many words, and a word. Show all possible words present in trie from that suggestion.
// Example:
//             (root)
//            /  |  \
//           h   a   s
//          /    |    \
//         e     n     u
//        / \    |\    |\
//       l   a   t i   n m
//      /     \     \     \ 
//     l       t     m     m
//    /               \     \   
//   o                 a     e           
//                      \     \
//                       l     r 
// Words in the above Trie: {"hell", "hello", "heat", "bat", "bamboo", "sun", "sum", "summer"}
// Applications:
// 1. Autocomplete: Efficiently finding all keys with a common prefix.
// 2. Spell Checking: Quickly verifying if a string is a valid word.
// 3. IP Routing: Storing routing tables in networks.
// 4. DNA Sequencing: Storing and querying sequences in bioinformatics.
// 5. Compression: Techniques like T9 predictive text input.

#include<iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
        char val;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode() {
            this->val = '\0';
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
        TrieNode(char val) {
            this->val = val;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

// T.C: O(L);   where L = length of word
// S.C: O(L)
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
    }
    else {
        child = root->children[index];
    }
    insertWordInTrie(child, word.substr(1));
}

// -----------------------------------------------------------------------------------------------------------------------------------

// Arguments received: storeString(lastChar, ans, searchString, prefix);
void storeString(TrieNode* root, vector<string>& ans, string& searchString, string& prefix) {
    // Base case: if the current node is a terminal node, add the word formed so far into the 'ans'
    if(root->isTerminal == true) ans.push_back(prefix + searchString);

    // Traverse all possible children nodes
    for(char ch = 'a'; ch <= 'z'; ch++) {
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

// Function to find all words in the Trie that start with a given prefix
// T.C: O(P+k);   where P is the length of the prefix, K is the number of nodes in the Trie.
// S.C: O(P)
void findPrefixString(TrieNode* root, string searchString, vector<string>& ans, string& prefix) {
    // Base case: if the searchString is empty, store all words starting from this node
    if(searchString.length() == 0) {
        // After reaching the last character of 'searchString', search for all possible
        // strings in the trie, via the storeString() function and store them in 'ans'.
        TrieNode* lastChar = root;
        storeString(lastChar, ans, searchString, prefix);
        return;
    }

    // 'index' holds the integer equivalent of first character of the searchString
    int index = searchString[0] - 'a';
    TrieNode* child;

    // If a child node exists for the first character of prefix, continue the search
    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        // If no child node exists for the first character of prefix, then this
        // prefix will obvoiusly not be present in the Trie. Thus return.
        return;
    }

    // Recursive call to process the remaining characters of the searchString
    findPrefixString(child, searchString.substr(1), ans, prefix);
}

int main() {
    // Initialize the Trie and insert words
    TrieNode* root = new TrieNode('-');  // Marking root node by '-'
    insertWordInTrie(root, "hell");
    insertWordInTrie(root, "hello");
    insertWordInTrie(root, "heat");
    insertWordInTrie(root, "bat");
    insertWordInTrie(root, "bamboo");
    insertWordInTrie(root, "sun");
    insertWordInTrie(root, "sum");
    insertWordInTrie(root, "summer");
    // Words inserted in the Trie: {"hell", "hello", "heat", "bat", "bamboo", "sun", "sum", "summer"}

    string searchString = "he";
    string prefix = searchString;

    vector<string> ans;
    findPrefixString(root, searchString, ans, prefix);

    // Print all words that start with the given prefix
    for(string i: ans) {
        cout << i << " ";
    }

    return 0;
}
