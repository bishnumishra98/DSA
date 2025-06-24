// gfg: Expression contains redundant bracket or not   --->   Given a string of balanced expression,
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

// Note: Please don't take this problem lightly. If else condition is very tricky.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        // code here
        stack <char> st;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];

            // if opening bracket or any operator found
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/') {
                st.push(ch);
            }
            
            // if closing bracket found
            if(ch==')') {
                int no_of_operators = 0;

                // Pop and count operators until an opening bracket is encountered
                while(!st.empty() && st.top()!='(') {
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/') {
                        // counting no.of operators between closing bracket and an opening bracket
                        no_of_operators++;
                    }
                    st.pop();
                }
                // if there we reach here, it means opening bracket '(' is found. So pop it.
                if(!st.empty()) st.pop();

                // if there are no operators between '(' and ')', redundancy brackets are present, i.e., return 1
                if(no_of_operators == 0) return 1;
            }
        }

        // if we reach here, no redundant brackets are found
        return 0;
    }
};

int main() {
    Solution obj;
    string s = "(a+b)";

    cout << obj.checkRedundancy(s);

    return 0;
}
