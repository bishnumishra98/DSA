// A trie is a tree-like data structure used to store words so that they can be quickly retrieved by their prefixes. Each
// node represents a character, and paths from the root to a node represent a prefix or a word. This makes it efficient
// for operations like searching for words, inserting new words, and finding all words that start with a given prefix.
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
using namespace std;

class TrieNode {
    public:
        char val;
        TrieNode* children[26];
        bool isTerminal;

        // Default constructor
        TrieNode() {
            this->val = '\0';   // Initialize val to null character
            for(int i=0; i<26; i++) {
                children[i] = NULL;   // Initialize all children to NULL
            }
            this->isTerminal = false;   // Initialize isTerminal to false
        }

        // Parameterized constructor
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
    // cout << "Recieved word: " << word << " for insertion " << endl;   // Printing the received word for confirmation
    // Base case: if the word is empty, mark the current node as terminal
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';   // Calculate the index of the first character of the word. Example: 'a' -> 0, 'b' -> 1, ..., 'z' -> 25.
    TrieNode* child;
    // If there is no child node at the calculated index, create a new TrieNode
    if(!root->children[index]) {   // means 'if(root->children[index] == NULL)'
        child = new TrieNode(word[0]);
        root->children[index] = child;   // Link the new node to the current node's children array
    }
    else {
        // If a child node already exists at the calculated index, use it
        child = root->children[index];
    }

    // Recursive call to insert the remaining characters of the word
    insertWordInTrie(child, word.substr(1));   // substr(1) means remove the first character from word, return the rest
}

// T.C: O(L)
// S.C: O(L)
bool searchWordInTrie(TrieNode* root, string word) {
    // Base case: if the word is empty, check if the current node is terminal
    if(word.length() == 0) return root->isTerminal;

    // Calculate the index of the first character of the word
    // Example: 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
    int index = word[0] - 'a';
    TrieNode* child;

    // If a child node exists at the calculated index, proceed with that child
    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        // If no child node exists at the index, the word is not in the trie
        return false;
    }

    // Recursive call to search the remaining characters of the word
    bool found = searchWordInTrie(child, word.substr(1));
    return found;
}

// T.C: O(L)
// S.C: O(L)
void deleteWordInTrie(TrieNode* root, string word) {
    // Base case: if the word is empty, mark the current node as non-terminal
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    // Calculate the index of the first character of the word
    // Example: 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
    int index = word[0] - 'a';
    TrieNode* child;

    // If a child node exists at the calculated index, proceed with that child
    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        // If no child node exists at the index, the word is not in the trie, return
        return;
    }

    // Recursive call to delete the remaining characters of the word
    deleteWordInTrie(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-');   // marking root node by '-'
    insertWordInTrie(root, "summer");
    insertWordInTrie(root, "sun");
    insertWordInTrie(root, "bat");

    cout << searchWordInTrie(root, "sun") << endl;   // o/p: 1
    cout << searchWordInTrie(root, "sum") << endl;   // o/p: 0
    deleteWordInTrie(root, "sun");
    cout << searchWordInTrie(root, "sun") << endl;   // o/p: 0

    return 0;
}
