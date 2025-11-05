#include <iostream>
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

// Function for printing details of linked list
void printLLDetails(Node* head) {
    // It a good practice to always make a copy of head before doing any operation with linked list
    // where we will need to traverse head Node.
    Node* temp = head;
    while(temp != NULL) {
        cout << "Node_address: " << temp << "\n";
        cout << "Node_Data: " << temp->data << "\n";
        cout << "Next_Node_address: " << temp->next << "\n\n";
        temp = temp->next;   // removing 'temp' from this Node and pointing to next Node
    }
}

// Function to print elements of linked list
void printElements(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to find length of linked list, i.e. no.of nodes
int lengthLL(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int main() {
    // Creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // Creating a linked list by connecting all nodes. To connect all nodes, we set the 'next' pointer
    // of each Node to point to the next Node. Note that, no one is pointing to the first Node; and
    // the fifth Node is pointing to NULL, as the 'next' pointer of all Nodes was initially pointing
    // to NULL, but we changed them to point to the next Node except the fifth one.
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Printing the details of linked list
    Node* head = first;

    cout << "Details of linked list are:\n";
    printLLDetails(head);

    cout << "Elements of linked list are:\n";
    printElements(head);
    cout << "\n\n";

    cout << "Length of linked list: " << lengthLL(head);
    cout << "\n\n";

    return 0;
}

// o/p:
// Details of linked list are:
// Node_address: 0x11abf20      
// Node_Data: 2
// Next_Node_address: 0x11abf30 

// Node_address: 0x11abf30      
// Node_Data: 4
// Next_Node_address: 0x11abf40 

// Node_address: 0x11abf40      
// Node_Data: 6
// Next_Node_address: 0x11abf50 

// Node_address: 0x11abf50      
// Node_Data: 8
// Next_Node_address: 0x11abf60 

// Node_address: 0x11abf60      
// Node_Data: 10
// Next_Node_address: 0

// Elements of linked list are: 
// 2 4 6 8 10

// Length of linked list: 5
