#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// A custom comparator is a user-defined function or function object that defines the sorting criteria for containers such as
// sort, priority_queue, set, and map. A comparator specifies how elements are compared during sorting or ordering operations.

// You can create comparators in C++ using functions, functors, or lambdas.
// Each approach has its use cases and benefits:
// -> Functions are simple and straightforward.
// -> Functors are more flexible and can maintain state.
// -> Lambdas are concise and can capture variables from the enclosing scope.

// ------------------------------------------------------------------------------------

// 1. USING A FUNCTION
bool compare(int a, int b) {   // Comparator function
    return a < b;   // Ascending order
}

// 2. USING A FUNCTOR (FUNCTION OBJECT)
struct Compare {   // Comparator functor. Note: Instead of 'struct', we can even use 'class'.
    bool operator()(int a, int b) {
        return a < b;   // Ascending order
    }
};

int main() {
    vector<int> vec = {4, 2, 5, 1, 3};
    
    // 1. USING A FUNCTION
    // sort(vec.begin(), vec.end(), compare);

    // 2. USING A FUNCTOR
    // sort(vec.begin(), vec.end(), Compare());

    // 3. USING A LAMBDA EXPRESSION
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return a < b;   // Ascending order
    });
    
    for(int num : vec) {
        cout << num << " ";
    }
    return 0;
}
