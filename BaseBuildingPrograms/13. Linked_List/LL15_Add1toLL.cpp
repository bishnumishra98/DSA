// Adding 1 to number represented by LL, i.e., add 1 as if LL was a number.

// Example 1:
// Input:
// 1 -> 5 -> 9
// Output:
// 1 -> 6 -> 0

// Example 2:
// Input:
// 9 -> 9 -> 9
// Output:
// 1 -> 0 -> 0 -> 0

// Example 3:
// Input:
// 0 -> 0 -> 0
// Output:
// 0 -> 0 -> 1

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
void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// function to return reversed linked list
Node* reverseLL(Node* head) {
    Node* prevNode = NULL;
    Node* currNode = head;
    
    while(currNode != NULL) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
    return head;
}

// T.C: O(3n) = O(n)
// S.C: O(1)
Node* addOneToLL(Node* head) {
    head = reverseLL(head);   // reversing list to make addition easy
            
    Node* temp = head;
    int carry = 1;
    
    while(carry) {
        temp->data += 1;   // adding one to temp node
        
        if(temp->data < 10) {
            return reverseLL(head);   // if no carry we can reverse back list and return it
        } else {
            temp->data = 0;   // else we continue with taking carry forward
        }
            
        if(temp->next == NULL) break;   // if, end of list, we break from loop  
        else temp = temp->next;   // else we move to next node
    }

    // If we reach here, it means input was something like 999, that's why list ended with 1 carry.
    // In this case, we insert new insert a new Node with 1, and attach it to end of list.
    // Then return the reversed list.
    temp->next = new Node(1);  // adding new node for the carried 1
    return reverseLL(head);
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(9);
    Node* node2 = new Node(9);
    Node* node3 = new Node(9);

    head->next = node2;
    node2->next = node3;

    printLL(head);
    cout << "\n";
    Node* ans = addOneToLL(head);
    printLL(ans);

    return 0;
}
