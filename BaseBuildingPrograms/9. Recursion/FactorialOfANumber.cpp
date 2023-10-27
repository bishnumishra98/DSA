#include <iostream>
using namespace std;

// T.C: O(n)
// S.C: O(n)
int fact(int n) {
    if(n < 0) return -1;

    //base case
    if(n==0 || n==1) {
        return 1;
    }

    // recursive relation
    int ans = n * fact(n-1);
    return ans;
}

int main() {
    int n = -6;

    cout << "Factorial: " << fact(n) << endl; 

    return 0;
}