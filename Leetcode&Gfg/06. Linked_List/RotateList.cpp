// Leetcode: 61. Rotate List   --->   Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

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
    // T.C: O(n);   where n is the number of nodes in the linked list
    // S.C: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        // Find the length and tail of LL in one-pass to reduce time complexity
        ListNode* tail = head;
        int length = 1;
        while(tail->next != NULL) {
            length++;
            tail = tail->next;
        }
        
        // Reduce k by modulo of length
        k = k % length;
        if(k == 0) return head;

        // Step 1: Link the tail of LL with head of LL
        tail->next = head;

        // Step 2: Reach the (length - k)th node from head of LL
        int pos = length - k;
        ListNode* temp = head;
        pos = pos - 1;
        while(pos--) {
            temp = temp->next;
        }

        // Step 3: Preserve the newHead of the LL and detach the (length - k)th node from LL
        ListNode* newHead = temp->next;
        temp->next = NULL;

        // Step 4: Return the newhead of LL
        return newHead;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    ListNode* result = Solution().rotateRight(head, k);
    ListNode* temp = result;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
