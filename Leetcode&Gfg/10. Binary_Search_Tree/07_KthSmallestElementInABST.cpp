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

// Optimal Algorithm: We can do an inorder traversal of the BST and keep track of the count of nodes visited so far.
// When the count becomes equal to k, we can return the value of the current node as the kth smallest element in the BST.

    // T.C: O(h + k);   where h = height of BST
    // S.C: O(h);   where h = height of BST
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(true) {
            // Traverse the left subtree continuously until we reach the leftmost node
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            // Pop the top node from the stack and decrement k by 1
            curr = st.top();
            st.pop();
            k = k - 1;

            // If k becomes 0, it means we have found the kth smallest element, so we return its value
            if(k == 0) return curr->val;

            // If k is not yet 0, we move to the right subtree of the current node and repeat the process
            curr = curr->right;
        }

        return -1;   // if k > number of nodes in the BST
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
    cout << sol.kthSmallest_bruteForce(root, k) << endl;   // o/p: 3
    cout << sol.kthSmallest(root, k);   // o/p: 3

    return 0;
}
