// What is atoi() function in C++ ?
// The atoi() function in C++ is used to convert a string (which represents a number) into its integer equivalent.
// The function is part of the C standard library and is included in the <cstdlib> header file. It takes a C-style
// string (const char*) as input and returns its integer value (int).
// If the string does not contain a valid integer representation, the function returns 0.


#include <iostream>
#include <cstdlib>   // for atoi
#include <string>
using namespace std;

int main() {
    string s1 = "456";
    string s2 = "   -789";
    string s3 = "42abc";   // stops conversion at 'a'
    string s4 = "abc42";   // no valid conversion, returns 0

    int num1 = atoi(s1.c_str());
    int num2 = atoi(s2.c_str());
    int num3 = atoi(s3.c_str());
    int num4 = atoi(s4.c_str());

    cout << num1 << "\n";  // o/p: 456
    cout << num2 << "\n";  // o/p: -789
    cout << num3 << "\n";  // o/p: 42
    cout << num4 << "\n";  // o/p: 0
    
    return 0;
}
