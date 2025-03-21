// Leetcode: 678. Valid Parenthesis String   --->   Given a string s containing only three types of characters:
// '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// • Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// • Any right parenthesis ')' must have a corresponding left parenthesis '('.
// • Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// • '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true

// Bruteforce algorithm: This brutforce is simple.
// 1. Call a function 'check()' with the string s, start index(0) and count(0) as arguments. This function returns a boolean value.
//    The idea is to increase count whenever we encounter '(' and decrease count whenever we encounter ')'. If we encounter '*',
//    we have 3 choices:
//    i.   Treat '*' as '(' and increase count by 1. 
//    ii.  Treat '*' as ')' and decrease count by 1.
//    iii. Treat '*' as empty character or blank and don't change the count.
//    If count becomes negative at any point, it means there is one ')' without a corresponding '('. Thus, return false stating
//    that a valid string is not possible.
// 2. Thus, when 'check()' is called, first check for the base case, if count < 0, return false. If not, then iterate through the
//    string starting from the start index. If we encounter '(', increase count by 1. If we encounter ')', decrease count by 1.
//    If we encounter '*', then call 'check()' recursively with 3 choices as mentioned above. If any of the choices return true,
//    then return true.
// 3. At the end of the loop, if count == 0, return true. Else, return false.



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(string& s, int start, int count) {
        if(count < 0) return false;
        for(int i = start; i < s.size(); i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') {
                if (count == 0) return false;
                count--;
            } else {
                return check(s, i + 1, count + 1) || check(s, i + 1, count - 1) || check(s, i + 1, count);
            }
        }
        return count == 0;
    }
public:
    // T.C: O(n * 3^m);   where n = s.length(), m = no.of asterisks in the string, 3^m = no.of possible choices for each asterisk
    // S.C: O(n)
    bool checkValidString_bruteforce(string s) {
        return check(s, 0, 0);
    }

// -----------------------------------------------------------------------------------------------------------------
};

int main() {
    Solution sol;
    cout << sol.checkValidString_bruteforce("(*))");

    return 0;
}
