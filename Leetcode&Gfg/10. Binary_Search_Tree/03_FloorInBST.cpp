// GFG: Floor in BSt   --->   You are given a BST(Binary Search Tree) with n number of nodes and value x. Your task
// is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Example 1:
// Input:
// n = 7  
//   2
//    \
//     81
//    /  \
//   42  87
//    \    \
//    66   90
//    /
//   45
// x = 87
// Output: 87
// Explanation: 87 is present in tree so floor will be 87.

// Example 2:
// Input:
// n = 4                   
//   6
//    \
//     8
//    / \
//   7   9
// x = 11
// Output: 9

// Example 3:
// Input:
// n = 4                 
//   6
//    \
//     8
//    / \
//   7   9
// x = 5
// Output: -1

// Constraint:
// 1 <= Node data <= 10^9
// 1 <= n <= 10^5

// Problem link: https://www.geeksforgeeks.org/problems/floor-in-bst/1


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
    int floor(Node* root, int x) {
        int floor = -1;

        while(root != NULL) {
            if(x > root->data) {
                floor = root->data;
                root = root->right;
            } else if(x < root->data) {
                root = root->left;
            } else {   // if(x == root->data)
                floor = root->data;
                break;
            }
        }

        return floor;
    }
};

int main() {
    Node* root = new Node(2);
    root->right = new Node(81);
    root->right->left = new Node(42);
    root->right->right = new Node(87);
    root->right->left->right = new Node(66);
    root->right->right->right = new Node(90);
    root->right->left->right->left = new Node(45);

    int x = 87;
    cout << Solution().floor(root, x);

    return 0;
}
