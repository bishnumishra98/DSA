// What is a class ?
// A class is a blueprint, template, or a prototype that
// defines the structure and behavior of objects.

// What is an object ?
// Object is an instance of a class.

#include <iostream>
using namespace std;

// An empty class, one without any member variables, still occupies space in memory.
// However, the size of an empty class is typically not 0 bytes; it is often 1 byte.
// The C++ standard mandates that an object must have a unique address. Therefore, even
// if the class has no data members, the compiler ensures that objects of that class
// have distinct addresses. If an empty class were assigned 0 bytes, every instance of
// that class would share the same memory address, leading to issues.

class Student {
    double weight;   // occupies 8 bytes
    int roll_no;   // occupies 4 bytes    
    bool attendance;   // occupies 1 byte

    // functions/methods don't occupy memory
    void study() {
        int subjects;
        cout << "I am studying" << endl;
    }

    void play() {
        cout << "I am playing" << endl;
    }

    void sleep() {
        cout << "I am sleeping" << endl;
    }
};

int main() {
    Student s1;  // Memory for s1 is allocated here

    cout << "Size of Student class: " << sizeof(Student) << " bytes" << endl;   // o/p: 16
    cout << "Size of s1: " << sizeof(s1) << " bytes" << endl;   // o/p: 16
    // When 'int roll_no' is placed above 'double weight' then output is 24 bytes.

    return 0;
}

// Explanation:
// The difference in the size of the Student class when we change the order of the
// data members (int roll_no and double weight) is due to the way the compiler aligns
// the data members and the padding it introduces for memory optimization.

// Case 1: When 'double weight' is placed above 'int roll_no', the memory layout is as follows:
// double weight (8 bytes)
// int roll_no (4 bytes)
// bool attendance (1 byte)
// (3 bytes of padding, to pick up int & bool together efficiently)
// Total: 8(double) + 4(int) + 1(bool) + 3(padding) = 16 bytes

// Case 2: When 'int roll_no' is placed above 'double weight', the memory layout is as follows:
// int roll_no (4 bytes)
// (4 bytes of padding, to pick up int efficiently)
// double weight (8 bytes)
// bool attendance (1 byte)
// (7 bytes of padding, to pick up bool efficiently)
// Total: 4(int) + 4(padding) + 8(double) + 1(bool) + 7(padding) = 24 bytes

// However, memory alignment and padding are implementation-dependent, and compilers may apply
// different strategies to optimize memory access and alignment for performance reasons.
// The actual size may vary on different systems or with different compilers.
