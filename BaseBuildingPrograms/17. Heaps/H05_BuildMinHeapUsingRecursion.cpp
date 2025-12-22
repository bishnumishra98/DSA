#include <iostream>
#include <vector>
using namespace std;

void printHeap(const vector<int>& heap) {
    for(int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

// Heapify subtree rooted at index (MIN HEAP)
void heapify(vector<int>& heap, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && heap[left] < heap[smallest]) smallest = left;

    if(right < n && heap[right] < heap[smallest]) smallest = right;

    if(smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Build Min Heap
// T.C: O(N);   where N = no.of elements in heap
// S.C: O(log N)   recursive stack
void buildMinHeap(vector<int>& heap) {
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

    buildMinHeap(heap);

    cout << "After Heapify (Min Heap): ";
    printHeap(heap);   // o/p: 10 20 30 40 60 50

    return 0;
}
