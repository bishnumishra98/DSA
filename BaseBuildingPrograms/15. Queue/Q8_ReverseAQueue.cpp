#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> q) {
    while(!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
    }
    cout << endl;
}

// T.C: O(n)
// S.C: O(n)
void reverseQueue_iterative(queue<int>& q) {
    stack <int> st;
    // pushing all elements of queue into stack
    while(!q.empty()) {
        int temp = q.front();
        st.push(temp);
        q.pop();
    }

    // popping all elements from stack back to queue
    while(!st.empty()) {
        int temp = st.top();
        q.push(temp);
        st.pop();
    }
}

// T.C: O(n)
// S.C: O(n)
void reverseQueue_recursive(queue<int>& q) {
    // base case
    if(q.empty()) return;

    int temp = q.front();
    q.pop();

    reverseQueue_recursive(q);

    q.push(temp);
}

int main() {
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    printQueue(q);
    reverseQueue_iterative(q);
    printQueue(q);
    reverseQueue_recursive(q);
    printQueue(q);

    return 0;
}

// Note: In terms of big-O notation, there is no significant difference in the two approaches.
// However, in practical terms, the iterative approach is more memory-efficient because it
// uses a stack to store elements temporarily, whereas the recursive approach relies on the
// call stack, which may lead to a higher memory consumption.
