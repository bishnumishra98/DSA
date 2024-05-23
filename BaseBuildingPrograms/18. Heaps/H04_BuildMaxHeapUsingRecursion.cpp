#include <iostream>
using namespace std;

void printHeap(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Recursive method to heapify elements
// Doing for 0 based index:
void heapify(int *arr, int n, int index) {
    int leftIndex = (2 * index) + 1; // Left child index for 0-based index
    int rightIndex = (2 * index) + 2; // Right child index for 0-based index
    int largestIndex = index;

    if(leftIndex < n && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;

    if(rightIndex < n && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;

    if(largestIndex != index) {
        swap(arr[index], arr[largestIndex]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largestIndex);
    }
}

// T.C: O(N)
// S.C: O(h);   where h = logN
void buildMaxHeap(int *arr, int n) {
    // Start from the last internal node all the way up to the root node.
    for (int i = n/2; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    // Lets create a max heap for {10, 20, 30, 40, 50, 60}
    // The heap for above array will look like this:
    //      _ 60 _ 
    //     /      \
    //    50      30
    //   /  \     /
    //  40  20   10

    int arr[] = {10, 20, 30, 40, 50, 60}; 
    int n = 6;    // Size of the heap (number of elements in the heap)
    printHeap(arr, n);   // Before heapification
    buildMaxHeap(arr, n);   // Build the max heap
    printHeap(arr, n);   // After heapification

    return 0;
}
