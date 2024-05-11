// -> A Binary Search Tree (BST) is a binary tree data structure where the left child of a node contains values less
//    than the node's value, while the right child contains values greater than the node's value. Hence, at any node of BST,
//    all nodes in its left subtree is always less than it, and all nodes in its right subtree is always greater than it. This
//    property enables efficient search, insertion, and deletion operations, making BSTs suitable for applications requiring
//    ordered data storage and retrieval.

// -> To search a node in BT, the time complexity was O(N) where N = no. of nodes in the tree; whereas the search time complexity
//    in a BST is O(H) where H = height of the tree. Height of a balanced tree is usually logN, therefore in average cases the
//    search time complexity of a BST is O(logN).

// -> The INORDER TRAVERSAL of a BST always gives a sorted array.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node() : left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void inOrderTraversal(Node* root) {
    if(root == NULL) return;   // base case

    inOrderTraversal(root->left);   // L
    cout << root->data << " ";   // N
    inOrderTraversal(root->right);   // R
}

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
            if(!q.empty()) q.push(NULL);   // 'if(!q.empty())' condition helps to stop pushing NULL in
            // queue if queue is empty, as a result we will be able to exit this while() loop in the last iteration.
        } else {   // If 'front' is a valid node
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            cout << front->data << " ";
        }
    }
}

// --------------------------------------------------------

Node* insert(Node* &root, int value) {
    if (root == NULL) return new Node(value);

    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);

    return root;
}

// T.C: O(NlogN) on average, O(N^2) in the worst case.
// S.C: O(N)
Node* createBST(int values[], int n) {
    Node* root = NULL;   // initializing the root of the BST as NULL.

    // Iterate over each value in the array and insert it into the BST using the insert() function.
    for (int i=0; i<n; i++) {
        root = insert(root, values[i]);
    }

    return root;
}


int main() {
// For values {5, 1, 3, 4, 2, 7, 9}, BST would look like this:
//          5 
//         / \
//        1   7
//         \   \
//          3   9
//         / \
//        2   4

    int values[] = {5, 1, 3, 4, 2, 7, 9};
    int size = 7;
    Node* root = createBST(values, size);

    // For verification of BST
    cout << "Inorder traversal:\n";
    inOrderTraversal(root);
    cout << "\nLevel order traversal:\n";
    levelOrderTraversal_LevelByLevel(root);

    return 0;
}
