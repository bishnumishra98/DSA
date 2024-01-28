// Dequeue stands for doubly ended queue. We can pop and push elements in a dequeue from both sides.
// The 4 fundamental functionalities in a dequeue should be:
// -> push_front(): Inserts an element at the front of the deque.
// -> push_back(): Inserts an element at the rear of the deque.
// -> pop_front(): Removes an element from the front of the deque.
// -> pop_back(): Removes an element from the rear of the deque.

#include <iostream>
#include <cstring>   // for memset()
using namespace std;

class Deque {
    public:
        int* arr;
        int size;
        int front;
        int rear;
        
        // constructor
        Deque(int size) {
            arr = new int[size];
            memset(arr, 0, size * sizeof(int));   // initializes all elements of arr with 0s.
            this->size = size;
            front = -1;
            rear = -1;
        }

        // destructor
        ~Deque() {
            delete[] arr;
        }

        void push_back(int data) {
            // when deque, i.e., array is full
            if(rear == size-1 && front == 0) {
                cout << "Dequeue overflow." << endl;
                return;
            } else {
                // if an element can be inserted in deque, there can be several cases:
                if(rear == -1) {
                    // Case 1: if user pushed first element in queue by push_back()
                    rear = 0;
                    if(front == -1) front = 0;
                } else if(rear == size-1) {
                    // Case 2: if user pushed an element by push_back(), but rear is already at
                    //         index 'size-1'. Thus, to insert an element at arr[size-1], we have
                    //         to make space for it by shifting all elements towards left by 1.
                    int temp = front;
                    while(temp <= size-1) {
                        arr[temp-1] = arr[temp];
                        temp++;
                    }
                    // repoint front to 'front - 1' as elements have been shifted to left by 1
                    front--;
                } else {
                    // Case 3: if rear pointer is not at -1 or 'size - 1' index
                    rear++;
                }
                
                arr[rear] = data;
            }
        }

        void push_front(int data) {
            // when deque, i.e., array is full
            if(rear == size-1 && front == 0) {
                cout << "Dequeue overflow." << endl;
                return;
            } else {
                // if an element can be inserted in deque, there can be several cases:
                if(front == -1) {
                    // Case 1: if user pushed first element in queue by push_front()
                    front = 0;
                    if(rear == -1) rear = 0;
                } else if(front == 0) {
                    // Case 2: if user pushed an element by push_front(), but front is already
                    //         at index 0. Thus, to insert an element at arr[0], we have to make
                    //         space for it by shifting all elements towards right by 1.
                    int temp = rear;
                    while(temp >= 0) {
                        arr[temp+1] = arr[temp];
                        temp--; 
                    }
                    // repoint rear to 'rear + 1' as elements have been shifted to right by 1
                    rear++;
                } else {
                    // Case 3: if front pointer is not at -1 or 0 index
                    front--;
                }

                arr[front] = data;
            }
        }

        void pop_front() {   // exactly same code as of pop() of Single Queue
            // if dequeue is empty
            if(front == -1 || front > rear) {
                cout << "Dequeue underflow." << endl;
                return;
            } else {
                // if dequeue is not empty
                arr[front] = -1;
                front++;
            }
        }

        void pop_back() {
            // if dequeue is empty
            if(front == -1 || front > rear) {
                cout << "Dequeue underflow." << endl;
                return;
            } else {
                // if dequeue is not empty
                arr[rear] = -1;
                rear--;
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

        void printDeque() {
            cout << "Deque: ";
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }   
};


int main() {
    Deque dq(5);

    dq.printDeque();   // Deque: 0 0 0 0 0
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << dq.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;

    cout << "Pushing 10, 20, 30 at rear:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.printDeque();   // Deque: 10 20 30 0 0
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 3
    cout << "Front element: " << dq.getFront() << endl;   // Front element: 10
    cout << "Rear element: " << dq.getRear() << endl;   // Rear element: 30
    cout << endl;

    cout << "Pushing 40, 50, 60 at front:\n";
    dq.push_front(40);
    dq.push_front(50);
    dq.push_front(60);   // Dequeue overflow.
    dq.printDeque();   // Deque: 50 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 5
    cout << "Front element: " << dq.getFront() << endl;   // Front element: 50
    cout << "Rear element: " << dq.getRear() << endl;   // Rear element: 30
    cout << endl;
    
    cout << "Popping 1 element from front:\n";
    dq.pop_front();
    dq.printDeque();   // Deque: -1 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 4
    cout << "Front element: " << dq.getFront() << endl;   // Front element: 40
    cout << "Rear element: " << dq.getRear() << endl;   // Rear element: 30
    cout << endl;
    
    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    dq.printDeque();   // Deque: -1 40 10 20 -1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 3
    cout << "Front element: " << dq.getFront() << endl;   // Front element: 40
    cout << "Rear element: " << dq.getRear() << endl;   // Rear element: 20
    cout << endl;
    
    cout << "Popping 3 elements from front:\n";
    dq.pop_front(); dq.pop_front(); dq.pop_front();
    dq.printDeque();   // Deque: -1 -1 -1 -1-1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // Queue empty status: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // Size of queue: 0
    cout << "Front element: " << dq.getFront() << endl;   // No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // No rear element present. Rear element: -1
    cout << endl;
    
    cout << "Popping 1 element from rear:\n";
    dq.pop_back();   // Dequeue underflow.
    dq.printDeque();   // Deque: -1 -1 -1 -1 -1
    
    return 0;
}
