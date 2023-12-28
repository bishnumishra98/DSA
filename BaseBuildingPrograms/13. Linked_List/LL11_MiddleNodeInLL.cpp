#include <iostream>
using namespace std;

// For a odd length linked list of n, middle node is ((n/2)+1)th node.
// Example: In 2 -> 4 -> 6 -> 8 -> 10, n=5, so middle miidle node is ((n/2)+1)th node, i.e. 6.

// For an even length linked list of n, middle node can be any (n/2)th or ((n/2)+1)th node. But in most
// cases, it is preferred to select as ((n/2)+1)th node.
// Example: In 2 -> 4 -> 6 -> 8, n=4, so middle can be any (n/2)th or ((n/2)+1)th node, i.e 4 or 6.

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

// function to print elements of linked list
void printElements(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// function to find length of linked list, i.e. no.of nodes
int lengthLL(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Brute force
// T.C: O(n)
// S.C: O(1)
Node* findMid_bruteForce(Node* head) {
    int len = lengthLL(head);

    int mid = len/2 + 1;
    cout << "\nMid poisition: " << mid;

    Node* temp = head;

    while(--mid) {   // Note: its pre-increment, because if mid = n, we want to run loop 'n-1' times.
        temp = temp->next;
    }

    return temp;
}

// Slow & fast pointer approach(Slow pointer moves 1 step ahead, only if fast pointer moves 2 step ahead)
// T.C: O(n/2)
// S.C: O(1)
Node* findMid_twoPointer(Node* head) {
    Node* fast = head;
    Node* slow = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    // creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // creating a linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;

    printElements(head);

    Node* ans = findMid_bruteForce(head);
    cout << "\nMiddle node: " << ans->data << endl;

    ans = findMid_twoPointer(head);
    cout << "\nMiddle node: " << ans->data << endl;
    

    return 0;
}
