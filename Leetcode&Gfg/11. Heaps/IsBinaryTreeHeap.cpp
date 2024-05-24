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
    bool isCompleteBinaryTree(Node* root) {
        if(!root) return true;
        
        queue<Node*> q;
        q.push(root);
        bool encounteredNull = false;

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if(!current) {
                encounteredNull = true;   // first null node encountered
            } else {
                if(encounteredNull) return false;   // found a non-null node after a null node

                q.push(current->left);
                q.push(current->right);
            }
        }

        return true;
    }

    bool hasHeapProperty(Node* root) {
        if(!root) return true;

        if(root->left && (root->data < root->left->data)) return false;
        if(root->right && (root->data < root->right->data)) return false;

        return hasHeapProperty(root->left) && hasHeapProperty(root->right);
    }

    // T.C:
    // S.C: 
    bool isHeap(Node* tree) {
        if (!tree) return true;

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
