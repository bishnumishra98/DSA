#include <iostream>
#include <cmath>   // for sqrt()
using namespace std;

// T.C: O(sqrt(n))
// S.C: O(1)
bool checkPrime(int n) {
    if(n<=1) return false;   // numbers less than equal 1 are non-prime

    // a non-prime number will always have a factor between 2 and sqrt(n)
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) return false;   // found a factor, thus return false
    }
    
    // If program comes here, it means no factors are found. Thus, it is a prime number. Hence, return true.
    return true;
}

int main() {
    int n = 31;

    if(checkPrime(n)) cout << "Prime number";
    else cout << "Composite number";
    
    return 0;
}
