#include <iostream>
using namespace std;

int main() {
//  1) Pointer variable can only store address of a variable.

//  2) Declaration of a pointer variable:
        // int* ptr;   // 'ptr' is a pointer to an integer variable.
        // char* ptr;   // 'ptr' is a pointer to a character variable.
        // bool* ptr;   // 'ptr' is a pointer to a boolean variable.
    
//  3) Initialize the pointer 'ptr' to the address of the integer variable 'x'.
        // int x = 10; 
        // int* ptr = &x;
        
//  4) '*' is called dereferencing variable, and '&' is called referencing varible.
        // int x = 10;
        // int* ptr = &x;
        // cout << "Value inside x: " << x << endl;   // o/p: 10
        // cout << "Address of x: " << &x << endl;   // o/p: 0x61ff0c
        // cout << "Value inside ptr: " << ptr << endl;   // o/p: 0x61ff0c
        // cout << "Address of ptr: " << &ptr << endl;   // o/p: 0x61ff08
        // cout << "*ptr: " << *ptr << endl;   // o/p: 10, i.e. '*ptr' means value stored at address stored in 'ptr'
        // cout << "*x: " << *x << endl;   // error bacause dereferencing variable can be used only with pointer variables, not regular variables

//  5) Size of a pointer in C++ depends on a variety of factors, including the target platform's
//     architecture, compiler implementation, and memory organization. However, on most platforms,
//     including those based on x86-64 architecture, pointers are typically 8 or 4 bytes in size support
//     the larger address space enabled by 64-bit memory address. Thus, always remember that size of a
//     pointer variable never depends on data type of pointer.
        // int a = 5;
        // int* ptr1 = &a;

        // long b = 10;
        // long* ptr2 = &b;

        // char ch = 'k';
        // char* ptr3 = &ch;

        // cout << "Size of ptr1: " << sizeof(ptr1) << endl;   // o/p: 4
        // cout << "Size of ptr2: " << sizeof(ptr2) << endl;   // o/p: 4
        // cout << "Size of ptr3: " << sizeof(ptr3) << endl;   // o/p: 4

//  6) Wild pointers: Pointers just declared, but uninitialized to address of any variable by programmer.
        // int* p;   // p is a wild pointer. It is pointing to an unknown memory location.
        // // Thus, p will store address of an unknown memory location due to which we got access to
        // // a memory location that does not belongs to our program.
        // cout << *p << endl;   // This may give run time error called Segmentation Fault (SIGSEGV).

        // // How to avoid creation of wild pointers ?
        // // We can avoid creating a wild pointer by initializing to 0th memory location or NULL (a keyword).
        // // This type of pointer is called a null pointer. Severals ways to initialize a null pointer are:
        // int* p = 0;   // This method assigns the integer constant 0 to the pointer variable p. This is equivalent to assigning the NULL macro to p, because NULL is defined to be 0.
        // int* p = NULL;   // This method assigns the NULL macro to the pointer variable p.
        // int* p = nullptr;   // This method assigns the nullptr keyword to the pointer variable p. nullptr is a C++11 keyword that was added to provide a more explicit way to create a null pointer.


    
   

    // arr, &arr, &arr[0] all point to base address of an array named 'arr'

    // arr[i] and i[arr] mean the same in C/C++, as they both are internally converted
    // like this: *(arr + i) and *(i + arr) respectively, where arr = base address of array


    return 0;
}

