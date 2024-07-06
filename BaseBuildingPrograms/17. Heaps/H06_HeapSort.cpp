// Heap sort is a comparison-based sorting algorithm that can be performed on any array, not just heaps. The
// algorithm works by first building a heap (either max-heap or min-heap) from the given array and then repeatedly
// extracting the maximum (or minimum) element from the heap and placing it at the end of the array.

// Detailed Steps:
// 1. Build Max-Heap:
//    -> Starting from the last non-leaf node, call heapify on each node to ensure the max-heap property is maintained.
// 2. Extract Elements:
//    -> Swap the root of the max-heap (the largest element) with the last element of the heap.
//    -> Reduce the heap size by one.
//    -> Call heapify on the root to maintain the max-heap property.
//    -> Repeat until the heap size is reduced to 1.

#include <iostream>
using namespace std;

void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Recursive method to heapify elements for 0-based index
void heapify(int *arr, int n, int index) {
    int largestIndex = index;
    int leftIndex = 2 * index + 1; // Left child index
    int rightIndex = 2 * index + 2; // Right child index

    // Check if left child exists and is greater than root
    if(leftIndex < n && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;

    // Check if right child exists and is greater than largest so far
    if(rightIndex < n && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;

    // Change root, if needed
    if(largestIndex != index) {
        swap(arr[index], arr[largestIndex]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largestIndex);
    }
}

// Function to build a max heap
void buildMaxHeap(int *arr, int n) {
    // Start from the last internal node all the way up to the root node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// T.C: O(n) + O(nlogn) = O(nlogn)
// S.C: O(h);   where h = logn
void heapSort(int *arr, int n) {
    // Build the max heap
    buildMaxHeap(arr, n);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
