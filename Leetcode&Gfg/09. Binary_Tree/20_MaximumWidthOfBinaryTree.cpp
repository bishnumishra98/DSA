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


// Algorithm: It is simple. The idea is to do a level order traversal of the tree while keeping track of the index of each node
//            as if the tree is a complete binary tree. For each level, we calculate the width as the difference between the
//            maximum and minimum indices of the nodes at that level plus one. We update the maximum width found so far.
//
// ● How to assign indices to nodes as per complete binary tree ?
//   We can assign indices to nodes in a complete binary tree as follows:
//   1. The root node is assigned an index of 0.
//   2. For any node at index i:
//      ▸ Its left child is assigned an index of (2 * i) + 1.
//      ▸ Its right child is assigned an index of (2 * i) + 2.
//      Example: () denotes index of node | .. means NULL node
//              __________ 10(0) __________
//             /                           \
//          _ 20(1) _                  __ 30(2) __            ---> children from 0th indexed parent
//         /         \                /           \
//       ..(3)      ..(4)           40(5)         50(6)       ---> children from 2nd indexed parent
//      /    \     /    \          /     \       /    \
//   ..(7) ..(8) ..(9) ..(10)  60(11) ..(12) ..(13)  70(14)   ---> children from 5th and 6th indexed parents
//
//   Width of each level can be calculated as: (last_index - first_index + 1)
//   And maximum width will be the maximum of widths of all levels. In the above example, maximum width is (14 - 11 + 1) = 4.
//
//   But linearly assigning indices like this can lead to very large index values for deep trees, which may cause
//   integer overflow. To handle this, we can normalize the indices at each level by subtracting the minimum index
//   of that level from all indices at that level.
//
//   ● How to normalize indices ?
//     1. The root is still assigned an index of 0.
//     2. The children of a node at index i are still assigned the same way:
//        ▸ Its left child is assigned an index of (2 * i) + 1.
//        ▸ Its right child is assigned an index of (2 * i) + 2.
//     3. However, after reaching each level, we perform normalization. To do normalization, we subtract the minimum index
//        of that level (levelMinIndex) from all indices at that level to prevent overflow. The minimum index at each level
//        always starts from ((2 * normalized_index_of_leftmostParent) + 1) if it is the left child, whereas if left child
//        is not present, levelMinIndex starts from the right child, i.e., ((2 * normalized_index_of_leftmostParent) + 2).
//        After normalization of the nodes at the current level, every node's index gets reduced by 'levelMinIndex'.
//
//     Example: The above example with normalized indices:
//              __ 10(0) __
//             /           \
//            20(0)    __ 30(1) __           ---> normalized nodes by subtracting levelMinIndex (levelMinIndex is 1 here as the node 20 had index 1 (2 * 0 + 1) when it was pushed initially from node 10).
//                    /           \               After normalization, 20(1) - 1 became 20(0); and 30(2) - 1 became 30(1).
//                  40(0)         50(1)      ---> normalized nodes by subtracting levelMinIndex (levelMinIndex is 3 here as the node 40 had index 3 (2 * 1 + 1) when it was pushed initially from node 30).
//                 /     \       /    \           After normalization, 40(3) - 3 became 40(0); and 50(4) - 3 became 50(1).
//              60(0)  ..(1)  ..(2)  70(3)   ---> normalized nodes by subtracting levelMinIndex (levelMinIndex is 1 here as the node 60 had index 1 (2 * 0 + 1) when it was pushed initially from node 40).
//                                                After normalization, 60(1) - 1 became 60(0); and 70(4) - 1 became 70(3).
//                                                                
//   
//   Width of each level can be calculated as same like previous: (last_normalized_index - first_normalized_index + 1)
//   And maximum width will be the maximum of widths of all levels. In this normalized example, maximum width is (3 - 0 + 1) = 4.


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
    // Bruteforce: Indexes are not normalized, thus it cannot handle very deep trees
    // T.C: O(n);   where n = number of nodes in tree
    // S.C: O(n)
    int widthOfBinaryTree_bruteforce(TreeNode* root) {
        if(root == NULL) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, int>> q;   // {node, index_in_complete_binary_tree}
        q.push({root, 0});

        while(!q.empty()) {
            int levelSize = q.size();
            int firstIndex = q.front().second;
            int lastIndex = firstIndex;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                int index = q.front().second;
                q.pop();

                lastIndex = index;   // will end up storing rightmost index

                if(node->left) q.push({node->left, index * 2 + 1});
                if(node->right) q.push({node->right, index * 2 + 2});
            }

            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return maxWidth;
    }

// ------------------------------------------------------------------------------------------------------------

    // Optimal Approach: Indexes are normalized at each level to prevent overflow for deep trees
    // T.C: O(n);   where n = number of nodes in tree
    // S.C: O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;   // {node, index_in_normalized_binary_tree}
        q.push({root, 0});

        while(!q.empty()) {
            int levelSize = q.size();
            long long levelMinIndex = q.front().second;   // minimum index at current level (used for normalization)
            long long firstIndex = 0;   // after normalization, firstIndex starts from 0 for every level
            long long lastIndex = firstIndex; 

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();

                long long normalizedIndex = index - levelMinIndex;   // normalize index to avoid overflow
                lastIndex = normalizedIndex;

                // Push children with complete-binary-tree indexing (normalized)
                if(node->left) q.push({node->left, normalizedIndex * 2 + 1});
                if(node->right) q.push({node->right, normalizedIndex * 2 + 2});
            }

            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return (int)maxWidth;
    }
};


int main() {
//        10
//       /  \
//      20  30
//         /  \
//        40  50
//       /      \
//      60      70
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    root->right->left->left = new TreeNode(60);
    root->right->right->right = new TreeNode(70);

    cout << Solution().widthOfBinaryTree_bruteforce(root) << endl;
    cout << Solution().widthOfBinaryTree(root) << endl;

    return 0;
}
