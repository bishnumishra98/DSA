// GFG: Kth Ancestor in a Tree   --->   Given a binary tree of size  N, a node, and a positive integer k.
// Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the
// given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Example 1:
// Input:
// K = 2 Node = 4
//        1
//       / \
//      2   3
//     / \
//    4   5
// Output: 1
// Explanation:
// Since, K is 2 and node is 4, so we
// first need to locate the node and
// look k times its ancestors.
// Here in this Case node 4 has 1 as his
// 2nd Ancestor aka the Root of the tree.

// Example 2:
// Input:
// K = 1 Node = 3 
//        1
//      /   \
//     2     3
// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.

// Constraints:
// 1 <= N <= 10^5
// 1 <= K <= 100
// 1 <= Node.data <= N

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int solve(Node *root, int &k, int node) {
    if(root == NULL) return -1;   // If root is NULL, the node is not found, so return -1.
    if(root->data == node) return root->data;   // If the root->data matches the node, return a 'non -1' value, that can be root->data.

    // Recursively search for the node in the left and right subtrees.
    int left = solve(root->left, k, node);
    int right = solve(root->right, k, node);

    // If node is not found any of the two subtrees, return not found(-1); else if found then
    // decrement value of k by 1 and check if its equal to 0, this is only the ancestor node,
    // so return it. If this is not the ancestor node, return only that node data(left or right) to parent node.
    if(left != -1) {
        k--;
        if(k == 0) return root->data;   // if k is 0, it means this node is only the ancestor
        return left;   // sending found signal to its parent
    } else if(right != -1) {
        k--;
        if(k == 0) return root->data;   // if k is 0, it means this node is only the ancestor
        return right;   // sending found signal to its parent
    } else {
        return -1;   // sending not found signal to its parent
    }
}

// T.C: O(n)
// S.C: O(h)
int kthAncestor(Node *root, int k, int node) {
    int ans = solve(root, k, node);
    // It is already given that k>=1. Thus, if node given is the root node itself and k is for sure >= 1,
    // then ancestor will exist beyond the root of the tree which is an invalid ancestor. Thus return -1 in this case too.
    if(ans == -1 || ans == node) return -1;
    else return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    int k = 2, node = 4;
    int ans = kthAncestor(root, k, node);
    cout << ans;

    return 0;
}
