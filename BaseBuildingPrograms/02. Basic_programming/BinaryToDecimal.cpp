#include <iostream>
#include <cmath>   // for pow
using namespace std;

// T.C: O(logn)
// S.C: O(1)
int BinaryToInt(long long n) {
    int bit, i = 0, ans = 0;

    while(n) {
        bit = n % 10;   // kicking out last bit of binary number
        ans = ans + (bit * round(pow(2, i)));
        n = n / 10;
        i++;
    }

    return ans;
}

int main() {
    long long n = 1001;
    cout << "Decimal representation: " << BinaryToInt(n);

    return 0;
}
