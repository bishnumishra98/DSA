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

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            cout << front->data << " ";
        }
    }
}

// --------------------------------------------------------------------------------

// T.C: O(N)
// S.C: O(H)   where H = NlogN on average case, and H = N in the worst case.
Node* createBSTFromInorder(int inorderArray[], int start, int end) {
    if(start > end) return NULL;   // base case

    // Creating root from mid element
    int mid = start + (end - start)/2;   // same as (start + end)/2
    int element = inorderArray[mid];
    Node* root = new Node(element);

    // Creating left subtree with elements before mid index
    root->left = createBSTFromInorder(inorderArray, start, mid - 1);
    
    // Creating right subtree with elements after mid index
    root->right = createBSTFromInorder(inorderArray, mid + 1, end);

    return root;
}


int main() {
// For the inorder array: {1, 2, 3, 4, 5, 6, 7}, BST would look like this:

//           4 
//         /   \
//        2     6
//       / \   / \
//      1   3 5   7

    int inorderArray[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node* root = createBSTFromInorder(inorderArray, start, end);

    cout << "Inorder traversal:\n";
    inOrderTraversal(root);
    cout << endl;
    cout << "Level-order traversal:\n";
    levelOrderTraversal_LevelByLevel(root);
    
    return 0;
}
