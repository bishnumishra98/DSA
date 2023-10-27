#include <iostream>
using namespace std;

// T.C: O(2^n)
// S.C: O(2^n)
int fiboNth(int n) {
    if(n <= 0) return -1;

    // base condition
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    
    // recursive relation
    int ans = fiboNth(n-1) + fiboNth(n-2);

    return ans;    
}

int main() {

    int n = 8;   // nth term of series(0, 1, 1, 2, 3, 5, 8, 13, ...)

    cout << fiboNth(n);

    return 0;
}