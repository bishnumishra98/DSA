// Leetcode: 700. Search in a Binary Search Tree   --->   You are given the root of a binary search tree (BST) and an integer val. Find the
// node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Example 1:
//      4
//     / \
//    2   7
//   / \
//  1   3
// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Example 2:
// Input: root = [4,2,7,1,3], val = 5
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
    // T.C: O(n)
    // S.C: O(n)
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;   // if root is NULL, return NULL

        if(val == root->val) return root;   // if 'val' matches the node's value, return that node

        // Search the 'val' in left and right subtrees
        TreeNode* left = searchBST(root->left, val);
        TreeNode* right = searchBST(root->right, val);

        // If we got any node from left subtree, then return that node; else return right node.
        // Anyways, if we get NULL from both left and right, we will be returning NULL from right.
        if(left) return left;
        else return right;
    }
};

int main() {
//      4
//     / \
//    2   7
//   / \
//  1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right= new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int target = 2;
    TreeNode* ans = sol.searchBST(root, target);
    cout << ans->val;

    return 0;
}
