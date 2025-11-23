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
    if(s.empty() || X > s.top()) {
        s.push(X);
        return;
    }
    
    int temp = s.top();
    s.pop();

    insertElementInSortedStack(s, X);
    s.push(temp);
}

// T.C: O(n^2) due to nested recursion
// S.C: O(n) due to recursion stack
void sortStack(stack<int> &s) {
    // Base case: If stack is empty, return
    if(s.empty()) return;

    int temp = s.top();
    s.pop();

    // Recursive relation
    sortStack(s);

    // Backtracking to insert popped out elements back to the stack in sorted order
    insertElementInSortedStack(s, temp);
}

int main() {
    stack <int> s;
    s.push(50);
    s.push(20);
    s.push(40);
    s.push(10);
    s.push(30);

    printStack(s);   // o/p: 30 10 40 20 50

    sortStack(s);

    printStack(s);   // o/p: 50 40 30 20 10

    return 0;
}
