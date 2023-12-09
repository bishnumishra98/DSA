#include <iostream>
using namespace std;

// Q1) What is an abstract or pure virtual function ?
// Answer: A pure virtual function is a virtual function that is declared in a base class and
//         has no implementation. It is denoted by adding " = 0" to the declaration.
//         Syntax of pure virtual function: virtual return_type function_name() const(optional) = 0;
//         Example: virtual void draw() = 0;

// Q2) What is an abstract class ?
// Answer: A class containing pure virtual functions is an abstract class in C++. Whereas, in Java,
//         a class that has keyword 'abstract' is called an abstract class.
//         Example:

// Abstract class Shape
class Shape {
    public:
        // Pure virtual function - must be overridden by derived classes
        virtual void draw() = 0;

        // Non-virtual function
        virtual void printInfo() {
            cout << "This is a shape object." << endl;
        }
};

// Derived class Circle
class Circle: public Shape {
    public:
        virtual void draw() override {
            cout << "Drawing a circle." << endl;
        }
};

// Derived class Square
class Square: public Shape {
    public:
        virtual void draw() override {
            cout << "Drawing a square." << endl;
        }
};

int main() {
    // Cannot create an object of an abstract class
    // Shape s; // Error

    // Creating objects of derived classes
    Circle circle;
    Shape *s = new Square();

    // Calling non-virtual function
    circle.printInfo();
    s->printInfo();

    // Calling virtual function
    circle.draw();
    s->draw();

    return 0;
}

// Characteristics of abstract class:
// 1) It cannot be directly instantiated.
// 2) It contain pure virtual functions that must be overridden by derived classes.
// 3) It can provide non-virtual functions that are common to all derived classes.
// 4) It allows polymorphism and dynamic binding.

// Q3) What's the use of abstract classes if we cannot make instances of it ?
// Answer: Abtract classes contains pure virtual functions that ensures that derived classes provide
//         specific implementations for those functions, enforcing a common interface across all
//         derived classes. This helps in achieving polymorphism(runtime) and code organization.
