// A Node in linked list can be inserted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a new node
//      Step 2: Attach new node to head node i.e. newNode->next = head
//      Step 3: Update head address i.e. head = newNode
// 2) At tail of linked list:
//      Step 1: Find tail, if tail is not given
//      Step 2: Create a new node
//      Step 3: Attach tail to new node i.e. tail->next = newNode
//      Step 4: Update tail address i.e. tail = newNode
// 3) In between the linked list, i.e. at a particular position(let positions start from 1):
//      Step 1: Create a new node
//      Step 2: Initialize two nodes named 'current' and 'previous' with NULL and head respectively
//      Step 3: Move forward the 'current' and 'previous' pointers in such way that 'previous' node is
//              just behind the 'current' node, uptil the 'current' node reaches the position where
//              newNode is to be inserted. For example, if a newNode is to be inserted at position 3,
//              then 'current' should be pointing at the 3rd node, while 'previous' should be pointing
//              at the 2nd node of the linked list, respectively.
//      Step 4: Attach 'previous' node to newNode, i.e. previous->next = newNode
//      Step 5: Attach newNode to 'cuurent' node, i.e. newNode->next = current

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
    if(head == NULL) {   // if linked list is empty, i.e. there are no nodes
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// INSERTION OF NODE AT HEAD
void insertAtHead(Node* &head, int data) {   // Note = Always pass head/tail by reference while insertion
    // create new node
    Node* newNode = new Node(data);
    // attach new node to head node
    newNode->next = head;
    // Update head address
    head = newNode;
}

// INSERTION OF NODE AT TAIL
void insertAtTail(Node* &head, int data) {   // Note = Always pass head/tail by reference while insertion
    Node* tail = findTail(head);   // This function returns address of tail Node of linked list.
    // If linked list has no nodes, i.e. head points to NULL, then this function also returns NULL,
    // and eventually tail also points to NULL.

    if(tail == NULL) {   // if linked list is empty, i.e. there are no nodes in linked list
        // create new node
        Node* newNode = new Node(data);
        // 1 new Node is createdin in the above line. Thus, it is first node of linked list.
        // Therefore, head should point to this first node, in order to let the above created node be
        // the first node for this empty linked list.
        head = newNode;
    } else {   // non-empty linked list
        // create new node
        Node* newNode = new Node(data);
        // attach tail to newNode
        tail->next = newNode;
        // update tail address
        tail = newNode;
    }
}

// INSERTION OF NODE AT A PARTICULAR POSITION IN THE LINKED LIST (POSITION START FROM 1)
void insertAtPosition(Node* &head, int data, int position) {
    if(position <= 1) {   // inserting at a position at or before head
        insertAtHead(head, data);
    } else if(position >= lengthLL(head)+1) {   // inserting at a position beyond tail
        insertAtTail(head, data);
    } else {   // inserting at a position (head < position <= tail)
        // create a new node
        Node* newNode = new Node(data);

        // create 2 nodes named 'previous' and 'current'. The newNode will be inserted in between
        // the 'previous' and 'current' node.
        Node* previous = NULL;
        Node* current = head;

        int pos = position - 1;   // we did 'pos = position-1', because if we didn't do this, the
        // newNode was getting insert at 'position+1' position in the linked list.
        while(pos--) {
            previous = current;
            current = current->next;
        }

        previous->next = newNode;
        newNode->next = current;
    }
}

int main() {
    // creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // creating singly linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;

    insertAtHead(head, 50);
    insertAtTail(head, 60);
    insertAtPosition(head, 55, 3);

    printElements(head);

    return 0;
}

// o/p: 50 2 55 4 6 8 10 60


