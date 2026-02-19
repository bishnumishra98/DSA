// Leetcode: 235. Lowest Common Ancestor of a Binary Search Tree   --->   Given a binary search tree (BST),
// find the lowest common ancestor (LCA) node of two given nodes in the BST.

// Example 1:
//      6
//    /   \
//   2     8
//  / \   / \
// 0   4 7   9
//    / \
//   3   5
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 3, q = 5
// Output: 4
// Explanation: The LCA of nodes 2 and 8 is 6.

// Example 2:
//      6
//    /   \
//   2     8
//  / \   / \
// 0   4 7   9
//    / \
//   3   5
// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


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
    // T.C: O(h)
    // S.C: O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if((p->val < root->val) && (q->val < root->val)) {   // Case 1: if p and q lie on left subtree, go more to left
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            return left;
        } else if((p->val > root->val) && (q->val > root->val)) {   // Case 2: if p and q lie on right subtree, go more to left
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            return right;
        } else {   // Case 3: If they both lie on opposite subtrees, this node is the LCA. Thus, return it.
            return root;
        }
    }
};

int main() {
//      6
//    /   \
//   2     8
//  / \   / \
// 0   4 7   9
//    / \
//   3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;

    TreeNode* p = root->left->right->left;
    TreeNode* q = root->left->right->right;
    cout << sol.lowestCommonAncestor(root, p, q)->val;

    return 0;
}
