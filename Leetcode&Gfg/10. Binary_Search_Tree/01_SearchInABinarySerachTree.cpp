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
    // T.C: O(h);   where h = height of tree, h = logn for balanced BST, h = n for skew tree
    // S.C: O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
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
