// GFG: Tree Boundary Traversal   --->   Given a root of a Binary Tree, return its boundary traversal in the following order:
// 1. Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and
//                   excluding leaves.
// 2. Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
// 3. Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the
//                            left, excluding leaves, and added in reverse order.
// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows
//       traversal preference not the path from the rightmost leaf.

// Example 1:
// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
//           _ 1 _
//          /     \
//         2       3
//        / \     / \
//       4   5   6   7
//          / \
//         8   9 
// Output: [1, 2, 4, 8, 9, 6, 7, 3]
// Left boundary: [1, 2] (excluding leaf nodes 4, 8, 9)
// Leaf nodes: [4, 8, 9, 6, 7]
// Right boundary: [3] (in reverse order)
// Final traversal: [1, 2, 4, 8, 9, 6, 7, 3]

// Example 2:
// Input: root = [1, N, 2, N, 3, N, 4, N, N]
//   1
//    \
//     2
//      \
//       3
//        \
//         4
// Output: [1, 4, 3, 2]
// Explanation:
// Left boundary: [1] (as there is no left subtree)
// Leaf nodes: [4]
// Right boundary: [3, 2] (in reverse order)
// Final traversal: [1, 4, 3, 2]

// Problem link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:
    bool isLeaf(Node* node) {
        return node->left == NULL && node->right == NULL;
    }

    // Step 1: Add the left boundary (excluding leaf nodes)
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    // Step 2: Add all leaf nodes (left to right)
    void addLeaves(Node* root, vector<int> &res) {
        if(root == NULL) return;

        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    // Step 3: Add right boundary in reverse (excluding leaf nodes)
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> temp;

        while(curr) {
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }

        // Add in reverse order
        reverse(temp.begin(), temp.end());
        for(int val: temp) res.push_back(val);
    }
    
public:
    // T.C: O(h) + O(n) + O(h) = O(n);   where h = height of tree, and n = number of nodes in tree
    // S.C: O(h);   in worst-case, i.e., in a skew tree: h = n
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root) return res;

        // Root itself (only if it's not a leaf)
        if(!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res);   // T.C: O(h)
        addLeaves(root, res);   // T.C: O(n)
        addRightBoundary(root, res);   // T.C: O(h)

        return res;
    }
};

int main() {
//           _ 1 _
//          /     \
//         2       3
//        / \     / \
//       4   5   6   7
//          / \
//         8   9
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> ans = Solution().boundaryTraversal(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
