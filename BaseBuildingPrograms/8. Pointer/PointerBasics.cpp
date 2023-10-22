#include <iostream>
using namespace std;

int main() {
//  1) Pointer variable can only store address of a variable.

//  2) Size of a pointer variable is 4 byte for 32-bit system, and 8 byte for 64-bit system.

//  3) Declaration of a pointer variable:
        // int* ptr;   // 'ptr' is a pointer to an integer variable.
        // char* ptr;   // 'ptr' is a pointer to a character variable.
        // bool* ptr;   // 'ptr' is a pointer to a boolean variable.
    
//  4) Initialize the pointer 'ptr' to the address of the integer variable 'x'.
        // int x = 10; 
        // int* ptr = &x;   // '*' is called dereferencing variable, and '&' is called referencing varible.
    
   

    // arr, &arr, &arr[0] all point to base address of an array named 'arr'

    // arr[i] and i[arr] mean the same in C/C++, as they both are internally converted
    // like this: *(arr + i) and *(i + arr) respectively, where arr = base address of array


    return 0;
}

