// Leetcode: 106. Construct Binary Tree from Preorder and Postorder Traversal   --->   Given two integer arrays
// inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder
// traversal of the same tree, construct and return the binary tree.

// Example 1:
//       3 
//     /   \
//    9     20
//         /  \
//        15   7              
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]


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

void levelOrderTraversal(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);
    q.push(NULL); 

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout << front->val << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

class Solution {
private:
    TreeNode* buildBinaryTree(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inorderMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inorderMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = buildBinaryTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inorderMap);
        root->right =buildBinaryTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inorderMap);
    }

public:
    // T.C: O(n)
    // S.C: O(n) for map + O(h) for recursion stack space, h = n for skew tree
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;

        unordered_map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        TreeNode* root = buildBinaryTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
        return root;
    }
};

int main() {
    Solution sol;
    //      3 
    //     / \
    //    9   20
    //       /  \
    //      15   7 
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    TreeNode* ans = sol.buildTree(inorder, postorder);

    levelOrderTraversal(ans);

    return 0;
}
