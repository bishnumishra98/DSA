// Leetcode: 101. Symmetric Tree   --->   Given the root of a binary tree, check whether it is a mirror of
// itself (i.e., symmetric around its center).

// Example 1:
// Input: root = [1,2,2,3,4,4,3]
//        1
//      /   \
//     2     2
//    / \   / \
//   3   4 4   3
// Output: true

// Example 2:
// Input: root = [1,2,2,null,3,null,3]
//     1
//    / \
//   2   2
//    \   \
//     3   3
// Output: false

// Algorithm: A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.
//            Thus, we can use a recursive approach to compare the left and right subtrees of the tree.
//            It is an extension of the 'Leetcode&Gfg\09. Binary_Tree\03_SameTree.cpp' problem, with a slight
//            modification in the recursive calls.

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
private:
    bool isBinaryTreeSymmetric(TreeNode* p, TreeNode* q) {
        // Base case: If both nodes are NULL, they are the same. Thus return true.
        // If one of them is NULL and the other is not, they are different. Thus return false.
        if(p == NULL || q == NULL) return (p == q);

        // If the values of the current nodes are different, return false.
        // Otherwise, recursively check the left and right subtrees. If both subtrees are the mirror, return true.
        return (p->val == q->val) && isBinaryTreeSymmetric(p->left, q->right) && isBinaryTreeSymmetric(p->right, q->left);
    }

public:
    // T.C: O(n);   where n is the number of nodes in the tree
    // S.C: O(h);   where h is the height of the tree due to the recursion stack, h = n for skewed tree
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;   // A null rooted tree by definition is symmetric
        return isBinaryTreeSymmetric(root->left, root->right);
    }
};

int main() {
//        1
//      /   \
//     2     2
//    / \   / \
//   3   4 4   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    cout << Solution().isSymmetric(root);   // o/p: 1 (true)

    return 0;
}
