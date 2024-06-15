// Print 1 to N using recursion

#include <iostream>
using namespace std;

// T.C: O(n);   as print function is called n times
// S.C: O(n);   as the stack had at most five print functions in stack
void print(int i, int n) {
    // Base case: When i reaches n, return
    if(i > n) return;

    // Processing block
    cout << i << " ";

    // Recursive relation
    print(i+1, n);
}

int main() {
    int n = 5;   // no.of times you want to print
    int i = 1;   // starting index
    print(i, n);

    return 0;
}
