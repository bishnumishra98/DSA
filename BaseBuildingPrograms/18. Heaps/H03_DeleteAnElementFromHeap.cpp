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

        // T.C:
        // S.C: 
        void deleteElementFromHeap() {
            
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
