// Circular Queue is a linear data structure in which the operations are performed based on
// FIFO (First In First Out) principle and the last position is connected back to the first
// position to make a circle. It is also called ‘Ring Buffer’.

#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
public:
    vector<int> arr;
    int size;
    int front;
    int rear;
    
    // Constructor
    CircularQueue(int size) {
        arr.resize(size, -1);   // resize arr to 'size' and initialize all elements to -1
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int data) {
        // If rear pointer is just behind the front pointer, queue is full
        if((rear + 1) % size == front) {
            cout << "Queue overflow.";
            return;
        } else {
            // If queue is not full
            rear = (rear + 1) % size;
            arr[rear] = data;

            // Make sure to bring front pointer to 0th index of array,
            // when a push operation happened on queue for the 1st time.
            if(front == -1) {
                front = 0;
            }
        }
    }

    void pop() {
        // If queue is empty
        if(front == -1) {
            cout << "Queue underflow.";
            return;
        } else if(front == rear) {
            // Only 1 element is remaining in queue, popping 1 more element will make queue empty
            arr[front] = -1;
            front = rear = -1;
        } else {
            // If queue is not empty
            arr[front] = -1;
            front = (front + 1) % size;
        }
    }

    int getSize() {
        if(front == -1) return 0;
        return ((rear - front + size) % size) + 1;   // correct modulo arithmetic for circular wrap-around
    }

    bool isEmpty() {
        if(front == -1) return true;
        else return false;
    }

    int getFront() {
        if(front == -1) {
            cout << "No front element present.";
            return -1;
        } else {
            return arr[front];
        }
    }

    int getRear() {
        if(front == -1) {
            cout << "No rear element present.";
            return -1;
        } else {
            return arr[rear];
        }
    }

    void printQueue() {
        if(front == -1) {
            cout << "Queue: (empty)" << endl;
            return;
        }

        cout << "Queue: ";
        int count = getSize();

        for(int i = 0; i < count; i++) {
            int idx = (front + i) % size;   // move circularly
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};


int main() {
    CircularQueue q(5);
    q.printQueue();   // o/p: (empty)
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Pushing 10, 20, 30 in queue.\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.printQueue();   // o/p: 10 20 30
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 3
    cout << "Front element: " << q.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Popping 3 elements from queue.\n";
    q.pop(); q.pop(); q.pop();
    q.printQueue();   // o/p: (empty)
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Pushing 10, 20, 30, 40, 50 in queue.\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.printQueue();   // o/p: 10 20 30 40 50
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 5
    cout << "Front element: " << q.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 50
    cout << endl;

    cout << "Pushing 60 in queue.\n";
    q.push(60);   // o/p: Queue overflow.
    cout << endl;

    cout << "Popping 2 element from queue.\n";
    q.pop(); q.pop();
    q.printQueue();   // o/p: 30 40 50
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 3
    cout << "Front element: " << q.getFront() << endl;   // o/p: 30
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 50
    cout << endl;

    cout << "Pushing 60, 70 in queue.\n";
    q.push(60);
    q.push(70);
    q.printQueue();   // o/p: 30 40 50 60 70
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 5
    cout << "Front element: " << q.getFront() << endl;   // o/p: 30
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 70
    cout << endl;

    cout << "Popping 5 elements from queue.\n";
    q.pop(); q.pop(); q.pop(); q.pop(); q.pop();
    q.printQueue();   // o/p: (empty)
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Popping 1 element from queue.\n";
    q.pop();   // o/p: Queue underflow.
    cout << endl;

    cout << "Pushing 10, 20, 30 in queue.\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.printQueue();   // o/p: 10 20 30
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 3
    cout << "Front element: " << q.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 30
    cout << endl;

    return 0;
}
