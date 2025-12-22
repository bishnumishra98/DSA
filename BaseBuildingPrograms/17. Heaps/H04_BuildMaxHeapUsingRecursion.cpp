#include <iostream>
#include <vector>
using namespace std;

void printHeap(vector<int>& heap) {
    for(int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

// Heapify subtree rooted at index (MAX HEAP)
void heapify(vector<int>& heap, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && heap[left] > heap[largest])
        largest = left;

    if(right < n && heap[right] > heap[largest])
        largest = right;

    if(largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Build Max Heap
// T.C: O(N);   where N = no.of elements in heap
// S.C: O(log N)   recursive stack
void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();

    // Start from last non-leaf node
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

int main() {
    vector<int> heap = {30, 20, 10, 40, 60, 50};

    cout << "Before Heapify: ";
    printHeap(heap);   // o/p: 30 20 10 40 60 50

    buildMaxHeap(heap);

    cout << "After Heapify (Max Heap): ";
    printHeap(heap);   // o/p: 60 40 50 30 20 10

    return 0;
}
