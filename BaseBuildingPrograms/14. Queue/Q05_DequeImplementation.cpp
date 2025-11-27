// A circular deque is an extension of the deque with a circular arrangement of elements. In a
// circular deque, the front and rear ends of the deque are connected, forming a loop or circle.

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
        arr.resize(size, -1);
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_back(int data) {
        // When deque, i.e., array is full
        if(rear == size - 1 && front == 0) {
            cout << "Dequeue overflow." << endl;
            return;
        } else {
            // If an element can be inserted in deque, there can be several cases:
            if(rear == -1) {
                // Case 1: If user pushed first element in queue by push_back()
                rear = 0;
                if(front == -1) front = 0;
            } else if(rear == size - 1) {
                // Case 2: If user pushed an element by push_back(), but rear is already at last index of array.
                //         Thus, to insert an element at arr[size - 1], we have to make space for it by shifting
                //         all elements towards left by 1.
                int temp = front;
                while(temp < size) {
                    arr[temp - 1] = arr[temp];
                    temp++; 
                }
                // Repoint front to 'front - 1' as elements have been shifted to left by 1
                front--;
            } else {
                // Case 3: If rear pointer is not at -1 or 'size - 1' index
                rear++;
            }
            
            arr[rear] = data;
        }
    }

    void push_front(int data) {
        // When deque, i.e., array is full
        if(rear == size - 1 && front == 0) {
            cout << "Dequeue overflow." << endl;
            return;
        } else {
            // If an element can be inserted in deque, there can be several cases:
            if(front == -1) {
                // Case 1: If user pushed first element in queue by push_front()
                front = 0;
                if(rear == -1) rear = 0;
            } else if(front == 0) {
                // Case 2: If user pushed an element by push_front(), but front is already
                //         at index 0. Thus, to insert an element at arr[0], we have to make
                //         space for it by shifting all elements towards right by 1.
                int temp = rear;
                while(temp >= 0) {
                    arr[temp + 1] = arr[temp];
                    temp--; 
                }
                // Repoint rear to 'rear + 1' as elements have been shifted to right by 1
                rear++;
            } else {
                // Case 3: If front pointer is not at -1 or 0 index
                front--;
            }

            arr[front] = data;
        }
    }

    void pop_front() {   // exactly same code as of pop() of Single Queue
        // If dequeue is empty
        if(front == -1 || front > rear) {
            cout << "Dequeue underflow." << endl;
            return;
        } else {
            // If dequeue is not empty
            arr[front] = -1;
            front++;
        }
    }

    void pop_back() {
        // If dequeue is empty
        if(front == -1 || front > rear) {
            cout << "Dequeue underflow." << endl;
            return;
        } else {
            // If dequeue is not empty
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
    CircularDeque dq(5);

    dq.printDeque();   // o/p: -1 -1 -1 -1 -1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 0
    cout << "Front element: " << dq.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;

    cout << "Pushing 10, 20, 30 at rear:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.printDeque();   // o/p: 10 20 30 -1 -1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 3
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;

    cout << "Pushing 40, 50, 60 at front:\n";
    dq.push_front(40);
    dq.push_front(50);
    dq.push_front(60);   // o/p: Dequeue overflow.
    dq.printDeque();   // o/p: 50 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 5
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 50
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;
    
    cout << "Popping 1 element from front:\n";
    dq.pop_front();
    dq.printDeque();   // o/p: -1 40 10 20 30
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 4
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 40
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 30
    cout << endl;
    
    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    dq.printDeque();   // o/p: -1 40 10 20 -1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 3
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 40
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 20
    cout << endl;
    
    cout << "Popping 3 elements from front:\n";
    dq.pop_front(); dq.pop_front(); dq.pop_front();
    dq.printDeque();   // o/p: -1 -1 -1 -1-1
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 0
    cout << "Front element: " << dq.getFront() << endl;   // o/p: No front element present. Front element: -1
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: No rear element present. Rear element: -1
    cout << endl;
    
    cout << "Popping 1 element from rear:\n";
    dq.pop_back();   // o/p: Dequeue underflow.
    dq.printDeque();   // o/p: -1 -1 -1 -1 -1
    cout << endl;

    cout << "Pushing 10 at rear:\n";
    dq.push_back(10);
    dq.printDeque();
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 0
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 1
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 10
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 10
    cout << endl;

    cout << "Pushing 20, 30 at front:\n";
    dq.push_front(20); dq.push_front(30);
    dq.printDeque();
    cout << "Queue empty status: " << dq.isEmpty() << endl;   // o/p: 1
    cout << "Size of queue: " << dq.getSize() << endl;   // o/p: 0
    cout << "Front element: " << dq.getFront() << endl;   // o/p: 30
    cout << "Rear element: " << dq.getRear() << endl;   // o/p: 10
    cout << endl;

    return 0;
}
