// Shallow copy and deep copy refer to two different approaches in copying the contents of one object
// into another in C++.

// Shallow copy:
// A shallow copy is a copy of the object where the contents (data members) are duplicated, but if the
// object contains pointers or references, only the addresses of those pointers or references are
// copied, not the data they point to. As a result, both the original and the copy share the same
// dynamically allocated memory, leading to potential issues.

// Deep copy:
// A deep copy, on the other hand, involves copying not only the contents of the object but also any
// dynamically allocated memory pointed to by the object. This ensures that the original and the copy
// have their own separate copies of the data, preventing unintended side effects due to shared memory.


#include <iostream>
using namespace std;

// Deep copy Illustration:
class Student {
    private:
        int *age;
        int weight;

    public:
       // non-parameterized constructor: initializes the object with default values.
        Student() {
            cout << "new object created by default ctor" << "\n";
        }

        // copy constructor
        Student(const Student &s) {
            cout << "new object created by copy ctor" << "\n";
            // Deep copy: allocate new memory and copy the data
            age = new int(*s.age);
            weight = s.weight;
        }

        // Destructor to release allocated memory
        ~Student() {
            delete age;
        }

        void setStudentData(int _age, int _weight) {
            *age = _age;
            weight = _weight;
        }

        void showStudentInfo() {
            cout << "Age: " << *age << "\n"
                 << "Weight: " << weight << "\n\n";
        }
};

int main() {
    Student s1;   // new object created by default ctor
    s1.setStudentData(18, 65);
    s1.showStudentInfo();

    // copy constructor will not be called in this case because s2 is made separately, i.e it is
    // not initialized with s1 on creation. Here, an implicit copy assignment operator
    // (an overloaded function made by the compiler) will be called by the compiler. The code to
    // make a copy of the object is automatically generated inside that copy assignment operator
    // by the compiler, unless a custom copy assignment operator is provided.
    Student s2;   // new object created by default ctor
    s2 = s1;
    s2.showStudentInfo();

    // copy constructor will called only in these two cases:
    // case 1:
    Student s3 = s1;   // new object created by copy ctor
    s3.showStudentInfo();
    // case 2:
    Student s4(s1);   // new object created by copy ctor
    s4.showStudentInfo();

    cout << "\n" << "When age & weight is changed in any one of the object:" << "\n\n";

    s4.setStudentData(20, 75);

    s1.showStudentInfo();
    s2.showStudentInfo();
    s3.showStudentInfo();
    s4.showStudentInfo();
    
    // Age in every object did not changed because the age pointer in all objects points to different
    // memory locations. Changing the value of one memory block does not affects any other objects.
    // Always define a destructor to delete the pointer in deep copy in order to avoid memory leakage.

    return 0;
}