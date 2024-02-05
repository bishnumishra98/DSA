// Leetcode: 104. Maximum Depth of Binary Tree   --->   Given the root of a binary tree, return its
// maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from
// the root node down to the farthest leaf node.

// Example 1:
//          3
//         / \
//        9   20 
//           /  \
//          15   7
//
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

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
    // T.C: O(n); n = no.of nodes
    // S.C: O(h); h = height of recursive call. If the tree is balanced, then h = log(n), 
    //                if tree is a skewed tree, then h = n.
    int maxDepth(TreeNode* root) {
        // base case
        if(root == NULL) return 0;
        int leftSubTree_height = maxDepth(root->left) + 1;
        int rightSubTree_height = maxDepth(root->right) + 1;
        int height = max(leftSubTree_height, rightSubTree_height);
        return height;
    }
};

int main() {
    Solution obj;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << obj.maxDepth(root);

    return 0;
}
