// A Node in linked list can be inserted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a nwNode 
//      Step 2: Attach newNode to head, i.e. newNode->next = head
//      Step 3: Attach prev of head to newNode, i.e. head->prev = newNode
//      Step 4: Update head pointer, i.e. head = newNode
// 2) At tail of linked list:
//      Step 1: Create a newNode
//      Step 2: Attach tail to newNode, i.e. tail->next = newNode
//      Step 3: Attach prev of newNode to tail, i.e. newNode->prev = tail
//      Step 4: Update tail pointer, i.e. tail = newNode
// 3) In between the linked list, i.e. at a particular position(let positions start from 1):
//

#include <iostream>
using namespace std;

// interface of node for doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node() : prev(NULL), next(NULL) {}
        Node(int data) : data(data), prev(NULL), next(NULL) {}
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

// INSERTION OF NODE AT HEAD
void insertAtHead(Node* &head, int data) {
    if(head == NULL) {   // if linked list is empty
        Node* newNode = new Node(data);
        head = newNode;
    } else {   // if linked list is not empty
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// INSERTION OF NODE AT TAIL
void insertAtTail(Node* &head, int data) {
    Node* tail = findTail(head);
    if(head == NULL) {   // if linked list is empty
        Node* newNode = new Node(data);
        head = newNode;
    } else {   // if linked list is not empty
        
    }
}


int main() {
    Node* head = NULL;

    insertAtHead(head, 2);
    insertAtHead(head, 4);

    printElements(head);

    return 0;
}
