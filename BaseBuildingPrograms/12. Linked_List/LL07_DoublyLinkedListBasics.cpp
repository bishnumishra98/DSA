#include <iostream>
using namespace std;

// Interface of node for doubly linked list
class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node() {
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

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

// Function for printing details of linked list
void printLLDetails(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << "Node_address: " << temp << "\n";
        cout << "Node_Data: " << temp->data << "\n";
        cout << "Previous_Node_address: " << temp->prev << "\n";
        cout << "Next_Node_address: " << temp->next << "\n\n";
        temp = temp->next;   // removing 'temp' from this Node and pointing to next Node
    }
}

int main() {
    // Creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // Creating linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    second->prev = first;
    third->prev = second;
    fourth->prev = third;
    fifth->prev = fourth;

    Node* head = first;

    cout << "Details of linked list are:\n";
    printLLDetails(head);

    return 0;
}

// o/p:
// Details of linked list are:
// Node_address: 0xe9bf20
// Node_Data: 2
// Previous_Node_address: 0
// Next_Node_address: 0xe9bf38       

// Node_address: 0xe9bf38
// Node_Data: 4
// Previous_Node_address: 0xe9bf20   
// Next_Node_address: 0xe9bf50       

// Node_address: 0xe9bf50
// Node_Data: 6
// Previous_Node_address: 0xe9bf38   
// Next_Node_address: 0xe9bf68       

// Node_address: 0xe9bf68
// Node_Data: 8
// Previous_Node_address: 0xe9bf50   
// Next_Node_address: 0xe9bf80       

// Node_address: 0xe9bf80
// Node_Data: 10
// Previous_Node_address: 0xe9bf68   
// Next_Node_address: 0
