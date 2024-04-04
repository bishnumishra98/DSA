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
#include <queue>
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

// T.C: O(n);   where n = no.of nodes
// S.C: O(height);   height = n for a skew tree
void preOrderTraversal(Node* root) {
    if(root == NULL) return;   // base case

    cout << root->data << " ";   // N
    preOrderTraversal(root->left);   // L
    preOrderTraversal(root->right);   // R
}

// T.C: O(n);   where n = no.of nodes
// S.C: O(height);   height = n for a skew tree
void inOrderTraversal(Node* root) {
    if(root == NULL) return;   // base case

    inOrderTraversal(root->left);   // L
    cout << root->data << " ";   // N
    inOrderTraversal(root->right);   // R
}

// T.C: O(n);   where n = no.of nodes
// S.C: O(height);   height = n for a skew tree
void postOrderTraversal(Node* root) {
    if(root == NULL) return;   // base case

    postOrderTraversal(root->left);   // L
    postOrderTraversal(root->right);   // R
    cout << root->data << " ";   // N
}

// T.C: O(n);   where n = no.of nodes
// S.C: O(width);   width = n for a skew tree
void levelOrderTraversal(Node* root) {
    queue <Node*> q;
    // Step 1: Push the parent node in queue
    q.push(root);

    while(!q.empty()) {
        // Step 2: Until the queue is empty, print its front element(parent node),
        //         pop the front element; and push its children(if exists) in queue.
        Node* front = q.front();
        cout << front->data << " ";
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

// T.C: O(n); where n = no.of nodes
// S.C: O(width);  width = n for a skew tree
void levelOrderTraversal_LevelByLevel(Node* root) {
    queue <Node*> q;
    q.push(root);
    q.push(NULL);   // NULL acts as an indicator to change line

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {   // If 'front' is a NULL node
            cout << endl;   // Line changed.
            // If 'front' of queue is a NULL, it means the last parent node has been printed,
            // popped out of queue, and its children have been pushed in queue already in the last
            // iteration. Thus, we should again add NULL to queue, in order to mark line change.
            if(!q.empty()) q.push(NULL);
        } else {   // If 'front' is a valid node
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
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

    cout << "Pre-order Traversal:\n";
    preOrderTraversal(root); cout << endl << endl;   // o/p: 10 20 30 40 50

    cout << "In-order Traversal:\n";
    inOrderTraversal(root); cout << endl << endl;   // o/p: 30 20 40 10 50

    cout << "Post-order Traversal:\n";
    postOrderTraversal(root); cout << endl << endl;   // o/p: 30 40 20 50 10

    cout << "Level-order Traversal:\n";
    levelOrderTraversal(root); cout << endl << endl;   // o/p: 10 20 50 30 40

    cout << "Level-order Traversal(LBL):\n";
    levelOrderTraversal_LevelByLevel(root);   // o/p: 10
                                             //       20 50
                                            //        30 40

    return 0;
}
