// We will make our implementation of queue using arrays and OOPs concept

#include <iostream>
#include <cstring>   // for memset()
using namespace std;
// Note: In a queue, push happens from -> rear, and pop happens from -> front

class Queue {
public:
    int* arr;
    int size;
    int front;
    int rear;
    
    // Constructor
    Queue(int size) {
        arr = new int[size];
        memset(arr, 0, size * sizeof(int));   // initializes all elements of arr with 0s.
        this->size = size;
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    void push(int data) {
        // If rear pointer reached last index of array, no more elements can be pushed
        if(rear == size-1) {
            cout << "Queue overflow." << endl;
            return;
        } else {
            // If rear pointer did not reached last index of array
            rear++;
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
        if(front == -1 || front > rear) {
            cout << "Queue underflow." << endl;
            return;
        } else {
            // If queue is not empty
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty() {
        if(front == -1 || front > rear) return true;
        else return false;
    }

    int getSize() {
        if(front == -1 || front > rear) return 0;
        else return (rear - front + 1);
    }

    int getFront() {
        if(front == -1 || front > rear) {
            cout << "No front element present." << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    int getRear() {
        if(front == -1 || front > rear) {
            cout << "No rear element present." << endl;
            return -1;
        } else {
            return arr[rear];
        }
    }

    void printQueue() {
        cout << "Queue: ";
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }   
};

int main() {
    Queue q(5);
    q.printQueue();   // o/p: 0 0 0 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: -1
    cout << "Popping 1 element from queue.\n"; q.pop();   // o/p: Queue underflow.
    cout << endl;

    cout << "Pushing 10, 20, 30 in queue.\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.printQueue();   // o/p: 10 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 3
    cout << "Front element: " << q.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Popping 1 element from queue.\n";
    q.pop();
    q.printQueue();   // o/p: -1 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 2
    cout << "Front element: " << q.getFront() << endl;   // o/p: 20
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Pushing 40, 50, 60 in queue.\n";
    q.push(40);
    q.push(50);
    q.push(60);   // o/p: Queue overflow.
    q.printQueue();   // o/p: -1 20 30 40 50
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 4
    cout << "Front element: " << q.getFront() << endl;   // o/p: 20
    cout << "Rear element: " << q.getRear() << endl;   // o/p: 50
    cout << endl;

    cout << "Popping 4 elements from queue.\n";
    q.pop(); q.pop(); q.pop(); q.pop();
    q.printQueue();   // o/p: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    // At this point of time, whole queue has been popped out. But still we will be unable to
    // push anything in queue, as the memory blocks of queue are deactivated after an element
    // gets popped out from queue. If we want ability to continuously push elements in queue,
    // we have to implement a circular queue.

    cout << "Pushing 70 in queue." << endl;
    q.push(70);
    q.printQueue();   // o/p: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << q.getSize() << endl;   // o/p: 0
    cout << "Front element: " << q.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    return 0;
}
