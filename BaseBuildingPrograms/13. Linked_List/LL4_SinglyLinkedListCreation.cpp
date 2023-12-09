#include <iostream>
using namespace std;

// interface for singly linked list
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

// function for printing details of linked list
void printLLDetails(Node* head) {
    // It a good practice to always make a copy of head before doing any operation with linked list
    Node* temp = head;
    while(temp != NULL) {
        cout << "Node_address: " << temp << "\n";
        cout << "Data: " << temp->data << "\n";
        cout << "Next_Node_address: " << temp->next << "\n";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // creating a linked list by connecting all nodes. To connect all nodes, we set the 'next' pointer
    // of each Node to point to the next Node. Note that, no one is pointing to the first Node; and
    // the fifth Node is pointing to NULL, as the 'next' pointer of all Nodes was initially pointing
    // to NULL, but we changed them to point to the next Node except the fifth one.
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // printing the details of linked list
    Node* head = first;
    cout << "Details of linked list are:\n\n";
    printLLDetails(head);

    return 0;
}