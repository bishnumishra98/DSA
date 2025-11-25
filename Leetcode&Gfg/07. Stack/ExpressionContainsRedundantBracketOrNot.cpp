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
            if(ch == '(' || ch=='+' || ch=='-' || ch=='*' || ch=='/') {
                st.push(ch);
            }
            else if(ch == ')') {   // if we see a closing bracket ')'
                bool hasOperator = false;   // checks if there is any operator inside the brackets

                // Pop everything until '(' is encountered
                while(!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') hasOperator = true;
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
