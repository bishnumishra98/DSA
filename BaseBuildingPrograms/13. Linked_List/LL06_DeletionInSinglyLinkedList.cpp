// A Node in linked list can be deleted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Node*  temp = head
//      Step 2: head = head->next
//      Step 3: temp->next = NULL
//      Step 4: delete temp
// 2) At tail of linked list:
//      Step 1: Initialize 'prev' node head
//      Step 2: Traverse till 2nd last node and point it from 'prev' pointer
//      Step 3: prev->next = NULL
//      Step 4: delete tail
//      Step 5: tail = prev
// 3) In between the linked list, i.e. at a particular position(let positions start from 1):
//      Step 1: Initialize two nodes named 'curr' and 'prev' with NULL and head respectively.
//      Step 2: Move forward the 'curr' and 'prev' pointers in such way that 'prev' node is
//              just behind the 'curr' node, uptil the 'curr' node reaches the position where
//              deletion is to be performed. For example, if 3rd Node is to be deleted, then the
//              'curr' pointer should be pointing at the 3rd node, while 'prev' should be
//              pointing at 2nd node of the linked list, respectively.
//      Step 3: prev->next = curr->next
//      Step 4: curr->next = NULL
//      Step 5: delete curr

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

int main() {

    return 0;
}