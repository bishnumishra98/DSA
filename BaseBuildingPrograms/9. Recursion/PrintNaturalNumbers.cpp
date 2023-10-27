#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
void printNaturalNumbers(int n) {
    if(n <= 0) cout << "-1";

    // base case
    if(n==1) {
        cout << n << " ";
        return;
    }

    // processing
    cout << n << " ";

    // recursive relation
    printNaturalNumbers(n-1);
}

int main() {
    int n = 10;

    printNaturalNumbers(n);

    return 0;
}