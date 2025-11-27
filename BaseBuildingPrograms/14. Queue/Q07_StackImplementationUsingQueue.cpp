// The functionalities we will provide for our stack will be as follows:
// -> push(x): Pushes x into stack.
// -> pop(): Pops out top element from stack.
// -> getTop(): Returns top element of stack.
// -> isEmpty(): Returns 1 if stack is empty, else returns 0.
// -> getSize(): Returns size of stack.

#include <iostream>
#include <queue>
using namespace std;

// METHOD 1: Stack using 2 queues (q1 = main queue, q2 = helper queue)
// push(x) is O(n), all other operations are O(1)

class Stack1 {
public:
    queue<int> q1, q2;   // q1 holds stack in correct order (front = top), q2 is helper
    int size = 0;

    // Push element on top of stack
    void push(int x) {
        size++;   // tracking stack size

        // Step 1: Push new element into helper queue q2
        q2.push(x);

        // Step 2: Move everything from q1 → q2 to maintain stack order
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Move everything back from q2 → q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop top element
    void pop() {
        if(size > 0) size--;
        if(q1.empty()) {
            cout << "Stack underflow.\n";
            return;
        }
        q1.pop();  // q1.front() is the top
    }

    // Get top element
    int getTop() {
        if(q1.empty()) {
            cout << "No top element in stack.\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    int getSize() {
        return size;
    }

    // Print stack from TOP → BOTTOM
    void printStack() {
        cout << "Stack: ";
        if(q1.empty()) {
            cout << "(empty)";
        } else {
            queue<int> temp = q1;
            while(!temp.empty()) {
                cout << temp.front() << " ";  // front = top
                temp.pop();
            }
        }
        cout << endl;
    }
};

int main() {
    Stack1 s1;
    cout << "Created a new Stack1:\n";
    
    cout << "Pushing 10, 20, 30 in stack:\n";
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.printStack();   // o/p: 30 20 10
    cout << "Top element: " << s1.getTop() << endl;   // o/p: 30
    cout << "Size: " << s1.getSize() << endl;         // o/p: 3
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;  // o/p: 0

    cout << "Popping 1 element from stack:\n";
    s1.pop();
    s1.printStack();   // o/p: 20 10
    cout << "Top element: " << s1.getTop() << endl;   // o/p: 20
    cout << "Size: " << s1.getSize() << endl;         // o/p: 2
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;  // o/p: 0

    cout << "Popping 2 elements from stack:\n";
    s1.pop();
    s1.pop();
    s1.printStack();   // o/p: (empty)
    cout << "Top element: " << s1.getTop() << endl;   // o/p: No top element present. -1
    cout << "Size: " << s1.getSize() << endl;         // o/p: 0
    cout << "stack empty status: " << s1.isEmpty() << endl << endl;  // o/p: 1

    cout << "Popping 1 element from stack:\n";
    s1.pop();   // o/p: Stack underflow.
    cout << endl << endl;

    return 0;
}
