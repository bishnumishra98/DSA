// This problem falls under views pattern of Binary Tree. Follow this sequence:
// 1. "Leetcode&Gfg\09. Binary_Tree\LeftViewOfBinaryTree.cpp"
// 2. "Leetcode&Gfg\09. Binary_Tree\BinaryTreeRightSideView.cpp"
// 3. "Leetcode&Gfg\09. Binary_Tree\TopViewOfBinaryTree.cpp"
// 4. "Leetcode&Gfg\09. Binary_Tree\BottomViewOfBinaryTree.cpp"

// GFG: Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree
// is the set of nodes visible when the tree is viewed from the top.

//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \
//        8
// Its top view will be 4 2 1 3 7

// This problem will require 3 data structures to get solved: vector(to store top view), queue(to push nodes in level order) 
// and map(to keep a track of horizontal distance and its respective top view nodes).

// Algorithm:
// 1. Initialize an empty vector 'topView' to store the top view of the binary tree.
// 2. Initialize an empty queue 'q' to perform level order traversal of the binary tree.
// 3. Initialize an empty map 'hdToNodeMap' to keep track of the horizontal distance and its respective top view nodes.
// 4. Push the root node and its horizontal distance (which is 0) into the queue.
// 5. While the queue is not empty, do the following:
//     - Dequeue a pair from the front of the queue. The pair contains a node and its horizontal distance.
//     - If there is no entry for the horizontal distance in hdToNodeMap, insert a new entry with the horizontal distance
//       as the key and the node's data as the value.
//     - If the left child of the node exists, enqueue the left child along with its horizontal distance (hd - 1).
//     - If the right child of the node exists, enqueue the right child along with its horizontal distance (hd + 1).
//     - Pop out the front element from the queue.
// 6. Traverse 'hdToNodeMap' and push the values of 'hdToNodeMap' into the 'topView' vector.
// 7. Return the 'topView' vector.

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> topView(Node *root)
    {   
        vector <int> topView;
        queue < pair<Node*, int> > q;
        map <int, int> hdToNodeMap;

        // pushing the first element in queue
        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair <Node*, int> temp = q.front();
            Node* node = temp.first;
            int hd = temp.second;

            // if no entry exists for hd in 'hdToNodemap', then push the entry 'hd : node->data' in 'hdToNodemap' map.
            if(hdToNodeMap.find(hd) == hdToNodeMap.end()) {
                hdToNodeMap[hd] = node->data;
            }

            // pushing the node's children(if exists) in queue
            if(node->left) q.push(make_pair(node->left, hd-1));
            if(node->right) q.push(make_pair(node->right, hd+1));

            // popping the queue
            q.pop();
        }

        // pushing the top view in 'topView' vector, and returning it
        for(auto i: hdToNodeMap) {
            topView.push_back(i.second);
        }
        return topView;
    }
};

int main() {
//          1 
//         / \
//        2   3
//       / \ / \
//      4  5 6  7
//       \
//        8
// Its top view will be 4 2 1 3 7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);

    Solution sol;
    vector<int> ans = sol.topView(root);
    for(int i: ans) {
        cout << i << " ";
    }

    return 0;
}
