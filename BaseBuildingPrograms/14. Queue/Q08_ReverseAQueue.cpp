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

// This is better than the recursive approach as it doesn't have the overhead of recursive calls
// T.C: O(n)
// S.C: O(n)
void reverseQueue_iterative(queue<int>& q) {
    stack<int> st;

    // Push all elements of queue into stack
    while(!q.empty()) {
        int temp = q.front();
        st.push(temp);
        q.pop();
    }

    // Pop all elements from stack back to queue
    while(!st.empty()) {
        int temp = st.top();
        q.push(temp);
        st.pop();
    }
}

// T.C: O(n)
// S.C: O(n)
void reverseQueue_recursive(queue<int>& q) {
    // Base case
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

