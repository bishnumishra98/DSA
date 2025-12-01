/*
Consider the Binary Tree:

            ______ 10 _______
          /                   \
     ___ 20 ___                30 
    /          \                 \
   40          50                60
  /  \        /  \              /  \
 70  80      90  100          110  120
                   \          /     /
                   130      140   150
*/

// There are 4 classical ways to traverse a Binary tree:
// 1) Pre-order Traversal: Cheatcode = Node-Left-Right (NLR)
//    Path: {10, 20, 40, 70, 80, 50, 90, 100, 130, 30, 60, 110, 140, 120, 150}
// 2) In-order traversal: Cheatcode = Left-Node-Right (LNR)
//    Path: {70, 40, 80, 20, 90, 50, 100, 130, 10, 30, 140, 110, 60, 150, 120}
// 3) Post-order Traversal: Cheatcode = Left-Right-Node (LRN)
//    Path: {70, 80, 40, 90, 130, 100, 50, 20, 140, 110, 150, 120, 60, 30, 10}
// 4) Level-order Traversal(Breadth-First Traversal): Visit nodes level by level, from left to right.
//    Path: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}

#include <iostream>
#include <vector>
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
Node* buildBinaryTree(vector<int>& nodes, int& i) {
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
    queue<Node*> q;
    // Step 1: Push the parent node in queue
    q.push(root);

    while(!q.empty()) {
        // Step 2: Until the queue is not empty, push its children(if exists) in queue,
        //         print its front element(parent node), and pop the front element.
        Node* front = q.front();
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
        cout << front->data << " ";
    }
}

// T.C: O(n);   where n = no.of nodes
// S.C: O(width);   width = n for a skew tree
void levelOrderTraversal_LevelByLevel(Node* root) {
    queue<Node*> q;
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
            if(!q.empty()) q.push(NULL);   // 'if(!q.empty())' condition also helps to stop pushing NULL in
            // queue if queue is empty, as a result we will be able to exit this while() loop in the last iteration.
        } else {   // If 'front' is a valid node
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            cout << front->data << " ";
        }
    }
}

int main() {
    vector<int> nodes = {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, -1};
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
