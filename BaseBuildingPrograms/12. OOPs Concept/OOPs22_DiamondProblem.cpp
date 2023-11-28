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

class Teacher: public Person {
    public:
        void teach() {
            cout << "I am teaching." << endl;
        }
};

class Researcher: public Person {
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
    obj.Teacher::walk();   // this means to invoke walk() from Teacher class.

    // Solution 2) By using virtual classes.
    // Illustration for it is given in next module.

    return 0;
}