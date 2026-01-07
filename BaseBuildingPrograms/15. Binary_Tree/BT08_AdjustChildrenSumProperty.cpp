// Adjust Children Sum Property   --->   Given the root of a Binary Tree, modify the tree so that every node's value is
// equal to the sum of its children's values. You can only increment the values of the nodes (i.e., you cannot decrement
// any node's value).
// Note: There can be multiple trees formed as an answer. Return any one of them.

// Example 1:
// Input:
//       _ 40 _
//      /      \
//     10      20
//    /  \    /  \
//   2    5  30  40
// Output:
//       _ 115 _
//      /       \
//     45       70
//    /  \     /  \
//   40   5   30  40
// Another possible answer:
//       _ 150 _
//      /       \
//     80       70
//    /  \     /  \
//   40   40  30  40

// Algorithm: Idea is simple. We do a post-order traversal of the tree (Left Right Root).
// 1. For every node, we first check the sum of its children. If the sum is greater than or equal to the node's value,
//    we update the node's value to the sum of its children's values.
// 2. If the node's value is greater than the sum of its children's values, we increment the children's values to make
//    them equal to the node's value.
// 3. We then recursively call the function for the left and right subtrees to ensure that the children sum property is
//    satisfied for all nodes in the tree.
// 4. After returning from the recursion, every node's children are either equal to parent or greater than parent.
//    So, we update the parent's value to the sum of its children's values.
//    Hence, the tree is modified to satisfy the children sum property.


#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void levelOrderTraversal_LevelByLevel(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
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

bool isLeafNode(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// T.C: O(n);   where n is the number of nodes in the binary tree
// S.C: O(h);   where h is the height of the binary tree, h = n in skewed tree
void adjustTree(Node* root) {
    if(root == NULL) return;

    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum >= root->data) {   // you may even write only '>' instead of '>='
        root->data = childSum;
    } else {
        // Increment children to make their sum equal to root's data
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;   // you may even use 'else if' here instead of 'if'; that
                                                         // will give another valid tree but with less increments
    }

    // Recur for left and right subtrees to make sure their children sum property is also satisfied
    adjustTree(root->left);
    adjustTree(root->right);

    // After coming back from recursion, update root's data to children's sum
    int childSum_postRecursion = 0;
    if(root->left) childSum_postRecursion += root->left->data;
    if(root->right) childSum_postRecursion += root->right->data;

    // Update root's data to children's sum if it's not a leaf node
    if(!isLeafNode(root)) root->data = childSum_postRecursion;
}


int main() {
//       _ 40 _
//      /      \
//     10      20
//    /  \    /  \
//   2    5  30  40
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    levelOrderTraversal_LevelByLevel(root);
    adjustTree(root);
    cout << "After adjustment: " << endl;
    levelOrderTraversal_LevelByLevel(root);

    return 0;
}
