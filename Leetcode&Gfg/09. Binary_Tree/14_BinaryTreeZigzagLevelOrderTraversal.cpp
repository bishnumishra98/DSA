// Leetcode: 103. Binary Tree Zigzag Level Order Traversal   --->   Given the root of a binary tree, return the zigzag
// level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and
// alternate between).

// Example 1:
//      3
//     / \
//    9  20
//      /  \
//     15   7 
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
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
    // T.C: O(n);   where n = number of nodes in the binary tree
    // S.C: O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = (leftToRight) ? i : (size - 1 - i);   // find position to fill node's value

                row[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // After this level
            leftToRight = !leftToRight;   // change the direction for next level
            ans.push_back(row);
        }

        return ans;
    }
};

int main() {
//      3
//     / \
//    9  20
//      /  \
//     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = Solution().zigzagLevelOrder(root);
    for(auto vec : ans) {
        for(auto val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
