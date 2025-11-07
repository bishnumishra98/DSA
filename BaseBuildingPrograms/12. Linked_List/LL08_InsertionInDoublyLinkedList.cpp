// A Node in linked list can be inserted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a nwNode 
//      Step 2: Attach newNode to head, i.e., newNode->next = head
//      Step 3: Attach prev of head to newNode, i.e., head->prev = newNode
//      Step 4: Update head pointer, i.e., head = newNode
// 2) At tail of linked list:
//      Step 1: Create a newNode
//      Step 2: Attach tail to newNode, i.e., tail->next = newNode
//      Step 3: Attach prev of newNode to tail, i.e., newNode->prev = tail
//      Step 4: Update tail pointer, i.e., tail = newNode
// 3) In between the linked list, i.e., at a particular position(let positions start from 1):
//      Step 1: Create a newNode
//      Step 2: Initialize two nodes named 'currNode' and 'prevNode' with NULL and head respectively.
//      Step 3: Move forward the 'currNode' and 'prevNode' pointers in such way that 'prevNode' node
//              is just behind the 'currNode' node, uptil the 'currNode' node reaches the position
//              where newNode is to be inserted. For example, if a newNode is to be inserted at
//              position 3, then 'currNode' should be pointing at the 3rd node, while 'prevNode'
//              should be pointing at the 2nd node of the linked list, respectively.
//      Step 4: Attach prevNode to newNode, i.e., prevNode->next = NewNode
//      Step 5: Attach prev of newNode to prevNode, i.e., newNode->prev = prevNode
//      Step 5: Attach newNode to currNode node, i.e., newNode->next = currNode
//      Step 6: Attach prev of currNode to NewNode, i.e., currNode->prev = newNode 

#include <iostream>
using namespace std;

// Interface of node for doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node() : prev(NULL), next(NULL) {}
        Node(int data) : data(data), prev(NULL), next(NULL) {}
};

// Function to print elements of linked list
void printElements(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to find length of linked list, i.e., no.of nodes
int lengthLL(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to find tail of linked list. This function returns address of tail Node of linked list.
Node* findTail(Node* head) {
    if(head == NULL) {   // if linked list is empty, i.e., there are no nodes, then tail will
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
    if(head == NULL) {   // if linked list is empty
        Node* newNode = new Node(data);
        head = newNode;
    } else {   // if linked list is not empty
        Node* tail = findTail(head);
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// INSERTION OF NODE AT A PARTICULAR POSITION IN THE LINKED LIST (POSITION START FROM 1)
void insertAtPosition(Node* &head, int data, int position) {
    if(position <= 1) {
        insertAtHead(head, data);
    } else if(position > lengthLL(head)) {
        insertAtTail(head, data);
    } else {
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* currNode = head;

        int pos = position - 1;
        while(pos--) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

int main() {
    Node* head = NULL;

    insertAtHead(head, 2);
    insertAtHead(head, 4);
    insertAtTail(head, 6);
    insertAtPosition(head, 8, 3);

    printElements(head);   // o/p: 4 2 8 6

    return 0;
}
