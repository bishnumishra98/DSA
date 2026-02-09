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

// Algorithm: It is similar to level order traversal of binary tree, with a slight modification that we need to keep track of
// the direction of traversal for each level using a boolean variable 'leftToRight'. If it is true, we fill the current level
// from left to right, otherwise from right to left.
// 1. Initialize a queue to facilitate level order traversal and a boolean variable 'leftToRight' to keep track of the direction.
// 2. While the queue is not empty, do the following:
//    a. Determine the number of nodes at the current level.
//    b. Create a vector 'row' to store the values of nodes at the current level.
//    c. For each node at the current level, do the following:
//       i.   Dequeue the front node from the queue.
//       ii.  Determine the index to fill in the 'row' vector based on the 'leftToRight' variable.
//       iii. Store the node's value in the 'row' vector at the determined index
//       iv.  Enqueue the left and right children of the node if they exist.
//    d. After processing all nodes at the current level, toggle the 'leftToRight' variable to change the direction for the
//       next level.
// 3. Return the result vector containing the zigzag level order traversal.

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

            // Traverse all nodes of the current level and store their values in 'row' vector acording to the direction
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = (leftToRight) ? i : (size - i - 1);   // find position to fill node's value

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
