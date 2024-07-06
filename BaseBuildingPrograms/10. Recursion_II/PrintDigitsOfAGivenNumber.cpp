#include <iostream>
#include <vector>
using namespace std;

// T.C: O(log(base10)n)
// S.C: O(log(base10)n)
void printDigits(int num, vector<int> &v) {
    // base case
    if(num == 0) {
        return;
    }

    // processing
    int digit = num % 10;
    num = num / 10;

    // recursive call
    printDigits(num, v);

    // processing
    v.push_back(digit);
}

int main() {
    int n = 4215;
    vector <int> v;

    printDigits(n, v);

    for(auto element: v) {
        cout << element << " ";
    }

    return 0;
}
