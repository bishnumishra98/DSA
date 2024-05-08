// This problem falls under views pattern of Binary Tree. Follow this sequence:
// 1. "Leetcode&Gfg\09. Binary_Tree\LeftViewOfBinaryTree.cpp"
// 2. "Leetcode&Gfg\09. Binary_Tree\BinaryTreeRightSideView.cpp"
// 3. "Leetcode&Gfg\09. Binary_Tree\TopViewOfBinaryTree.cpp"
// 4. "Leetcode&Gfg\09. Binary_Tree\BottomViewOfBinaryTree.cpp"

// GFG: Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

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
    vector<int> bottomView(Node *root)
    {
        //Your code here
    }

};

int main() {
//          1 
//         / \
//        2   3
//       / \
//      4   5
//       \
//        6
// Its bottom view will be 4 6 5 3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.bottomView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
