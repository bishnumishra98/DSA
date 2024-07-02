// A map is a collection of key-value pairs, where each key is unique and is associated with a value. Maps are used to efficiently
// store and retrieve data based on keys. In C++, the Standard Template Library (STL) provides two primary types of maps:

// 1. map or ordered map:
// -> Ordered Map: map stores elements in a balanced binary search tree (typically a Red-Black tree), ensuring
//    that keys are always sorted.
// -> Unique Keys: Each key in a map must be unique.
// -> Logarithmic Complexity: Operations such as insertion, deletion, and search have logarithmic time complexity O(logn).
// -> Usage: Useful when you need to maintain order among elements or need sorted data.

// 2. unordered_map
// -> Unordered Map: unordered_map uses a hash table to store elements, meaning the order of elements is not maintained.
// -> Unique Keys: Like map, each key in an unordered_map must be unique.
// -> Average Constant Time Complexity: Insertion, deletion, and search operations have average constant time complexity
//    O(1), but worst-case complexity can be linear O(n) if there are many hash collisions.
// -> Usage: Preferred when order is not important, and you need faster average time complexity for operations.

#include <map>   // for orderedMap
#include <unordered_map>   // for unorederedMap
#include <iostream>
using namespace std;

int main() {
    map<int, string> orderedMap;
    orderedMap[3] = "three";
    orderedMap[2] = "two";
    orderedMap[1] = "one";
    orderedMap[4] = "four";
    

    cout << "orederedMap:\n";
    for (const auto& pair : orderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

// --------------------------------------------------------------------

    unordered_map<int, string> unorderedMap;
    unorderedMap[3] = "three";
    unorderedMap[2] = "two";
    unorderedMap[1] = "one";
    unorderedMap[4] = "four";

    cout << "\nunorederedMap:\n";
    for (const auto& pair : unorderedMap) {
        cout << pair.first << ": " << pair.second << endl;   // order of printing is random in unorderedMap
    }

    return 0;
}
