// This problem falls under views pattern of Binary Tree. Follow this sequence:
// 1. "Leetcode&Gfg\09. Binary_Tree\LeftViewOfBinaryTree.cpp"
// 2. "Leetcode&Gfg\09. Binary_Tree\BinaryTreeRightSideView.cpp"
// 3. "Leetcode&Gfg\09. Binary_Tree\TopViewOfBinaryTree.cpp"
// 4. "Leetcode&Gfg\09. Binary_Tree\BottomViewOfBinaryTree.cpp"

// GFG: Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

// This problem has exactly same logic and code as that of "Leetcode&Gfg\09. Binary_Tree\TopViewOfBinaryTree.cpp",
// the only difference here is that we don't need to use the condition: "if(hdToNodeMap.find(hd) == hdToNodeMap.end())".
// This is because we want to overwrite the entry of hd in 'hdToNodeMap', i.e., overwrite the values(node->data) for
// keys(horizontal distance) so that we reach to deeper levels, i.e., till the leaf nodes of the binary tree. As a
// result, the deepest nodes could be stored for each horizontal distance in the 'hdToNodeMap'.

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> bottomView(Node *root) {
        vector <int> bottomView;
        queue < pair<Node*, int> > q;
        map <int, int> hdToNodeMap;

        // pushing the first element in queue
        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair <Node*, int> temp = q.front();
            Node* node = temp.first;
            int hd = temp.second;

            // ONLY CHANGE
            // overwrite the values(node->data) for keys(horizontal distance), so that we could go deeper till leaf nodes
            hdToNodeMap[hd] = node->data;

            // pushing the node's children(if exists) in queue
            if(node->left) q.push(make_pair(node->left, hd-1));
            if(node->right) q.push(make_pair(node->right, hd+1));

            // popping the queue
            q.pop();
        }

        // pushing the top view in 'bottomView' vector, and returning it
        for(auto i: hdToNodeMap) {
            bottomView.push_back(i.second);
        }
        return bottomView;
    }
};

int main() {
//          1 
//         / \
//        2   3
//       / \
//      4   5
//       \
//        6
// Its bottom view will be 4 6 5 3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.bottomView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
