// Module: Virtual functions

// How virtual table help in achieving runtime polymorphism or late binding ?
// -> The compiler makes a hidden pointer named *_vptr in the class containing virtual function
//    at compile time. All the derived classes of that class will also inherit vptr. All
//    objects have their own vptr, and the role of vptr is to point to a virtual table.
// -> Then it makes a static array named vtable(virtual table), which is an array of function
//    pointers. Note that the virtual table is created per class, not per object. All objects of
//    the same class share the same virtual table.
// -> When a virtual function is called through a base class pointer or reference, the program
//    uses the vptr to access the correct virtual table.
// -> Based on that vtable, correct function is called with the help of array of function
//    pointers present in the vtable.
// -> For example: In the below illustration, 

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
    void erase() {
        cout << "Erasing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
    void erase() {
        cout << "Erasing a circle." << endl;
    }
};

int main() {
    Circle circle;

    // Base class pointer pointing to an object of the derived class
    Shape* shapePtr = &circle;

    // Late binding through virtual function
    shapePtr->draw();   // o/p: Drawing a circle.

    // Early binding, as erase() is not a virtual function
    shapePtr->erase();   // o/p: Erasing a shape.

    return 0;
}

// Q) Can virtual functions be static ?
// A) No, virtual functions cannot be static in C++. This is because virtual functions
//    are member functions of a class, and static member functions are associated with
//    the class itself, not with any particular object of the class. When a virtual
//    function is called, the virtual table (vtable) of the object is used to determine
//    which implementation of the function to call. Static member functions do not have
//    vtables, so they cannot be virtual.

// Q) Can virtual functions be static?
// A) No, virtual functions cannot be static in C++. This is because virtual functions
//    are member functions of a class, and static member functions are associated with
//    the class itself, not with any particular object of the class. When a virtual
//    function is declared in a class, it is meant to be overridden by derived classes.
//    When a virtual function is called through a base class pointer or reference,
//    the virtual table (vtable) of the actual object's type is used to determine
//    which implementation of the function to call. Static member functions, on the
//    other hand, do not participate in the polymorphic behavior of virtual functions
//    and do not have vtables. Therefore, they cannot be declared as virtual.


