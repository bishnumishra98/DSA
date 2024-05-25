// Given a tree in input, that is a CBT as well as a BST; construct a maxHeap from it.
// Example:
// Input:
//        _ 10 _
//       /      \
//      5       15
//     / \     /  \
//    4   6   11  20
//   /
//  2
// Output:
//        _ 20 _
//       /      \
//      6       15
//     / \     /  \
//    4   5   10  11
//   /
//  2

// Algorithm:
// 1. Store the inorder traversal(LNR) of the given tree. As it is also a BST, it's inorder will
//    be a sorted array: {2, 4, 5, 6, 10, 11, 15, 20}
// 2. Now traverse the given tree in postorder(LRN) and replace the values of given tree's nodes
//    with the values from the sorted array to create a max-heap.

#include <iostream>
#include <vector>
#include <queue>
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

void levelOrderTraversal(Node* root) {
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(!front) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            cout << front->data << " ";
        }
    }
}

// ------------------------------------------------------------------------------------------------

void storeInorderTraversal(Node* root, vector<int> &v) {
    if(!root) return;
    storeInorderTraversal(root->left, v);
    v.push_back(root->data);
    storeInorderTraversal(root->right, v);
}

void replaceWithInorderUsingPostorderTraversal(Node* root, vector<int> inorderArray, int &index) {
    if(!root) return;

    // Postorder traversal: LRN
    replaceWithInorderUsingPostorderTraversal(root->left, inorderArray, index);
    replaceWithInorderUsingPostorderTraversal(root->right, inorderArray, index);
    root->data = inorderArray[index];
    index++;
}

// T.C: O(n) + O(n) = O(n)
// S.C: O(n)
void convertBSTIntoHeap(Node* root) {
    vector<int> inorderArray;
    storeInorderTraversal(root, inorderArray);

    // Replace the node values with the 'inorderArray' value, using the path of postorder traversal
    int StartIndex = 0;
    replaceWithInorderUsingPostorderTraversal(root, inorderArray, StartIndex);
}

int main() {
//        _ 10 _
//       /      \
//      5       15
//     / \     /  \
//    4   6   11  20
//   /
//  2

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(11);
    root->right->right = new Node(20);
    root->left->left->left = new Node(2);

    cout << "Given input:" << endl;
    levelOrderTraversal(root);
    cout << endl << "Max heap:" << endl;
    convertBSTIntoHeap(root);
    levelOrderTraversal(root);
    // O/P:
    // Max heap:
    // 20
    // 6 15
    // 4 5 10 11
    // 2

    return 0;
}
