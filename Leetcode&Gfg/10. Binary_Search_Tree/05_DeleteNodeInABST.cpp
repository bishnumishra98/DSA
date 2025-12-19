// Leetcode: 450. Delete Node in a BST   --->   Given a root node reference of a BST and a key, delete the node with
// the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// 1. Search for a node to remove.
// 2. If the node is found, delete the node.

// Example 1:
//      5                        5              5
//     / \                      / \            / \
//    3   6        --->        4   6     OR   2   6
//   / \   \                  /     \          \   \  
//  2   4   7                2       7          4   7
// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.

// Example 2:
// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.

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

void levelOrderTraversal_LevelByLevel(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);
    q.push(NULL);   // NULL acts as an indicator to change line

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
private:
    // It takes the parameter 'root' as the node to be deleted and returns the new root of the modified subtree
    TreeNode* deleteNodeFromBST(TreeNode* root) {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        else {
            TreeNode* rightChild = root->right;
            TreeNode* rightmostNodeOfLeftChild = findLastRightNode(root->left);
            rightmostNodeOfLeftChild->right = rightChild;
            return root->left;
        }
    }

    TreeNode* findLastRightNode(TreeNode* root) {
        if(root->right == NULL) return root;
        return findLastRightNode(root->right);
    }

public:
    // T.C: O(h);   where h = height of tree, h = logn for balanced BST, h = n for skew tree
    // S.C: O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return deleteNodeFromBST(root);

        TreeNode* dummy = root;
        while(root != NULL) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    root->left = deleteNodeFromBST(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = deleteNodeFromBST(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

int main() {
//      5  
//     / \
//    3   6
//   / \   \
//  2   4   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    int key = 3;
    TreeNode* ans = sol.deleteNode(root, key);

    levelOrderTraversal_LevelByLevel(root);

    return 0;
}
