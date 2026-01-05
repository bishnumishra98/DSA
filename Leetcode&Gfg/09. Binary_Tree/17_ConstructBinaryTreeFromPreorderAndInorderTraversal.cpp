// Leetcode: 105. Construct Binary Tree from Preorder and Inorder Traversal   --->   Given two integer arrays
// preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal
// of the same tree, construct and return the binary tree.

// Example 1:
//       3 
//     /   \
//    9     20
//         /  \
//        15   7              
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]


// ● Extra Info: Using a pair of preorder and postorder arrays, multiple binary trees can be formed.
//               But using a pair of inorder and preorder arrays, OR inorder and postorder arrays,
//               only one unique binary tree can be formed.

// Algorithm: 


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
    TreeNode* buildBinaryTree(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildBinaryTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderMap);
        root->right= buildBinaryTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);
        return root;
    }

public:
    // T.C: O(n)
    // S.C: O(n) for map + O(h) for recursion stack space, h = n for skew tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;   // {node of inorder array -> index of that node in inorder array}

        for(int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;

        TreeNode* root = buildBinaryTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
        return root;
    }
};

int main() {
    Solution sol;
    //      3 
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* ans = sol.buildTree(preorder, inorder);

    levelOrderTraversal(ans);
    // o/p: 
    // 3 
    // 9 20
    // 15 7

    return 0;
}
