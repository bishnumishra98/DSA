// Deque (Double Ended Queue) is a linear data structure that allows insertion and deletion of elements from both ends
// (front and rear). It is implemented using the STL (Standard Template Library) in C++.

#include <iostream>
#include <deque>   // double-ended queue
using namespace std;

void printDeque(deque<int> dq) {
    cout << "dq: ";
    // for(int value : dq) {
    //     cout << value << " ";
    // }
    while(!dq.empty()) {
        int temp = dq.front();
        cout << temp << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main() {
    deque<int> dq;

    cout << "Pushing 10, 20, 30 at rear:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    printDeque(dq);   // o/p: 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // o/p: 10
    cout << "dq.back(): " << dq.back() << endl << endl;   // o/p: 30

    cout << "Pushing 40, 50, 60 at front:\n";
    dq.push_front(40);
    dq.push_front(50);
    dq.push_front(60);
    printDeque(dq);   // o/p: 60 50 40 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // o/p: 60
    cout << "dq.back(): " << dq.back() << endl << endl;   // o/p: 30

    cout << "Popping 1 element from front:\n";
    dq.pop_front();
    printDeque(dq);   // o/p: 50 40 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // o/p: 50
    cout << "dq.back(): " << dq.back() << endl << endl;   // o/p: 30

    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    printDeque(dq);   // o/p: 50 40 10 20
    cout << "dq.front(): " << dq.front() << endl;   // o/p: 50
    cout << "dq.back(): " << dq.back() << endl << endl;   // o/p: 20

    cout << "Popping 3 elements from front:\n";
    dq.pop_front(); dq.pop_front(); dq.pop_front();
    printDeque(dq);   // o/p: 20
    cout << "dq.front(): " << dq.front() << endl;   // o/p: 20
    cout << "dq.back(): " << dq.back() << endl << endl;   // o/p: 20

    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    printDeque(dq);   // o/p: (empty)

    return 0;
}
