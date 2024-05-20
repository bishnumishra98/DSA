// Heaps are implemented using arrays, but visualized using tree concept.
// Lets create a max heap for {10, 50, 60, 30, 20, 40}

#include <iostream>
using namespace std;

// Definition of heap
class Heap {
    public:
        int *arr;
        int capacity;
        int size;

        // Default constructor
        Heap() {
            this->capacity = 10;  // default capacity any be any of our choice, we gave it 10 by default.
            this->arr = new int[capacity];
            this->size = 0;  // size is number of elements in heap, i.e., it should be 0 by default
        }

        // Parameterized constructor
        Heap(int capacity) {
            this->arr = new int[capacity];
            this->capacity = capacity;
            this->size = 0;   // size is number of elements in heap, i.e., it should be 0 by default
        }

        // Destructor to free the allocated memory
        ~Heap() {
            delete[] arr;
        }

        // Method to insert a new value in heap
        void insert(int val) {
            // If size of heap already is equal to its capacity, no more elements can be inserted
            if(size == capacity) {
                cout << "Heap OverFlow" << endl;
                return;
            }

            // Indexing in our heap starts from 1. So first element will be inserted at arr[1], and so on.
            size++;
            int index = size;
            arr[index] = val;

            // Take the val to its correct position
            while(index > 1) {   // 'index > 1' because we need to heapify up until the root element. 
                                // The root element (at index 1) cannot be further heapified as it has no parent.
                int parentIndex = index / 2;   // Refer 'H01_MaxHeapParentChildRelation.png' for this formula
                if(arr[index] > arr[parentIndex]) {   // If current value is greater than its parent
                    swap(arr[index], arr[parentIndex]);   // Swap the current element with its parent
                    index = parentIndex;   // Update index to the parent's index to continue heapifying up
                }
                else {   // If current value is not greater than its parent
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

    return 0;
}
