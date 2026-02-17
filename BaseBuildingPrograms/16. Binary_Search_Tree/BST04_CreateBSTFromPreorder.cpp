#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node() : left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void preorderTraversal(Node* root) {
    if(root == NULL) return;   // base case

    cout << root->data << " ";   // N
    preorderTraversal(root->left);   // L
    preorderTraversal(root->right);   // R
}

void levelorderTraversal_LevelByLevel(Node* root) {
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
Node* createBSTFromPreorder(vector<int>& preorderArray) {
    if(preorderArray.empty()) return NULL;

    Node* root = new Node(preorderArray[0]);

    vector<int> left, right;
    for(int i = 1; i < preorderArray.size(); i++) {
        if(preorderArray[i] < root->data) left.push_back(preorderArray[i]);
        else right.push_back(preorderArray[i]);
    }

    root->left = createBSTFromPreorder(left);
    root->right = createBSTFromPreorder(right);

    return root;
}


int main() {
// For the preorder array: {4, 2, 1, 3, 6, 5, 7}, BST would look like this:

//           4 
//         /   \
//        2     6
//       / \   / \
//      1   3 5   7

    vector<int> preorderArray = {4, 2, 1, 3, 6, 5, 7};
    Node* root = createBSTFromPreorder(preorderArray);

    cout << "Preorder traversal:\n";
    preorderTraversal(root);
    cout << endl;
    cout << "Level-order traversal:\n";
    levelorderTraversal_LevelByLevel(root);
    
    return 0;
}
