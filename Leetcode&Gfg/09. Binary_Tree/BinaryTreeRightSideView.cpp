// Exactly same as "Leetcode&Gfg\09. Binary_Tree\LeftViewOfBinaryTree.cpp". The only difference being here is that
// first call recursion for right subtree, then for left subtree, as we have to store the right view of the binary tree.

// Leetcode: 199. Binary Tree Right Side View ---> Given the root of a binary tree, imagine yourself standing on the
// right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:
//         1
//        / \
//       2   3
//        \   \
//         5   4 
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

// Example 2:
// Input: root = [1,null,3]
// Output: [1,3]

// Example 3:
// Input: root = []
// Output: []

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, vector<int>& rightViewVector, int level) {
        if(root == NULL) return;

        if(rightViewVector.size() == level) rightViewVector.push_back(root->val);

        solve(root->right, rightViewVector, level+1);
        solve(root->left, rightViewVector, level+1);
    }

    // T.C: O(n)
    // S.C: O(h)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightViewVector;
        int level = 0;
        solve(root, rightViewVector, level);
        return rightViewVector;
    }
};

int main() {
//          _ 1 _ 
//         /     \
//        2       3
//       / \     / \
//      4   5   6   7
//       \
//        8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    Solution sol;
    vector<int> ans = sol.rightSideView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
