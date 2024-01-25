// In circular single queue, if an element is popped

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