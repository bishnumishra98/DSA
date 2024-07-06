// Queue works on FIFO(first in first out) principal. Pushing an element in queue is called an
// 'enqueue' operation, while popping out an element from queue is called 'dequeue' operation.

#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Note: We are using STL implementation of queue
    // creation of int and string type stack
    queue <int> q;
    queue <string> q1;

    // Basic queue operations: push(), pop(), size(), empty(), front(), back()
    cout << "Queue empty status: " << q.empty() << endl;   // 1
    cout << "Pushed 10, 20, 30, 40 in queue" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Queue empty status: " << q.empty() << endl;   // 0
    cout << "Size: " << q.size() << endl;   // 4
    cout << "Popped one element from queue" << endl;
    q.pop();
    cout << "Front/First element: " << q.front() << endl;   // 20
    cout << "Rear/last element: " << q.back() << endl;   // 40
    
    return 0;
}
