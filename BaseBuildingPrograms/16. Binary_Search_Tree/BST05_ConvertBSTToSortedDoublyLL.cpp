// Convert BST to Sorted Doubly Linked List

// Example:
// Input BST:
//          100 
//         /   \
//        50   200
//       /  \    \
//      5   60   300
//
// Output DLL:
// 5 <-> 50 <-> 60 <-> 100 <-> 200 <-> 300

#include <bits/stdc++.h>
using namespace std;

// Definition for BST node
struct Node {
    int data;
    Node* left;   // prev in DLL
    Node* right;  // next in DLL

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to print DLL
void printDoublyLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// ----------------------------------------------------------------------------------------

// Brute Force Approach

void inorderTraversal(Node* root, vector<int>& v) {
    if(!root) return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

Node* createDLLFromVector(vector<int>& v) {
    if(v.empty()) return NULL;

    Node* head = new Node(v[0]);
    Node* prev = head;

    for (int i = 1; i < v.size(); i++) {
        Node* curr = new Node(v[i]);
        prev->right = curr;
        curr->left = prev;
        prev = curr;
    }

    return head;
}

// T.C: O(N)
// S.C: O(N)
Node* convertBSTtoDLL_bruteForce(Node* root) {
    vector<int> v;
    inorderTraversal(root, v);
    return createDLLFromVector(v);
}

// ----------------------------------------------------------------------------------------

// Optimal Approach (In-place)

// Reverse inorder traversal: R → N → L
// T.C: O(N)
// S.C: O(H)
void convertBSTtoDLL_Optimal(Node* root, Node*& head) {
    if(!root) return;

    // Right
    convertBSTtoDLL_Optimal(root->right, head);

    // Node
    root->right = head;
    if(head != NULL) head->left = root;
    head = root;

    // Left
    convertBSTtoDLL_Optimal(root->left, head);
}

Node* convertBSTtoDLL(Node* root) {
    Node* head = NULL;
    convertBSTtoDLL_Optimal(root, head);
    return head;
}

// ----------------------------------------------------------------------------------------

int main() {
    // Constructing BST
    Node* root = new Node(100);
    root->left = new Node(50);
    root->right = new Node(200);
    root->left->left = new Node(5);
    root->left->right = new Node(60);
    root->right->right = new Node(300);

    // Convert BST to DLL (Optimal)
    Node* head = convertBSTtoDLL(root);

    // Print DLL
    printDoublyLinkedList(head);

    return 0;
}
