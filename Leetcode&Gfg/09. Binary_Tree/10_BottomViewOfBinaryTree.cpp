// GFG: Bottom View of Binary Tree   --->   You are given the root of a binary tree, and your task is to return its
// bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the
// level order traversal is considered.

// Example 1:
// Input: root = [1, 2, 3, 4, 5, N, 6]
//        1
//       / \
//      2   3
//     / \   \
//    4   5   6
// Output: [4, 2, 5, 3, 6]

// Example 2:
// Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
//        _ 20 _
//       /      \
//      8       22
//     / \     /  \
//    5   3   4   25
//       / \      /
//      10 14    28
// Output: [5, 10, 4, 28, 25]

// Probem link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Algorithm: Exactly same as 'Leetcode&Gfg\09. Binary_Tree\09_TopViewOfBinaryTree.cpp'.
//            The only difference here is that we have to store the last seen node of every vertical line.
//            To achieve this, just always update the value of node occurring in every vertical.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        map<int, int> mpp;   // {vertical (x-coordinate) -> node's data}
        queue<pair<Node*, int>> q;   // {node, vertical (x-coordinate)}
        q.push({root, 0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int vertical = it.second;

            // For bottom view -> always update the value for this vertical
            mpp[vertical] = node->data;

            // Push the node's children in queue with vertical line
            if(node->left) q.push({node->left, vertical - 1});
            if(node->right) q.push({node->right, vertical + 1});
        }

        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};

int main() {
//        1
//       / \
//      2   3
//     / \   \
//    4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.bottomView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
