// Leetcode: 112. Path Sum   --->   Given the root of a binary tree and an integer targetSum, return true if the tree has
// a root-to-leaf path such that adding up all the values along the path equals targetSum. A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1 
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown - [2, 11, 4, 5]

// Example 2:
// Input: root = [1,2,3], targetSum = 5
//     1
//    / \
//   2   3
// Output: false
// Explanation: There two root-to-leaf paths in the tree:
// (1 --> 2): The sum is 3.
// (1 --> 3): The sum is 4.
// There is no root-to-leaf path with sum = 5.

// Example 3:
// Input: root = [], targetSum = 0
// Output: false
// Explanation: Since the tree is empty, there are no root-to-leaf paths.

// Algorithm: It is simple.
// Do a DFS traversal of the tree. At each node, subtract the node's value from targetSum.
// If we reach a leaf node (no children), check if the remaining targetSum is 0. If yes, return true; else false.

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
    // T.C: O(n)   where n = no.of nodes
    // S.C: O(h)   where h = height of tree
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If tree is empty → no path exists
        if(root == NULL) return false;

        // Subtract current node's value from targetSum
        targetSum -= root->val;

        // If we reached a leaf node (no children): If the remaining sum is 0, return true; else false.
        if(!root->left && !root->right) {
            return (targetSum == 0);
        }

        // Otherwise, check in left or right subtree
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

int main() {
    Solution sol;

    int targetSum = 22;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    cout << sol.hasPathSum(root, targetSum);   // o/p: 1 (true)

    return 0;
}
