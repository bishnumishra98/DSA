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
    // Indexes are not normalized, thus it cannot handle very deep trees
    // T.C: O(n);   where n = number of nodes in tree
    // S.C: O(n)
    int widthOfBinaryTree_bruteforce(TreeNode* root) {
        if(root == NULL) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;   // {node, index_in_complete_binary_tree}
        q.push({root, 0});

        while(!q.empty()) {
            int levelSize = q.size();
            long long firstIndex = q.front().second;
            long long lastIndex = firstIndex;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                int index = q.front().second;
                q.pop();

                lastIndex = index;   // will end up storing rightmost index

                if(node->left) q.push({node->left, index * 2 + 1});

                if(node->right) q.push({node->right, index * 2 + 2});
            }

            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return (int)maxWidth;
    }

// ------------------------------------------------------------------------------------------------------------

    // T.C: O(n);   where n = number of nodes in tree
    // S.C: O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;   // {node, index_in_complete_binary_tree}
        q.push({root, 0});

        while(!q.empty()) {
            int levelSize = q.size();
            long long levelMinIndex = q.front().second;   // minimum index at current level (used for normalization)
            long long firstIndex = 0, lastIndex = 0;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front().first;
                long long currentIndex = q.front().second;
                q.pop();

                long long normalizedIndex = currentIndex - levelMinIndex;   // normalize index to avoid overflow

                if(i == 0) firstIndex = normalizedIndex;
                if(i == levelSize - 1) lastIndex = normalizedIndex;

                // Push children with complete-binary-tree indexing
                if(currentNode->left) q.push({currentNode->left, normalizedIndex * 2 + 1});

                if(currentNode->right) q.push({currentNode->right, normalizedIndex * 2 + 2});
            }

            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return (int)maxWidth;
    }
};


int main() {
//          1
//         / \
//        3   2
//       / \   \
//      5   3   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << Solution().widthOfBinaryTree_bruteforce(root) << endl;
    cout << Solution().widthOfBinaryTree(root) << endl;

    return 0;
}
