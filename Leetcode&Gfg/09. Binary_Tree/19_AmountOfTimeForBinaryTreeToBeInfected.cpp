// Leetcode: 2385. Amount of Time for Binary Tree to Be Infected   --->   You are given the root of a binary tree
// with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
// Each minute, a node becomes infected if:
// ● The node is currently uninfected.
// ● The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

// Example 1:
//     _ 1 _
//    /     \
//   5       3
//    \     / \
//     4   10  6
//    / \
//   9   2
// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.

// Example 2:
//   1
// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return 0.

// Algorithm: It is simple. From any node, the infection can spread in 3 directions: left child, right child, and parent.
//            We can traverse to left and right child easily using the tree structure. But to traverse to parent, we do not
//            have a direct link. So, we will first create a mapping of each node to its parent using BFS
//            (level order traversal). This map will help us to traverse to parent node easily.
//            After that, we will do another BFS from the target node (start node) to calculate the time taken to infect
//            all nodes.

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
private:
    // Map each node to its parent and return the start node. This can be done using BFS (level order traversal).
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mp, int start) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* target = NULL;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val == start) target = curr;   // if start node is found, store it

            if(curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return target;
    }

    // BFS from target node to calculate max distance (time)
    int timeToInfectAllNodes(map<TreeNode*, TreeNode*>& mp, TreeNode* target) {
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool spread = false;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // From every node, the infection can spread in 3 directions: left child, right child, and parent.

                // Left child
                if(curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    spread = true;
                }

                // Right child
                if(curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    spread = true;
                }

                // Parent
                if(mp.find(curr) != mp.end() && !visited[mp[curr]]) {
                    visited[mp[curr]] = true;
                    q.push(mp[curr]);
                    spread = true;
                }
            }

            if(spread) time++;
        }

        return time;
    }

public:
    // T.C: O(n);  where n = number of nodes in the binary tree
    // S.C: O(n)
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;   // {node -> parent}
        TreeNode* target = bfsToMapParents(root, mp, start);
        int time = timeToInfectAllNodes(mp, target);
        return time;
    }
};


int main() {
//     _ 1 _
//    /     \
//   5       3
//    \     / \
//     4   10  6
//    / \
//   9   2
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    int start = 3;
    cout << Solution().amountOfTime(root, start);

    return 0;
}
