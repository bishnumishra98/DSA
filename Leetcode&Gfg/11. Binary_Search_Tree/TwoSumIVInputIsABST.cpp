// Leetcode: 653. Two Sum IV - Input is a BST   --->   Given the root of a binary search tree and an integer k,
// return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Example 1:
//      5
//     / \
//    3   6
//   / \   \
//  2   4   7
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

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
    void inorderTraversal(TreeNode* root, vector<int> &inorderArray) {
        if(!root) return;

        inorderTraversal(root->left, inorderArray);   // L
        inorderArray.push_back(root->val);   // N
        inorderTraversal(root->right, inorderArray);   // R
    }

    // T.C: O(n)
    // S.C: O(h)
    bool findTarget(TreeNode* root, int k) {
        vector <int> inorderArray;
        inorderTraversal(root, inorderArray);   // got a sorted array in 'inorderArray'

        // Two pointer approach
        int start = 0;
        int end = inorderArray.size() - 1;

        while(start < end) {
            int sum = inorderArray[start] + inorderArray[end];

            if(sum == k) {
                return true;
            } else if(sum < k) {   // if(sum < k), move the 'start' pointer towards right
                start++;
            } else {   // if(sum > k), move the 'end' pointer towards left
                end--;
            }
        }

        return false;   // If sum is not equal to the target 'k', return false
    }
};

int main() {
//      5
//     / \
//    3   6
//   / \   \
//  2   4   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right= new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;
    int target = 2;
    cout << sol.findTarget(root, target);
}
