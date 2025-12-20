// ● What is Heap ?
//
//   A Heap is a specialized tree-based data structure that satisfies two important properties:
//
//   1. Heap Property: There are two types of heaps:
//      i.  Max Heap:
//          ▪ Parent ≥ Children
//          ▪ The maximum element is always at the root.
//          ▪ Example:-
//                    50
//                   /  \
//                 30    40
//                /  \
//              10   20
//
//      ii. Min Heap:
//          ▪ Parent ≤ Children
//          ▪ The minimum element is always at the root.
//          ▪ Example:-
//                    10
//                   /  \
//                 20    30
//                /  \
//              40   50
//
//   2. Complete Binary Tree: A heap is always a complete binary tree:
//                            ▪ All levels are fully filled, except possibly the last.
//                            ▪ The last level is filled from left to right.


// ● Array Representation of Heap
//   If heap is stored in an array (0-indexed):
//   ▪ Parent index = (i - 1) / 2
//   ▪ Left child = 2i + 1
//   ▪ Right child = 2i + 2
//
//     Array    : [10, 20, 30, 40, 50]
//     Index (i):   0   1   2   3   4
//
//     Tree:
//             10
//            /  \
//          20    30
//         /  \
//       40   50


// ● Time Complexity
//     Operation     | Time    
//   --------------- | --------
//   ▪ Insert        | O(log n)
//   ▪ Delete (root) | O(log n)
//   ▪ Get Min / Max | O(1)    
//   ▪ Build Heap    | O(n)    
