// There are 5 types of inheritance in C++:

// i)   Single Inheritance:
//      Diagram: Base --> Derived1
//      Explanantion: A class inherits from only one parent class.

// ii)  Multiple Inheritance (not supported in Java):
//      Diagram: Base --> Derived1
//               Derived2 --> Derived1
//      Explanantion: A class inherits from two or more parent classes. This also gives birth
//                    to "diamond problem".

// iii) Multilevel Inheritance:
//      Diagram: Base --> Derived2
//               Derived2 --> Derived3
//      Explanantion: A class inherits from another class, which in turn inherits from another class.
                      
// iv)  Hierarchical Inheritance:
//      Diagram: Base2 --> Derived4
//               Base2 --> Derived5
//      Explanantion: Two or more classes inherit from the same parent class.

// v)   Hybrid Inheritance:
//      Diagram: Base --> Derived1
//               Base --> Derived2
//               Derived3 --> Derived2
//               Derived6 --> Derived3, Derived1
//      Explanantion: A class inherits from multiple parent classes, and one of those parent classes
//                    also inherits from another class. This is actually Combination of Multiple and
//                    Multilevel Inheritance.


#include <iostream>
using namespace std;

// i)   Single Inheritance:
            class A {
                // code
            };

            class B: public A {
                // code
            };


// ii)  Multiple Inheritance:
            class A {
                // code
            };

            class B {
                // code
            };

            class C: public A, public B {
                // code
            };


// iii) Multilevel Inheritance
            class A {
                // code
            };

            class B: public A {
                // code
            };

            class C: public B {
                // code
            };


// iv)  Hierarchical Inheritance:
            class A {
                // code
            };

            class B: public A {
                // code
            };

            class C: public A {
                // code;
            };


// v)   Hybrid Inheritance:
            class A {
                // code
            };

            class B {
                // code
            };

            class C: public A, public B {
                // code
            };

            class D: public A {
                // code
            };

            class E: public B, public D {
                // code
            };

