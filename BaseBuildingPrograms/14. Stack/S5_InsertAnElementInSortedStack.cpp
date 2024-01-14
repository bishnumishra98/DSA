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

void solve(stack<int> &s, int X) {
    // base case
    if(s.top() < X) {
        s.push(X);
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    solve(s, X);

    // backtracking to reconstruct the original stack
    s.push(temp);
}

// T.C: 
// S.C: 
void insertElementInSortedStack(stack<int> &s, int X) {
    // If stack is empty, push the element directly into the stack
    if(s.empty()) {
        s.push(X);
        return;
    }
    
    solve(s, X);
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
