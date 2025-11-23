#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// T.C: O(n)
// S.C: O(n)
void insertElementInSortedStack(stack<int> &s, int X) {
    // Base case: If stack is empty, push the element directly into the stack. Or if X is greater than
    // the top element of stack, push X into stack.
    if(s.empty() || X > s.top()) {
        s.push(X);
        return;
    }
    
    int temp = s.top();
    s.pop();

    // Recursive call
    insertElementInSortedStack(s, X);

    // Backtracking to reconstruct the original stack
    s.push(temp);
}

int main() {
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack(s);

    insertElementInSortedStack(s, 25);

    printStack(s);

    return 0;
}
