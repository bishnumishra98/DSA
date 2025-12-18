// Leetcode: 701. Insert into a Binary Search Tree   --->   You are given the root node of a binary search tree (BST)
// and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the
// new value does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.
// You can return any of them.

// Example 1:
// Input: root = [4,2,7,1,3], val = 5
//       4
//      / \
//     2   7
//    / \
//   1   3
// Output: [4,2,7,1,3,5]
//        4
//      /   \
//     2     7
//    / \   /
//   1   3 5
// Explanation: Another accepted tree is:
//       5
//      / \
//     2   7
//    / \
//   1   3
//        \
//         4

// Example 2:
// Input: root = [40,20,60,10,30,50,70], val = 25
// Output: [40,20,60,10,30,50,70,null,null,25]

// Example 3:
// Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
// Output: [4,2,7,1,3,5]

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

// For printing purpose
void levelOrderTraversal_LevelByLevel(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL); 
        } else {
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            cout << front->val << " ";
        }
    }
}

class Solution {
public:
    // T.C: O(h);   where h = height of tree, h = logn for balanced BST, h = n for skew tree
    // S.C: O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* curr = root;
        while(true) {
            if(val > curr->val) {
                if(curr->right) {
                    curr = curr->right;
                } else {   // if(curr->right == NULL)
                    curr->right = new TreeNode(val);
                    break;
                }
            } else {   // if(val < curr->val)
                if(curr->left) {
                    curr = curr->left;
                } else {   // if(curr->left == NULL)
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};



int main() {
//       4
//      / \
//     2   7
//    / \
//   1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    TreeNode* updatedTreeRoot = Solution().insertIntoBST(root, val);

    levelOrderTraversal_LevelByLevel(updatedTreeRoot);

    return 0;
}
