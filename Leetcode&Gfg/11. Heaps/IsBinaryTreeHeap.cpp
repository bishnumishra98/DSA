// GFG: is binary Tree Heap   --->   Given a binary tree. The task is to check whether the given tree follows the
// max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// Example:
// Input:
//      5
//     / \
//    3   4
//   / \
//  1   2
// Output: 1


#include<bits/stdc++.h>
using namespace std;

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Check 'Leetcode&Gfg\09. Binary_Tree\CheckCompletenessOfABinaryTree.cpp' for understanding this function.
    bool isCompleteBinaryTree(Node* root) {
        if(!root) return true;   // Let's consider a null root tree as CBT.

        queue<Node*> q;
        q.push(root);
        bool encounteredNULL = false;

        while(!q.empty()) {
            Node* front = q.front();
            q.pop();

            if(!front) {
                encounteredNULL = true;
            } else {
                if(encounteredNULL) return false;
                q.push(front->left);
                q.push(front->right);
            }
        }

        return true;
    }

    bool hasHeapProperty(Node* root) {
        if(!root) return true;   // Return true if a null node is reached
        
        // If the left child exists and the root's data is less than the left child's data,
        // it violates the max heap property, so return false. Similarly, check for right child.
        if(root->left && (root->data < root->left->data)) return false;
        if(root->right && (root->data < root->right->data)) return false;

        // Recursively check the heap property for the left and right subtree
        bool left = hasHeapProperty(root->left);
        bool right = hasHeapProperty(root->right);
        
        // Return true only if both left and right subtrees satisfy the heap property
        return left && right;
    }

    // T.C: O(n) for isCompleteBinaryTree() + O(n) for hasHeapProperty() = O(n)
    // S.C: O(n) for isCompleteBinaryTree() + O(logn) for hasHeapProperty() = O(n)
    bool isHeap(Node* tree) {
        if(!tree) return true;   // Let's consider a null root tree as heap.
        return isCompleteBinaryTree(tree) && hasHeapProperty(tree);
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    Solution sol;

    cout << sol.isHeap(root);
}
