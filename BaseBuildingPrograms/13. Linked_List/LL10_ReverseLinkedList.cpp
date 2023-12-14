// Reverse a Singly Linked List:
// Step 1: Initialize two pointers 'prevNode' and 'currNode' to NULL and head respectively.
// Step 2: Iterate them until currNode points to NULL. At that point, prevNode would point to last
//         node of linked list.
// Step 3: Update head to prevNode.

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

void reverseLinkedList(Node* &head) {
    Node* prevNode = NULL;
    Node* currNode = head;
    
    while(currNode != NULL) {
        Node* nextNode = currNode->next;   // If we loose track of next node of currNode, we will
        // not be able to move currNode pointer to next position in the linked list. Thus, next node
        // of currNode is stored temporarily in nextNode pointer.
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    // loop ends when currNode points to NULL. At that point, prevNode will point to last element of
    // linked list. Thus, we will repoint head pointer on that node, i.e. on prevNode.
    head = prevNode;
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
    cout << "\nReversed linked list is:\n";
    reverseLinkedList(head);
    printElements(head);

    return 0;
}

