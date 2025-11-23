// We will implement 2 stacks in an array, one stack filling from left of array and another stack
// filling from right of the array. In this way, an array is most space efficiently used up.

#include <iostream>
#include <cstring>   // for memset()
using namespace std;

class Stack{
    public:
        int *arr;
        int size;   // size of array
        int top1;   // top1 pointer for stack 1
        int top2;   // top2 pointer for stack 2

        // Constructor
        Stack(int size) {
            arr = new int[size];   // initializes arr of size 'size' with all values as 0.
            // However, some compilers may assign garbage values to such array allocation.
            // Thus, we can use the "memory set" function to initialize array with all 0s.
            memset(arr, 0, size * sizeof(int));  // initializes all elements of arr with 0s.
            this->size = size;
            top1 = -1;   // initializing top1 pointer from -1 (top1 will move towards right)
            top2 = size;   // initializing top2 pointer from size (top2 will move towards left)
        }

        // Push functionality of stack 1
        // The push operations takes place on arr[0], arr[1], ... i.e.,
        // 1st, 2nd, ... elements of array.
        void push1(int data) {
            if(top2 - top1 == 1) {
                cout << "Stack overflow\n\n";
            } else {
                top1++;
            arr[top1] = data;
            }
        }

        // Push functionality of stack 2
        // The push operations takes place on arr[size-1], arr[size-2], ... i.e., last,
        // 2nd last, ... elements of array respectively.
        void push2(int data) {
            if(top2 - top1 == 1) {
                cout << "Stack overflow\n\n";
            } else {
                top2--;
                arr[top2] = data;
            }
        }

        // Pop functionality for stack 1
        void pop1() {
            if(top1 == -1) {
                cout << "Stack underflow\n\n";   // as we cannot pop out anything from empty stack
            } else {
                arr[top1] = 0;   // resetting array value back to 0
                top1--;   // top1 going back towards left
            }
        }

        // Pop functionality for stack 2
        void pop2() {
            if(top2 == size) {
                cout << "Stack underflow\n\n";   // as we cannot pop out anything from empty stack
            } else {
                arr[top2] = 0;   // resetting array value back to 0
                top2++;   // top2 going back towards right
            }
        }

        // Print stack functionality
        void printStack() {
            cout << "Top 1: " << top1 << endl;
            cout << "Top 2: " << top2 << endl;
            cout << "Stack: ";
            for(int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
        }
};

int main() {
    Stack s(5);   // static creation of Stack object 's' of size 5
    s.printStack();   // o/p: Stack: 0 0 0 0 0

    s.push1(10);
    s.push2(50);
    s.printStack();   // o/p: Stack: 10 0 0 0 50

    s.push1(20);
    s.push2(40);
    s.printStack();   // o/p: Stack: 10 20 0 40 50

    s.push1(30);
    s.printStack();   // o/p: Stack: 10 20 30 40 50

    s.push1(35);   // o/p: Stack overflow

    s.pop2();
    s.printStack();   // o/p: Stack: 10 20 30 0 50

    s.pop2();
    s.printStack();   // o/p: Stack: 10 20 30 0 0

    s.pop2();   // o/p: Stack underflow

    return 0;
}
