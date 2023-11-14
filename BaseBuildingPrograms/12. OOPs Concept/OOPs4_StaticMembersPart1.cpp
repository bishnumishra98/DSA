// There are 3 types static members in C+ :
// 1) static local/global variables
// 2) static member variables
// 3) static member functions

// Below is the illustration for static local/global variables:

#include <iostream>
using namespace std;

static int y;   // static global variable

void manipulateY() {
    cout << "y inside manipulateY = " << y << endl;
    y = y + 10;
}

void manipulateX() {
    static int x = 5;   // static local variable
    cout << "x inside manipulateX = " << x << endl;
    x = x + 5;
}

int main() {
// Properties of Static local variables:

// 1) By default initialized to 0.

// 2) Accessible throughout the entire block and its nested blocks where it is declared. Example:
        static int a;   // static local variable
        cout << "First a = " << a << endl;   // o/p: 0
        {
            a = a + 2;
            cout << "Second a = " << a << endl;   // o/p: 2
            {
                a = a + 2;
                cout << "Third a = " << a << endl;   // o/p: 4
            }
        }        

        {
            static int b = 10;   // static local variable
            cout << "First b = " << b << endl;   // o/p: 10
        }

        // b = b * 2;   // compilation error, because scope of b is within the above block only.

// 3) It retains its value between function calls. Example:
        manipulateX();   // o/p: 5
        manipulateX();   // o/p: 10
        // x = x + 5;   // compilation error, because scope of x is within manipulateX() only.
        manipulateX();   // o/p: 15



// Properties of Static global variables:

// 1) By default initialized to 0.

// 2) Accessible throughout the entire source file where it is declared. Example:
        cout << "First y = " << y << endl;   // o/p: 0

// 3) It retains its value between function calls. Example:
        manipulateY();   // o/p: 0
        manipulateY();   // o/p: 10
        y = y + 10;   // works fine, because of y is within this source file.
        manipulateY();   // o/p: 30


    return 0;
}

