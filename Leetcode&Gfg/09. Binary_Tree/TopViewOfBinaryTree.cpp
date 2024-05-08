// This problem falls under views pattern of Binary Tree. Follow this sequence:
// 1. "Leetcode&Gfg\09. Binary_Tree\LeftViewOfBinaryTree.cpp"
// 2. "Leetcode&Gfg\09. Binary_Tree\BinaryTreeRightSideView.cpp"
// 3. "Leetcode&Gfg\09. Binary_Tree\TopViewOfBinaryTree.cpp"
// 4. "Leetcode&Gfg\09. Binary_Tree\BottomViewOfBinaryTree.cpp"

// GFG: Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree
// is the set of nodes visible when the tree is viewed from the top.

//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \
//        8
// Its top view will be 4 2 1 3 7

// This problem will require 3 data structures to get solved: vector, queue and map.

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

class Solution
{
    public:
    // T.C: 
    // S.C: 
    vector<int> topView(Node *root)
    {
        //Your code here
    }

};

int main() {
//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \
//        8
// Its top view will be 4 2 1 3 7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);

    Solution sol;
    vector<int> ans = sol.topView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
