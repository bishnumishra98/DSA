// Diamond problem:

//          Person
//         /      \
//        /        \
//       /          \
//      / is a       \ is a
//     /              \
//    /                \
// Teacher          Researcher
//    \                /
//     \              /
//      \ is a       / is a
//       \          /
//        \        / 
//         \      /
//         Engineer

#include <iostream>
using namespace std;

class Person {
    public:
        void walk() {
            cout << "I am walking." << endl;
        }  
};

class Teacher: virtual public Person {
    public:
        void teach() {
            cout << "I am teaching." << endl;
        }
};

class Researcher: virtual public Person {
    public:
        void research() {
            cout << "I am researching." << endl;
        }
};

class Engineer: public Teacher, public Researcher {
    public:
        void code() {
            cout << "I am coding." << endl;
        }
};


int main() {
    Engineer obj;
    // obj.walk();   // gives an error: walk() is ambiguous. This error occurs because the
    //              // object 'obj' is getting confused, whether to invoke walk() of Teacher class
    //             // or walk() of Researcher class respectively. This is called diamond problem.
    
    // Diamond problem has two solutions:

    // Solution 1) By using scope resolution:
    // obj.Teacher::walk();   // this means to explicitly invoke walk() from Teacher class.

    // Solution 2) By using virtual classes.
    obj.walk();   // Here, obj.walk() means Person::walk() because the virtual keyword is used for both
                 // Teacher and Researcher classes during inheritance from Person.

    // How virtual keyword works here?
    // When there was no virtual keyword, the compiler made two separate copies of Person::walk(), one for
    // Teacher and the other for Researcher at compile time (also called early binding).
    // Now, by using virtual inheritance, the compiler ensures that there is only one shared instance of
    // Person::walk() within the Engineer object at runtime. The virtual table (vtable) is used to resolve
    // the function call dynamically (also called late binding), allowing Engineer obj to invoke walk() of
    // the shared Person class directly.


    return 0;
}