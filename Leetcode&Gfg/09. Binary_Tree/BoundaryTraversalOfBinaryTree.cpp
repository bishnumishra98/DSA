// GFG: Boundary Traversal of binary tree   --->   Given a Binary Tree, find its Boundary Traversal. The traversal
// should be in the following order: 
// 1. Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when
//    you always travel preferring the left subtree over the right subtree. 
// 2. Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// 3. Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the
//    leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root
//    from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \     / \
//        8   9   10
// Boundary can be divided into 4 parts:
// 1) Root node: 1
// 2) Left boundary: 2, 4
// 3) Leaf boundary: 8, 5, 6, 9, 10
// 4) Right boundary: 7, 3 
// Joining all four parts, its boundary traversal will be 1 2 4 8 5 6 9 10 7 3

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }

    Node() {
        left = right = NULL;
    }
};

class Solution {
public:
    vector <int> ans;

    void leftBoundary(Node* root) {
        // If root is a null, or if it is a leaf node, return.
        if(!root || (!root->left && !root->right)) return;

        // push the node in vector
        ans.push_back(root->data);

        // If left children exists, then go to left, else go to right.
        if(root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }

    void leafBoundary(Node* root) {
        // If root is null, return
        if(!root) return;

        // If we are at leaf node, push the leaf in the vector
        if(!root->left && !root->right) ans.push_back(root->data);

        // Search for more leaf nodes in left/right subtrees
        leafBoundary(root->left);
        leafBoundary(root->right);
    }

    void rightBoundary(Node* root) {
        // If root is a null, or if it is a leaf node, return.
        if(!root || (!root->left && !root->right)) return;

        // If right children exists, then go to right, else go to left.
        if(root->right) rightBoundary(root->right);
        else rightBoundary(root->left);

        // push the node in vector while coming back from recursive call, so that
        // the right boundary nodes gets stored in 'ans' in reverse order.
        ans.push_back(root->data);
    }

    // T.C: O(n)
    // S.C: O(n)
    vector <int> boundary(Node *root) {
        ans.push_back(root->data);   // pushing the root node in vector

        leftBoundary(root->left);   // start searching for left boundary nodes from left subtree
        
        // If there is only 1 node in tree, the root and leaf both are the same. And that node will already
        // be pushed in the vector from this line 'ans.push_back(root->data)'. So don't unnecessarily push that
        // node again in the vector in the name of leaf node.
        // Thus, leaf nodes should only be searched and pushed in vector if the tree has more than 1 node in it.
        if(root->left || root->right) leafBoundary(root);
        
        rightBoundary(root->right);   // start searching for right boundary nodes from right subtree

        return ans;
    }
};

int main() {
//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \     / \
//        8   9   10
// Its boundary traversal will be 1 2 4 8 5 6 9 10 7 3
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    Solution sol;
    vector<int> ans = sol.boundary(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
