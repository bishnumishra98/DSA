// Leetcode: 19. Remove Nth Node From End of List   --->   Given the head of a linked list, remove the nth node from
// the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

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
    int findLengthOfLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // T.C: O(length) + O(length - n) = O(2 * length) in the worst case when n = 1
    // S.C: O(1)
    ListNode* removeNthFromEnd_bruteforce(ListNode* head, int n) {
        if(head == NULL) return head;

        int length = findLengthOfLL(head);

        // If the node to be deleted is the head node
        if(length == n) {
            ListNode* newHead = head->next;
            head->next = NULL;
            delete head;
            return newHead;
        }

        int k = length - n;   // kth node is the just previous node before the node which has to be deleted
        ListNode* prev = head;
        k = k - 1;
        while(k--) {
            prev = prev->next;
        }
        // prev points to the just previous node before the node which has to be deleted

        ListNode* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return head;
    }

// ------------------------------------------------------------------------------------------------------------------

    // T.C: O(length)
    // S.C: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* dummy = new ListNode(0, head);   // dummy->next = head
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps forward
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both until fast points to last node
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // slow points to the just previous node before the node which has to be deleted

        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete nodeToDelete;

        return dummy->next;   // don't return head because head node may be deleted
    }
};


int main() {
    // Creating the linked list
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    ListNode* head = first;
    int n = 2;

    Solution sol;
    // head = sol.removeNthFromEnd_bruteforce(head, n);
    head = sol.removeNthFromEnd(head, n);

    // Printing the modified linked list
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
