// Leetcode: 987   --->   Given the root of a binary tree, calculate the vertical order traversal of the
// binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1)
// and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index
// starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the
// same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
//         3
//        / \
//       9   20
//          /  \
//         15   7 
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

// Example 2:
// Input: root = [1,2,3,4,5,6,7]
//          1
//        /   \
//       2     3
//      / \   / \
//     4   5 6   7
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.

// Example 3:
// Input: root = [1,2,3,4,6,5,7]
//          1
//        /   \
//       2     3
//      / \   / \
//     4   6 5   7
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// This case is the exact same as example 2, but with nodes 5 and 6 swapped.
// Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

// Problem link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

// Algorithm: Code may look tough, but algorithm is simple.
//
// We perform a Level Order Traversal (BFS) while assigning coordinates
// (row, col) to each node:
//   - Root is at (0, 0)
//   - Left child  -> (row + 1, col - 1)
//   - Right child -> (row + 1, col + 1)
//
// We store all nodes that lie on the same vertical line (same column index).
// For this, we use a nested ordered data structure:
//
//   map<col, map<row, multiset<values>>>
//
// Why this structure?
// 1. 'col' (x-coordinate) is used to group nodes belonging to the same
//    vertical line and ensures left-to-right ordering automatically.
// 2. 'row' (y-coordinate) ensures nodes are processed from top to bottom
//    within the same vertical.
// 3. 'multiset' is used because multiple nodes can exist at the same
//    (row, col), and the problem requires them to be sorted by value.
//    Multiset is a powerful data structure which allows duplicates to get
//    stored in a set, and also keep all elements sorted.
//
// BFS (Level Order Traversal) is used instead of DFS because BFS naturally
// processes nodes level by level (top to bottom), which aligns perfectly
// with the vertical traversal requirement.
//
// After BFS, we iterate through the map from leftmost column to rightmost
// column, and for each column, we collect nodes row-wise and value-wise
// to build the final vertical order traversal.


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
    // T.C: n * log(n) for inserting into map
    //      + O(n) for pushing and popping elements in queue
    //      + O(n) for iterating the map and storing all values in 'ans'
    //      = O(n * logn);   where n = no.of nodes in tree
    // S.C: O(n) for map holding n nodes
    //      + O(n) for queue storing all nodes in skew tree
    //      + O(n) for vector storing all elements of tree
    //      = O(n)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;   // x-coordinate (vertical) -> {y-coordinate (level) -> multiple nodes}
        queue<pair<TreeNode*, pair<int, int>>> q;   // {TreeNode*, {x-coordinate (vertical), y-coordinate (level)}}
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);

            // Push the children of current node in the queue along with their coordinates
            if(node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Store nodes as a vector in 'ans' that come in the same vertical, i.e., same column 'x'
        vector<vector<int>> ans;
        // Iterate over columns from leftmost to rightmost (ordered by column index)
        for(auto it1: nodes) {   // it1 is of type: map<int, map<int, multiset<int>>>
            vector<int> col;
            // For the current column, iterate row-wise from top to bottom
            for(auto it2: it1.second) {   // it2 is of type: map<int, multiset<int>>
                // Append node values in sorted order (handled by multiset)
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(col);   // add all nodes that come in current 'col'
        }

        return ans;
    }
};

int main() {
//         3
//        / \
//       9   20
//          /  \
//         15   7 
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.verticalTraversal(root);
    for(auto row: ans) {
        for(auto i: row) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
