#include <iostream>
using namespace std;

// T.C: O(n!);   where n = size of string
// S.C: O(n);   // This function receives 'str' argument by value. Thus, it makes separate
//                 copies of 'str' which increases space complexity.
void printAllPermutation_(string str, int i) {
    int n = str.length();

    // base case
    if(i >= n){
        cout << str << " ";
        return;
    }
    
    for(int j=i; j<n; j++) {
        swap(str[i], str[j]);
        printAllPermutation_(str, i+1);   // recursive call
    }
}

// T.C: O(n!);   where n = size of string
// S.C: O(1)   // This function receives 'str' argument by reference. Thus, it does not take
//                any extra space.
void printAllPermutation(string &str, int i) {
    int n = str.length();

    // base case
    if(i >= n){
        cout << str << " ";
        return;
    }
    
    for(int j=i; j<n; j++) {
        swap(str[i], str[j]);
        printAllPermutation(str, i+1);   // recursive call
        swap(str[i], str[j]);   // backtracking to nullify the changes that were made
        // to the mother string 'str' that were made during the above swap operation
    }
}

int main() {
    string str = "abc";
    int i = 0;

    // printAllPermutation_(str, i);
    printAllPermutation(str, i);

    return 0;
}