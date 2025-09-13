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
    // T.C: O(max(len(a),len(b)))
    // S.C: O(max(len(a),len(b)))
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Iterate while there are digits in either string or there is a carry
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;   // start with the carry value
            if (i >= 0) sum += a[i--] - '0';   // add the digit of a at ith index and move the pointer
            if (j >= 0) sum += b[j--] - '0';   // add the digit of b at jth index and move the pointer
            carry = sum / 2;   // update the carry (1 if sum is 2 or more, otherwise 0)
            result += (sum % 2) + '0';   // append the current digit (sum % 2) to the result
        }

        // Reverse the result string as it is built in reverse order
        reverse(result.begin(), result.end());
        return result;
    }
};

// Why a[i--] - '0' ?
// The expression "- '0'" is used to convert a character representing a digit (e.g., '0', '1', ..., '9') to its
// corresponding integer value.
// '0' -> ASCII value 48
// '1' -> ASCII value 49
// '2' -> ASCII value 50
// '9' -> ASCII value 57

// '1' - '0' becomes 49 - 48, which is 1.
// '5' - '0' becomes 53 - 48, which is 5.

int main() {
    Solution sol;
    string s1 = "11";
    string s2 = "1";

    cout << sol.addBinary(s1, s2);

    return 0;
}
