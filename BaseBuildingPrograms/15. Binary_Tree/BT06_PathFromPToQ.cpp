// Problem: Given a Binary Tree and two nodes p and q present in the tree, return a vector<int> containing the
//          values of nodes on the path from node p to node q (inclusive).
//          Note:
//          1. All node values are unique.
//          2. It is guaranteed that both p and q exist in the tree.

// Example 1:
// Input:
// p = 4, q = 3
//        1
//      /   \
//     2     3
//    / \
//   4   5
// Output:
// [4, 2, 1, 3]
// Explanation:
// Path from 4 → 2 → 1 → 3

// Example 2:
// Input:
// p = 7, q = 4
//        3
//      /   \
//     5     1
//    / \
//   6   2
//      / \
//     7   4
// Output:
// [7, 2, 4]


// Algorithm:
// 1. Perform a DFS traversal to find the path from the root to node p. Store this path in vector pathP.
// 2. Perform another DFS traversal to find the path from the root to node q. Store this path in vector pathQ.
// 3. Compare pathP and pathQ from the beginning to find the first index at which the node values differ.
//     The node at index (i - 1) is the Lowest Common Ancestor (LCA).
// 4. Construct the final path from p to q as follows:
//    a) Traverse pathP from the last index down to index i (this gives the path from p up to but excluding the LCA).
//    b) Add the LCA node once.
//    c) Traverse pathQ from index i to the end (this gives the path from the LCA down to q).


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal to find path from root -> target
bool getPath(TreeNode* root, TreeNode* target, vector<int>& path) {
    if(root == NULL) return false;

    // Add current node to path
    path.push_back(root->val);

    // If target is found, return true
    if(root == target) return true;

    // Search in left or right subtree. If target is found in any of the subtrees, propagate true upwards.
    if(getPath(root->left, target, path) || getPath(root->right, target, path)) return true;

    // Backtrack if target not found in this path. If target is not found in any of the subtrees, propagate false upwards.
    path.pop_back();
    return false;
}

// T.C: O(n);   where n = no.of nodes in tree
// S.C: O(h);   where h = height of tree, h = n for skew tree
vector<int> pathFromPtoQ(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<int> pathP, pathQ, result;

    // Find root -> p and root -> q paths
    getPath(root, p, pathP);
    getPath(root, q, pathQ);

    // Find the index where paths diverge
    int i = 0;
    while(i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
        i++;
    }

    // Add path from p up to LCA (excluding LCA)
    for(int j = pathP.size() - 1; j >= i; j--) {
        result.push_back(pathP[j]);
    }

    // Add LCA
    result.push_back(pathP[i - 1]);

    // Add path from LCA to q (excluding LCA)
    for (int j = i; j < pathQ.size(); j++) {
        result.push_back(pathQ[j]);
    }

    return result;
}

int main() {
//       1
//      / \
//     2   3
//    / \
//   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* p = root->left->left;   // p = Node 4
    TreeNode* q = root->right;        // q = Node 3

    vector<int> ans = pathFromPtoQ(root, p, q);

    for(int x : ans) cout << x << " ";

    return 0;
}
