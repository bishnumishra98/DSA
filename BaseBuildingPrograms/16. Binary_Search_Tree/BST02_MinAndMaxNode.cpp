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

// --------------------------------------------------------------------------------

// T.C: O(logN) on average case(balanced tree), O(N) in the worst case(skew tree).
// S.C: O(1)
Node* minNodeInBST(Node* root) {
    if(!root) return NULL;   // If root is NULL, return NULL

    Node* temp = root;

    // Go towards the left until a left node is present.
    while(temp->left) {
        temp = temp->left;
    }

    // The leftmost node of the BST is the smallest node. Thus, return it.
    return temp;
}

// T.C: O(logN) on average case(balanced tree), O(N) in the worst case(skew tree).
// S.C: O(1)
Node* maxNodeInBST(Node* root) {
    if(!root) return NULL;   // If root is NULL, return NULL

    Node* temp = root;

    // Go towards the right until a right node is present.
    while(temp->right) {
        temp = temp->right;
    }

    // The rightmost node of the BST is the largest node. Thus, return it.
    return temp;
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

    Node* minNode = minNodeInBST(root);
    Node* maxNode = maxNodeInBST(root);

    cout << "Min node: " << minNode->data << endl;
    cout << "Max node: " << maxNode->data;

    return 0;
}
