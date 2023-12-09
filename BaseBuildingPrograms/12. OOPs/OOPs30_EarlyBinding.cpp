// Module: Virtual functions

// What is early binding (also called Static Binding or Compile-Time Binding) ?
// -> Early binding occurs at compile time. The compiler determines the appropriate function or
//    be called during the compilation phase. Early binding is default behavior of compiler.


// What is late binding (also called Dynamic Binding or Runtime Binding) ?
// -> Late binding occurs at runtime. The compiler determines which function to call dynamically
//    at runtime. Late binding allows the program to achieve runtime polymorphism. Late binding
//    is done through virtual functions.


#include <iostream>
using namespace std;

class Car{
    public:
        void f1() {
            cout << "I am f1 of Car" << endl;
        }
        void f2() {
            cout << "I am f2 of Car" << endl;
        }
};

class SportsCar: public Car {
    public:
        void f2() {   // method override
            cout << "I am f2 of SportsCar" << endl;
        }
        // Note: Here, we performed method overriding without using virtual keyword in base
        // class function. Thus, the binding will be resolved at compile-time, which is
        // known as early binding or static binding.
        void f3() {
            cout << "I am f3 of SportsCar" << endl;
        }
};

int main() {
    Car *p;   // p is called base class pointer. Base class pointers can point to objects of its
             // descendent classes. However, the viceversa is not true, i.e a descendent
            // class pointer cannot point to its parent.
    SportsCar obj;
    p = &obj;

    obj.f1();   // I am f1 of Car, as f1() from Car class is inherited in SportsCar class

    obj.f2();   // I am f2 of SportsCar, obvious because obj is instance of SportsCar class

    obj.f3();   // I am f3 of Sportscar, obvious because obj is instance of SportsCar class

    p->f1();   // I am f1 of Car, as f1() from Car class is inherited in SportsCar class

    p->f2();   // I am f2 of Car, calls f2() of Car even though the pointer 'p' contains address
    // an object of type SportsCar. This happens due to early binding. Early binding is done by
    // seeing type of pointer, not content of pointer(type of object the pointer points to).

    // p->f3();   // compile-time error
    // f3() is early bind with p. So by seeing type of pointer, the compiler tries of find f3()
    // in Car class. And when there is no f3() found, the compiler throws an error.

    return 0;
}