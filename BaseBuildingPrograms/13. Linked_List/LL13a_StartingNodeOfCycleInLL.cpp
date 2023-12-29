// The node where tail of a LL points, is the starting node of the cycle in LL.

// -> How to find starting node of cycle ?
// -> There is an algorithm to find starting node of cycle in LL:
//    Step 1) Use tortoise and hare algorithm to find if a cycle exists in LL.
//    Step 2) Repoint any one of the pointers to head of LL, for instance repoint slow pointer on head.
//    Step 3) Then move slow and fast pointer by one step respectively until they meet. The point where
//            they meet is the starting node of LL.
//    The mathematical proof of this algorithm is illustrated in LL13b.

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

// T.C: O(n)
// S.C: O(1)
Node* startingNodeOfCycle(Node* head) {
    // Step 1) tortoise and hare algorithm
    Node* fast = head;
    Node* slow = head;

    // Don't use while(fast != NULL && fast->next != NULL) here. Instead write this condition
    // in two parts(while & if). This will help in returning something if LL had no cycles.
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) {   // if 'fast==slow', it means cycle exists in LL
            break;
        }
    }

    // Its an extra step we added for better program. If no cycle is present in LL, return NULL.
    if(fast == NULL) {
        return NULL;
    }

    // Step 2) Now the repoint slow pointer on head
    slow = head;

    // Step 3) Moving slow and fast pointer by one step respectively until they meet
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);
    Node* node6 = new Node(60);
    Node* node7 = new Node(70);
    Node* node8 = new Node(80);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node3;

    Node* ans = startingNodeOfCycle(head);
    cout << "Starting node of cycle: " << ans->data;   // Starting node of cycle: 30
    
    return 0;
}
