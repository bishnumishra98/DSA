// In the last module, we saw how to create a Binary Tree manually using a Node class. But what if the
// tree is big ? Then creating nodes by writing 'left->right->left->...' would be a hectic task. Here
// we will need help of a 'createBinaryTree' function.

#include <iostream>
#include <vector>
using namespace std;

// Node for building a Binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() : left(NULL), right(NULL) {}
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// Function that returns root node of the constructed binary tree
Node* buildBinaryTree(vector<int>& nodes, int& i) {
    // Base case
    if(nodes[i] == -1) return NULL;

    Node* newNode = new Node(nodes[i]);   // newNode will represent the root node of this binary tree
    i++;
    newNode->left = buildBinaryTree(nodes, i);   // recursive call to build left subtree
    i++;
    newNode->right = buildBinaryTree(nodes, i);   // recursive call to build right subtree

    return newNode;
}

int main() {
    // Build a Binary Tree Preorder: {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, -1},
    //                               where -1 represents NULL node
    /*
    Build a tree like this:

                   ___ 10 ___
                 /            \
             _ 20 _            50
           /        \        /    \
          30         40    NULL   NULL
         /  \       /  \
      NULL NULL   NULL NULL

    */

    vector<int> nodes = {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, -1};

    // Creating the BT
    int i = 0;
    Node* root = buildBinaryTree(nodes, i);

    // Printing all nodes of BT
    cout << "root->data: " << root->data << endl;
    cout << "root->left->data: " << root->left->data << endl;
    cout << "root->left->left->data: " << root->left->left->data << endl;
    cout << "root->left->right->data: " << root->left->right->data << endl;
    cout << "root->right->data: " << root->right->data << endl;

    return 0;
}
