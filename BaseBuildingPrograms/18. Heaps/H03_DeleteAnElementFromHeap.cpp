// Heaps are implemented using arrays, but visualized using tree concept.
// Lets create a max heap for {10, 50, 60, 30, 20, 40}.
// Deleteion is performed always on root node. Then the elements are heapified to form a heap.
// Algorithm:
// 1. Replace the last element of heap with the root element of heap.
// 2. Delete the last element(where root element is currently present).
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

        void insert(int val) {
            if(size == capacity) {
                cout << "Heap OverFlow" << endl;
                return;
            }
            size++;
            int index = size;
            arr[index] = val;
            while(index > 1) {
                int parentIndex = index / 2;
                if(arr[index] > arr[parentIndex]) {
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else {
                    break;
                }
            }
        }

        void printHeap() {
            for(int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // T.C: O(h);   where h = logN
        // S.C: O(1)
        void deleteElementFromHeap() {
            // Step 1: Replace last element with root node
            arr[1] = arr[size];

            // Step 2: Delete the last element. By doing 'size--', we just reduced the size of element. So eventully,
            // the last element of array is out of scope now; hence it can be considered as deleted.
            size--;

            // Step 3: Heapify
            // Heapify the elements starting from the root
            int index = 1;
            while(true) {
                // Calculate indices of left and right children of the current element
                int leftChildIndex = 2 * index;
                int rightChildIndex = 2 * index + 1;

                int largestElementIndex = index;   // Initialize largest element index as the current element's index

                // Update largest element index to the left child if it's larger
                if (leftChildIndex <= size && arr[leftChildIndex] > arr[largestElementIndex]) {
                    largestElementIndex = leftChildIndex;
                }

                // Update largest element index to the right child if it's larger
                if (rightChildIndex <= size && arr[rightChildIndex] > arr[largestElementIndex]) {
                    largestElementIndex = rightChildIndex;
                }

                // After the above two conditions, if the largest element's index is still on the
                // current element's index, we're done with heapifying. Thus, break the loop.
                if (largestElementIndex == index) {
                    break;
                } else {   // Else if the current element is not the largest element, swap them.
                    swap(arr[index], arr[largestElementIndex]);
                    index = largestElementIndex;   // Update the current index to the position where
                                                  // the larger child was swapped to continue heapification.
                }
            }
        }
};


int main() {
    // Lets create a max heap for {10, 50, 60, 30, 20, 40}
    // The heap for above array will look like this:
    //      _ 60 _ 
    //     /      \
    //    30      50
    //   /  \     /
    //  10  20   40
    
    Heap h(20);   // creating a heap of capacity 20 elements
    h.insert(10);
    h.insert(50);
    h.insert(60);
    h.insert(30);
    h.insert(20);
    h.insert(40);

    // Printing elements of heap
    h.printHeap();   // 60 30 50 10 20 40
    h.deleteElementFromHeap();
    h.printHeap();   // 50 30 40 10 20

    return 0;
}
