// Note: This problem was already solved in 'BaseBuildingPrograms\13. Linked_List\LL16a_Sort0s1s2sInLL.cpp'.

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
    // T.C: O(n)
    // S.C: O(1)
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // if no or only 1 node exists in LL, return head simply
        if(head == NULL || head->next == NULL) {
            return head;
        }
        Node* temp = head;
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);

        Node* zero = dummy0;
        Node* one = dummy1;
        Node* two = dummy2;

        // Traversing the original LL and segregate nodes based on their data value
        while(temp != NULL) {
            if(temp->data == 0) {
                zero->next = temp;
                zero = zero->next;   // or, zero = temp;
            } else if(temp->data == 1) {
                one->next = temp;
                one = one->next;   // or, one = temp;
            } else {
                two->next = temp;
                two = two->next;   // or, two = temp;
            }
            temp = temp->next;
        }

        // Connecting the three dummy nodes to form a LL
        zero->next = dummy1->next ? dummy1->next : dummy2->next;
        one->next = dummy2->next;
        two->next = NULL;

        Node* newHead = dummy0->next;

        // Deleting the pointers to avoid memory leaks
        delete dummy0;
        delete dummy1;
        delete dummy2;

        return newHead;
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
    // Create a sample linked list: 1 -> 2 -> 2 -> 0 -> 0 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(1);

    printLL(head);
    cout << "\n";
    
    Solution obj;
    Node* ans = obj.segregate(head);

    printLL(ans);

    return 0;
}
