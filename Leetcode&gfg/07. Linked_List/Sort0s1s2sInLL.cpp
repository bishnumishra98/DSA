// gfg: Given a linked list of 0s, 1s and 2s, sort it   --->   Given a linked list of N nodes where
// nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list
// such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of
// 0s and 2s.

// Example 1:
// Input: head = [1,2,2,1,2,0,2,2]
// Output: [0,1,1,2,2,2,2,2]

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {

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

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printLL(head);
    cout << "\n";
    
    Solution obj;
    Node* ans = obj.segregate(head);

    printLL(ans);

    return 0;
}
