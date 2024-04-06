// Leetcode: 110. Balanced Binary Tree   --->   Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

// Algorithm: A node is balanced only if 3 conditions are met:
// 1) Left sub-tree is balanced
// 2) Right sub-tree is balanced
// 3) Diiference in heights of left and right sub-tree is less than equal to 1.

#include <iostream>
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
    int heightOfBT(TreeNode *root) {
        if (root == NULL) return 0;
        int leftHeight = heightOfBT(root->left);
        int rightHeight = heightOfBT(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // T.C: O(n);   where n = no.of nodes in BT
    // S.C: O(h);   where h = height of a tree. Hieght is no.of nodes if tree is skew.
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;   // Base case: an empty tree/leaves are balanced

        // Check if left and right sub-trees are balanced
        bool isLeftTreeBalanced = isBalanced(root->left);
        bool isRightTreeBalanced = isBalanced(root->right);
    
        // Calculate heights of left and right subtrees
        int leftHeight = heightOfBT(root->left);
        int rightHeight = heightOfBT(root->right);
        
        // If the difference in heights is less than equal to 1, difference is true, else false
        bool difference = (abs(leftHeight - rightHeight) <= 1);

        if(isLeftTreeBalanced && isRightTreeBalanced && difference) return true;
        else return false;
    }
};

int main() {
    Solution sol;
    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.isBalanced(root) << endl;

    return 0;
}
