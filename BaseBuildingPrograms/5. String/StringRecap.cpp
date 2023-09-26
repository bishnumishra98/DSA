#include <iostream>
#include <vector>
using namespace std;

int main() {
    // How to find length of:

    // 1) Arrays
    int myArray[] = {1, 2, 3, 4, 5};
    int length_array = sizeof(myArray) / sizeof(myArray[0]);

    // 2) Vectors
    vector<int> myVector = {1, 2, 3, 4, 5};
    int length_vector = myVector.size();

    // 3) Strings
    string myString = "Hello, World!";
    int length_string = myString.size();   // or, myString.length();
    // cout << length_string << endl;

    
    // push and pop operations in string
    myString.push_back('a');
    cout << myString << endl;

    myString.pop_back();
    cout << myString << endl;

    return 0;
}

