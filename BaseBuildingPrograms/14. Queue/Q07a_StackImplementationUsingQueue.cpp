// The functionalities we will provide for our stack will be as follows:
// -> push(x): Pushes x into stack.
// -> pop(): Pops out top element from stack.
// -> getTop(): Returns top element of stack.
// -> isEmpty(): Returns 1 if stack is empty, else returns 0.
// -> getSize(): Returns size of stack.

#include <iostream>
#include <queue>
using namespace std;

// METHOD 1: Uses 2 queues.
// T.C: O(n) -> push(x)
//    : O(1) -> pop(), getTop(), isEmpty(), getSize()
class Stack1 {
    public:
        queue <int> q1, q2;   // Here q1 is main queue, and q2 is helper.
        int size = 0;

        void push(int x) {
            size++;   // just keeping a track of size of stack.
            // Step 1: Push x in q2
            q2.push(x);

            // Step 2: Transfer elements from q1 to q2
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            // Step 3: Transfer back all elements from q2 to q1
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }

        void pop() {
            if(size > 0) size--;   // just keeping a track of size of stack.
            if(q1.empty()) {
                cout << "Stack underflow.\n";
            } else {
                q1.pop();
            } 
        }

        int getTop() {
            if(q1.empty()) {
                cout << "No top element in stack.\n";
                return -1;
            } else {
                return q1.front();
            } 
        }

        bool isEmpty() {
            return q1.empty() && q2.empty();
        }

        int getSize() {
            return size;
        }
};


// METHOD 2: Uses only 1 queue.
// T.C: O(n) -> push(x)
//    : O(1) -> pop(), getTop(), isEmpty(), getSize()
class Stack2 {
    public:
        queue <int> q1;   // Here q1 is only queue.
        int size = 0;

        void push(int x) {
            size++;   // just keeping track of the size of the stack.
            
            // Step 1: Push x into q1
            q1.push(x);

            // Step 2: Reverse the order of elements in q1. This can be done by
            //         popping 1 element from queue and pushing it back in queue.
            for(int i = 0; i < q1.size() - 1; i++) {
                int frontElement = q1.front();
                q1.pop();
                q1.push(frontElement);
            }
        }

        void pop() {
            if(size > 0) size--;   // just keeping a track of size of stack.
            if(q1.empty()) {
                cout << "Stack underflow.\n";
            } else {
                q1.pop();
            } 
        }

        int getTop() {
            if(q1.empty()) {
                cout << "No top element in stack.\n";
                return -1;
            } else {
                return q1.front();
            } 
        }

        bool isEmpty() {
            return q1.empty();
        }

        int getSize() {
            return size;
        }
};


int main() {
    Stack1 s1;
    cout << "Created a new Stack1:\n";
    cout << "Pushing 10, 20, 30 in stack:\n";
    s1.push(10); s1.push(20); s1.push(30);
    cout << "Top element: " << s1.getTop() << endl;
    cout << "Size: " << s1.getSize() << endl;
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;

    cout << "Popping 1 element from stack:\n";
    s1.pop();
    cout << "Top element: " << s1.getTop() << endl;
    cout << "Size: " << s1.getSize() << endl;
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;

    cout << "Popping 2 elements from stack:\n";
    s1.pop(); s1.pop();
    cout << "Top element: " << s1.getTop() << endl;
    cout << "Size: " << s1.getSize() << endl;
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;

    cout << "Popping 1 element from stack:\n";
    s1.pop();   // stack underflow.
    cout << endl << endl;


    Stack1 s2;
    cout << "Created a new Stack2:\n";
    cout << "Pushing 10, 20, 30 in stack:\n";
    s2.push(10); s2.push(20); s2.push(30);
    cout << "Top element: " << s2.getTop() << endl;
    cout << "Size: " << s2.getSize() << endl;
    cout << "stack empty status: " << s2.isEmpty() << endl << endl;

    cout << "Popping 1 element from stack:\n";
    s2.pop();
    cout << "Top element: " << s2.getTop() << endl;
    cout << "Size: " << s2.getSize() << endl;
    cout << "stack empty status: " << s2.isEmpty() << endl << endl;

    cout << "Popping 2 elements from stack:\n";
    s2.pop(); s2.pop();
    cout << "Top element: " << s2.getTop() << endl;
    cout << "Size: " << s2.getSize() << endl;
    cout << "stack empty status: " << s2.isEmpty() << endl << endl;

    cout << "Popping 1 element from stack:\n";
    s2.pop();   // stack underflow.
    cout << endl << endl;


    return 0;
}
