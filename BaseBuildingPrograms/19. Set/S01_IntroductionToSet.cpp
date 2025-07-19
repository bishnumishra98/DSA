// In C++, a set is a container in the Standard Template Library (STL) that stores unique elements following a specific order.
// It is of two types just like map:
// 1) Ordered Set (std::set):
//    i)   The elements are stored in a specific order (by default, in ascending order).
//    ii)  It is usually implemented as a balanced binary search tree (typically a Red-Black Tree).
//    iii) Supports passing a custom comparator to define the order of elements.

// 2) Unordered Set (std::unordered_set):
//    i)   The elements are not stored in any particular order.
//    ii)  It is usually implemented as a hash table.
//    iii) Does not support custom ordering since elements are organized based on their hash values.

// OPERATIONS COMPARISON:
// Operations    |    set        |    unordered_set
// ------------------------------------------------------------
// Insertion:    |    O(logn)    |    Avg: O(1), worst: O(n)
// Deletion:     |    O(logn)    |    Avg: O(1), worst: O(n)
// Search:       |    O(logn)    |    Avg: O(1), worst: O(n)
// Traversal:    |    O(n)       |    O(n + b);   b = no.of buckets
// Extra Info: A bucket is a container within a hash table that stores elements that hash to the same value. When
// an element is inserted into the hash table, its hash value is computed, and it is placed into the corresponding bucket.

#include <iostream>
#include <set>   // for set
#include <unordered_set>   // for unordered_set
using namespace std;


int main() {
    // 1) Ordered set
    // i) Elements are stored in ascending order by default
    set<int> s = {50, 20, 10, 30, 40, 20, 40, 50};
    for(const int& elem : s) {
        cout << elem << " ";   // o/p: 10 20 30 40 50
    }

    cout << endl;

    // ii) Elements are stored in descending order by providing a comparator 'greater<int>'
    set<int, greater<int>> s_reversed = {50, 20, 10, 30, 40, 20, 40, 50};
    for(const int& elem : s_reversed) {
        cout << elem << " ";   // o/p: 50 40 30 20 10
    }

    cout << endl;



    // 2) Unordered set: Elements are stored in random order
    unordered_set<int> us = {50, 20, 10, 30, 40, 20, 40, 50};
    for(const int& elem : us) {
        cout << elem << " ";   // o/p: 40 30 10 20 50
    }

    return 0;
}
