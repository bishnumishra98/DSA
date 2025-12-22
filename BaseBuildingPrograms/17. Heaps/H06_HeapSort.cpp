// Heap sort is a comparison-based sorting algorithm that can be performed on any array, not just heaps. The
// algorithm works by first building a heap (either max-heap or min-heap) from the given array and then repeatedly
// extracting the maximum (or minimum) element from the heap and placing it at the end of the array.

// Summary of Heap Sort Variants:
// | Heap Type              | Sorted Order | In-Place |
// | ---------------------- | ------------ | -------- |
// | Max Heap               | Ascending    | ✅       |
// | Min Heap               | Descending   | ✅       |
// | Min Heap + extra array | Ascending    | ❌       |


#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Heapify subtree rooted at index (MAX HEAP)
void heapify(vector<int>& arr, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;

    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Max Heap
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from last non-leaf node
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap Sort
// T.C: O(nlogn);   where n = no.of elements in heap
// S.C: O(logn)   recursive stack
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max Heap
    buildMaxHeap(arr);

    // Step 2: Extract elements one by one
    for(int i = n - 1; i > 0; i--) {
        // Move current root to end so that the largest element is at the end of the array
        swap(arr[0], arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {30, 20, 10, 40, 60, 50};

    cout << "Original array: ";
    printArray(arr);   // o/p: 30 20 10 40 60 50

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);   // o/p: 10 20 30 40 50 60

    return 0;
}
