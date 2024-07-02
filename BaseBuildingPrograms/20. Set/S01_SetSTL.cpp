#include <vector>
#include <iostream>
#include <cstddef>   // For size_t. It is an unsigned integer type. It is the type returned by the size, sizeof, count, etc.
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

// ------------------------------------------------------------------------------------------------------------

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

// ------------------------------------------------------------------------------------------------------------

    // 3. CAPACITY OF SET
    size_t size = s3.size();   // you can even use 'int' instead of 'size_t'
    cout << "Size of s3: " << size << endl;

    bool isEmpty = s3.empty();
    cout << "s3 is empty: " << isEmpty << endl;

    s3.clear();   // clears the set

    size = s3.size();   // you can even use 'int' instead of 'size_t'
    cout << "Size of s3: " << size << endl;

    isEmpty = s3.empty();
    cout << "s3 is empty: " << isEmpty << endl;

// ------------------------------------------------------------------------------------------------------------

    // 4. LOOKUP VALUE IN SET
    // i) find: Searches for an element in the set
    if(s1.find(20) != s1.end()) cout << "20 is present in set s1." << endl;
    else cout << "20 is not present in the set s1" << endl;

    // ii) count: Returns the number of elements matching the value (always 0 or 1 for set)
    size_t count = s1.count(20);
    cout << "count in set s1: " << count << endl;   // o/p: 1
    

    return 0;
}
