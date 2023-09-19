#include <iostream>
#include <cmath>   // for pow()
using namespace std;

//T.C: O(logn)
// S.C: O(1)
bool checkArmstrong(int n) {
    int num = n;   // keeping a backup of original number

    // counting no.of digits in number
    int count_digits = 0;
    while(n) {
        count_digits++;
        n = n / 10;
    }

    // Armstrong number logic
    n = num;   // as n became 0 in last operation, we are setting back n to its original value
    int bit, sum = 0;
    while(n) {
        bit = n % 10;
        sum = sum + round(pow(bit, count_digits));   // The pow() function in C++ returns a floating-point number, even if the inputs are integers. So better round off for precise output.
        n = n / 10;
    }
    // comparing value in sum with original number
    if(sum == num) {
        return true;
    } else {
        return false;
    }   
}

int main() {
    int n = 153;

    if(checkArmstrong(n)) {
        cout << "Armstrong number";
    } else {
        cout << "Not an Armstrong number";
    }

    return 0;
}