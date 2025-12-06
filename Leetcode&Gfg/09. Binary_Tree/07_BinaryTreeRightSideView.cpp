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

// Algorithm: It is a simple DFS traversal.
// We keep track of the current level while traversing the tree.
// If we reach a level for the first time, we add the node's value to the answer vector.
// To ensure we add the nodes that comes in right view of tree, we first traverse the right subtree
// and then the left subtree.


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
    void storeRightView(TreeNode* root, int level, vector<int>& ans) {
        if(root == NULL) return;

        // Store the node's value in 'ans' only if the node is being visited for the first time in this level
        if(ans.size() == level) ans.push_back(root->val);
        
        storeRightView(root->right, level + 1, ans);
        storeRightView(root->left, level + 1, ans);
    }

public:
    // T.C: O(n),   where n = number of nodes in the tree
    // S.C: O(h),   where h = height of the tree (h = n in skew tree)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        storeRightView(root, 0, ans);
        return ans;
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
