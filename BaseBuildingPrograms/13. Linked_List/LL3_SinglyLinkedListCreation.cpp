#include <iostream>
using namespace std;

// interface or blueprint for singly linked list
class Node {
    private:
        int data;    // this linked list will be able to store only integer values
        Node* next;   // 'next' pointer will point to next Node
    public:
        // default constructor
        Node() {
            cout << "I am inside default ctor." << endl;
            this->next = NULL;   // 'next' pointer is assigned the value NULL, i.e. it points nowhere
        }
        // parameterized constructor
        Node(int data) {
            cout << "I am inside param ctor." << endl;
            this->data = data;
            this->next = NULL;
        }
};

int main() {
    // Creating Node objects:
    // static object creation, i.e. objects are created on stack at compile-time
    Node obj1;
    Node obj2(6);

    // dynamic object creation, i.e. objects are created on heap at runt-time
    Node* n1 = new Node();
    Node* n2 = new Node(9);


    return 0;
}