#include <iostream>
#include <cmath>   // for sqrt()
using namespace std;

// T.C: O(sqrt(n))
// S.C: O(1)
bool checkPrime(int n) {
    if(n<=1) {
        return false;
    }

    // a non-prime number will always have a factor >=2 and <= sqrt(n)
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;   // found a factor
        }
    }
    
    return true;
}

int main() {
    int n = 31;

    if(checkPrime(n)) {
        cout << "Prime number";
    } else {
        cout << "Composite number";
    }

    return 0;
}