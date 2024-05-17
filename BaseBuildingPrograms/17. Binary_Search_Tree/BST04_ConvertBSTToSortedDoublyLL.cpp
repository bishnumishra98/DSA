// Convert BST to sorted doubly linked list

// Example 1:
// Input:
//          100 
//         /   \
//        50   200
//       /  \    \
//      5   60   300
// Output: 5 <-> 50 <-> 60 <-> 100 <-> 200 <-> 300

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

// Definition for doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node() : prev(NULL), next(NULL) {}
        Node(int x) : data(x), prev(NULL), next(NULL) {}
};

// Function to print elements of linked list
void printElementsOfLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// ----------------------------------------------------------------------------------------

// Brute force

void inorderTraversal(TreeNode* root, vector<int> &v) {
    if(!root) return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

// Function to create a doubly linked list from a vector
void createLL(vector<int>& v, Node*& head) {
    head = NULL;   // Initialize head pointer to null
    Node* prevNode = NULL;

    for (int value : v) {
        // Create a new node
        Node* newNode = new Node(value);
        newNode->prev = prevNode;

        if (prevNode != NULL) {
            prevNode->next = newNode;
        }

        if (head == NULL) {
            head = newNode;   // If head is null, set it to the first node
        }

        prevNode = newNode;
    }
}

// T.C: O(n)
// S.C: O(2n)
void convertBSTtoLL_bruteForce(TreeNode* root, Node* &head) {
    vector<int> v;
    inorderTraversal(root, v);
    createLL(v, head);
}

// ----------------------------------------------------------------------------------------

// Optimal algorithm:

// T.C: 
// S.C: 
void convertBSTtoLL(TreeNode* root, Node* &head) {
    if(!root) return;

    // R
    convertBSTtoLL( root->right, head);

    // N
    // attaching next pointer of current node to head of LL
    root->right = head;
    // attaching prev pointer of head of LL to current node
    if(head != NULL) head->prev = root;
    head = root;

    // L
    convertBSTtoLL( root->left, head);
}


int main() {
//          100 
//         /   \
//        50   200
//       /  \    \
//      5   60   300

    // Creating a tree
    TreeNode* root = new TreeNode(100);
    root->left = new TreeNode(50);
    root->right = new TreeNode(200);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(60);
    root->right->right = new TreeNode(300);

    // Creating a blank doubly Linked List
    Node* head = new Node();

    // convertBSTtoLL_bruteForce(root, head);
    convertBSTtoLL(root, head);

    printElementsOfLL(head);

    cout << endl;
    cout << head->next->next->prev->data;

    return 0;
}
