// Example 1:
//          1
//         / \
//        2   3 
//       / \
//      4   5

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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

// T.C:
// S.C: 
int diameterOfTree(TreeNode* root) {
    if(root == NULL) return 0;

    int dia_left = diameterOfTree(root->left);
    int dia_right = diameterOfTree(root->right);

    int dia_fromThisNode = heightOfBT(root->left) + heightOfBT(root->left);

    return max(dia_left, dia_right, dia_fromThisNode);
}

int heightOfBT(TreeNode* root) {
    if(root == NULL) return 0;

    int left_height = heightOfBT(root->left) + 1;
    int right_height = heightOfBT(root->right) + 1;

    return max(left_height, right_height);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << diameterOfTree(root);

    return 0;
}
