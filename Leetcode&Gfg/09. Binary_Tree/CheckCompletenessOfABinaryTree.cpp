// Leetcode: 958. Check Completeness of a Binary Tree   --->   Given the root of a binary tree, determine if it is a
// complete binary tree. In a complete binary tree, every level, except possibly the last, is completely filled, and all
// nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    // T.C: 
    // S.C: 
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(!current) {
                encounteredNull = true;   // first null node encountered
            } else {
                if(encounteredNull) return false;   // found a non-null node after a null node

                q.push(current->left);
                q.push(current->right); 
            }
        }

        return true;
    }
};