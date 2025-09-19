// ● What is atoi() function in C++ ?
//   The atoi() function in C++ is used to convert a string (which represents a number) into its integer equivalent.
//   The function is part of the C standard library and is included in the <cstdlib> header file. It takes a C-style
//   string (const char*) as input and returns its integer value (int).
//   If the string does not contain a valid integer representation, the function returns 0.

// ● What is stoi() function in C++ ?
//   The stoi() function in C++ is used to convert a string (which represents a number) into its integer equivalent.
//   The function is part of the C++ standard library and is included in the <string> header file. It takes a C++ string
//   (std::string) as input and returns its integer value (int).
//   If the string does not contain a valid integer representation, the function throws an invalid_argument exception.

// ● What is to_string() function in C++ ?
//   The to_string() function in C++ is used to convert a numeric value (like int, float, double, etc.) into its string
//   representation. The function is part of the C++ standard library and is included in the <string> header file.
//   It takes a numeric value as input and returns its string equivalent (std::string).


#include <iostream>
#include <cstdlib>   // for atoi
#include <string>   // for stoi
using namespace std;

int main() {
    // ● Converting string to integer
    string s1 = "456";
    string s2 = "   -789";
    string s3 = "42abc";
    string s4 = "abc42";

    int num1 = atoi(s1.c_str());
    int num2 = atoi(s2.c_str());
    int num3 = atoi(s3.c_str());
    int num4 = atoi(s4.c_str());

    cout << num1 << "\n";  // o/p: 456
    cout << num2 << "\n";  // o/p: -789
    cout << num3 << "\n";  // o/p: 42 (stops conversion at 'a')
    cout << num4 << "\n";  // o/p: 0 (no valid conversion)

    cout << stoi(s1) << "\n";  // o/p: 456
    cout << stoi(s2) << "\n";  // o/p: -789
    cout << stoi(s3) << "\n";  // o/p: 42 (stops conversion at 'a')
    cout << stoi(s4) << "\n";  // o/p: throws invalid_argument exception


    // ● Converting integer to string
    int num1 = 12;
    cout << to_string(num1) + "34" << endl;   // o/p: "1234"

    return 0;
}



// atoi() vs stoi():
// | Feature                | atoi()                        | stoi()
// | -----------------------| ----------------------------- | -----------------------------------------------
// | Header                 | <cstdlib>                     | <string>
// | Input type             | const char* (C-style string)  | string (C++ string)
// | Error handling         | No error handling → returns 0 | Throws exceptions:
// |                        | if input was 0 or invalid.    | • invalid_argument → if no conversion possible.
// |                        |                               | • out_of_range → if value doesn’t fit in 'int'.
// | Range check            | No (undefined behavior if     | Yes (checks if result fits in 'int')
// |                        | number is too large/small)    |
// | Introduced             | C standard library (very old) | C++11
// | Preferred in modern C++| unsafe, outdated              | safe, modern
