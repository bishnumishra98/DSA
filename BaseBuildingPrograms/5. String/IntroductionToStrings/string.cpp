#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// int main() {
//     // How to find length of:

//     // 1) Arrays
//     int myArray[] = {1, 2, 3, 4, 5};
//     int length_array = sizeof(myArray) / sizeof(myArray[0]);

//     // 2) Vectors
//     vector<int> myVector = {1, 2, 3, 4, 5};
//     int length_vector = myVector.size();

//     // 3) Strings
//     string myString = "Hello, World!";
//     int length_string = myString.size();   // or, myString.length();
//     // cout << length_string << endl;

    
//     // push and pop operations in string
//     myString.push_back('a');
//     cout << myString << endl;

//     myString.pop_back();
//     cout << myString << endl;

//     return 0;
// }


// character array
int main() {
    char ch[100];

    // cin >> ch;   // if input is "Hello world", it will be able to take only "Hello"
    // as space, tab and enter are delimeters for cin. To avoid this we use getline()
    cin.getline(ch, 100);   // delimeter for getline() is only Enter.
    // cout << ch;

    // find length of characater array
    cout << strlen(ch);

    return 0;
}

