// --------------------------------------------------------------------------------------------------
// ------------------------------------------- TREE -------------------------------------------------
// In data structures, a tree is a hierarchical, non-linear data structure with a set of connected
// nodes. It is widely used for organizing and representing hierarchical relationships between
// elements. A tree consists of nodes connected by edges, where each node contains data and may have
// zero or more child nodes.

// --------------------------------------------------------------------------------------------------
// ---------------------------------------- K-ARY Tree ----------------------------------------------
// A tree in which every internal node has a degree of at most k. In a k-ary tree, each internal node
// can have either 0, 1, 2, ..., k children.

// --------------------------------------------------------------------------------------------------
// ---------------------------------------- UNARY TREE ----------------------------------------------
// A tree k-ary tree with k = 1 is called a Unary Tree. In unary tree, every internal node has a
// degree of 1. In other words, each internal node has exactly one child.

// --------------------------------------------------------------------------------------------------
// ---------------------------------------- BINARY TREE ---------------------------------------------
// A tree k-ary tree with k = 2 is called a binary Tree. In binary tree, every internal node has
// a degree of at most 2, i.e., a binary tree can have atmost 2 children from a node.

// --------------------------------------------------------------------------------------------------
// ---------------------------------------- TERNARY TREE --------------------------------------------
// A tree k-ary tree with k = 2 is called a ternary Tree. In ternary tree, every internal node has
// a degree of at most 3, i.e., a binary tree can have atmost 2 children from a node.

// --------------------------------------------------------------------------------------------------
// ------------------------------------ BINARY TREE IN DETAIL ---------------------------------------

// In data structures, a binary tree is a hierarchical data structure composed of nodes.
// Each node in a binary tree has at most two children, which are referred to as the left child and the
// right child. The topmost node in a binary tree is called the root, and nodes with no children are
// called leaves. Binary trees are widely used in computer science for various applications, including
// searching, sorting, and hierarchical representation of data.

// Here are some important terminologies associated with binary trees:

// -> Node: The fundamental building block of a binary tree. Each node contains a data element and
//          may have references (links or pointers) to its left and right children.

// -> Root: The topmost node in a binary tree, serving as the starting point for traversing the tree.

// -> Parent: A node in a binary tree that has one or more child nodes. For example, the root is the
//            parent of its left and right children.

// -> Child: Nodes directly connected to another node. A node in a binary tree may have at most two
//           children: a left child and a right child.

// -> Leaf: Nodes in a binary tree that have no children (i.e., both the left and right child
//          pointers are null).

// -> Subtree: A tree formed by a node and all its descendants, including the node itself.

// -> Depth (Level): The level or depth of a node in a binary tree is the number of edges on the
//                   path from the root to that node. The root is at level 0.

// -> Height (Depth): The height of a binary tree is the maximum depth of any node in the tree.
//                    It is the length of the longest path from the root to a leaf. The height of an
//                    empty tree is -1, while height of a tree with a single node (root only) is 0.

// -> Degree Of Nodes: The number of children a node has.

// -> Balanced Binary Tree: A binary tree is considered balanced if, for every node, the height
//                          difference between its left and right subtrees is at most 1.

// -> Full Binary Tree: A binary tree in which every node has either 0 or 2 children. No node has
//                      only 1 child.

// -> Complete Binary Tree: A binary tree in which all levels, except possibly the last, are
//                          completely filled, and all nodes are as left as possible.

// -> Strictly Binary Tree: A strictly binary tree is a type of binary tree in which each non-leaf
//                          node has exactly two children. In other words, every internal (non-leaf)
//                          node in a strictly binary tree has a left child and a right child, and
//                          no internal node has fewer or more than two children.
//                          The degree of nodes of all internal nodes for a Strictly Binary Tree is 2.
//                          It is also known as 'Extended 2-Tree' or 'Simple 2-Tree'.

// -> Binary Search Tree (BST): A binary tree with the property that the value of each node in the
//                              tree is greater than or equal to all values in its left subtree and
//                              less than or equal to all values in its right subtree.


#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        int* left;
        int* right;
};

int main() {

    return 0;
}
