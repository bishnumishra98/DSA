#include <iostream>
using namespace std;

// T.C: O(1)
// S.C: O(1)
bool checkEven1(int n) {
    return n % 2 == 0;
}

// T.C: O(1)
// S.C: O(1)
bool checkEven2(int n) {
    return (n & 1) == 0;
}


int main() {
    int n = 5;

    if(checkEven2(n)) {
        cout << "Even number";
    } else {
        cout << "Odd number";
    }

    return 0;
}
