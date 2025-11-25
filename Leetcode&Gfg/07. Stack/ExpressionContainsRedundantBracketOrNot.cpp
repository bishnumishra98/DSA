// GFG: Expression contains redundant bracket or not   --->   Given a string of balanced expression,
// find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the
// same sub-expression is surrounded by unnecessary or multiple brackets. Expression contains
// + , - , *, and / operators along with brackets. Given expression is valid and there are no
// white spaces present. Your task is to complete the function checkRedundancy() which takes the
// string s as input and returns 1 if it contains redundant parentheses else 0.

// Example 1:
// Input:
// exp = ((a+b))
// Output:
// Yes
// Explanation:
// ((a+b)) can reduced to (a+b).

// Example 2:
// Input:
// exp = (a+b+(c+d))
// Output:
// No
// Explanation:
// (a+b+(c+d)) doesn't have any redundant or multiple brackets.

// Problem link: https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

// Algorithm:
// ● How to identify redundant brackets from naked eye ?
//   We can say that brackets are redundant if there is no operator between a pair of brackets.
//   For example:
//   ▶ (a+b) --> Not redundant
//   ▶ (a) --> Redundant
//   ▶ ((a+b)) --> Redundant, because inner brackets have operator but outer brackets don't have any operator inside it.
// ● Thereby, we can use stack to solve this problem.

// 1. Initialize an empty stack to store characters(opening bracket '(' and the operators +, -, *, /).
// 2. Traverse the given string character by character.
//    a. If the current character is an opening bracket '(' or an operator (+, -, *, /), push it onto the stack.
//    b. If the current character is a closing bracket ')':
//       i.   Initialize a boolean variable hasOperator to false. This variable will help us track if there is any
//            operator between the opening and closing brackets.
//       ii.  Pop all operators from the stack until we encounter an opening bracket '('.
//            - If we pop an operator(+, -, *, /), set hasOperator to true.
//       iii. After popping, if the stack is not empty, for sure an opening bracket '(' is present. Pop it out from satck.
//       iv.  If hasOperator is still false after popping, it means there were no operators between the brackets,
//            indicating that the brackets are redundant. In this case, return 1.
// 3. If we finish traversing the string without finding any redundant brackets, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        stack<char> st;   // stack to store characters

        for(char ch: s) {
            // Push only useful characters:
            // 1) '('
            // 2) Operators: + - * /
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            }
            else if(ch == ')') {   // if we see a closing bracket ')'
                bool hasOperator = false;   // checks if there is any operator inside the brackets

                // Pop everything until '(' is encountered
                while(!st.empty() && st.top() != '(') {
                    hasOperator = true;   // if you come inside this loop, it means there is at least one operator
                    st.pop();
                }

                // If we reach here, it means '(' has been encountered or stack may be empty. Remove the '(' from stack if exists.
                if(!st.empty()) st.pop();

                // If NO operator was inside ( ), brackets are redundant
                if(hasOperator == false) return 1;
            }
        }

        return 0;  // no redundant brackets found
    }
};

int main() {
    Solution obj;
    string s = "((a+b))";

    cout << obj.checkRedundancy(s);   // o/p: 1 (redundant brackets present)

    return 0;
}
