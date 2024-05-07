// Before this problem, have a look at "Leetcode: 105. Construct Binary Tree from Preorder and Inorder Traversal".
// The most important difference here will be that first right subtree will be made, then left one. This is because
// in postorder, we are going to traverse the postorder array from rightmost to leftmost, unlike we did in preorder.
// In preorder(NLR), the leftmost element of preorder array used to represent the root of tree, and we were traversing from
// 0th index to rightside. Thus, 1st index would represent a parent of left subtree. Hence, first left subtree was made.
// But for a postorder(LRN) array of size n, we are traversing from 'n-1'th element to leftside. 'n-1'th element of
// postorder array represents the root of tree, while the 'n-2'th element of postorder array represents a parent of
// right subtree. Thus, first right subtree has to be made in this case.

// Leetcode: 106. Construct Binary Tree from Preorder and Postorder Traversal   --->   Given two integer arrays
// inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder
// traversal of the same tree, construct and return the binary tree.

// Example 1:
//       3 
//     /   \
//    9     20
//         /  \
//        15   7              
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: inorder = [-1], postorder = [-1]
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

    // IMPORTANT NOTE: Its mandatory to pass postorderIndex as reference, as we want to build subtree for
    //                 every element of postorder vector. To do so, a new element(next element leftside) of
    //                 postorder vector must be traversed each time the solve() function is called.
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postorderIndex, int inorderStart, int inorderEnd, int size, map<int, int>& inorderMap) {
        // Base case (CHANGE 2)
        if((postorderIndex < 0) || (inorderStart > inorderEnd)) return NULL;

        // The last element in the postorder array is the root of the tree. Extract this element from postorder array and
        // store it in a variable say 'element'. Then search this element in inorder array. All elements on left of this
        // element in the inorder array represents left subtree, while all elements on right of this element in the
        // inorder array represents right subtree. Once the element is extracted, move on to next index of the postorder array.
        int element = postorder[postorderIndex];   // CHANGE 3
        postorderIndex--;   // CHANGE 4

        // Create a tree from this element
        TreeNode* root = new TreeNode(element);

        // Find the position of 'element' in inorder array. This searching is happening in O(n) which can be reduced to O(1) using map.
        // int position = searchPositionInInorderArray(inorder, size, element);
        // Optimized searching using map
        int position = inorderMap[element];

        // Once we know position of 'element' in the inorder array, construct rest of the tree recursively.
        // All elements on left of this element in the inorder array represents left subtree, while
        // all elements on right of this element in the inorder array represents right subtree.
        // CHANGE 5: Just change the order of left and right subtree recursive calls.
        root->right = solve(inorder, postorder, postorderIndex, position+1, inorderEnd, size, inorderMap);
        root->left = solve(inorder, postorder, postorderIndex, inorderStart, position-1, size, inorderMap);
        
        return root;
    }

    // T.C: O(n);   where n = no.of elements in postorder or inorder vector
    // S.C: O(n)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();

        // If you are not using map for searching, no need to write next two lines, neither need to pass 'inorderMap' in solve().
        map <int, int> inorderMap;
        createMapping(inorder, size, inorderMap);
        
        int postorderIndex = size - 1;   // CHANGE 1
        int inorderStart = 0;
        int inorderEnd = size - 1;
        TreeNode* root = solve(inorder, postorder, postorderIndex, inorderStart, inorderEnd, size, inorderMap);
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

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    
    TreeNode* ans = sol.buildTree(inorder, postorder);

    sol.levelOrderTraversal(ans);

    return 0;
}
