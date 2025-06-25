// Print 1 to N and N to 1 using both recursion and backtracking

#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
void print1ToN(int i, int n) {
    // Base case: When i exceeds n, return
    if(i > n) return;

    // Processing block
    cout << i << " ";

    // Recursive relation
    print1ToN(i+1, n);
}

// T.C: O(i)
// S.C: O(i)
void print1ToN_backtracking(int i) {
    // Base case: When i becomes less than 1, return
    if(i < 1) return;

    // Recursive relation
    print1ToN_backtracking(i-1);

    // Processing block
    cout << i << " ";
}

// ---------------------------------------------------------------

// T.C: O(i)
// S.C: O(i)
void printNTo1(int i) {
    // Base case: When i becomes less than 1, return
    if(i < 1) return;

    // Processing block
    cout << i << " ";

    // Recursive relation
    printNTo1(i-1);
}

// T.C: O(n)
// S.C: O(n)
void printNTo1_backtracking(int i, int n) {
    // Base case: When i becomes more than n, return
    if(i > n) return;

    // Recursive relation
    printNTo1_backtracking(i+1, n);

    // Processing block
    cout << i << " ";
}

int main() {
    int i = 1;   // starting index
    int n = 5;   // no.of times you want to print
    
    print1ToN(i, n);   // 1 2 3 4 5
    cout << endl;
    print1ToN_backtracking(n);   // 1 2 3 4 5
    cout << endl;
    printNTo1(n);    // 5 4 3 2 1
    cout << endl;
    printNTo1_backtracking(i, n);   // 5 4 3 2 1

    return 0;
}
