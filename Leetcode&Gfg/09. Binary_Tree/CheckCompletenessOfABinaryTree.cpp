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
    // The structure of this code is similar to level-order traversal of Binary Tree.
    // T.C: O(n)
    // S.C: O(n)
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;   // If root of BT is itself a NULL, consider it a CBT or not; its your choice.
        
        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(!front) {   // If queue contains a null node, it means we are currently at
                          // a null node. Thus, make the 'encounteredNull' flag as true.
                encounteredNull = true;
            } else {   // If queue contains a valid node
                // If 'encounteredNULL' is true, it means a null node was found. And now,
                // as we came here means a non-null node is found. Therefore, it means
                // that a non-null node is found after a null node, which violates the
                // condition for a CBT. Thus, straightaway return false.
                if(encounteredNull) return false;

                // Push the left and right child of BT into queue
                q.push(front->left);
                q.push(front->right); 
            }
        }
        
        // If all non-null nodes appear before all null nodes, it is a CBT. Return true.
        return true;
    }
};