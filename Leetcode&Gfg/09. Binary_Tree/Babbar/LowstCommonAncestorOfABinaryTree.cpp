// Leetcode: 236. Lowest Common Ancestor of a Binary Tree   --->   Given a binary tree,
// find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q
// as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

// Example 3:
// Input: root = [1,2], p = 1, q = 2
// Output: 1

// Algorithm: For a tree like this: [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//                ___ 3 ___
//              /            \
//             5              1
//           /   \          /   \
//          6     2        0     8
//               /  \
//              7    4
// Base cases:
// 1) If we reach null, return null to parent node.
// 2) If we reach the node p or q, return that node, i.e, return a non-null value to the parent node.
// Actual logic:
// 1) If both left & right subtree returns null, return null to its parent node.
// 2) If any one of the subtree returns a non-null value, return that non-null value to its parent node.
// 3) If both left & right subtree returns non-null, its parent is the LCA.


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // T.C: O(n);   where n = no.of nodes
    // S.C: O(h);   where h = height of tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: root is NULL or equal to p or q
        if (!root || root == p || root == q) return root;
    
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
       
        if (!left && !right) return NULL;    // 1st condition: If both left and right are NULL
        else if (left && !right) return left;   // 2nd condition: If either left or right is not NULL
        else if (!left && right) return right;
        else return root;   // 3rd condition: If both left and right are not NULL
    }
};

int main() {
    Solution sol;
    // [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    cout << sol.lowestCommonAncestor(root, p, q)->val << endl;

    return 0;
}
