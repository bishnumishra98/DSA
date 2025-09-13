// Leetcode 67. Add Binary   --->   Given two binary strings a and b, return their sum as a binary string.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(max(n1, n2));   n1 = length of string a;   n2 = length of string b
    // S.C: O(1);   as the result string is not considered in space complexity
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        int carry = 0;
        string result = "";

        int i = n1 - 1;
        int j = n2 - 1;
        
        while(i >= 0 && j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
            i--;
            j--;
        }
        
        while(i >= 0) {
            int sum = (a[i] - '0') + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
            i--;
        }
        
        while(j >= 0) {
            int sum = (b[j] - '0') + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
            j--;
        }
        
        while(carry) {
            result.push_back((carry % 2) + '0');
            carry /= 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "11";
    string s2 = "1";

    cout << sol.addBinary(s1, s2);

    return 0;
}
