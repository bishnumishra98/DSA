// Leetcode: 791. Custom Sort String   --->   You are given two strings order and s. All the
// characters of order are unique and were sorted in some custom order previously. Permute the
// characters of s so that they match the order that order was sorted.

// Example 1:
// Input: order = "cba", s = "abcd"
// Output: "cbad"

// Example 2:
// Input: order = "cbafg", s = "abcd"
// Output: "cbad"

#include <iostream>
#include <algorithm>   // for sort()
using namespace std;

string str;   // global declaration of 'str'

bool customComparator(char c1, char c2) {
    return (str.find(c1) < str.find(c2));
}

// leetcode given function
// T.C: O(nlogn);   because T.C of sort() in C++ is O(nlogn)
// S.C: O(m);   where m = order.size()
string customSortString(string order, string s) {
    str = order;
    sort(s.begin(), s.end(), customComparator);
    return s;
}

int main() {
    string order = "cbafg", s = "abcd";

    cout << customSortString(order, s);
    
    return 0;
}