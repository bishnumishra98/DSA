// Leetcode: 230. Kth Smallest Element in a BST   --->   Given the root of a binary search tree, and an integer k,
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:
//      3
//     / \
//    1   4
//     \
//      2
// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Example 2:
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3


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
    // Brute force
    void inorderTraversal(TreeNode* root, vector<int> &v) {
        if(!root) return;

        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }

    // T.C: O(n);   where n = number of nodes in the BST
    // S.C: O(h) + O(n);   where h = height of BST
    int kthSmallest_bruteForce(TreeNode* root, int k) {
        vector<int> v;
        inorderTraversal(root, v);
        return v[k - 1];
    }

// ------------------------------------------------------------------------------------------------

// Optimal Algorithm:
// In an in-order traversal (left, node, right) of a binary search tree (BST), nodes are visited in ascending order.
// Therefore, the k-th node visited during this traversal is the k-th smallest element in the BST.
//
// Algorithm Steps:
// 1. Use a helper function to perform the in-order traversal.
// 2. Pass the root and the value of k by reference to the helper function.
// 3. Traverse the left subtree first (recursively).
// 4. Visit the current node:
//    - Decrement the value of k by 1.
//    - If k becomes 0, the current node is the k-th smallest element.
//    - Return the value of the k-th smallest element up the recursive calls.
// 5. Traverse the right subtree (recursively).
// 6. If the k-th smallest element is found in the left or right subtree, propagate this value up the recursive calls.
// 7. If neither the left nor the right subtree contains the k-th smallest element, return -1.

    int solve(TreeNode* root, int &k) {
        if (!root) return -1;   // Base case: if the node is null, return -1

        // Traverse the left subtree
        int left = solve(root->left, k);
        if (left != -1) return left;   // If the left subtree contains the k-th smallest, return it

        // Visit the current node (while backtracking from the left subtree)
        k--;  // Decrement k when visiting a node
        if (k == 0) return root->val;   // If k is zero, we've found the k-th smallest element

        // Traverse the right subtree
        int right = solve(root->right, k);
        if (right != -1) return right;   // If the right subtree contains the k-th smallest, return it

        return -1;  // If neither subtree contains the k-th smallest, return -1
    }

    // T.C: O(n)
    // S.C: O(h)
    int kthSmallest(TreeNode* root, int k) {
        int ans = solve(root, k);
        return ans;
    }

};

int main() {
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution sol;

    int k = 3;
    cout << sol.kthSmallest(root, k);

    return 0;
}
