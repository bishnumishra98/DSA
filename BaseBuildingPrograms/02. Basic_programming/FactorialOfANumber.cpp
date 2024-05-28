#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(1)
long fact(int n) {
    if(n<0) return 0;

    long ans = 1;
    for(int i=1; i<=n; i++) {
        ans = ans * i;
    }

    return ans;
}

int main() {
    int n = 5;
    cout << "Factorial: " << fact(n);

    return 0;
}
