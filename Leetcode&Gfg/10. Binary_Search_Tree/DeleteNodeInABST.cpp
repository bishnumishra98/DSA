// Leetcode: 450. Delete Node in a BST   --->   Given a root node reference of a BST and a key, delete the node with
// the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// 1. Search for a node to remove.
// 2. If the node is found, delete the node.

// Example 1:
//      5                        5
//     / \                      / \
//    3   6        --->        4   6  
//   / \   \                  /     \
//  2   4   7                2       7
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

// ---------------------------------------------------------------------------------------------------

class Solution {
public:
    TreeNode* maxNodeInBST(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* temp = root;
        while(temp->right) {
            temp = temp->right;
        }
        return temp;
    }

    // T.C: O(H); H = logN in average case, while H = N in worst case
    // S.C: O(N)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;   // If root is NULL, there's nothing to delete. So return NULL.

        if(key == root->val) {   // if key found, there can be any 1 out of 4 scenarios to delete it
            if(!root->left && !root->right) {   // case 1: The node to delete is a leaf node
                delete root;
                return NULL;
            } else if(root->left && !root->right) {   // case 2: The node to delete has a left child node, but no right child node
                TreeNode* leftSubTree = root->left;
                delete root;
                return leftSubTree;
            } else if(root->right && !root->left) {   // case 3: The node to delete has a right child node, but no left child node
                TreeNode* rightSubTree = root->right;
                delete root;
                return rightSubTree;
            } else {   // case 4: The node to delete has both left and right child nodes
                // Step 1: Bring max node of left subtree in variable say 'maxi'
                TreeNode* maxi = maxNodeInBST(root->left);
                // Step 2: Replace 'root->val' with the 'maxi->val'
                root->val = maxi->val;
                // Step 3: Delete 'maxi' node, and return root
                root->left = deleteNode(root->left, maxi->val);
                return root;
            }
        } else if(key < root->val) {   // if key not found, and 'key < root->val', try to search and delete the key in left subtree
            root->left = deleteNode(root->left, key);
        } else {   //  if still key is not found, key must be greater than 'root->val', thus search and delete the key in right subtree
            root->right = deleteNode(root->right, key);
        }

        // After handling the deletion scenarios, we need to return the modified subtree(with the deleted node removed)
        return root;
    }
};

int main() {
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
