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
            cout << "I am f1 of Car." << endl;
        }
        void f2() {
            cout << "I am f2 of Car." << endl;
        }
};

class SportsCar: public Car {
    public:
        void f2() {   // method override
            cout << "I am f2 of SportsCar." << endl;
        }
        void f3() {
            cout << "I am f3 of Sportscar." << endl;
        }
};

int main() {
    SportsCar obj;
    Car *p;   // p is called base class pointer. Base class pointers can point to objects of its
             // descendent classes. However, the viceversa is not true, i.e a descendent
            // class pointer cannot point to its parent.
    p = &obj;

    obj.f1();   // 
    obj.f2();
    obj.f3();

    p->f1();
    p->f2();
    // p->f3();
    // f3() is early bind with p. So by seeing type of pointer, the compiler tries of find f3()
    // in Car class. And when there is no f3() found, the compiler throws an error. 






    return 0;
}