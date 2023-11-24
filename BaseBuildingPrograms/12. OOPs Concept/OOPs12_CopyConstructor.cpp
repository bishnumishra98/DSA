// In C++, a copy constructor is a special member function of a class that is used to create an object
// as a copy of another object of the same class.

// Properties of copy constructors are the same as a regular constructor:
// 1) It is an instance member function of the class. It can never be static.
// 2) Its name must be the same as the class name.
// 3) It has no return type.
// 4) It must be placed in the public section of the class.
// 5) If the programmer does not specify a copy constructor, the C++ compiler generates a default copy
//    constructor when a new object is created as a copy of an existing object, and it is used to
//    initialize the new object with the values of the existing object. The default copy constructor
//    performs a member-wise copy of the object's data members, essentially copying each member variable
//    from the source object to the destination object. However, this copy is a shallow copy.


// Q) Why to create copy constructor if compiler creates default one on its own ?

// A) While the C++ compiler does automatically generate a default copy constructor if one is not
//    explicitly defined, there are cases where a we might want to create our own copy constructor:

//    1) Perform deep copy:
//       The default copy constructor performs a shallow copy, meaning it copies the values of the
//       data members. If a class contains dynamically allocated memory or resources, a shallow copy
//       can lead to issues because the copied object will share the same resources with the original.
//       In such cases, a programmer might want to define a custom copy constructor to perform a deep
//       copy and ensure that each object has its own independent copy of resources.

//    2) Additional Initialization Logic:
//       If there is additional logic or initialization steps required during the copying process,
//       a custom copy constructor can provide the flexibility to include that logic.



#include <iostream>
using namespace std;

class Student {
    private:
        int standard;
        int age;
        float weight;

    public:
        // parameterized constructor: initializes the object with specified values.
        Student(int age, float w) {
            standard = 12;
            this->age = age;
            weight = w;
        }

        // copy constructor
        Student(const Student &s) {
            standard = 12;
            age = s.age;   // or, this->age = s.age;
            weight = s.weight;   // or, this->weight = s.weight;
        }
        // Note: The above illustration is a shallow copy. Even if the programmer had not defined
        // this copy constructor, the C++ compiler would have generated a default copy constructor,
        // which would look exactly the same as above.
        // The real use of copy constructor is shown in next module when we need to perform deep copy.

        // Alternate way of defining a copy constructor, using initializers list:
        // Student(const Student &s) : standard(12), age(s.age), weight(s.weight) {}


        // -> Purpose of 'const' keyword and 'passing object by reference(&s)' in copy constructor:

        // -> The 'const' keyword in the parameter list indicates the values of the members of the source
        //    object ('s' in this case) should not be changed during the copying process. It ensures that
        //    the copy constructor does not unintentionally modify the state of the source object.

        // -> It is necessary to pass object as reference and not by value in copy constructors because
        //    if we pass it by value, a new copy of object will be made using the copy constructor.
        //    This means the copy constructor would call itself to make a new copy of the Student object.
        //    This process will continue, resulting in an infinite recursion until the stack overflows.

        void showStudentInfo() {
            cout << "Standard: " << standard << "\n"
                 << "Age: " << age << "\n"
                 << "Weight: " << weight << "\n\n";
        }
};

int main() {
    Student s1(18, 65);
    // creating a new object 's2' as a copy of 's1'
    Student s2 = s1;   // or, Student s2(s1);

    s1.showStudentInfo();
    s2.showStudentInfo();

    return 0;
}