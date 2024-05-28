// 2 numbers can be swapped in three different ways

#include <iostream>
using namespace std;

// T.C: O(1)
// S.C: O(1)
void swapByTemp(int a, int b) {
    cout << "Swap by Temp:\n";

    int temp = a;   // temp = 2
    a = b;   // a = 3
    b = temp;   // b = 2

    cout << "a = " << a << "   " << "b = " << b;
    cout << endl << endl;
}

// T.C: O(1)
// S.C: O(1)
void swapByArithmetic_operation(int a, int b) {
    cout << "Swap by Arithmetic_operation:\n";

    a = a + b;   // 2 + 3 = 5
    b = a - b;   // 5 - 3 = 2
    a = a - b;   // 5 - 2 = 3

    cout << "a = " << a << "   " << "b = " << b;
    cout << endl << endl;
}

// T.C: O(1)
// S.C: O(1)
void swapByXOR(int a, int b) {
    cout << "Swap by XOR:\n";

    a = a ^ b;   // a = 2 ^ 3
    b = a ^ b;   // b = 2 ^ 3 ^ 3 = 2
    a = a ^ b;   // a = 2 ^ 3 ^ 2 = 3

    cout << "a = " << a << "   " << "b = " << b;
}


int main() {
    int a = 2, b = 3;
    swapByTemp(a, b);
    swapByArithmetic_operation(a, b);
    swapByXOR(a, b);   // This is fastest method to swap, because BITWISE operations are
                      // often implemented at the hardware level and are highly efficient.

    return 0;
}
