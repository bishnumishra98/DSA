#include <iostream>
using namespace std;

// T.C: O(log(base10)n)
// S.C: O(log(base10)n)
void printDigits(int num) {
    // base case
    if(num == 0) {
        return;
    }

    // processing
    int digit = num % 10;
    num = num / 10;

    // recursive call
    printDigits(num);

    // processing
    cout << digit << " ";
}

int main() {
    int n = 4215;

    printDigits(n);

    return 0;
}