#include <iostream>
using namespace std;

int x = 10;
int y = 100;

int main() {
    int x = 20;

    {
        int x = 30;
        cout << "x = " << x << endl;   // o/p: 30
    }

    cout << "x = " << x << endl;   // o/p: 20

    cout << "global x = " << ::x << endl;   // o/p: 10   // global variables are distinguised using
                                           // scope resolution operator(::)
    cout << "y = " << y << endl;   // o/p: 100   // no distinction required as 'y' doesn't conflict with
                                  // any other variable name. So here, 'y' means global variable.

    x = x + 5;
    ::x = ::x + 5;   

    cout << "x = " << x << endl;   // o/p: 25
    cout << "global x = " << ::x << endl;   // o/p: 15

    return 0;
}
