// Leetcode: 105. Construct Binary Tree from Preorder and Inorder Traversal   --->   Given two integer arrays
// preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal
// of the same tree, construct and return the binary tree.

// Example 1:
//       3 
//     /   \
//    9     20
//         /  \
//        15   7              
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]


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
    // Just for printing purpose. Don't include this function in leetcode. 
    void levelOrderTraversal(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL); 

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL) {
                cout << endl;
                if(!q.empty()) q.push(NULL);
            } else {
                cout << front->val << " ";
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
    }

//---------------------------------------------------------------------------------------------

    int searchPositionInInorderArray(vector<int>& inorder, int size, int element) {
        for(int i=0; i<size; i++) {
            if(element == inorder[i]) return i;
        }
        return -1;
    }

    // IMPORTANT NOTE: Its mandatory to pass preorderIndex as reference, as we want to build subtree for
    //                 every element of preorder vector. To do so, a new element(next element) of
    //                 preorder vector must be traversed each time the solve() function is called.
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int inorderStart, int inorderEnd, int size) {
        // Base case
        if((preorderIndex >= size) || (inorderStart > inorderEnd)) return NULL;

        // The first element in the preorder array is the root of the tree. Extract this element from preorder array and
        // store it in a variable say 'element'. Then search this element in inorder array. All elements on left of this
        // element in the inorder array represents left subtree, while all elements on right of this element in the
        // inorder array represents right subtree. Once the element is extracted, move on to next index of the preorder array.
        int element = preorder[preorderIndex];
        preorderIndex++;

        // Create a tree from this element
        TreeNode* root = new TreeNode(element);

        // Find the position of 'element' in inorder array
        int position = searchPositionInInorderArray(inorder, size, element);

        // Once we know position of 'element' in the inorder array, construct rest of the tree recursively.
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, position-1, size);
        root->right = solve(preorder, inorder, preorderIndex, position+1, inorderEnd, size);

        return root;
    }

    // T.C: O(n);   where n = no.of elements in preorder or inorder vector
    // S.C: O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        TreeNode* root = solve(preorder, inorder, preorderIndex, inorderStart, inorderEnd, size);
        return root;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* ans = sol.buildTree(preorder, inorder);

    sol.levelOrderTraversal(ans);

    return 0;
}
