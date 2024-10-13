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
        cout << *it << " ";   // o/p: 10 20 30 40 50 60 70
    }
    cout << endl;

    // ii) Through foreach loop
    for(auto i: s2) {
        cout << i << " ";   // o/p: 20 30
    }
    cout << endl;

// ------------------------------------------------------------------------------------------------------------

    // 3. CAPACITY & DELETION OF SET
    size_t size = s3.size();   // you can even use 'int' instead of 'size_t'
    cout << "Size of s3: " << size << endl;   // o/p: Size of s3: 2

    bool isEmpty = s3.empty();
    cout << "s3 is empty: " << isEmpty << endl;   // o/p: s3 is empty: 0

    s3.clear();   // clears the set

    size = s3.size();   // you can even use 'int' instead of 'size_t'
    cout << "Size of s3: " << size << endl;   // o/p: Size of s3: 0
    s1.erase(30);
    for(auto it: s1) cout << it << " ";   // o/p: 10 20 40 50 60 70
    cout << endl;

    isEmpty = s3.empty();
    cout << "s3 is empty: " << isEmpty << endl;   // o/p: s3 is empty: 1

// ------------------------------------------------------------------------------------------------------------

    // 4. LOOKUP VALUE IN SET
    // i) find: Searches for an element in the set
    if(s1.find(20) != s1.end()) cout << "20 is present in set s1." << endl;   // o/p: 20 is present in set s1.
    else cout << "20 is not present in the set s1" << endl;

    // ii) count: Returns the number of elements matching the value (always 0 or 1 for set)
    size_t count = s1.count(20);
    cout << "count in set s1: " << count << endl;   // o/p: count in set s1: 1
    

    return 0;
}
