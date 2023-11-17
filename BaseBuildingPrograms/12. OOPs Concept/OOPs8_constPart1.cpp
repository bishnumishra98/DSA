// const keyword in C++ is used to declare constants and to specify that an identifier's value
// cannot be modified throughout its scope.

// In this module, we will see const with data and pointers.

#include <iostream>
using namespace std;

int main() {
    int x = 10;
    // In dynamic memory allocation, we can typically have 4 scenarios while working with data and pointer:

    // 1) NON const DATA, NON const POINTER:
    int *a1 = new int(5);   // *a1 is a pointer that points to a memory location that stores '5'
    *a1 = *a1 + 2;   // data manipulated here
    cout << "*a1 = " << *a1 << endl;
    a1 = &x;   // pointer manipulated here, i.e. now 'a1' points to a new memory location 'x'
    cout << "*a1 = " << *a1 << endl << endl;

    // 2) const DATA, NON const POINTER
    const int *a2 = new int(5);
    // *a2 = *a2 + 2;   // data cannot be manipulated as 'a2' is pointing to constant data
    cout << "*a2 = " << *a2 << endl; 
    a2 = &x;   // pointer manipulated here, i.e. now 'a2' points to a new memory location 'x'
    cout << "*a2 = " << *a2 << endl << endl;

    // 3) NON const DATA, const POINTER
    int *const a3 = new int(5);
    *a3 = *a3 + 2;   // data manipulated here
    cout << "*a3 = " << *a3 << endl << endl;
    // a3 = &x;   // pointer cannot be manipulated as pointer is constant

    // 4) const DATA, const POINTER
    const int *const a4 = new int(5);
    // *a4 = *a4 + 2;   // data cannot be manipulated as 'a4' is pointing to constant data
    cout << "*a4 = " << *a4;
    // a4 = &x;   // pointer cannot be manipulated as pointer is constant

    return 0;
}