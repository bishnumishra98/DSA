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

// Reverse linked list using iterative approach
// T.C: O(n)
// S.C: O(1)
void reverseLinkedList_Iterative(Node* &head) {
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

// recursive function
Node* reverse_by_recursion(Node* &prevNode, Node* &currNode) {
    if(currNode == NULL) {
        return prevNode;   // We know head lies on prevNode of a reversed linked list.
                          // Thus, returning prevNode.
    }

    Node* nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;

    reverse_by_recursion(prevNode, currNode);
}

// Reverse linked list using recursive approach
// T.C: O(n)
// S.C: O(n)
void reverseLinkedList_Recursive(Node* &head) {
    Node* prevNode = NULL;
    Node* currNode = head;

    head = reverse_by_recursion(prevNode, currNode);
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

    cout << "Original linked list:\n";
    printElements(head);
    cout << "\nReversed linked list:\n";
    reverseLinkedList_Iterative(head);
    printElements(head);
    cout << "\nReversed linked list:\n";
    reverseLinkedList_Recursive(head);
    printElements(head);

    return 0;
}
