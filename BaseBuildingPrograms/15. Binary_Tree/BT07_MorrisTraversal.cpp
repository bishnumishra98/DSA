// ● What is Morris Traversal ?
//   Morris Traversal is a tree traversal algorithm that does not use recursion or a stack, unlike
//   standard recursive or iterative approaches. It uses threaded binary trees to achieve O(1) space
//   complexity, where other traversal methods typically require O(h) space, with h being the height
//   of the tree. However, time complexity remains O(n) for Morris Traversal, where n is the number
//   of nodes in the tree.

// ● How does Morris Traversal work ?
//   The key idea behind Morris Traversal is to temporarily modify the tree structure to create
//   "threads" that allow traversal without additional space. The algorithm follows these steps:
//   1. Initialize the current node as the root.
//   2. While the current node is not NULL:
//      a. If the current node has no left child, visit the current node and move to its right child.
//      b. If the current node has a left child, find the inorder predecessor of the current node
//         (the rightmost node in the left subtree).
//         i. If the predecessor's right child is NULL, set it to point to the current node (create
//            a thread), and move to the left child of the current node.
//         ii. If the predecessor's right child points to the current node (indicating a thread),
//             revert the changes (remove the thread), visit the current node, and move to its right child.
//   3. Repeat until all nodes are visited.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// T.C: O(n);   where n = no.of nodes in tree
// S.C: O(1)
vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* current = root;

    while(current != NULL) {
        if(current->left == NULL) {
            // If there is no left child, visit this node and go to right child
            inorder.push_back(current->val);
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            TreeNode* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // Make current as the right child of its inorder predecessor
            if(predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                // Revert the changes made in the tree
                predecessor->right = NULL;
                inorder.push_back(current->val);
                current = current->right;
            }
        }
    }

    return inorder;
}

// T.C: O(n);   where n = no.of nodes in tree
// S.C: O(1)
vector<int> morrisPreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* current = root;

    while(current != NULL) {
        if(current->left == NULL) {
            // If there is no left child, visit this node and go to right child
            preorder.push_back(current->val);
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            TreeNode* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // Make current as the right child of its inorder predecessor
            if(predecessor->right == NULL) {
                preorder.push_back(current->val); // Visit the node before going to left subtree
                predecessor->right = current;
                current = current->left;
            } else {
                // Revert the changes made in the tree
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }

    return preorder;
}


int main() {
//       1
//      / \
//     2   3
//    / \
//   4   5
//        \
//         6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> inorder = morrisInorderTraversal(root);
    cout << "Morris Inorder Traversal: ";
    for(int val : inorder) {
        cout << val << " ";   // o/p: 4 2 5 6 1 3
    }
    cout << endl;
    vector<int> preorder = morrisPreorderTraversal(root);
    cout << "Morris Preorder Traversal: ";
    for(int val : preorder) {
        cout << val << " ";   // o/p: 1 2 4 5 6 3
    }

    return 0;
}
