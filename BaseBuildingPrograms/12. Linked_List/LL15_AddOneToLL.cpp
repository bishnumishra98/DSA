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

// Function to print elements of linked list
void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to return reversed linked list
Node* reverseLL(Node* head) {
    Node* prevNode = NULL;
    Node* currNode = head;
    
    while(currNode != NULL) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

// Approach 1
// T.C: O(n)
// S.C: O(1)
// Node* addOneToLL(Node* head) {
//     head = reverseLL(head);   // reversing list to make addition easy       
//     Node* temp = head;
    
//     while(1) {
//         temp->data += 1;   // adding 1 to temp node
        
//         if(temp->data < 10) {    // if 'data < 10', no need of any carry. We can return reversed list.
//             return reverseLL(head);
//         } else {   // else we continue with making data as 0 and add 1(carry) to next node
//             temp->data = 0;
//         }
            
//         if(temp->next != NULL) {   // if we didn't reached last node of LL, keep moving forward
//             temp = temp->next;
//         } else {
//             break;   // If last node of LL is reached, break from the loop
//         }
//     }

//     // Reaching here implies that the last node's data is still not less than 10, and the LL has
//     // ended. This means there is a carry of 1 left to be inserted after the last node. This only
//     // happens when input is all 9. For example: 999, 9999, etc. Thus, we insert a new node
//     // with data as 1 at the end of the LL and return the reversed list.
//     temp->next = new Node(1);  // adding new node for the carried 1
//     return reverseLL(head);
// }

// Approach 2
// T.C: O(n)
// S.C: O(1)
Node* addOneToLL(Node* head) {
    head = reverseLL(head);   // reversing list to make addition easy 
    Node* p = head;
    Node* temp = NULL;   // temp will denote tail at end of while loop

    int carry = 1;   // as 1 is to be added to LL, we assume 1 is the carry in the beginning
    while(p != NULL) {
        int x = (p != NULL) ? p->data : 0;
        int sum = x + carry;
        carry = sum / 10;
        p->data = sum % 10;
        temp = p;
        p = p->next;   // when p reaches NULL, temp will reach tail of LL
    }

    // If carry is still greater than 0(obviously it will be 1), and the LL has ended; it means
    // there is still a carry of 1 left to be inserted after the last node. This only
    // happens when input is all 9. For example: 999, 9999, etc. Thus, we insert a new node
    // with data as 1 at the end of the LL and return the reversed list.
    if(carry > 0) {
        temp->next = new Node(1);
    }

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
