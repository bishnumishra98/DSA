// Leetcode problem 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include<iostream>
#include<limits.h>   // for INT_MAX and INT_MIN
using namespace std;

// T.C: O(logx)
// S.C: O(1)
int reverse(int x) {
    if(x <= INT_MIN) {
        return 0;
    }

    bool isNeg = false;
    if(x < 0) {
        isNeg = true;
        x = -x;
    }
    
    int num = x, bit, ans = 0;
    while(x > 0) {
        if(ans > INT_MAX/10) {
            return 0;
        }
        // main logic for reversing integer
        bit = x % 10;
        ans =  (ans * 10) + bit;
        x = x / 10;
    }

    return isNeg ? -ans : ans;
}

int main() {
    int n;
    cin >> n;
    cout << "Reversed integer: " << reverse(n);
}