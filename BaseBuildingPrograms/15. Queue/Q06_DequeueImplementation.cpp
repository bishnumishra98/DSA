// Dequeue stands for doubly ended queue. We can pop and push elements in a dequeue from both sides.
// The 4 fundamental functionalities in a dequeue should be:
// -> push_front(): Inserts an element at the front of the deque.
// -> push_back(): Inserts an element at the rear of the deque.
// -> pop_front(): Removes an element from the front of the deque.
// -> pop_back(): Removes an element from the rear of the deque.

#include <iostream>
#include <cstring>   // for memset()
using namespace std;

class Dequeue {
    public:
        int* arr;
        int size;
        int front;
        int rear;
        
        // constructor
        Dequeue(int size) {
            arr = new int[size];
            memset(arr, 0, size * sizeof(int));   // initializes all elements of arr with 0s.
            this->size = size;
            front = -1;
            rear = -1;
        }

        // destructor
        ~Dequeue() {
            delete[] arr;
        }

        void push_front(int data) {
            // if rear pointer reached last index of array, no more elements can be pushed
            if(rear == size-1) {
                cout << "Queue overflow." << endl;
                return;
            } else {
                // if rear pointer did not reached last index of array
                front++;
                arr[front] = data;

                // make sure to bring rear pointer also ahead
                rear++;
            }
        }

        void push_back(int data) {   // exactly same code as of push() of Single Queue
            // if rear pointer reached last index of array, no more elements can be pushed
            if(rear == size-1) {
                cout << "Queue overflow." << endl;
                return;
            } else {
                // if rear pointer did not reached last index of array
                rear++;
                arr[rear] = data;

                // make sure to bring front pointer to 0th index of array,
                // when a push operation happened on queue for the 1st time.
                if(front == -1) {
                    front = 0;
                }
            }
        }

        void pop_front() {
            
        }

        void pop_back() {
            
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

        void printDequeue() {
            cout << "Queue: ";
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }   
};


int main() {
    Dequeue q(5);
    q.printDequeue();   // Queue: 0 0 0 0 0
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
    q.printDequeue();   // Queue: 10 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 3
    cout << "Front element: " << q.getFront() << endl;   // Front element: 10
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 30
    cout << endl;

    cout << "Popping 1 element from queue.\n";
    q.pop();
    q.printDequeue();   // Queue: -1 20 30 0 0
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 2
    cout << "Front element: " << q.getFront() << endl;   // Front element: 20
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 30
    cout << endl;

    cout << "Pushing 40, 50, 60 in queue.\n";
    q.push(40);
    q.push(50);
    q.push(60);   // Queue overflow.
    q.printDequeue();   // Queue: -1 20 30 40 50
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 4
    cout << "Front element: " << q.getFront() << endl;   // Front element: 20
    cout << "Rear element: " << q.getRear() << endl;   // Rear element: 50
    cout << endl;

    cout << "Popping 4 elements from queue.\n";
    q.pop(); q.pop(); q.pop(); q.pop();
    q.printDequeue();   // Queue: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << q.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;

    // At this point of time, whole queue has been popped out. But still we will be unable to
    // push anything in queue, as the memory blocks of queue are deactivated after an element
    // gets popped out from queue. If we want ability to continuously push elements in queue,
    // we have to implement a circular queue.

    cout << "Pushing 70 in queue." << endl;
    q.push(70);
    q.printDequeue();   // Queue: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << q.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << q.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << q.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << q.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;

    return 0;
}

