// Leetcode: 543. Diameter of Binary Tree   --->   Given the root of a binary tree, return the length
// of the diameter of the tree. The diameter of a binary tree is the length of the longest path
// between any two nodes in a tree. This path may or may not pass through the root. The length of a
// path between two nodes is represented by the number of edges between them.

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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // T.C:
    // S.C: 
    int diameterOfBinaryTree(TreeNode* root) {
        static int longestDiameter = 0;
        // base case
        if(root == NULL) return 0;

        int leftSubTree_diamter = diameterOfBinaryTree(root->left);
        int rightSubTree_diamter = diameterOfBinaryTree(root->right);
        int diameter = leftSubTree_diamter + rightSubTree_diamter;
        longestDiameter = max(longestDiameter, diameter);
        return longestDiameter;
    }
};

int main() {
    Solution obj;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << obj.diameterOfBinaryTree(root);

    return 0;
}
