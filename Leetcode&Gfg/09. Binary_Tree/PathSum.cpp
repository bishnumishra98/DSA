// Leetcode: 112. Path Sum   --->   Given the root of a binary tree and an integer targetSum, return true if the tree has
// a root-to-leaf path such that adding up all the values along the path equals targetSum. A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.

// Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: false
// Explanation: There two root-to-leaf paths in the tree:
// (1 --> 2): The sum is 3.
// (1 --> 3): The sum is 4.
// There is no root-to-leaf path with sum = 5.

// Example 3:
// Input: root = [], targetSum = 0
// Output: false
// Explanation: Since the tree is empty, there are no root-to-leaf paths.

// Algorithm: Starting from sum=0 at root node, keep a track of cumulative sum on each node and once
//            leaf node is reached, return true if sum is equal to targetSum, else return false. Lets
//            say if true and false is received to a node from its both children, pass true, i.e.,
//            (left || right) to the above parent node, as targetSum has been already found.

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
    bool solve(TreeNode* root, int targetSum, int sum) {
        if(root == NULL) return false;

        sum = sum + root->val;   // calculating cumulative sum on each node
        // If leaf node is reached, check if sum is equal to targetSum
        if(root->left==NULL && root->right==NULL) return (sum==targetSum) ? true : false;

        // Recursively check for a path with the targetSum in the left and right subtrees.
        bool left = solve(root->left, targetSum, sum);
        bool right = solve(root->right, targetSum, sum);

        // Return true if either the left or right subtree has a path where sum is equal to targetSum.
        return (left || right);
    }

    // T.C: O(n)   where n = no.of nodes
    // S.C: O(h)   where h = height of tree
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};

int main() {
    Solution sol;
    // [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
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

    cout << sol.hasPathSum(root, targetSum);

    return 0;
}
