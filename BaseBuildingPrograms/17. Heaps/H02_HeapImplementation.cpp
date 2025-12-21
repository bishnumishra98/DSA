// Heaps are implemented using arrays, but visualized using tree concept.

// Lets create a max heap for {20, 50, 60, 30, 10, 40}

// Step 1:
// 20

// Step 2:
//   50
//  /
// 20

// Step 3:
//   60
//  /  \
// 20  50

// Step 4:
//     60
//    /  \
//   30  50
//  /
// 20

// Step 5:
//     60
//    /  \
//   30  50
//  /  \
// 20  10

// Step 6:
//     _ 60 _
//    /      \
//   30      50
//  /  \    /
// 20  10  40



#include <iostream>
using namespace std;

// Definition of heap
class Heap {
public:
    int *arr;
    int capacity;
    int size;

    // Constructor
    Heap(int capacity = 10) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor
    ~Heap() {
        delete[] arr;
    }

    // Insert into max heap (0-based indexing)
    // T.C: O(h);   where h = logn
    // S.C: O(1)
    void insert(int val) {
        if(size == capacity) {
            cout << "Heap Overflow" << endl;
            return;
        }

        // Step 1: Insert at end (0-based)
        int index = size;
        arr[index] = val;
        size++;

        // Step 2: Heapify up
        while(index > 0) {
            int parentIndex = (index - 1) / 2;   // 0-based parent formula

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
};

int main() {
    // Creating max heap for {20, 50, 60, 30, 10, 40}
    Heap h(20);

    h.insert(20);
    h.insert(50);
    h.insert(60);
    h.insert(30);
    h.insert(10);
    h.insert(40);

    h.printHeap();
    // Expected output (array form):
    // 60 30 50 20 10 40

    return 0;
}


// An easier version of implementation is present, using vectors:

// class Heap {
// public:
//     vector<int> arr;   // 0-based heap

//     // Insert into max heap
//     void insert(int val) {
//         arr.push_back(val);
//         int index = arr.size() - 1;

//         // Heapify up
//         while (index > 0) {
//             int parent = (index - 1) / 2;
//             if (arr[index] > arr[parent]) {
//                 swap(arr[index], arr[parent]);
//                 index = parent;
//             } else {
//                 break;
//             }
//         }
//     }

//     void printHeap() {
//         for (int x : arr) cout << x << " ";
//         cout << endl;
//     }
// };
