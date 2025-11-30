// A binary tree's height or maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.

// Example 1:
//          3
//         / \
//        9   20 
//           /  \
//          15   7
//
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

#include <iostream>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

// T.C: O(n);   where n = no.of nodes
// S.C: O(h);   where h = height of recursive call. If the tree is balanced, then h = log(n), 
//                        if tree is a skewed tree, then h = n.
int heightOfTree(TreeNode* root) {
    // Base case
    if(root == NULL) return 0;
    
    int leftSubTree_height = heightOfTree(root->left);
    int rightSubTree_height = heightOfTree(root->right);

    return max(leftSubTree_height, rightSubTree_height) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << heightOfTree(root);

    return 0;
}
