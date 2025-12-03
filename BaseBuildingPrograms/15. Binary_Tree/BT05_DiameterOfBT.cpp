// Diameter of Binary Tree: The diameter of a binary tree is the length of the longest path between any
//                          two nodes in a tree. This path may or may not pass through the root. By length,
//                          we mean the number of edges between the two nodes.

// Example 1:
//          1
//         / \
//        2   3 
//       / \
//      4   5

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3]. There are 3 edges in each path.

// Example 2:
// Input: root = [1,2]
// Output: 1

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

int dfsHeight(TreeNode* root, int &diameter) {
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left, diameter);     // left height
    int rh = dfsHeight(root->right, diameter);    // right height

    // Update best diameter found so far
    diameter = max(diameter, lh + rh);

    // Return height
    return 1 + max(lh, rh);
}

// T.C: O(n)
// S.C: O(n)
int diameterOfTree(TreeNode* root) {
    int diameter = 0;
    dfsHeight(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << diameterOfTree(root) << endl;   // o/p: 3

    return 0;
}
