// Leetcode: 114. Flatten Binary Tree to Linked List   --->   Given the root of a binary tree, flatten the tree into
// a "linked list":
// ● The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the
//   list and the left child pointer is always null.
// ● The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
// Example 1:
//       1              1
//      / \              \
//     2   5     --->     2
//    / \   \              \
//   3   4   6              3
//                           \
//                            4
//                             \
//                              5
//                               \
//                                6
// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [0]
// Output: [0]

// Algorithm: We will do a reverse pre-order traversal (right -> left -> root) of the binary tree and keep track of
//            the previously visited node using a pointer 'prev'. For each node, we will set its right child to 'prev'
//            and its left child to NULL. Finally, we will update 'prev' to the current node.

// Video link: https://www.youtube.com/watch?v=sWf7k1x9XR4

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
private:
    void flattenTree(TreeNode* root, TreeNode*& prev) {
        if(root == NULL) return;

        flattenTree(root->right, prev);
        flattenTree(root->left, prev);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

public:
    // T.C: O(n);   where n is the number of nodes in the binary tree
    // S.C: O(h);   where h is the height of the binary tree, h = n in skewed tree
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        flattenTree(root, prev);
    }
};

int main() {
//       1
//      / \
//     2   5
//    / \   \
//   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution().flatten(root);

    TreeNode* temp = root;   // root is the head of LL
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->right;
    }

    return 0;
}
