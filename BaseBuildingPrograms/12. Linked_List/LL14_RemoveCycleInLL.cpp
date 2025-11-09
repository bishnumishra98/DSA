// Removing cycle in linked list means to repoint the tail of LL to NULL. Tail is the node that is
// present just before the starting node of cycle.

// -> How to remove cycle from LL ?
// -> Step 1: Find starting node of cycle in LL(Refer 'LL13a_StartingNodeOfCycleInLL.cpp')
//    Step 2: Repoint node present just before the starting node of cycle to NULL.

#include <iostream>
using namespace std;

// Interface of Node for singly linked list
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

// Function to find tail of linked list.
Node* findTail(Node* head) {
    if(head == NULL) {   // if linked list is empty, i.e. there are no nodes, then tail will also point to NULL.
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// T.C: O(n)
// S.C: O(1)
void removeCycle(Node* &head) {
    // Step 1: Find starting node of cycle in LL
    Node* fast = head;
    Node* slow = head;

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

    // If no cycle is present in LL.
    if(fast == NULL) {
        cout << "No cycle found in LL\n";
    }

    // Repointing slow pointer on head
    slow = head;

    // Moving slow and fast pointer by one step respectively until they meet
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // Starting node of cycle is pointed by both fast and slow pointer

    // Step 2: Repoint node present just before the starting node of cycle to NULL
    while(slow->next != fast) {
    // Keeping fast pointer on its place, and moving slow pointer by 1 step until, slow->next points
    // to fast. Thus, slow comes at a place which denotes the node just before starting node of cycle.
        slow = slow->next;
    }
    // Repointing node just before starting node of cycle to NULL
    slow->next = NULL;
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

    removeCycle(head);
    Node* ans = findTail(head);
    cout << "Cycle broken & tail is: " << ans->data;
    
    return 0;
}
