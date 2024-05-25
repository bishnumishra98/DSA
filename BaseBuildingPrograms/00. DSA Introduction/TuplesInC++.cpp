// A tuple is a fixed-size collection of heterogeneous values, meaning that each element in a tuple can be of a different type.
// The size of a tuple is determined at compile-time and cannot be changed.

#include <iostream>
#include <tuple>
using namespace std;

int main() {
    // Create a tuple (Way 1)
    // Direct Instantiation
    tuple<int, string, double> myTuple(1, "example", 3.14);

    // Access elements of the tuple
    cout << "Integer value: " << get<0>(myTuple) << endl;
    cout << "String value: " << get<1>(myTuple) << endl;
    cout << "Double value: " << get<2>(myTuple) << endl;

    // Modify elements of the tuple
    get<0>(myTuple) = 42;
    get<1>(myTuple) = "new value";
    get<2>(myTuple) = 2.71;

    // Print modified tuple
    cout << "Modified integer value: " << get<0>(myTuple) << endl;
    cout << "Modified string value: " << get<1>(myTuple) << endl;
    cout << "Modified double value: " << get<2>(myTuple) << endl;

    // Get the size of the tuple
    constexpr size_t tupleSize = tuple_size<decltype(myTuple)>::value;
    cout << "Size of tuple: " << tupleSize << endl;

    // Create a tuple (Way 2)
    // Utility function to create a tuple object from the provided arguments. In this method, the
    // 'make_tuple' function automatically deduces the types of the elements from the provided values.
    auto personInfo = make_tuple(25, "Bishnu", 78);

    // print the above 'personInfo' tuple
    cout << "personInfo: " << get<0>(personInfo) << " " << get<1>(personInfo) << " " << get<2>(personInfo) << endl;

    return 0;
}
