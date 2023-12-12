// A Node in linked list can be deleted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a temporary node, i.e. Node* temp = head
//      Step 2: Make the node just next to head, as the new head node, i.e. head = head->next
//      Step 3: Unlink temp node from linked list, i.e. temp->next = NULL
//      Step 4: Delete temp node, i.e. delete temp
// 2) At tail of linked list:
//      Step 1: Initialize 'prev' node head
//      Step 2: Traverse till 2nd last node and point it from 'prev' pointer
//      Step 3: Unlink prev node from tail of linked list, i.e. prev->next = NULL
//      Step 4: Delete tail node, i.e. delete tail
// 3) In between the linked list, i.e. at a particular position(let positions start from 1):
//      Step 1: Initialize two nodes named 'curr' and 'prev' with NULL and head respectively.
//      Step 2: Move forward the 'curr' and 'prev' pointers in such way that 'prev' node is
//              just behind the 'curr' node, uptil the 'curr' node reaches the position where
//              deletion is to be performed. For example, if 3rd Node is to be deleted, then the
//              'curr' pointer should be pointing at the 3rd node, while 'prev' should be
//              pointing at 2nd node of the linked list, respectively.
//      Step 3: Attach prev to the node present just next of curr, i.e. prev->next = curr->next
//      Step 4: Unlink curr from linked list, i.e. curr->next = NULL
//      Step 5: Delete curr node, i.e. delete curr

#include <iostream>
using namespace std;

// interface of Node for singly linked list
class Node {
    public:
        int data;
        Node* next;
        // Constructors
        Node() : next(NULL) {}
        Node(int data) : data(data), next(NULL) {}

        // Destructor
        ~Node() {
            cout << "Destructor called for the Node: " << this->data << endl;
            delete next;   // releasing dynamically allocated memory
            next = NULL;   // setting next to NULL to avoid potential issues
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

// function to find tail of linked list. This function returns address of tail Node of linked list.
Node* findTail(Node* head) {
    if(head == NULL) {   // if linked list is empty, i.e. there are no nodes, then tail will
                        // also point to NULL.
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// DELETION OF NODE AT A PARTICULAR POSITION IN THE LINKED LIST (POSITION START FROM 1)
void deleteAtPosition(Node* &head, int position) {
    if(head == NULL) {   // no deletion can be performed in an empty linked list
        cout << "Cannot delete anything from an empty linked list" << endl;
        return;
    }
    if(position<1 || position>lengthLL(head)) {   // deletion can be done only if position exist in linked list
        cout << "Please enter a valid position" << endl;
        return;
    } else {   // if linked list is non-empty and deletion is performed in valid position
        if(position == 1) {
            // deletion at head
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        } else if(position == lengthLL(head)) {
            // deletion at tail
            Node* tail = findTail(head);
            Node* prev = head;
            int pos = position - 2;
            while(pos--) {
                prev = prev->next;
            }
            prev->next = NULL;
            delete tail;
        } else {
            // deletion in between the linked list
            Node* prev = NULL;
            Node* curr = head;
            int pos = position - 1;
            while(pos--) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

int main() {
    // creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // creating linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;

    deleteAtPosition(head, 3);

    printElements(head);


    // Free memory occupied by the nodes
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}