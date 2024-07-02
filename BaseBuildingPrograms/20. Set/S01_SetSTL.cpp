#include <iostream>
#include <cstddef>   // For size_t. It is an unsigned integer type. It is the type returned by the sizeof operator.
#include <set>   // for set

#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    // Insert elements
    s.insert(10);
    s.insert(20);
    s.insert(30);

    // Iterate through the set
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    if (s.find(20) != s.end()) {
        std::cout << "20 is in the set" << std::endl;
    }

    // Remove an element
    s.erase(20);

    // Size of the set
    std::cout << "Size of set: " << s.size() << std::endl;

    return 0;
}
