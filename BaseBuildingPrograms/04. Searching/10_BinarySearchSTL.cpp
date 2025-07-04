// In C++, the Standard Template Library (STL) provides several functions related to binary search operations,
// which work efficiently on sorted ranges. These functions are part of the <algorithm> header. Here's a list of
// the most important ones:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 5, 5, 7, 9};
    int target = 5;

    // 1. binary_search(): Checks if a value exists in a sorted range. Returns true if found, false otherwise.
    if(binary_search(v.begin(), v.end(), target)) cout << target << " is found" << endl;
    else cout << target << " is not found" << endl;

    // 2. lower_bound(): Returns an iterator to the first element greater than or equal to the given target.
    //                   It works in logarithmic time on sorted ranges.
    auto it1 = lower_bound(v.begin(), v.end(), target);
    if(it1 != v.end()) cout << "First element >= " << target << " is " << *it1 << endl;
    else cout << "No element is >= " << target << endl;

    // 3. upper_bound(): Returns an iterator to the first element greater than the given target
    //                   It also works in logarithmic time on sorted ranges.
    auto it2 = upper_bound(v.begin(), v.end(), target);
    if(it2 != v.end()) cout << "First element > " << target << " is " << *it2 << endl;
    else cout << "No element is > " << target << endl;


    return 0;
}
