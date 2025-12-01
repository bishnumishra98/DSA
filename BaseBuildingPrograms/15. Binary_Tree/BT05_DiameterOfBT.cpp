// Diameter of Binary Tree: The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.

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


int heightOfBT(TreeNode* root) {
    if(root == NULL) return 0;

    int left_height = heightOfBT(root->left);
    int right_height = heightOfBT(root->right);

    return max(left_height, right_height) + 1;
}

// T.C: O(n^2)
// S.C: O(n)
int diameterOfTree_bruteForce(TreeNode* root) {
    if(root == NULL) return 0;

    int dia_left = diameterOfTree_bruteForce(root->left);
    int dia_right = diameterOfTree_bruteForce(root->right);

    int dia_fromThisNode = heightOfBT(root->left) + heightOfBT(root->right);

    return max(max(dia_left, dia_right), dia_fromThisNode);
}

//------------------------------------------------------------------------------------

int ans = 0;
int height(TreeNode* root) {
    if(root == NULL) return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    ans = max(ans, left_height + right_height);

    return max(left_height, right_height) + 1;
}

// T.C: O(n)
// S.C: O(n)
int diameterOfTree(TreeNode* root) {
    height(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << diameterOfTree_bruteForce(root) << endl;   // o/p: 3
    cout << diameterOfTree(root) << endl;   // o/p: 3

    return 0;
}
