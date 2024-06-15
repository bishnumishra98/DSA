// Print 1 to N and N to 1 using recursion

#include <iostream>
using namespace std;

// T.C: O(n);
// S.C: O(n);
void print1ToN(int i, int n) {
    // Base case: When i exceeds n, return
    if(i > n) return;

    // Processing block
    cout << i << " ";

    // Recursive relation
    print1ToN(i+1, n);
}

// T.C: O(i);
// S.C: O(i);
void printNTo1(int i) {
    // Base case: When i becomes less than 1, return
    if(i < 1) return;

    // Processing block
    cout << i << " ";

    // Recursive relation
    printNTo1(i-1);
}

int main() {
    int i = 1;   // starting index
    int n = 5;   // no.of times you want to print
    
    print1ToN(i, n);
    cout << endl;
    printNTo1(n);

    return 0;
}
