// Leetcode: 98. Validate Binary Tree   --->   Given the root of a binary tree,
// determine if it is a valid binary search tree (BST).

// Example 1:
//     2
//    / \
//   1   3
// Input: root = [2,1,3]
// Output: true

// Example 2:
//     5
//    / \
//   1   4
//      / \
//     3   6
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

#include<bits/stdc++.h>
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
    // Brute force
    void inorderTraversal(TreeNode* root, vector<int> &v) {
        if(!root) return;

        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }

    bool isSorted(vector<int> &v) {
        for(int i=0; i<v.size()-1; i++) {
            if(v[i] >= v[i+1]) return false;
        }
        return true;
    }

    // T.C: O(n)
    // S.C: O(h) + O(n)
    bool isValidBST_bruteForce(TreeNode* root) {
        vector <int> v;
        inorderTraversal(root, v);   // inorder traverse the tree and store its node->val in a vector 'v'

        return isSorted(v);   // if 'v' is sorted, then it is a BST; else not.
    }

// ----------------------------------------------------------------------------------------------

    // More space efficient algorithm
    bool solve(TreeNode* root, long long lowerBound, long long upperBound) {
        if(!root) return true;   // if root is NULL, return true

        bool cond1 = ((root->val > lowerBound) && (root->val < upperBound));   // check if root lies within 'lowerBound' and 'upperBound'
        bool cond2 = solve(root->left, lowerBound, root->val);   // check if left node lies within 'lowerBound' and 'root'
        bool cond3 = solve(root->right, root->val, upperBound);   // check if right node lies within 'root' and 'upperBound'

        return cond1 && cond2 && cond3;   // return true(it is a BST) if all conditions met
    }

    // T.C: O(n)
    // S.C: O(h)
    bool isValidBST(TreeNode* root) {
        long long lowerBound = -2147483657;   // this is 10 less than INT_MIN
        long long upperBound = 2147483657;   // this is 10 greater than INT_MAX

        return solve(root, lowerBound, upperBound);
    }
};

int main() {
//     5
//    / \
//   1   4
//      / \
//     3   6
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    Solution sol;

    cout << sol.isValidBST(root);

    return 0;
}
