// GFG: Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree
// is the set of nodes visible when the tree is viewed from the left side.
// Note: If the tree is empty, return an empty list.

// Example 1:
// Input: root = [1, 2, 3, 4, 5, N, N]
//       1
//      / \
//     2   3
//    / \
//   4   5
// Output:[1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

// Example 2:
// Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]
//       1
//      / \
//     2   3
//        /
//       4
//        \
//         5
// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

// Problem link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


#include <bits/stdc++.h>
using namespace std;

// A binary tree node
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


// T.C: O(n);   where n is the number of nodes in the binary tree.
// S.C: O(h);   where h is the height of the binary tree.
class Solution {
public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();   // size means there are 'size' nodes at the current level.

            // The first node in the queue belongs to the leftmost position
            // of the current level, so this node is visible from the left side.
            ans.push_back(q.front()->data);

            // Now remove all nodes of this level from the queue,
            // and add their children (which form the next level).
            while(size--) {
                Node* curr = q.front();
                q.pop();

                // Add left child first, so it appears before right child
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return ans;
    }
};

int main() {
//       1
//      / \
//     2   3
//        /
//       4
//        \
//         5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);

    vector<int> ans = Solution().leftView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
