// The approach of this problem is similar to 'DeleteMiddleElementOfAStack.cpp'.

// gfg: Insert an Element at the Bottom of a Stack   --->   You are given a stack St
// of N integers and an element X. You have to insert X at the bottom of the given stack.

// Example 1:
// Input:
// N = 5
// X = 2
// St = {4,3,2,1,8}
// Output:
// {2,4,3,2,1,8}
// Explanation:
// After insertion of 2, the final stack will be {2,4,3,2,1,8}.

// Example 2:
// Input:
// N = 3
// X = 4
// St = {5,3,1}
// Output:
// {4,5,3,1}
// Explanation:
// After insertion of 4, the final stack will be {4,5,3,1}.

#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    void solve(stack <int> &s, int X, int &size) {
        // Base case
        // Insert X when stack is empty, i.e., size of stack is 0.
        if(size == 0) {
            s.push(X);
            return;
        }

        size--;
        int temp = s.top();
        s.pop();

        // recursive call
        solve(s, X, size);

        // backtracking to reconstruct the original stack
        s.push(temp);
    }

    // T.C: O(n)
    // S.C: O(n)
    stack<int> insertAtBottom(stack<int> St,int X){
        if(St.empty()) {
            return St;
        }

        int size = St.size();

        solve(St, X, size);

        return St;
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
    s.push(5);
    s.push(3);
    s.push(1);

    printStack(s);

    stack<int> ans = obj.insertAtBottom(s, 4);

    printStack(ans);

    return 0;
}
