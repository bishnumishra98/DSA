// A Node in linked list can be inserted in any one of the three areas:
// 1) At head of linked list:
//      Step 1: Create a new node
//      Step 2: Attach new node to head node i.e., newNode->next = head
//      Step 3: Update head i.e., head = newNode
// 2) At tail of linked list:
//      Step 1: Create a new node
//      Step 2: tail->next 
//      Step 3:
// 3) In between the linked list:
//      Step 1:
//      Step 2:
//      Step 3:

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

// INSERTION AT HEAD
void insertAtHead(Node* &head, int data) {   // Note = Always pass head by reference while insertion
    // create new node
    Node* newNode = new Node(data);
    // attach new node to head node
    newNode->next = head;
    // Update head
    head = newNode;
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

    Node* head = NULL;
    insertAtHead(head, 50);
    printElements(head);

    return 0;
}
