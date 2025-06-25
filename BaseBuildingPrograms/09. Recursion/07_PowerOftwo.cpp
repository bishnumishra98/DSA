#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
int pow(int n) {
    if(n < 0) return -1;

    // base case
    if(n==0) {
        return 1;
    }

    // recursive relation
    int ans = 2 * pow(n-1);

    return ans;
}

int main() {
    int power = 8;

    cout << "2 raised to the power " << power << " is: " << pow(power);

    return 0;
}
