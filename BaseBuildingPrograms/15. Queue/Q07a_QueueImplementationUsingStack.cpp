// The functionalities we will provide for our queue will be as follows:
// -> push(x): Pushes x into queue.
// -> pop(): Pops out front element from queue.
// -> getFront(): Returns front element of queue.
// -> getRear() : Returns rear element of queue.
// -> isEmpty(): Returns 1 if queue is empty, else returns 0.
// -> getSize(): Returns size of queue.

#include <iostream>
#include <stack>
using namespace std;

// METHOD 1: If pop() or getFront() operations are more frequently used in queue,
//           this algorithm is preferred.
// T.C: O(n) -> push(x), getRear()
//    : O(1) -> pop(), getFront(), isEmpty(), getSize()
class Queue1 {
    public:
        stack <int> s1, s2;   // Here s1 is main stack, and s2 is helper.
        int size = 0;

        void push(int x) {
            size++;   // just keeping a track of size of queue.
            // Step 1: Transfer all values from s1 to s2
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            // Step 2: Push x into s1
            s1.push(x);

            // Step 3: Transfer back all values from s2 into s1
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        void pop() {
            if(size > 0) size--;   // just keeping a track of size of queue.
            if(s1.empty()) {
                cout << "Queue underflow.\n";
            } else {
                s1.pop();
            } 
        }

        int getFront() {
            if(s1.empty()) {
                cout << "No front element in stack.\n";
                return -1;
            } else {
                return s1.top();
            } 
        }

        int getRear() {
            if(s1.empty()) {
                cout << "No rear element in stack.\n";
                return -1;
            } else {
                // Step 1: Tranfer all values from s1 to s2
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }

                // Step 2: Store top element of s2
                int rearElement = s2.top();

                // Step 3: Tranfer back all values from s2 into s1, in order to reconstruct s1
                while(!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }

                // Step 4: Return rearElement
                return rearElement;
            }
        }

        bool isEmpty() {
            if(s1.empty()) return true;
            else return false;
        }

        int getSize() {
            return size;
        }

        // just for checking purpose
        void printQueue() {
            cout << "Queue: ";
            stack <int> temp = s1;
            while(!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
};

// METHOD 2: If push() operation is more frequently used in queue, this algorithm is preferred.
// T.C: O(n) -> pop(), getFront(), getRear()
//    : O(1) -> push(), isEmpty(), getSize()
class Queue2 {
    public:
        stack <int> s1, s2;   // Here s2 is main stack, and s1 is helper.
        int size = 0;

        void push(int x) {
            size++;   // just keeping a track of size of queue.
            s1.push(x);
        }

        void pop() {
            if(size > 0) size--;   // just keeping a track of size of queue.
            if(s1.empty() && s2.empty()) {
                cout << "Queue underflow.\n";
            } else if(!s2.empty()) {
                s2.pop();
            } else {
                // Step 1: Transfer all values from s1 to s2
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }

                // Step 2: Pop top element of s2
                s2.pop();
            }
        }

        int getFront() {
            if(s1.empty() && s2.empty()) {
                cout << "No front element in stack.\n";
                return -1;
            } else if(!s2.empty()) {
                return s2.top();
            } else {
                // Step 1: Transfer all values from s1 to s2
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }

                // Step 2: Return top element of s2
                return s2.top();
            }
        }

        int getRear() {
            if(s1.empty() && s2.empty()) {
                cout << "No rear element in stack.\n";
                return -1;
            } else if(!s1.empty()) {
                return s1.top();
            } else {
                // Step 1: Transfer all values from s2 to s1
                while(!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }

                // Step 2: Store top element of s2
                int rearElement = s1.top();

                // Step 3: Tranfer back all values from s1 into s2, in order to reconstruct s2
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }

                // Step 4: Return rearElement
                return rearElement;
            }
        }

        bool isEmpty() {
            if(s1.empty() && s2.empty()) return true;
            else return false;
        }

        int getSize() {
            return size;
        }

        // just for checking purpose
        void printQueue() {
            cout << "Queue: ";
            stack <int> temp = s2;
            while(!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
};


int main() {
    Queue1 q1;
    cout << "Created a new queue1:\n";
    cout << "Pushing 10, 20, 30 in queue:\n";
    q1.push(10); q1.push(20); q1.push(30);
    q1.printQueue();
    cout << "Front element: " << q1.getFront() << endl;
    cout << "Rear element: " << q1.getRear() << endl;
    cout << "Size: " << q1.getSize() << endl;
    cout << "Queue empty status: " << q1.isEmpty() << endl << endl;

    cout << "Popping 1 element from queue:\n";
    q1.pop();
    q1.printQueue();
    cout << "Front element: " << q1.getFront() << endl;
    cout << "Rear element: " << q1.getRear() << endl;
    cout << "Size: " << q1.getSize() << endl;
    cout << "Queue empty status: " << q1.isEmpty() << endl << endl;

    cout << "Popping 2 elements from queue:\n";
    q1.pop(); q1.pop();
    q1.printQueue();
    cout << "Front element: " << q1.getFront() << endl;
    cout << "Rear element: " << q1.getRear() << endl;
    cout << "Size: " << q1.getSize() << endl;
    cout << "Queue empty status: " << q1.isEmpty() << endl << endl;

    cout << "Popping 1 element from queue:\n";
    q1.pop();   // Queue underflow.
    cout << endl << endl;


    Queue2 q2;
    cout << "Created a new queue2:\n";
    cout << "Pushing 10, 20, 30 in queue:\n";
    q2.push(10); q2.push(20); q2.push(30);
    q2.printQueue();
    cout << "Front element: " << q2.getFront() << endl;
    cout << "Rear element: " << q2.getRear() << endl;
    cout << "Size: " << q2.getSize() << endl;
    cout << "Queue empty status: " << q2.isEmpty() << endl << endl;

    cout << "Popping 1 element from queue:\n";
    q2.pop();
    q2.printQueue();
    cout << "Front element: " << q2.getFront() << endl;
    cout << "Rear element: " << q2.getRear() << endl;
    cout << "Size: " << q2.getSize() << endl;
    cout << "Queue empty status: " << q2.isEmpty() << endl << endl;

    cout << "Popping 2 elements from queue:\n";
    q2.pop(); q2.pop();
    q2.printQueue();
    cout << "Front element: " << q2.getFront() << endl;
    cout << "Rear element: " << q2.getRear() << endl;
    cout << "Size: " << q2.getSize() << endl;
    cout << "Queue empty status: " << q2.isEmpty() << endl << endl;

    cout << "Popping 1 element from queue:\n";
    q2.pop();   // Queue underflow.
    cout << endl << endl;


    return 0;
}
