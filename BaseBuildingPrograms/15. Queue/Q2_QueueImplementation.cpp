// We will make our implementation of queue using arrays and OOPs concept

#include <iostream>
#include <cstring>   // for memset()
using namespace std;
// Note: In a queue, push happens from -> rear
//               and pop happens from -> front

class Queue {
    public:
        int* arr;
        int size;
        int front;
        int rear;
        
        // constructor
        Queue(int size) {
            arr = new int[size];
            memset(arr, 0, size * sizeof(int));  // initializes all elements of arr with 0s.
            this->size = size;
            front = -1;
            rear = -1;
        }

        // destructor
        ~Queue() {
            delete[] arr;
        }

        void push(int data) {
            // if rear pointer reached last index of array, no more elements can be pushed
            if(rear == size-1) {
                cout << "Queue overflow." << endl;
                return;
            } else {
                // if array is empty, i.e., first element is being pushed in queue
                if(front == -1 && rear == -1) {
                    front++;
                    rear++;
                    arr[rear] = data;
                } else {   // if second element or element after second element is pushed in queue
                    rear++;
                    arr[rear] = data;
                }
            }
        }

        void pop() {
            // if array is empty
            if(front == -1 && rear == -1) {
                cout << "Queue underflow." << endl;
                return;
            } else {
                if(front == rear) {
                    // if only 1 element is present in queue
                    arr[front] = -1;   // mark that element as -1 to indicate its no more present
                    front = -1;   // reset front pointer to -1
                    rear = -1;   // reset rear pointer to -1
                } else {
                    // if more than 1 element is present in queue
                    arr[front] = -1;
                    front++;
                }
            }
        }

        bool isEmpty() {
            if(front == -1 && rear == -1) return true;
            else return false;
        }

        int getSize() {
            // if queue is empty, return 0 as size
            if(front == -1 && rear == -1) return 0;
            else return rear - front + 1;
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
    Queue q(5);
    q.printQueue();   // Queue: 0 0 0 0 0
    q.push(10);
    q.push(20);
    q.push(30);
    q.printQueue();   // Queue: 10 20 30 0 0
    q.pop();
    q.pop();
    // q.pop();
    q.printQueue();   // Queue: -1 -1 30 0 0
    q.push(40);
    q.push(50);
    q.push(60);   // Queue overflow.
    // q.push(70);
    // q.push(80);
    q.printQueue();   // Queue: -1 -1 30 40 50
    
    // I had popped only 2 elements from stack, but still I am not able to push more than
    // 2 elements in queue, i.e., when I am trying to push q.push(60) in queue, it is
    // showing queue overflow. This is normal behavior of queue according to 'Queue Class-1'.

    // But let's say if I had popped 3 elements from queue instead of 2. Then according to the
    // implementation, front and rear pointers would come at same index of array, and thus they
    // both will reset back to -1. And boom, here's the bug !. Now queue becomes entirely empty
    // as it was in beginning, and I will be able to push 5 new elements in queue.

    // How is this peculiar implementation of queue using arrays, justified ?

    return 0;
}


/*
int main() {
    Queue q(5);
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
*/
