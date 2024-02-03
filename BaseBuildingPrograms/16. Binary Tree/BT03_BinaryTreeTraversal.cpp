/*
Consider the Binary Tree:

           ____ 10 ____
         /              \
     __ 20 __            50 
    /        \          /  \
   30        40       NULL NULL
  /  \      /  \
NULL NULL NULL NULL

*/

// There are 4 classical ways to traverse a Binary tree:
// 1) Pre-order Traversal: Cheatcode = Node-Left-Right (NLR)
//    Path: {10, 20, 30, 40, 50}
// 2) In-order traversal: Cheatcode = Left-Node-Right (LNR)
//    Path: {30, 20, 40, 10, 50}
// 3) Post-order Traversal: Cheatcode = Left-Right-Node (LRN)
//    Path: {30, 40, 20, 50, 10}
// 4) Level-order Traversal(Breadth-First Traversal): Visit nodes level by level, from left to right.
//    Path: {10, 20, 50, 30, 40}

#include <iostream>
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
Node* buildBinaryTree(int nodes[], int& i) {
    if(nodes[i] == -1) return NULL;

    Node* newNode = new Node(nodes[i]);
    i++;
    newNode->left = buildBinaryTree(nodes, i);
    i++;
    newNode->right = buildBinaryTree(nodes, i);

    return newNode;
}

void preOrderTraversal(Node* root) {

}

void preOrderTraversal(Node* root) {
    
}

int main() {
    int nodes[] = {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, -1};
    /*
    Building a tree like this:

               ____ 10 ____
             /              \
         __ 20 __            50 
        /        \          /  \
       30        40       NULL NULL
      /  \      /  \
    NULL NULL NULL NULL
    */

    // creating the BT
    int i = 0;
    Node* root = buildBinaryTree(nodes, i);

    


    return 0;
}
