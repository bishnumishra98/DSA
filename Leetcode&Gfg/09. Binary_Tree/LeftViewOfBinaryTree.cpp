// GFG: Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree
// is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as
// argument. If no left view is possible, return an empty tree.

// Left view of following tree is 1 2 4 8.
//          _ 1 _ 
//         /     \
//        2       3
//       / \     / \
//      4   5   6   7
//       \
//        8


#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Simple Algorithm:

// leftView(root):
//     1. Initialize an empty vector 'leftViewVector' to store the left view of the binary tree.
//     2. Initialize a variable 'level' to 0.
//     3. Call solve(root, leftViewVector, level) to traverse the tree and populate the left view.
//     4. Return leftViewVector.

// solve(root, leftViewVector, level):
//     1. If root is NULL, return.
//     2. If the size of leftViewVector is equal to the current level, push the value of root->data into leftViewVector.
//     3. Recursively call solve for the left subtree with level+1(as left subtree will be present in next level).
//     4. Recursively call solve for the right subtree with level+1(as right subtree will be present in next level).

void solve(Node* root, vector<int>& leftViewVector, int level) {
    if(root == NULL) return;

    // If level of tree matches the size of 'leftViewVector' array, push that 'root->data' into 'leftViewVector'.
    if(leftViewVector.size() == level) leftViewVector.push_back(root->data);

    solve(root->left, leftViewVector, level+1);
    solve(root->right, leftViewVector, level+1);
}

// T.C: O(n);   where n is the number of nodes in the binary tree.
// S.C: O(h);   where h is the height of the binary tree.
vector<int> leftView(Node *root) {
    vector<int> leftViewVector;
    int level = 0;

    solve(root, leftViewVector, level);

    return leftViewVector;
}

int main() {
//          _ 1 _ 
//         /     \
//        2       3
//       / \     / \
//      4   5   6   7
//       \
//        8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);

    vector<int> ans = leftView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
