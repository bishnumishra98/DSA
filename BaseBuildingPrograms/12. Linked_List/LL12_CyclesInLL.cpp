// If tail of linked list points to a node of linked list, it means there is a cycle present in linked list.

#include <iostream>
#include <map>
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

// Finding cycles using map
// T.C: O(n)
// S.C: O(n)
bool hasCycle_map(Node *head) {
    map<Node*, bool> table;   // by default bool value is initialized with false in a map

    Node* temp = head;
    while(temp != NULL) {
        if(table[temp] == false) {   // if table[temp] is false, this Node is unvisited before.
        // Thus we will mark this Node as visited, by marking true.
            table[temp] = true;
        } else {
            // If table[temp] is true, this Node is visited before, which signifies a cycle.
            return true;
        }
        temp = temp->next;
    }
    // If loop ends, it means complete linked list was traversed without any cycles.
    // Thus, we return false signifying that linked list contains no cycles.
    return false;
}

// Finding cycles using two pointers / tortoise and hare algorithm / Floyd's cycle-finding algorithm
// T.C: O(n)
// S.C: O(1)
bool hasCycle_twoPointer(Node* head) {
    Node* fast = head;
    Node* slow = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            // If cycle is present in LL, fast and slow pointers will certainly meet at a certain point.
            return true;
        }
    }
    return false;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 2 -> 3
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

    // cout << hasCycle_map(head);
    cout << hasCycle_twoPointer(head);   // o/p: 1 (true)
    
    return 0;
}
