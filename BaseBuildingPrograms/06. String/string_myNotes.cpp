#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// // character array
// int main() {
//     char ch[100];

//     // cin >> ch;   // if input is "Hello world", it will be able to take only "Hello"
//     // as space, tab and enter are delimeters for cin. To avoid this we use getline()
//     cin.getline(ch, 100);   // delimeter for getline() is only Enter.
//     // cout << ch;

//     // find length of characater array
//     cout << strlen(ch);

//     return 0;
// }




// string
int main() {
    // How to find length of:
    // 1) Arrays
    int myArray[] = {1, 2, 3, 4, 5};
    int length_array = sizeof(myArray) / sizeof(myArray[0]);   // length_array: 5

    // 2) Vectors
    vector<int> myVector = {1, 2, 3, 4, 5};
    int length_vector = myVector.size();   // length_vector: 5

    // 3) Strings
    string myString = "Hello, World!";
    int length_string = myString.size();   // or, myString.length();
    // cout << length_string << endl;   // o/p: 13


    // Push and pop operations in string
    myString.push_back('a');
    cout << myString << endl;   // Hello, World!a

    myString.pop_back();
    cout << myString << endl;   // Hello, World!

    string substr1 = myString.substr(3);   // from 3rd index, print rest of the string
    cout << substr1 << endl;   // lo, World!

    string substr2 = myString.substr(3, 6);   // from 3rd index, print 6 characters of the string
    cout << substr2 << endl;   // lo, Wo

    {
        string str = "hola:bola";

        string sub_str = str.substr(str.find(':')+1,4);

        cout << sub_str;   // bola
    }

    return 0;
}


