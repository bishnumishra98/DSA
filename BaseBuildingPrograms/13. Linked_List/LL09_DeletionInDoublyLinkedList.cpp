// A Node in linked list can be deleted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a temporary node, i.e. Node* temp = head
//      Step 2: Make the node just next to head, as the new head node, i.e. head = head->next
//      Step 3: Unlink temp from linked list, i.e. temp->next = NULL
//      Step 4: Unlink head from temp, i.e. head->prev = NULL
//      Step 5: Delete temp node, i.e. delete temp
// 2) At tail of linked list:
//      Step 1: Find tail and mark its previous node by prevNode, i.e. Node* prevNode = tail->prev
//      Step 2: Unlink prevNode from tail of linked list, i.e. prevNode->next = NULL
//      Step 3: Unlink prev of tail from prevNode of linked list, i.e tail->prev = NULL
//      Step 4: Delete tail node, i.e. delete tail
// 3) In between the linked list, i.e. at a particular position(let positions start from 1):
//      Step 1: Initialize a node named 'currNode' with head.
//      Step 2: Move forward the 'currNode' pointer in such a way that the 'currNode' node reaches
//              the position where deletion is to be performed. For example, if 3rd Node is to be
//              deleted, then the 'currNode' pointer should be pointing at the 3rd node of the
//              linked list.
//      Step 3: Initialize a new node named 'prevNode' as prev of currNode,
//              i.e. Node* prevNode = currNode->prev
//              Similarly, Initialize one more new node named 'nextNode' as next of currNode,
//              i.e. Node* nextNode = currNode->next
//      Step 4: Repoint prevNode to nextNode, i.e. prevNode->next = nextNode,
//              and point prev of nextNode to preNode, i.e. nextNode->prev = prevNode
//      Step 5: Unlink currNode from linked list, i.e. currNode->prev = NULL, currNode->next = NULL

#include <iostream>
using namespace std;

// interface of Node for doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        // Constructors
        Node() : prev(NULL), next(NULL) {}
        Node(int data) : data(data), prev(NULL), next(NULL) {}

        // Destructor
        ~Node() {
            cout << "Destructor called for the Node: " << this->data << endl;
            delete prev;   // releasing dynamically allocated memory
            delete next;   // releasing dynamically allocated memory
            prev = NULL;   // setting prev to NULL to avoid potential issues
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
            head->prev = NULL;
            delete temp;
        } else if(position == lengthLL(head)) {
            // deletion at tail
            Node* tail = findTail(head);
            Node* prevNode = tail->prev;
            prevNode->next = NULL;
            tail->prev = NULL;
            delete tail;
        } else {
            // deletion in between the linked list
            Node* currNode = head;
            int pos = position - 1;
            while(pos--) {
                currNode = currNode->next;
            }
            Node* prevNode = currNode->prev;
            Node* nextNode = currNode->next;

            prevNode->next = nextNode;   // or, prevNode->next = currNode->next;
            nextNode->prev = prevNode;   // or, nextNode->prev = currNode->prev;
            
            currNode->prev = NULL;
            currNode->next = NULL;
            
            delete currNode;
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

    second->prev = first;
    third->prev = second;
    fourth->prev = third;
    fifth->prev = fourth;

    Node* head = first;

    deleteAtPosition(head, 3);

    printElements(head);

    return 0;
}

// o/p:
// Destructor called for the Node: 6
// 2 4 8 10
