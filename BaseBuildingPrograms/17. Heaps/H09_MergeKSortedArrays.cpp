// If we were to merge two or three sorted arrays, we could have used two-pointer or three-pointer approach.
// But if no.of sorted arrays are many, this approach is not feasible. Thus, we will use concept of min-heap.

// Bruteforce Agorithm: It is a cakewalk. Just insert all elements of all arrays into a single array, sort it and return.

// Algorithm: It is simple.
// 1. Create a min-heap to store the first element of each sorted array along with the array index and element index,
//    i.e., (value, rowIndex, colIndex). The min-heap will help us efficiently get the smallest element among the arrays.
//    The min-heap decides the smallest element based on the value.
// 2. While the min-heap is not empty:
//    i.   Extract the minimum element from the heap (the root of the heap).
//    ii.  Add this element to the result array.
//    iii. If there is a next element in the same array from which the minimum element was extracted, insert that next
//         element into the min-heap.
// 3. Repeat step 2 until all elements from all arrays have been processed. And finally, the result array will contain
//    all elements from the k sorted arrays in sorted order.


// ● Guide for good practice of writing a Custom comparator:
//
//   ● What do you understand with the term STL comparator ?
//     STL comparator is a function-like object that has no internal data and only compares two read-only values
//     without changing anything.
//
//   Comparator must be:
//      ▪ Read-only on elements
//      ▪ Read-only on itself
//      So STL should be: const elements + const comparator
//   A simple analogy to understand this is:-
//      Think of comparator as a judge:
//      ▪ Judge cannot change the contestants
//      ▪ Judge cannot change himself while judging
//   That's why we use 'const' for both elements and comparator.
//
//   ● Final Rule: All STL comparators should be stateless and declared as const call operators with const parameters.
//     ▪ Stateless means comparator has no internal data and does not change behavior between calls.


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Custom comparator for min-heap
struct Compare {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
        return get<0>(a) > get<0>(b);   // min-heap
    }
};


// T.C: O(N log k);   where N is total no.of elements and k is no.of arrays
// S.C: O(k)   for min-heap storing k elements at max
vector<int> mergeKSortedArrays(vector<vector<int>>& arr) {
    // Min-heap storing (value, rowIndex, colIndex)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;

    // Push first element of each array
    for(int i = 0; i < arr.size(); i++) {
        if(!arr[i].empty()) {
            minHeap.push({arr[i][0], i, 0});
        }
    }

    vector<int> result;

    while(!minHeap.empty()) {
        auto it = minHeap.top();
        minHeap.pop();

        int value = get<0>(it);
        int row = get<1>(it);
        int col = get<2>(it);

        result.push_back(value);

        // Push next element from the same array (if exists)
        if(col + 1 < arr[row].size()) {
            minHeap.push({arr[row][col + 1], row, col + 1});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arr = {
        {5, 10, 15, 20},
        {3, 6},
        {2, 4, 6, 8}
    };

    vector<int> ans = mergeKSortedArrays(arr);

    for(int x : ans) {
        cout << x << " ";   // o/p: 2 3 4 5 6 6 8 10 15 20
    }

    return 0;
}
