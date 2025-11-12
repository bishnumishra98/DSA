// Leetcode: 25. Reverse Nodes in k-Group   --->   Given the head of a linked list, reverse the
// nodes of the list k at a time, and return the modified list. k is a positive integer and is less
// than or equal to the length of the linked list. If the number of nodes is not a multiple of k,
// then left-out nodes in the end should remain as it is.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Algorithm: https://www.youtube.com/watch?v=lIar1skcQYI&t=357s

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper function to reverse the linked list in place
    void reverseLL(ListNode* &head) {   // passing '&head' is mandatory in in-place reversal
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        while(currNode != NULL) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
    }

    // Helper function to get the k-th node from the current position. If fewer than k nodes remain, returns NULL.
    ListNode* getkThNode(ListNode* temp, int k) {
        // we are at the 1st node already; move (k-1) steps
        k = k - 1;
        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // T.C: O(n) for traversing all nodes + O(n) for reversing nodes = O(2n) ~ O(n)
    // S.C: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1) return head;

        ListNode* temp = head;
        ListNode* prevLast = NULL;   // tail of the previous reversed group

        while(temp != NULL) {
            ListNode* kThNode = getkThNode(temp, k);
            if(kThNode == NULL) {
                // Fewer than k nodes left -> link remaining part and stop
                if(prevLast != NULL) prevLast->next = temp;
                break;
            }

            ListNode* nextGroupHead = kThNode->next;
            // Detach current group
            kThNode->next = NULL;

            // Remember group's start (will become tail after reversal)
            ListNode* groupStart = temp;

            // Reverse this k-sized group; temp will be updated to new head of the group
            reverseLL(temp);   // temp now points to the head of reversed group

            // Connect previous group to current reversed group
            if(prevLast == NULL) {
                // First reversed group -> update overall head
                head = temp;
            } else {
                prevLast->next = temp;
            }

            // Update prevLast to the tail of the reversed group (which was groupStart)
            prevLast = groupStart;

            // Move to next group
            temp = nextGroupHead;
        }

        return head;
    }
};


// Function to print elements of linked list
void printLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printLL(head);
    cout << "\n";

    int k = 2;
    Solution obj;
    ListNode* ans = obj.reverseKGroup(head, k);

    printLL(ans);

    return 0;
}
