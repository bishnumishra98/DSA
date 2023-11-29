#include <iostream>
using namespace std;

// What is virtual in C++ ?
// In C++, the virtual keyword is used to declare a virtual function or to specify that a function
// in a base class should be overridden in a derived class. The use of virtual is a key feature of
// polymorphism in C++. Here are the main uses of virtual:

// 1. Virtual Functions: When you declare a member function in a base class as virtual, you indicate
//                       that this function may be overridden in derived classes. This allows the
//                       program to determine at runtime which version of the function to call
//                       based on the actual type of the object. Example:
                         class Base {
                         public:
                            virtual void myFunction() {
                                // Base class implementation
                            }
                         };

                         class Derived : public Base {
                         public:
                            void myFunction() override {
                                // Derived class implementation
                            }
                         };
//                       The 'override' keyword is optional but is considered good practice to use
//                       for clarity and to catch potential errors.

// 2. Virtual Destructors: When working with polymorphism and dynamic memory allocation, it's
//                         essential to have a virtual destructor in the base class. This ensures
//                         that the correct destructor is called for an object when it's deleted
//                         through a pointer to the base class.
                            class Base {
                            public:
                                virtual ~Base() {
                                    // Virtual destructor implementation
                                }
                            };

                            class Derived : public Base {
                            public:
                                ~Derived() override {
                                    // Derived class destructor implementation
                                }
                            };
//                          Using a virtual destructor is crucial to ensure that the destructors
//                          of both the base and derived classes are called when deleting an object
//                          through a base class pointer.

// 3. Virtual Base Classes: In cases where a class is inherited by multiple paths in a hierarchy,
//                          using the virtual keyword for inheritance can help prevent issues
//                          related to the "diamond problem." It ensures that only one instance
//                          of the base class is present in the derived class.
                            class A {
                            public:
                                int data;
                            };

                            class B : virtual public A {
                                // Inherits virtually to avoid multiple instances of A
                            };

                            class C : virtual public A {
                                // Inherits virtually to avoid multiple instances of A
                            };

                            class D : public B, public C {
                                // Now, D has only one instance of A
                            };
//                          The use of virtual is a fundamental aspect of C++ polymorphism,
//                          allowing for runtime method resolution and enabling more flexible
//                          and extensible code designs.





int main() {

    return 0;
}