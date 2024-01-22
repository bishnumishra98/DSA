#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Algorithm: Let there be a queue{10, 20, 30, 40, 50} of size(n) = 5, k = 3.

// Step 1: pop first k elements from queue i.e., '10, 20, 30' into stack.
// Dry run:   stack = {10, 20, 30},   queue = {40, 50}

// Step 2: Pop the k elements stored in stack, i.e., '30, 20, 10' and insert them behind the queue.
// Dry run:   stack = {},   queue = {40, 50, 30, 20, 10} 

// Step 3: Pop the front (n-k) elements from queue, i.e., '40, 50' and insert them behind the queue.
// Dry run:   stack = {},   queue = {30, 20, 10, 40, 50}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
    }
    cout << endl;
}

// T.C: O(n); where n = q.size()
// S.C: O(k)
queue<int> reverseFirstKElementsInQueue(queue<int> q, int k) {
    stack <int> st;

    // Step 1: pop first k elements into stack
    int k_ = k;
    while(k_--) {
        int temp = q.front();
        st.push(temp);
        q.pop();
    }

    // Step 2: Pop the k elements stored in stack and insert them behind the queue
    while(!st.empty()) {
        int temp = st.top();
        q.push(temp);
        st.pop();
    }

    // Step 3: Pop the front (n-k) elements from queue and insert them behind the queue
    int x = q.size() - k;
    while(x--) {
        int temp = q.front();
        q.push(temp);
        q.pop();
    }

    return q;
}

int main() {
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;
    queue <int> q_reversed = reverseFirstKElementsInQueue(q, k);
    printQueue(q_reversed);

    return 0;
}
