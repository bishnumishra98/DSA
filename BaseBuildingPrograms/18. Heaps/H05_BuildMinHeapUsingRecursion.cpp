// Exactly same as 'H04_BuildMaxHeapUsingRecursion.cpp', just there will be a change in if condition of heapify().

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
    int smallestIndex = index;

    if(leftIndex < n && arr[leftIndex] < arr[smallestIndex])
        smallestIndex = leftIndex;

    if(rightIndex < n && arr[rightIndex] < arr[smallestIndex])
        smallestIndex = rightIndex;

    if(smallestIndex != index) {
        swap(arr[index], arr[smallestIndex]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallestIndex);
    }
}

// T.C: O(N)
// S.C: O(h);   where h = logN
void buildMinHeap(int *arr, int n) {
    // Start from the last internal node all the way up to the root node
    for (int i = n/2; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    // Lets create a min heap for {60, 50, 40, 30, 20, 10}
    // The heap for above array will look like this:
    //      _ 10 _ 
    //     /      \
    //    20      30
    //   /  \     /
    //  40  50   60

    int arr[] = {60, 50, 40, 30, 20, 10}; 
    int n = 6;    // Size of the heap (number of elements in the heap)
    printHeap(arr, n);   // Before heapification
    buildMinHeap(arr, n);   // Build the min heap
    printHeap(arr, n);   // After heapification

    return 0;
}
