// Heaps are implemented using arrays, but visualized using tree concept.
// Lets create a max heap for {10, 50, 60, 30, 20, 40}.
// Deleteion is performed always on root node. Then the elements are heapified to form a heap.
// Algorithm:
// 1. Replace the last element of heap with the root element of heap.
// 2. Delete the last element (where root element is currently present).
// 3. Heapify the elements.

#include <iostream>
using namespace std;

// Definition of heap
class Heap {
public:
    int *arr;
    int capacity;
    int size;

    Heap() : capacity(10), arr(new int[10]), size(0) {}
    Heap(int capacity) : arr(new int[capacity]), capacity(capacity), size(0) {}
    ~Heap() { delete[] arr; }

    // Insert into max heap (0-based indexing)
    void insert(int val) {
        if(size == capacity) {
            cout << "Heap OverFlow" << endl;
            return;
        }

        // Step 1: Insert at end
        int index = size;
        arr[index] = val;
        size++;

        // Step 2: Heapify up
        while(index > 0) {
            int parentIndex = (index - 1) / 2;
            if(arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void printHeap() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete root element (max heap)
    // T.C: O(log N)
    // S.C: O(1)
    void deleteElementFromHeap() {
        if(size == 0) return;

        // Step 1: Replace root with last element
        arr[0] = arr[size - 1];

        // Step 2: Remove last element
        size--;

        // Step 3: Heapify down from root
        int index = 0;
        while(true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;

            int largestElementIndex = index;

            if(leftChildIndex < size &&
                arr[leftChildIndex] > arr[largestElementIndex]) {
                largestElementIndex = leftChildIndex;
            }

            if(rightChildIndex < size &&
                arr[rightChildIndex] > arr[largestElementIndex]) {
                largestElementIndex = rightChildIndex;
            }

            if(largestElementIndex == index) {
                break;
            } else {
                swap(arr[index], arr[largestElementIndex]);
                index = largestElementIndex;
            }
        }
    }
};

int main() {
    // Lets create a max heap for {10, 50, 60, 30, 20, 40}
    // Final heap:
    //        60
    //       /  \
    //     30    50
    //    /  \   /
    //  10  20 40

    Heap h(20);

    h.insert(10);
    h.insert(50);
    h.insert(60);
    h.insert(30);
    h.insert(20);
    h.insert(40);

    h.printHeap();   // 60 30 50 10 20 40

    h.deleteElementFromHeap();
    h.printHeap();   // 50 30 40 10 20

    return 0;
}
