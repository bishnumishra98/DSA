// GFG: Top View of Binary Tree   --->   You are given the root of a binary tree, and your task is to return its top view.
// The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:
// ● Return the nodes from the leftmost node to the rightmost node.
// ● If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included
//   in the view.

// Example 1:
// Input: root = [1, 2, 3]
//      1
//     / \
//    2   3
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

// Example 2:
//         10
//       /    \
//      20    30
//     /  \  /  \
//    40  6090  100
// Input: root = [10, 20, 30, 40, 60, 90, 100]
// Output: [40, 20, 10, 30, 100]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

// Problem link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Algorithm: It is simple. For every vertical line of the tree, store the top node of that vertical line, and
//            eventually we get the top view of the entire tree.
//            To store the top node that comes in every vertical line, we can probably use a map data structure
//            to map each vertical with its top node.
//            And traverse the tree in BFS so that we can easily move deeper into the tree and record the topmost
//            node for each vertical line.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // T.C: O(n)   where n = no.of nodes in the tree
    // S.C: O(n)
    vector<int> topView(Node *root) {
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

            // If vertical is not found in map, store the vertical with the node seen on this vertical in the map
            if(mpp.find(vertical) == mpp.end()) mpp[vertical] = node->data;
            // If vertical is found in the map, do not update the node, because we are interested in only the
            // first node that is seen on this vertical line. In this way we make sure that we are storing only
            // the top view of every vertical.

            // Push the node's children in queue with vertical line
            if(node->left) q.push({node->left, vertical - 1});
            if(node->right) q.push({node->right, vertical + 1});
        }

        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};

int main() {
//         10
//       /    \
//      20    30
//     /  \  /  \
//    40  6090  100

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->left = new Node(90);
    root->right->right = new Node(100);

    Solution sol;
    vector<int> ans = sol.topView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
