// Adding 1 to LL means to adding 1 as if LL was a number.

// Example 1:
// Input:
// 1 -> 5 -> 9
// Output:
// 1 -> 6 -> 0

// Example 2:
// Input:
// 9 -> 9 -> 9
// Output:
// 1 -> 0 -> 0 -> 0

#include <iostream>
using namespace std;

// interface of Node for singly linked list
class Node {
    public:
        int data;
        Node* next;
        Node() {
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

int main() {

    return 0;
}
