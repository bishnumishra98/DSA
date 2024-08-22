#include <iostream>
#include <cmath>   // for pow
using namespace std;

// T.C: O(log(base 2)n)
// S.C: O(1)
long long intToBinary(int n) {
    long long ans = 0;
    int i = 0;
    
    while(n) {
        int bit = n & 1;   // kicking out last bit from binary equivalent of decimal number
        ans = ans + (bit * round(pow(10, i)));
        n = n >> 1;
        i++;
    }

    return ans;
}

int main() {
    int n = 8;
    cout << "Binary representation: " << intToBinary(n);

    return 0;
}
