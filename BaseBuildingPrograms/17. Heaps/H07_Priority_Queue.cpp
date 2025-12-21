// In C++, the Standard Template Library (STL) provides a convenient way to implement a heap using
// the priority_queue container. The priority_queue by default implements a max-heap, where the
// largest element has the highest priority. If you need a min-heap, you can use a custom comparator.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Creating a max-heap priority queue
    priority_queue<int> maxHeap;

    // Inserting elements
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(40);

    // Displaying the top element
    cout << "Top element (max-heap): " << maxHeap.top() << endl;   // o/p: 50

    // Removing the top element
    maxHeap.pop();

    // Displaying the top element after pop
    cout << "Top element after pop (max-heap): " << maxHeap.top() << endl;   // o/p: 40

    // Checking the size of the priority queue
    cout << "Size of max-heap: " << maxHeap.size() << endl;   // o/p: 4

    // Checking if the priority queue is empty
    if(maxHeap.empty()) {   // o/p: The max-heap is not empty.
        cout << "The max-heap is empty." << endl;
    } else {
        cout << "The max-heap is not empty." << endl;
    }

//----------------------------------------------------------------------------------------

    // Creating a min-heap priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting elements
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(40);

    // Displaying the top element
    cout << "Top element (min-heap): " << minHeap.top() << endl;   // o/p: 10

    // Removing the top element
    minHeap.pop();

    // Displaying the top element after pop
    cout << "Top element after pop (min-heap): " << minHeap.top() << endl;   // o/p: 20

    // Checking the size of the priority queue
    cout << "Size of min-heap: " << minHeap.size() << endl;   // o/p: 4

    // Checking if the priority queue is empty
    if(minHeap.empty()) {   // o/p: The min-heap is not empty.
        cout << "The min-heap is empty." << endl;
    } else {
        cout << "The min-heap is not empty." << endl;
    }

//----------------------------------------------------------------------------------------

    // Creating a maxHeap from an array
    int arr[] = {10, 20, 30};
    int size = 3;
    priority_queue<int> pq_max_fromArray(arr, arr+size);

    // Creating a maxHeap from a vector
    vector<int> v = {10, 20, 30};
    priority_queue<int> pq_max_fromVector(v.begin(), v.end());

//----------------------------------------------------------------------------------------

    return 0;
}
