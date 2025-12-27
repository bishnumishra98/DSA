// Leetcode: 113. Path Sum II   --->   Given the root of a binary tree and an integer targetSum, return all
// root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned
// as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//               5
//             /   \
//            4     8
//           /     / \
//          11    13  4
//         /  \      /  \
//        7    2    5    1 
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

// Example 2:
// Input: root = [1,2,3], targetSum = 5
//     1
//    / \
//   2   3
// Output: []

// Example 3:
// Input: root = [1,2], targetSum = 0
// Output: []


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
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if(!root) return;

        // Include current node in path
        path.push_back(root->val);

        // Subtract targetSum
        targetSum -= root->val;

        // If we reached a leaf node (no children): If the remaining sum is 0, the required path is found. Store it.
        if(!root->left && !root->right) {
            if(targetSum == 0) {
                result.push_back(path);   // store a copy of current path
            }
        }

        // Otherwise, check in left or right subtree
        dfs(root->left, targetSum, path, result);
        dfs(root->right, targetSum, path, result);

        // Backtrack → remove current node before returning
        path.pop_back();
    }

    // T.C: O(n)
    // S.C: O(h)
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;   // will store all valid paths
        vector<int> path;             // current path from root → current node
        dfs(root, targetSum, path, result);
        return result;
    }
};


int main() {
//               5
//             /   \
//            4     8
//           /     / \
//          11    13  4
//         /  \      /  \
//        7    2    5    1 
    int targetSum = 22;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> ans = Solution().pathSum(root, targetSum);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
