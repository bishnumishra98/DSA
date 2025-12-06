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


class Solution {
private:
    void storeLeftView(Node* root, int level, vector<int>& ans) {
        if(root == NULL) return;

        // Store the node's value in 'ans' only if the node is being visited for the first time in this level
        if(ans.size() == level) ans.push_back(root->data);
        
        storeLeftView(root->left, level + 1, ans);
        storeLeftView(root->right, level + 1, ans);
    }

public:
    // T.C: O(n),   where n = number of nodes in the tree
    // S.C: O(h),   where h = height of the tree (h = n in skew tree)
    vector<int> leftView(Node *root) {
        vector<int> ans;
        storeLeftView(root, 0, ans);
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
