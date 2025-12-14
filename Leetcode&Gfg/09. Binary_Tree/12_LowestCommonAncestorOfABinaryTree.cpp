// Leetcode: 236. Lowest Common Ancestor of a Binary Tree   --->   Given a binary tree,
// find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q
// as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//                _ 3 _
//              /       \
//             5         1
//            / \       / \
//           6   2     0   8
//              / \
//             7   4
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//                _ 3 _
//              /       \
//             5         1
//            / \       / \
//           6   2     0   8
//              / \
//             7   4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

// Example 3:
// Input: root = [1,2], p = 1, q = 2
// Output: 1


// Algorithm: It is simple. Dry run for best understanding.
// 1. Perform a DFS traversal of the tree starting from the root.
// 2. Base cases:
//    a) If the current node is NULL, return NULL.
//    b) If the current node is equal to p or q, return the current node.
// 3. Recursively search for p and q in the left and right subtrees.
// 4. After recursion, any one of the following cases may occur:
//    i.   If both left and right recursive calls return non-NULL values, then p and q are found in different subtrees.
//         Hence, the current node is their Lowest Common Ancestor. Return the current node.
//    ii.  Otherwise, if only one of the recursive calls returns non-NULL, propagate that non-NULL value upward.
//    iii. If both recursive calls return NULL, return NULL.
// 5. The value returned to the initial caller is the Lowest Common Ancestor.


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // T.C: O(n)
    // S.C: O(h)   due to recursion stack, h = n for skew tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base cases
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in left and right subtrees respectively, current node is the LCA; thus return current node
        if(left && right) return root;

        // Otherwise, propagate the non-null result upward. If both are NULL, return NULL.
        return left ? left : right;
    }
};

int main() {
//                _ 3 _
//              /       \
//             5         1
//            / \       / \
//           6   2     0   8
//              / \
//             7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* p = root->left;   // p = 5
    TreeNode* q = root->right;   // q = 1

    cout << Solution().lowestCommonAncestor(root, p, q)->val;

    return 0;
}
