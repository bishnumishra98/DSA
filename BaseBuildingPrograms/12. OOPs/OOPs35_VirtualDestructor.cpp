// Module: Virtual destructor

// Q1) Is virtual destructor possible ?
// Answer: Yes
// Explanation: A virtual destructor is useful when we have a base class with virtual functions,
//              and we want to ensure that the correct destructor is called for objects of
//              derived classes when they are deleted through a pointer to the base class.
//              Destructor of base class is made virtual. It will instruct compiler to delete
//              memory of derived class objects first, then delete base class objects.


#include<iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Base ctor" << endl;
        }
        // virtual destructor
        virtual ~Base() {
            cout << "Base dtor" << endl;
        }
};

class Derived: public Base {
    public:
        Derived() {
            cout << "Derived ctor" << endl;
        }
        ~Derived() {
            cout << "Derived dtor" << endl;
        }
};

int main() {
    Base *b = new Derived();
    delete b;

    return 0;
}

// o/p:
// Base ctor
// Derived ctor
// Derived dtor
// Base dtor

// o/p, if base class destructor was not virtual:
// Base ctor
// Derived ctor
// Base dtor


// Q2) Is virtual constructor possible ?
// Answer: No
// Explanation: Virtual constructor is not possible due to following reasons:
//              i)  The constructor must know the type of object beforehand before creating it,
//                  contradicting the concept of a virtual function.
//              ii) The compiler decides which implementation of virtual function to be called at
//                  runtime using a virtual table for which a virtual pointer must be created in
//                  memory allocated to the object of a class. Therefore, to call any virtual
//                  constructor, it has to be disptached from the virtual table using virtual pointer
//                  which exists only after object creation. But an object is created only after
//                  calling a constructor. Due to this paradox, virtual constructor is impossible.
