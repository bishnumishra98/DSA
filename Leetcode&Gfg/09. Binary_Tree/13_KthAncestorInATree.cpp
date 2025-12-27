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

// Problem link: https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1


// Algorithm: It is simple. Dry run for best understanding.
// 1. Perform a DFS traversal of the tree.
// 2. Base case:
//    - If the current node is NULL, return -1.
//    - If the current node is the target, return its value to signal that the target is found.
// 3. Recursively search the left and right subtrees.
// 4. If the target is found in either subtree:
//    - Decrement k.
//    - If k becomes 0, the current node is the kth ancestor; return its value.
//    - Otherwise, propagate the found signal upward.
// 5. If the target is not found in either subtree, return -1.


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int findKthAncestor(Node* root, int &k, int target) {
        // Base cases
        if(root == NULL) return -1;
        if(root->data == target) return target;   // if target node is found, propagate the found signal upward with target

        // Search in left and right subtrees
        int left = findKthAncestor(root->left, k, target);
        int right = findKthAncestor(root->right, k, target);

        // If target is found in either subtree
        if(left != -1 || right != -1) {
            k--;
            // If k becomes 0, the current node is the kth ancestor of target; thus propagate
            // the found signal upward, but this time with the value of current node
            if(k == 0) return root->data;
            // If k is not yet 0, propagate found signal upward with the value of target itself
            return (left != -1) ? left : right;
        }

        return -1;   // target not found in this subtree
    }

public:
    // T.C: O(n)
    // S.C: O(h)   due to recursion stack, h = n for skew tree
    int kthAncestor(Node *root, int k, int node) {
        int result = findKthAncestor(root, k, node);

        // If ancestor doesn't exist or node itself returned.
        // Node itself returned means the target was found but we couldn't move up k levels, because the tree
        // does not have enough ancestors above it to move up k levels (i.e., kth ancestor doesn't exist).
        if(result == -1 || result == node) return -1;

        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2, node = 4;
    cout << Solution().kthAncestor(root, k, node);

    return 0;
}
