#include <iostream>
using namespace std;

int x = 10;
int y = 100;

int main() {
    int x = 20;

    {
        int x = 30;
        cout << "x = " << x << endl;
    }

    cout << "x = " << x << endl;

    cout << "global x = " << ::x << endl;   // global variables are distinguised using
                                           // scope resolution operator(::)
    cout << "y = " << y << endl;   // no distinction required as 'y' doesn't conflict with
                                  // any other variable name. So here, 'y' means global variable.

    x = 25;
    ::x = 15;   

    cout << "x = " << x << endl;
    cout << "global x = " << ::x << endl;

    return 0;
}

// Ouput of the above program:
// x = 30
// x = 20
// global x = 10
// y = 100
// x = 25
// global x = 15
