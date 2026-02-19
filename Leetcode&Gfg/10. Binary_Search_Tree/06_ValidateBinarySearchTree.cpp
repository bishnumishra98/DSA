// Leetcode: 98. Validate Binary Search Tree   --->   Given the root of a binary tree, determine if it is a valid binary
// search tree (BST).
// A valid BST is defined as follows:
// ● The left subtree of a node contains only nodes with keys strictly less than the node's key.
// ● The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// ● Both the left and right subtrees must also be binary search trees.
 
// Example 1:
//     2
//    / \
//   1   3
// Input: root = [2,1,3]
// Output: true

// Example 2:
//     5
//    / \
//   1   4
//      / \
//     3   6
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.


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
    // Bruteforce approach

    void inorderTraversal(TreeNode* root, vector<int>& inorderArray) {
        if(root == NULL) return;
        inorderTraversal(root->left, inorderArray);
        inorderArray.push_back(root->val);
        inorderTraversal(root->right, inorderArray);
    }

    // T.C: O(N)   where N is the number of nodes in the binary tree
    // S.C: O(N)   where N is the number of nodes in the binary tree (due to the inorderArray vector)
    bool isValidBST_bruteforce(TreeNode* root) {
        vector<int> inorderArray;
        inorderTraversal(root, inorderArray);

        // If inorderArray is perfectly sorted, it is a BST; else not
        for(int i = 0; i < inorderArray.size() - 1; i++) {
            if(inorderArray[i] >= inorderArray[i + 1]) return false;
        }

        return true;
    }

// ----------------------------------------------------------------------------------------------------------

    // Optimal approach

    bool isValidBST_helper(TreeNode* root, long long minVal, long long maxVal) {
        if(!root) return true;

        if(root->val <= minVal || root->val >= maxVal) return false;

        return isValidBST_helper(root->left, minVal, root->val) &&
               isValidBST_helper(root->right, root->val, maxVal);
    }

    // T.C: O(N)   where N is the number of nodes in the binary tree
    // S.C: O(H)   where H is the height of the binary tree (due to recursion stack)
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, LLONG_MIN, LLONG_MAX);
    }
};


int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << Solution().isValidBST_bruteforce(root) << endl;   // o/p: 0 (false)
    cout << Solution().isValidBST(root);   // o/p: 0 (false)

    return 0;
}
