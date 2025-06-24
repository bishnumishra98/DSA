// Have a look at 'BaseBuildingPrograms\14. Stack\S4_FindMiddleElementOfStack.cpp' before this problem.

// gfg: Delete middle element of a stack   --->   Given a stack, delete the middle element of the
// stack without using any additional data structure.
// Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.
// Note: The output shown by the compiler is the stack from top to bottom.

// Example 1:
// Input: 
// Stack = {10, 20, 30, 40, 50}
// Output:
// ModifiedStack = {10, 20, 40, 50}
// Explanation:
// If you print the stack the bottom-most element will be 10 and the top-most element will be 50.
// Middle element will be element at index 3 from bottom, which is 30. Thus, deleting 30.

// Example 2:
// Input: 
// Stack = {10 20 30 40}
// Output:
// ModifiedStack = {10 30 40}
// Explanation:
// If you print the stack the bottom-most element will be 10 and the top-most element will be 40.
// Middle element will be element at index 2 from bottom, which is 20. Thus, deleting 20.

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    public:
    void solve(stack <int> &s, int &pos) {
        // base case
        if(pos == 1) {
            s.pop();
            return;
        }

        pos--;
        int temp = s.top();   // storing top element of stack in 'temp' variable
        s.pop();

        // recursive call
        solve(s, pos);

        // backtracking to ensure that the original stack gets reconstructed in the end of the program
        s.push(temp);
    }

    // T.C: O(n)
    // S.C: O(n)
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        if(s.empty()) {
            return;
        }

        int pos = sizeOfStack/2 + 1;

        solve(s, pos);
    }
};

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Solution obj;
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int size = s.size();

    obj.deleteMid(s, size);

    printStack(s);
    
    return 0;
}
