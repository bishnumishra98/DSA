// Leetcode: 1910. Remove All Occurrences of a Substring. Ex:-
// (1) i/p: s = "daabcbaabcbc", part = "abc",   o/p: "dab"
// (2) i/p: s = "axxxxyyyyb", part = "xy",   o/p: "xy"


#include <iostream>
using namespace std;

// T.C: O(k*s*p); where k = no.of occurrences of 'part' in 's', s = length of 's', p = length of 'part'
// S.C: O(s); where s = length of 's'
string removeOccurrences(string s, string part) {
    while(s.find(part) != string::npos) {   // jbtk 'part' exists in 's'
        s.erase(s.find(part), part.size());   // s.find(part) returns index of first character of 'part' in 's'
    }

    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part);

    return 0;
}