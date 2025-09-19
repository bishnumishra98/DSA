// Leetcode: 8. String to Integer (atoi)   --->   Implement the myAtoi(string s) function, which converts a string to a
// 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// 1. Whitespace: Ignore any leading whitespace (" ").
// 2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// 3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the
//    string is reached. If no digits were read, then the result is 0.
// 4. Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain
//    in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1
//    should be rounded to 2^31 - 1.
// Return the integer as the final result.

// Example 1:
// Input: s = "42"
// Output: 42

// Example 2:
// Input: s = " -042"
// Output: -42

// Example 3:
// Input: s = "1337c0d3"
// Output: 1337

// Example 4:
// Input: s = "0-1"
// Output: 0

// Example 5:
// Input: s = "words and 987"
// Output: 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    int myAtoi_abstracted(string s) {
        try {
            long long num = stoll(s);   // use stoll (long long) to safely detect overflow, instead of stoi()
            if(num < INT_MIN) return INT_MIN;
            if(num > INT_MAX) return INT_MAX;
            return (int)num;
        } 
        catch(invalid_argument&) {
            return 0;   // if no valid conversion
        } 
        catch(out_of_range&) {
            if(s[0] == '-') return INT_MIN;
            return INT_MAX;
        }
    }

// --------------------------------------------------------------------------------------------------------------------

    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    int myAtoi(string s) {
        int i = 0, n = s.size();
    
        // 1. Skip spaces
        while(i < n && s[i] == ' ') i++;
        
        // 2. Handle sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits
        long result = 0;
        while(i < n && (s[i] >= '0' && s[i] <= '9')) {   // (i < n && isdigit(s[i]))
            int digit = s[i] - '0';
            
            if(result > (INT_MAX - digit) / 10) return (sign == 1) ? INT_MAX : INT_MIN;   // check overflow before adding
            
            result = result * 10 + digit;
            i++;
        }
        
        return (int)(result * sign);
    }
};


int main() {
    string s = "1337c0d3";

    cout << Solution().myAtoi_abstracted(s) << endl;
    cout << Solution().myAtoi(s);

    return 0;
}
