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

class Queue {
    public:
        int* arr;
        int size;
        int front;
        int rear;
        
        // constructor
        Queue(int size) {
            arr = new int[size];
            memset(arr, 0, size * sizeof(int));   // initializes all elements of arr with 0s.
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
            if(rear + 1 == front) {
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

        void pop() {
            // if queue is empty
            if(front == -1 || front > rear) {
                cout << "Queue underflow." << endl;
                return;
            } else {
                // if array is not empty
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