// Module: Virtual functions

// How does the virtual table help in achieving runtime polymorphism or late binding?
// -> The compiler generates a static array called vtable (virtual table) for each class,
//    and this array consists of function pointers. It's important to note that the vtable is
//    created per class, not per object. Objects of the same class points to the same vtable,
//    using a hidden pointer member variable called *_vptr.
// -> Each object has its own vptr, which points to the vtable of the type of object, i.e.
//    class of object.
// -> When a virtual function is called through a base class pointer or reference, the program
//    uses the vptr to access the correct vtable associated with the actual object's type.
// -> Based on the vtable, the correct function is invoked by referencing the array of
//    function pointers present in the vtable.


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
    void enlarge() {
        cout << "Enlarge the shape." << endl;
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
    // memory allocation in stack
    // Circle circle;
    // Shape* shapePtr = &circle;

    // memory allocation in heap
    Shape* shapePtr = new Circle();

    // Late binding through virtual function
    shapePtr->draw();   // o/p: Drawing a circle.

    // Early binding, as erase() is not a virtual function
    shapePtr->erase();   // o/p: Erasing a shape.

    // As enlarge() is inherited in Circle
    shapePtr->enlarge();   // o/p: Enlarge the shape.

    return 0;
}

// Q) Can virtual functions be static?
// A) No, virtual functions cannot be static in C++. This is because virtual functions
//    are member functions of a class(associated to instances of class), on the other hand
//    static member functions are associated with the class itself, not with any particular
//    instance of the class. When a virtual function is declared in a class, it is meant to
//    be overridden by derived classes. But static member functions do not participate in
//    polymorphic behavior like virtual functions do. Therefore, they cannot be static.


