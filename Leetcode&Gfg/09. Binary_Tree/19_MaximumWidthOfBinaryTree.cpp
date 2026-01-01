// Leetcode 662. Maximum Width of Binary Tree   --->   Given the root of a binary tree, return the maximum width
// of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
// where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that
// level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// Example 1:
//          1
//         / \
//        3   2
//       / \   \
//      5   3   9
// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

// Example 2:
//          1
//         / \
//        3   2
//       /     \
//      5       9
//     /       /
//    6       7
// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

// Example 3:
//          1
//         / \
//        3   2
//       /
//      5
// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).

#include <bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) {
        
    }
};

int main() {
//          1
//         / \
//        2   3 
//       / \
//      4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << Solution().widthOfBinaryTree(root);

    return 0;
}
