// Leetcode: 476. Number Complement   --->   The complement of an integer is the integer you get when you flip all
// the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

// Example 1:
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

// Example 2:
// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(log(base2)(num))
    // S.C: O(1)
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        
        // Build a mask with all bits as 1. Ex: For num = 5, binary equivalent is 101. Thus, the mask must be: 111
        while(temp) {
            mask = (mask << 1) | 1; 
            temp = temp >> 1;
        }
        
        return num ^ mask;   // XOR the number with the mask to get the complement
    }
};


int main() {
    Solution sol;
    int num = 5;
    cout << sol.findComplement(num);

    return 0;
}
 