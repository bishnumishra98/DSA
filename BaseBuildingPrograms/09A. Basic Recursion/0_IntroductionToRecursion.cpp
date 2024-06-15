// A function calling itself is called recursion.

// There are 3 parts of every recursive program :-

// 1) Base case: It is a mandatory step. If this step is missed, program results in run-time memory overflow or stack overflow.
//               It tells the program where to stop.

// 2) Recursive relation / recursive call: It is also a mandatory step. It calls next function in stack.

// 3) Processing: This part is not required for some programs. It is basically a processing block of code.

#include <iostream>
using namespace std;

// T.C: O(n);   as print function is called n times
// S.C: O(n);   as the stack had at most five print functions in stack
void print(string str, int n, int i) {
    // Base case: When i reaches n, return
    if(i >= n) return;

    // Processing block
    cout << "Here i: " << i << ", ";
    cout << str << endl;

    // Recursive relation
    print(str, n, i+1);
}

int main() {
    string str = "Bishnu";
    int n = 5;   // no.of times you want to print
    int i = 0;   // starting index
    print(str, n, i);

    return 0;
}
