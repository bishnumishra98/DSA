#include<iostream>
using namespace std;

// T.C: O(1)
// S.C: O(1)
int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << "Result: " << setKthBit(n, k);
    return 0;
}