// What is method overloading ?
// -> Method overloading refers to the ability to define multiple methods with the same name
//    within the same class but different parameter lists or return types. This allows for
//    multiple ways to perform the same task with different inputs or outputs.

// What is method overriding ?
// -> Method overriding refers to the ability of a derived class to provide a
//    specific(can be same(rarely) or different(most of the time)) implementation for a function
//    that has already been defined in its base class. This allows objects of the derived class
//    to use their own version of the function rather than the one defined in the base class.
//    Always remember, methods overriden in base class should be the same in terms of
//    function signature(name, return type, and parameters) of base class.
//    Note that, if a particular function has been inherited in derived class, there is no point
//    of overrding method with same body. Its unnecessary writing of same function reduntantly.
//    Overriding method with same body is useful if that function couldn't be inherited in
//    derived class(this happens if a function is private in base class).

 
#include <iostream>
using namespace std;

class A{
    public:
        void sum(int a, int b) {
            cout << "Class A int sum: " << a + b << endl;
        }
};

class B: public A {
    public:
        void sum(int a, int b) {   // method override (overrides the body of sum() of class A)
            cout << "Class B int sum: " << a + b << endl;
        }

        void product(int a, int b) {
            cout << "Class B int product: " << a*b << endl;
        }

        void product(double a, double b) {   // method overload
            // the product() function overloads due to different parameter, i.e. only
            // different parameters are self-sufficient to make this function a unique one.
            cout << "Class B double product: " << a*b << endl;
        }

        // // Only different return type is not self-sufficient to make this function a unique one,
        // // i.e. method overload will not happen here. This function will throw an error.
        // double product(double a, double b) {
        //     return a*b;
        // }

        float product(float a, float b) {
            // the product() function overloads due to different parameter and different return type
            return a*b*10;   // intentionally did '*10' to specify product() with float was called
        }
};

int main() {
    A obj1;
    obj1.sum(5, 4);

    B obj2;
    obj2.sum(5, 4);

    obj2.product(2, 3);

    obj2.product(2.5, 3.5);

    cout << "Class B float product: " << obj2.product(2.5f, 3.5f);
    // Note: if we remove 'f' from the above values passed, the product() with double parameter
    // would have been called, because parameters passed with decimal values are of type double
    // by default. And, as product() with double parameter is of return type void, this
    // statement would have thrown an error.

    return 0;
}