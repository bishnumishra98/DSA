// We will make our implementation of stack using arrays and OOPs concept

#include <iostream>
using namespace std;

class Stack {
public:
    int* arr;
    int size;
    int top;

    // Constructor
    Stack(int size) {
        arr = new int[size];
        this->size = size;
        this->top = -1;   // top will be used to track index of topmost element in stack in array
    }

    // Push functionality
    void push(int data) {
        if(top == size - 1) {
            cout << "Stack overflow\n";
        } else {
            top++;
            arr[top] = data;
        }
    }

    // Pop functionality
    void pop() {
        if(top == -1) cout << "Stack underflow\n";
        else top--;
    }

    // Empty functionality
    bool isEmpty() {
        if(top == -1) return true;
        return false;
    }

    // Get top element of stack functionality
    int getTop() {
        if(top == -1) {
            cout << "Stack is empty, ";
            return -1;
        } else {
            return arr[top];
        }
    }

    // Get size of stack functionality
    int getSize() {
        return top + 1;
    }

    // Print elements of stack functionality
    void printStack() {
        if(top == -1) {
            cout << "Stack is empty\n\n";
        } else {
            cout << "Stack: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
        }
    }
};

int main() {
    Stack st(3);   // static creation of Stack object 'st' of size 3
    
    cout << "No elements pushed in stack yet.\n";
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 1 (true)
    cout << "Top element: " << st.getTop() << endl;   // o/p: Stack is empty, -1
    cout << "Size: " << st.getSize() << endl;   // o/p: 0
    st.printStack();   // o/p: Stack is empty

    cout << "Pushing element '10' in stack:\n";
    st.push(10);
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 0 (false)
    cout << "Top element: " << st.getTop() << endl;   // o/p: 10
    cout << "Size: " << st.getSize() << endl;   // o/p: 1
    st.printStack();   // o/p: Stack: 10

    cout << "Pushing element '20' in stack:\n";
    st.push(20);
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 0 (false)
    cout << "Top element: " << st.getTop() << endl;   // o/p: 20
    cout << "Size: " << st.getSize() << endl;   // o/p: 2
    st.printStack();   // o/p: Stack: 10 20

    cout << "Pushing element '30' in stack:\n";
    st.push(30);
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 0 (false)
    cout << "Top element: " << st.getTop() << endl;   // o/p: 30
    cout << "Size: " << st.getSize() << endl;   // o/p: 3
    st.printStack();   // o/p: Stack: 10 20 30

    cout << "Pushing element '40' in stack:\n";
    st.push(40);   // o/p: Stack overflow
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 0 (false)
    cout << "Top element: " << st.getTop() << endl;   // o/p: 30
    cout << "Size: " << st.getSize() << endl;   // o/p: 3
    st.printStack();   // o/p: Stack: 10 20 30

    cout << "After popping two elements:\n";
    st.pop();
    st.pop();
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 0 (false)
    cout << "Top element: " << st.getTop() << endl;   // o/p: 10
    cout << "Size: " << st.getSize() << endl;   // o/p: 1
    st.printStack();   // o/p: Stack: 10

    cout << "After popping two elements:\n";
    st.pop();
    st.pop();   // o/p: Stack underflow
    cout << "Stack empty status: " << st.isEmpty() << endl;   // o/p: 1 (true)

    return 0;
}
