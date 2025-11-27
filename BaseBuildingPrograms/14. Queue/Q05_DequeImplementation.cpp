// A circular deque is an extension of the deque with a circular arrangement of elements. In a
// circular deque, the front and rear ends of the deque are connected, forming a loop or circle.
// It supports push_front, push_back, pop_front, pop_back in O(1) using modulo arithmetic.

#include <iostream>
#include <vector>
using namespace std;

class CircularDeque {
public:
    vector<int> arr;
    int size;
    int front;
    int rear;
    
    // Constructor
    CircularDeque(int size) {
        arr.resize(size, -1);   // resize to 'size' and initialize to -1 (empty slots)
        this->size = size;
        front = -1;
        rear = -1;
    }

    // Insert element at rear (back)
    void push_back(int data) {
        // Queue full when next position of rear is front
        if ((rear + 1) % size == front) {
            cout << "Dequeue overflow." << endl;
            return;
        }

        // If deque was empty, set both pointers to 0
        if (front == -1) {
            front = rear = 0;
        } else {
            // Move rear circularly
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
    }

    // Insert element at front
    void push_front(int data) {
        // Queue full when next position of rear is front
        if ((rear + 1) % size == front) {
            cout << "Dequeue overflow." << endl;
            return;
        }

        // If deque was empty, set both pointers to 0
        if (front == -1) {
            front = rear = 0;
        } else {
            // Move front circularly backwards
            front = (front - 1 + size) % size;
        }

        arr[front] = data;
    }

    // Remove element from front
    void pop_front() {
        // If deque is empty
        if (front == -1) {
            cout << "Dequeue underflow." << endl;
            return;
        }

        // Single element -> become empty
        if (front == rear) {
            arr[front] = -1;
            front = rear = -1;
        } else {
            arr[front] = -1;
            front = (front + 1) % size;
        }
    }

    // Remove element from rear
    void pop_back() {
        // If deque is empty
        if (front == -1) {
            cout << "Dequeue underflow." << endl;
            return;
        }

        // Single element -> become empty
        if (front == rear) {
            arr[rear] = -1;
            front = rear = -1;
        } else {
            arr[rear] = -1;
            rear = (rear - 1 + size) % size;
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    int getSize() {
        if (front == -1) return 0;
        return ((rear - front + size) % size) + 1;   // correct modulo arithmetic
    }

    int getFront() {
        if (front == -1) {
            cout << "No front element present." << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (front == -1) {
            cout << "No rear element present." << endl;
            return -1;
        }
        return arr[rear];
    }

    // Print deque elements in order from front -> rear (logical order)
    void printDeque() {
        if (front == -1) {
            cout << "Deque: (empty)" << endl;
            return;
        }

        cout << "Deque: ";
        int count = getSize();
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % size;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }   
};


int main() {
    CircularDeque dq(5);

    dq.printDeque();   // o/p: (empty)
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 0
    cout << "Front element: " << dq.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Pushing 10, 20, 30 at rear:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.printDeque();   // o/p: 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 3
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Pushing 40, 50 at front:\n";
    dq.push_front(40);
    dq.push_front(50);
    dq.printDeque();   // o/p: 50 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 5
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 50
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Pushing 60 (should overflow):\n";
    dq.push_front(60);   // o/p: Dequeue overflow.
    cout << endl;

    cout << "Popping 1 element from front:\n";
    dq.pop_front();
    dq.printDeque();   // o/p: 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 4
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 40
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    dq.printDeque();   // o/p: 40 10 20
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 3
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 40
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 20
    cout << endl;

    cout << "Popping 3 elements from front:\n";
    dq.pop_front(); dq.pop_front(); dq.pop_front();
    dq.printDeque();   // o/p: (empty)
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 0
    cout << "Front element: " << dq.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Popping 1 element from rear (should underflow):\n";
    dq.pop_back();   // o/p: Dequeue underflow.
    cout << endl;

    cout << "Pushing 10 at rear:\n";
    dq.push_back(10);
    dq.printDeque();   // o/p: 10
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 1
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 10
    cout << endl;

    cout << "Pushing 20, 30 at front:\n";
    dq.push_front(20); dq.push_front(30);
    dq.printDeque();   // o/p: 30 20 10
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 3
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 30 
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 10
    cout << endl;

    return 0;
}
