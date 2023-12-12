#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;   // 'p' stores address of 'a'
    int** q = &p;   // 'q' stores address of 'p'
    int*** r = &q;   // 'r' stores address of 'q'

    cout << "p = " << p << endl;   // 1004 (suppose)
    cout << "&p = " << &p << endl;   // 2004 (suppose)
    cout << "*p = " << *p << endl;   // 5

    cout << "q = " << q << endl;   // 2004
    cout << "&q = " << &q << endl;   // 3004 (suppose)
    cout << "*q = " << *q << endl;   // 1004
    cout << "**q = " << **q << endl;   // 5

    cout << "r = " << r << endl;   // 3004
    cout << "&r = " << &r << endl;   // 4004 (suppose)
    cout << "*r = " << *r << endl;   // 2004
    cout << "**r = " << **r << endl;   // 1004
    cout << "***r = " << ***r << endl;   // 5


    return 0;
}