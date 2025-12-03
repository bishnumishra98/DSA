// Leetcode: 958. Check Completeness of a Binary Tree   --->   Given the root of a binary tree, determine if it is a
// complete binary tree. In a complete binary tree, every level, except possibly the last, is completely filled, and all
// nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

// Example 1:
// Input: root = [1,2,3,4,5,6]
//             1
//           /   \
//          2     3
//         / \    /
//        4   5  6
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the
// last level ({4, 5, 6}) are as far left as possible.

// Example 2:
// Input: root = [1,2,3,4,5,null,7]
//             1
//           /   \
//          2     3
//         / \     \
//        4   5     7
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.

// Algorithm: It is simple.
// We will do a BFS (level-order) traversal of the tree to find if there are any non-null nodes
// that occur after a null node.

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
    // T.C: O(n)
    // S.C: O(n)
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;   // empty tree is considered complete by definition
        
        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;   // this flag becomes true when we see the first NULL in level order.

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL) {   // NULL node occurs
                // Once we see a NULL, all nodes that come later in level-order
                // must also be NULL for the tree to be complete.
                encounteredNull = true;
            } else {   // NON-NULL node occurs
                // If we already saw a NULL before and now we see a non-null node,
                // that means there is a gap -> not a complete binary tree.
                if(encounteredNull) return false;

                // Push left and right children even if they are NULL.
                // This helps us detect gaps in the tree.
                q.push(front->left);
                q.push(front->right); 
            }
        }
        
        // If we never found a non-null node after a null, it's complete.
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << Solution().isCompleteTree(root);   // o/p: 1 (true)

    return 0;
}
