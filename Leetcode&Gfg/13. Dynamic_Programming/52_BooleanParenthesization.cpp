// GFG: Boolean Parenthesization   --->   You are given a boolean expression s containing
//     'T' ---> true
//     'F' ---> false 
// and following operators between symbols
//    &   ---> boolean AND
//     |   ---> boolean OR
//    ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// Note: The answer is guaranteed to fit within a 32-bit integer.

// Example 1:
// Input: s = "T|T&F^T"
// Output: 4
// Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// Example 2:
// Input: s = "T^F|F"
// Output: 2
// Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).

// Constraints:
// 1 ≤ |s| ≤ 100 

// Problem link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: 
    // S.C: 
    int countWays_recursion(string &s) {
        
    }

// -------------------------------------------------------------------------------------------------------

    
};

int main() {
    string s = "T|T&F^T";

    cout << Solution().countWays_recursion(s) << endl;

    return 0;
}
