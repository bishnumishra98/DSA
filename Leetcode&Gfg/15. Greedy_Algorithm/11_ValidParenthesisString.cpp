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

    // Optimal approach algorithm: The idea is inspired by brute force. The idea is to keep track of minimum and maximum
    // value of count. If we encounter a '(', then we used to increment count. If we encounter a ')', then we used to decrement
    // count. If we encounter '*', then we had 3 choices which would make the count either increase(+1), decrease(-1) or remain
    // the same(+0). So instead of maintaining a count, we will be maintaining a range of count (from count - 1 to count + 1).
    // So the minimum value of count will be count - 1, and maximum value of count will be count + 1.
    // 1. Initialize min and max value of count to 0.
    // 2. Iterate through the string. For each character, do the following:
    //    i.   If character is '(':
    //            Increment both min and max value of count by 1.
    //    ii.  Else if character is ')':
    //            Decrement both min and max value of count by 1.
    //    iii: Else if character is '*':
    //            Decrement min value of count by 1 and increment max value of count by 1 as we have 3 choices for '*'
    //            as discussed above.
    //    iv. If Maximum value of count is negative:
    //            It means that there are more ')' than '(' and '*' in the string. Thus, return false stating that a valid string
    //            is not possible.
    //    v. If minimum value of count is negative:
    //            It means that max value is still >= 0, otherwise we would have returned from above only. Only min value has come
    //            down to negative. It can only happen is a '*' is encountered and is treated as ')'. Thus, there is no use of
    //            considering '*' as ')', as a valid string is not possible. So, explore the other minimum value of count, i.e.,
    //            an empty character or blank. Thus, set the min value of count to 0.
    // 3. At the end of the loop, if range of count is within 0 to +ve number, it means a valid string is possible. Thus, check if
    //    the minimum value of count is 0. If it is 0, return true. Else, return false.

    // T.C: O(n);   where n = s.length()
    // S.C: O(1)
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for(char c : s) {
            if(c == '(') {
                min++;
                max++;
            } else if (c == ')') {
                min--;
                max--;
            } else {
                min--;
                max++;
            }
            if(max < 0) return false;
            if(min < 0) min = 0;
        }

        return min == 0;
    }
};

int main() {
    Solution sol;
    cout << sol.checkValidString_bruteforce("(*))") << endl;
    cout << sol.checkValidString("(*))");

    return 0;
}
