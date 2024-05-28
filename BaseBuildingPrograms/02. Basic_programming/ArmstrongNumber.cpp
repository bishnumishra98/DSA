#include <iostream>
#include <cmath>   // for pow()
using namespace std;

// T.C: O(logn)
// S.C: O(1)
bool checkArmstrong(int n) {
    int num = n;   // keeping a backup of original number inside 'num'    
    int noOfDigits = log10(n) + 1;   // counting no.of digits in number

    // Armstrong number logic
    int bit, sum = 0;
    while(n) {
        bit = n % 10;
        sum = sum + round(pow(bit, noOfDigits));   // pow() returns a floating-point number,
        // even if both arguments are integers. So better round off for precise output.
        n = n / 10;
    }

    // comparing value in sum with original number
    if(sum == num) return true;
    else return false;
}

int main() {
    int n = 153;

    if(checkArmstrong(n)) cout << "Armstrong number";
    else cout << "Not an Armstrong number";

    return 0;
}
