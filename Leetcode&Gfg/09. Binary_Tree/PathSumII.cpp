// Leetcode: 112. Path Sum   --->   Given the root of a binary tree and an integer targetSum, return all
// root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be
// returned as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

// Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: []

// Example 3:
// Input: root = [1,2], targetSum = 0
// Output: []

// Algorithm: Starting from sum=0 at root node, keep a track of cumulative sum on each node and a temp vector where value
//            of each node is getting populated as we are moving down. Once, the leaf node is reached, store that temp vector
//            somewhere probably in an 'ans' vector that we should sent as a reference to solve() function, if sum == targetSum.

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
    void solve(TreeNode* root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> temp) {
        if(root == NULL) return;

        // Keep a track of nodes that we are visiting
        temp.push_back(root->val);
        sum = sum + root->val;
        
        // If leaf node is reached, push pack 'temp' into 'ans' if 'sum == targetSum'
        if(root->left==NULL && root->right==NULL) {
            if(sum == targetSum) ans.push_back(temp);
            return;
        }

        // Recursively check if required path exists in subtrees or not
        solve(root->left, targetSum, sum, ans, temp);
        solve(root->right, targetSum, sum, ans, temp);
    }

    // T.C: O(n)
    // S.C: O(h)
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, sum, ans, temp);
        return ans;
    }
};

void printVector(vector<vector<int>> ans) {
    for(int i=0; i<ans.size(); i++) {
        cout << "[ ";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "] ";
    }
}

int main() {
    Solution sol;
    // [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
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

    vector<vector<int>> ans = sol.pathSum(root, targetSum);

    printVector(ans);

    return 0;
}
