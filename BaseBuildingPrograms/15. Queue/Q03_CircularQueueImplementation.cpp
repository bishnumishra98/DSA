// Circular Queue is a linear data structure in which the operations are performed based on
// FIFO (First In First Out) principle and the last position is connected back to the first
// position to make a circle. It is also called ‘Ring Buffer’.

// Let a circular queue be implemented by 'arr' of size 'n'. Set both front and rear pointers to -1.
// -> When an element is pushed in queue, move rear pointer ahead using
//    the relation: rear = (rear+1)%n; and then push element at rear index.
// -> When an element is popped from queue, remove element at front index and move
//    the front pointer ahead using the relation: front = (front+1)%n;
// -> When rear pointer is just behind the front pointer(rear + 1 = front), it means the array
//    is full, i.e., queue is full. Pushing any further element will throw 'queue overflow'.
// -> When front pointer reached rear pointer(front == rear), it means only 1 element is remaining
//    in the array or queue. If any further pop operation is performed, reset both front & rear
//    to -1, i.e., queue becomes completely empty as it was in the beginning.
// -> If an element is popped from an empty queue, throw 'queue underflow'.

#include <iostream>
#include <cstring>
using namespace std;

class CircularQueue {
    public:
        int* arr;
        int size;
        int front;
        int rear;
        
        // constructor
        CircularQueue(int size) {
            arr = new int[size];
            memset(arr, 0, size * sizeof(int));   // initializes all elements of arr with 0s.
            this->size = size;
            front = -1;
            rear = -1;
        }

        // destructor
        ~CircularQueue() {
            delete[] arr;
        }

        void push(int data) {
            // if rear pointer is just behind the front pointer, queue is full
            if(rear + 1 == front) {
                cout << "Queue overflow." << endl;
                return;
            } else {
                // if queue is not full
                rear = (rear + 1) % size;
                arr[rear] = data;

                // make sure to bring front pointer to 0th index of array,
                // when a push operation happened on queue for the 1st time.
                if(front == -1) {
                    front = 0;
                }
            }
        }

        void pop() {
            // if queue is empty
            if(front == -1 && rear == -1) {
                cout << "Queue underflow." << endl;
                return;
            } else {
                // if array is not empty
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty() {
            if(front == -1 && rear == -1) return true;
            else return false;
        }

        int getSize() {
            if(front == -1 && rear == -1) return 0;
            else return (rear - front + 1);
        }

        int getFront() {
            if(front == -1 && rear == -1) {
                cout << "No front element present." << endl;
                return -1;
            } else {
                return arr[front];
            }
        }

        int getRear() {
            if(front == -1 && rear == -1) {
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
    CircularQueue q(5);
    q.printQueue();   // Queue: 0 0 0 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << q.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // No rear element present. Rear element: -1
    cout << "Popping 1 element from queue.\n"; q.pop();   // Queue underflow.
    cout << endl;

    cout << "Pushing 10, 20, 30 in queue.\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.printQueue();   // Queue: 10 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 3
    cout << "Front element: " << q.getFront() << endl;   // Front element: 10
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 30
    cout << endl;

    cout << "Popping 1 element from queue.\n";
    q.pop();
    q.printQueue();   // Queue: -1 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 2
    cout << "Front element: " << q.getFront() << endl;   // Front element: 20
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 30
    cout << endl;

    cout << "Pushing 40, 50, 60 in queue.\n";
    q.push(40);
    q.push(50);
    q.push(60);   // Queue overflow.
    q.printQueue();   // Queue: -1 20 30 40 50
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 4
    cout << "Front element: " << q.getFront() << endl;   // Front element: 20
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 50
    cout << endl;

    cout << "Popping 4 elements from queue.\n";
    q.pop(); q.pop(); q.pop(); q.pop();
    q.printQueue();   // Queue: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << q.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;

    // At this point of time, whole queue has been popped out. But still we will be unable to
    // push anything in queue, as the memory blocks of queue are deactivated after an element
    // gets popped out from queue. If we want ability to continuously push elements in queue,
    // we have to implement a circular queue.

    cout << "Pushing 70 in queue" << endl;
    q.printQueue();   // Queue: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << q.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;

    return 0;
}