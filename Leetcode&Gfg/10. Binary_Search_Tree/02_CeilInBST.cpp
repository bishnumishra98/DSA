// GFG: Ceil in BST   --->   You are given a root binary search tree and an integer x . Your task is to find the
// Ceil of x in the tree.
// Note: Ceil(x) is a number that is either equal to x or is immediately greater than x.
// If Ceil could not be found, return -1.

// Example 1:
// Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3
//      5
//     / \
//    1   7
//     \
//      2
//       \
//        3 
// Output: 3
// Explanation: We find 3 in BST, so ceil of 3 is 3.

// Example 2:
// Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], x = 6
//       10
//      /  \
//     5    11
//    / \
//   4   7
//        \
//         8
// Output: 7
// Explanation: We find 7 in BST, so ceil of 6 is 7.

// Constraints:
// 1  ≤ Number of nodes  ≤ 10^5
// 1  ≤ Value of nodes ≤ 10^5

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    // T.C: O(h);   where h = height of tree, h = logn for balanced BST, h = n for skew tree
    // S.C: O(1)
    int findCeil(Node* root, int x) {
        int ceil = -1;

        while(root != NULL) {
            if(x > root->data) {
                root = root->right;
            } else if(x < root->data) {
                ceil = root->data;
                root = root->left;
            } else {   // if(x == root->data)
                ceil = root->data;
                break;
            }
        }

        return ceil;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->right = new Node(8);

    int x = 6;
    cout << Solution().findCeil(root, x);

    return 0;
}
