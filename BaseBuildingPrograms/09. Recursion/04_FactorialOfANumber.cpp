#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
int fact(int i) {
    if(i <= 1) return 1;
    return i * fact(i-1);
}

int main() {
    int n = 5;

    cout << "Factorial: " << fact(n) << endl; 

    return 0;
}
