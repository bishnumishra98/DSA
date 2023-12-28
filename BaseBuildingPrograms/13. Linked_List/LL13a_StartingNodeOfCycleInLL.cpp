// The node where tail of a LL points, is the starting node of the cycle in LL.

// -> How to find starting node of cycle ?
// -> There is an algorithm to find starting node of cycle in LL:
//    1) Use tortoise and hare algorithm to find if a cycle exists in LL.
//    2) Leave the fast pointer at the node where slow and head met, and repoint slow point on head of LL.
//    3) Then move slow and fast pointer by one step, and they will meet on the starting node of LL.
//    The mathematical proof of this algorithm is illustrated in LL13b.

#include <iostream>
#include <map>
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

// T.C:
// S.C:
Node* startingNodeOfCycle(Node* head) {
    // tortoise and hare algorithm
    Node* fast = head;
    Node* slow = head;

    

}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(2);
    Node* node5 = new Node(3);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;   // node5 points to node3, making a cycle

    Node* ans = startingNodeOfCycle(head);
    cout << "Starting node: " << ans->data;
    
    return 0;
}


