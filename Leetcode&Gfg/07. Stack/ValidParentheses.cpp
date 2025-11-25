// Leetcode: 20. Valid Parentheses   --->   Given a string s containing just the characters '(', ')',
// '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{') {   // if opening brackets found
                st.push(ch);
            } else {   // if closing brackets found
                if(!st.empty()) {
                    if((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{')) {
                        st.pop();
                    } else {
                        // If closing brackets found, but none of the above if conditions matched,
                        // it means a closing bracket doesn't have its corresponding opening bracket.
                        return false;
                    }
                } else {
                    // Stack is empty, but closing bracket found.
                    return false;
                }
            }
        }

        // After complete traversal of string, if stack is empty, then valid parentheses; else invalid.
        if(st.empty()) return true;
        else return false;
    }
};

int main() {
    Solution obj;
    string s = "(])";

    cout << obj.isValid(s);   // o/p: 0 (false)

    return 0;
}
