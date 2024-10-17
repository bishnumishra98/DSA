// There are many advantages of making functions in a program like it makes our code easy to read,
// modify and debug. It also saves time by avoiding rewriting the same code again. At last, its
// biggest advantage is that it provides better memory utilization of RAM.

// However, every time a function is called, it takes a lot of time in executing a series of
// instructions for tasks such as jumping to functions, saving registers, pushing arguments into
// stack and returning to the calling function. This makes a disadvantage of making a function call
// in a program, if the function size is very small. For small functions, the time needed to make
// the function call is often a lot more than the time needed to actually execute the function. 

// This is where C++ provides the option of making inline functions for small functions.

// An inline function can be thought as a wrapper of codes that is inserted wherever we need that
// function call and that wrapper is opened during the program compilation phase. Thus, inline
// fucntions are not called, they are opened during compilation phase. Note that, inline function
// is a request, not a command. The compiler may ignore the inline function request in some cases
// like if the function contains loops, switch, goto statments, or recursion or static variables.

#include <iostream>
using namespace std;

// inline function
inline void printNumber(int n) {
    cout << n << endl;
}

int main() {
    printNumber(6);
    printNumber(7);
    printNumber(8);

    return 0;
}


// Q) How is inline functions different from macros ?
// A) Inline functions and macros in C++ are both mechanisms to improve code performance by
//    avoiding the overhead associated with function calls. However, inline functions can be
//    ignored by compiler in some cases and get treated as regular functions during compilation
//    phase. Whereas, macros are expanded even before the compilation phase, i.e in the
//    pre-processing phase. Thus, they cannot be ignored by compiler.
