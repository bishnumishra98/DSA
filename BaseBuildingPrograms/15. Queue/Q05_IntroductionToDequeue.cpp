#include <iostream>
#include <deque>
using namespace std;

 /* // Brute_force
void printDeque(deque<int> dq) {
    cout << "dq: ";
    while(!dq.empty()) {
        int temp = dq.front();
        cout << temp << " ";
        dq.pop_front();
    }
    cout << endl;
}
*/

void printDeque(const deque<int> dq) {
    cout << "dq: ";
    for(int value : dq) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    deque <int> dq;

    cout << "Pushing 10, 20, 30 at rear:\n";
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    printDeque(dq);   // dq: 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // dq.front(): 10
    cout << "dq.back(): " << dq.back() << endl << endl;   // dq.back(): 30

    cout << "Pushing 40, 50, 60 at front:\n";
    dq.push_front(40);
    dq.push_front(50);
    dq.push_front(60);
    printDeque(dq);   // dq: 60 50 40 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // dq.front(): 60
    cout << "dq.back(): " << dq.back() << endl << endl;   // dq.back(): 30

    cout << "Popping 1 element from front:\n";
    dq.pop_front();
    printDeque(dq);   // dq: 50 40 10 20 30
    cout << "dq.front(): " << dq.front() << endl;   // dq.front(): 50
    cout << "dq.back(): " << dq.back() << endl << endl;   // dq.back(): 30

    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    printDeque(dq);   // dq: 50 40 10 20
    cout << "dq.front(): " << dq.front() << endl;   // dq.front(): 50
    cout << "dq.back(): " << dq.back() << endl << endl;   // dq.back(): 20

    cout << "Popping 3 elements from front:\n";
    dq.pop_front(); dq.pop_front(); dq.pop_front();
    printDeque(dq);   // dq: 20
    cout << "dq.front(): " << dq.front() << endl;   // dq.front(): 20
    cout << "dq.back(): " << dq.back() << endl << endl;   // dq.back(): 20

    cout << "Popping 1 element from rear:\n";
    dq.pop_back();
    printDeque(dq);   // dq: 

    return 0;
}
