#include <iostream>
using namespace std;

// Interface or blueprint of Node for singly linked list
class Node {
    public:
        int data;    // this linked list will be able to store only integer values
        Node* next;   // 'next' pointer will point to next Node
        
        // Default constructor
        Node() {
            cout << "I am inside default ctor." << endl;
            this->next = NULL;   // 'next' pointer is assigned the value NULL, i.e., it points nowhere
        }
        // Parameterized constructor
        Node(int data) {
            cout << "I am inside param ctor." << endl;
            this->data = data;
            this->next = NULL;
        }
};

int main() {
    // Creating Node objects:
    // 1. Static object creation, i.e., objects are created on stack at compile-time
    Node obj1;
    Node obj2(6);
    obj1.data = 4;   // accessing data member using . operator
    cout << "obj1 data: " << obj1.data << endl;   // o/p: 4
    cout << "obj2 data: " << obj2.data << endl;   // o/p: 6

    // 2. Dynamic object creation, i.e., objects are created on heap at run-time
    Node* n1 = new Node();
    Node* n2 = new Node(9);
    n1->data = 15;   // accessing data member using -> operator
    cout << "n1 data: " << n1->data << endl;   // o/p: 15
    cout << "n2 data: " << n2->data << endl;   // o/p: 9

    return 0;
}


// ● What is -> operator ?

// 1. -> is used to access members of a class/structure through a pointer variable.

// 2. It is used when we have a pointer to an object and we want to access its members (attributes or methods).
//    . is used when we have an object itself and we want to access its members.
//    Example:
//              Node obj;
//              obj.data = 10;
//              Here, we use . operator to access data member of obj
//    Similarly, -> is used when we have a pointer to an object and we want to access its members.
//    Example:
//              Node* ptr = &obj;
//              ptr->data = 20;   // same as (*ptr).data = 20;
//              -> is essentially shorthand for using the dereference operator (*) and the dot operator (.) together.
//              Example: n1->data is equivalent to (*n1).data meaning accesses the data member of the object pointed
//                       to by n1.

// 3. Let's say n1 is pointer to a Node object created dynamically using new operator.
//    Example:
//              Node* n1 = new Node();
//    If we want to set or access their members, we must use the -> operator:
//    Example:
//              n1->data = 15;   // sets the data member of the Node object pointed to by n1

// 4. Inside a class, the keyword this is a special pointer that points to the current object of the class.
//    It is used to refer to the current object's members (attributes or methods) when there is a naming conflict
//    between member variables and parameters or local variables.
//    Example:
//            this->data = data;   // here, this->data refers to the member variable 'data' of the current object,
//                                 // while the right-hand side 'data' refers to the parameter passed to the constructor
//    It is same as writing:
//            (*this).data = data;
//    However, using this-> is more readable and preferred in such cases. Since writing (*this).data is ugly and
//    confusing, C++ provides the cleaner arrow operator syntax.
