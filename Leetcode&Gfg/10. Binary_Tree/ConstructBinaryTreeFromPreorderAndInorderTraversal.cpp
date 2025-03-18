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
    // Brute force(T.C: O(n)) method to search an element from preorder array in inorder array. Each time
    // an element is to be found, we will consume O(n) time. Thus, its better not to use this function.
    int searchPositionInInorderArray(vector<int>& inorder, int size, int element) {
        for(int i=0; i<size; i++) {
            if(element == inorder[i]) return i;
        }
        return -1;
    }

    // Optimized method to search an element from preorder array in inorder array.
    // Creation of 'inorderMap' takes O(n) time, but once its done, the index of an element
    // in inorder vector can be retrieved in O(1) time using 'inorderMap'.
    void createMapping(vector<int>& inorder, int size, map<int, int>& inorderMap) {
        for(int i=0; i<size; i++) {
            inorderMap[inorder[i]] = i;   // creating a mapping of 'element -> index'.
        }
    }

    // IMPORTANT NOTE: Its mandatory to pass preorderIndex as reference, as we want to build subtree for
    //                 every element of preorder vector. To do so, a new element(next element) of
    //                 preorder vector must be traversed each time the solve() function is called.
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preorderIndex, int inorderStart, int inorderEnd, int size, map<int, int>& inorderMap) {
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

        // Find the position of 'element' in inorder array. This searching is happening in O(n) which can be reduced to O(1) using map.
        // int position = searchPositionInInorderArray(inorder, size, element);
        // Optimized searching using map
        int position = inorderMap[element];

        // Once we know position of 'element' in the inorder array, construct rest of the tree recursively.
        // All elements on left of this element in the inorder array represents left subtree, while
        // all elements on right of this element in the inorder array represents right subtree.
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, position-1, size, inorderMap);
        root->right = solve(preorder, inorder, preorderIndex, position+1, inorderEnd, size, inorderMap);

        return root;
    }

    // T.C: O(n);   where n = no.of elements in preorder or inorder vector
    // S.C: O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();

        // If you are not using map for searching, no need to write next two lines, neither need to pass 'inorderMap' in solve().
        map <int, int> inorderMap;
        createMapping(inorder, size, inorderMap);
        
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        TreeNode* root = solve(preorder, inorder, preorderIndex, inorderStart, inorderEnd, size, inorderMap);
        return root;
    }
};

int main() {
    Solution sol;
    //       3 
    //     /   \
    //    9     20
    //         /  \
    //        15   7
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
