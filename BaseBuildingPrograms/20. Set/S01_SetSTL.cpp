#include <vector>
#include <iostream>
#include <cstddef>   // For size_t. It is an unsigned integer type. It is the type returned by the sizeof operator.
#include <set>   // for set

#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {60, 50, 70};
    int n = 3;
    vector<int> v = {20, 30};
    
    // 1. CREATION OF SET: Set can be created from 3 types of constructors:
    // i) Create set using default constructor and insert values in it using insert() function:
    set<int> s1;
    s1.insert(50);
    s1.insert({40, 10});
    s1.insert(v.begin(), v.end());   // inserting a vector 'v' in set
    s1.insert(arr, arr+n);   // inserting a arr 'arr' in set


    // ii) Range constructor:
    set<int> s2(v.begin(), v.end());   // if you want to initialize s2 with array: set<int> s2(arr, arr+n);

    // iii) Copy constructor:
    set<int> s3(s2);   // 's3' is copy of 's2'

// --------------------------------------------------------------------------------------

    // 2. ACCESSING VALUES OF SET
    // i) Through iterators
    for(auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // ii) Through foreach loop
    for(auto i: s2) {
        cout << i << " ";
    }
    cout << endl;

    

    return 0;
}
