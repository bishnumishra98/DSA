// Given a string, print each unique character of string with its frequency.

#include <iostream>
#include <map>
using namespace std;

void countCharacters(string str) {
    map<char, int> map;
    // Creating a map of (char, frequency) from the string
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        map[ch]++;
    }

    // Printing elements of map:
    /*
    for(auto i: map) {
        //code
    }
    */
    // Using auto without the reference (&) means that each element in the map is copied when the loop iterates over it.
    // For small maps and simple types, this overhead might be negligible, but for larger maps or more complex types, it
    // is more efficient to use a reference to avoid unnecessary copying.

    // Better way of printing the elements of map
    for(const auto& i: map) {
        cout << i.first << ": " << i.second << endl;
    }
    // 'const auto& i' ensures that you are not copying the elements but rather accessing them by reference. Using 'const'
    // indicates that you do not intend to modify the elements, which can help avoid accidental changes and might allow for
    // certain compiler optimizations.
}

int main() {
    string str = "aabccdefabcafedbcafedfa";
    countCharacters(str);

    return 0;
}
