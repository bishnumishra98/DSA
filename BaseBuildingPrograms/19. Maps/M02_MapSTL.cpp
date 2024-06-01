#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    // 1. CREATION OF A MAP
    unordered_map<int, string> um;

// -----------------------------------------------------------------------------------------------------

    // 2. INSERTION IN A MAP: Pair type value is inserted in a map via insert() function.
    um.insert(pair<int, string>(1, "one"));

    um.insert(make_pair(2, "two"));

    um.insert({3, "three"});   // insert using initializer list

    pair<int, string> p = make_pair(4, "four");
    um.insert(p);

    pair<int, string> q(5, "five");
    um.insert(q);

    pair<int, string> r;
    r.first = 6;
    r.second = "six";
    um.insert(r);

    um[7] = "seven";   // insert using key value pair

// -----------------------------------------------------------------------------------------------------

    // 3. PRINTING VALUES OF MAP
    for(const auto& pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }

// -----------------------------------------------------------------------------------------------------

    // 4. ACCESSING ANY VALUE OF MAP
    // i.  Using [] brackets
    cout << "um[5]: " << um[5] << endl;   // Note: Never use [] brackets to search any key in map. Whenever
    // we use [] brackets, if an entry corressponding to that key is not present, an entry with value 0
    // will be created in map corressponding to that key. Thus, for searching purposes, use count() or find().
    // ii. Using at() function
    cout << "um.at(6): " << um.at(6) << endl;

// -----------------------------------------------------------------------------------------------------

    // 5. SEARCHING A KEY IN MAP
    // i.  count(): Returns 1 if key found, else returns 0.
    cout << "um.count(7): " << um.count(7) << endl;   // o/p: 1
    cout << "um.count(8): " << um.count(8) << endl;   // o/p: 0

    // ii. find(): find() takes a key as argument and returns an iterator. If key found, the iterator
    //             stops at that element, else it goes to the end position of map.
    auto it = um.find(3);

    if(it != um.end()) cout << "um(3) found. Iterator is at " << it->first << ": " << it->second << endl;
    else cout << "um(3) not found. Iterator is at end of map." << endl;

    it = um.find(9);
    if(it != um.end()) cout << "um(9) found. Iterator is at " << it->first << ": " << it->second << endl;
    else cout << "um(9) not found. Iterator is at end of map." << endl;

// -----------------------------------------------------------------------------------------------------

    // 6. PRINTING SIZE OF MAP
    cout << "Size of map: " << um.size() << endl;   // o/p: 7

// -----------------------------------------------------------------------------------------------------

    // 7. empty(): Checks whether map is empty or not
    cout << "Map empty status: " << um.empty() << endl;   // o/p: 0

// -----------------------------------------------------------------------------------------------------

    // 8. erase(): Erases element from map by key
    um.erase(2);   // erases {2, "two"} element from map
    cout << "Size of map: " << um.size() << endl;   // o/p: 6

// -----------------------------------------------------------------------------------------------------

    // 9. clear(): Removes all elements from map
    um.clear();
    cout << "Size of map: " << um.size() << endl;   // o/p: 0
    cout << "Map empty status: " << um.empty() << endl;   // o/p: 1

    return 0;
}
