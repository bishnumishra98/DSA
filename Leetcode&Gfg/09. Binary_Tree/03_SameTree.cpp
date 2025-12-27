// Leetcode: 100. Same Tree   --->   Given the roots of two binary trees p and q, write a function to check if they
// are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
//     1           1
//    / \         / \
//   2   3       2   3
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
//     1    1
//    /      \
//   2        2
// Output: false

// Example 3:
// Input: p = [1,2,1], q = [1,1,2]
//     1           1
//    / \         / \
//   2   1       1   2
// Output: false

// Algorithm: If both trees are same, the tree traversal of both trees would be exactly same. We can do any
//            type of traversal on the trees. For instance, let's move forward with preorder traversal.

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
    // T.C: O(min(m, n));   where m and n are the number of nodes in the two trees
    // S.C: O(min(m, n))   due to the recursion stack in the case of skewed trees
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: If both nodes are NULL, they are the same. Thus return true.
        // If one of them is NULL and the other is not, they are different. Thus return false.
        if(p == NULL || q == NULL) return (p == q);

        // If the values of the current nodes are different, return false.
        // Otherwise, recursively check the left and right subtrees. If both subtrees are the same, return true.
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
//     1           1
//    / \         / \
//   2   3       2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << Solution().isSameTree(root1, root2);   // o/p: 1 (true)

    return 0;
}
