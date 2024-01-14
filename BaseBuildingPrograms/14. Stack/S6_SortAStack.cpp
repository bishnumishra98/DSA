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

void insertElementInSortedStack(stack<int> &s, int X) {
    // Base case
    // If stack is empty, push the element directly into the stack. Or if X is greater than
    // the top element of stack, push X into stack.
    if(s.empty() || X > s.top()) {
        s.push(X);
        return;
    }
    
    int temp = s.top();
    s.pop();

    // recursive call
    insertElementInSortedStack(s, X);

    // backtracking to reconstruct the original stack
    s.push(temp);
}

// T.C: O(nlogn)
// S.C: O(n)
void sortStack(stack<int> &s) {
    // Base case
    if(s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive relation
    sortStack(s);

    // backtracking to insert popped out elements back to the stack in sorted order
    insertElementInSortedStack(s, temp);
}

int main() {
    stack <int> s;
    s.push(50);
    s.push(20);
    s.push(40);
    s.push(10);
    s.push(30);

    printStack(s);

    sortStack(s);

    printStack(s);

    return 0;
}
