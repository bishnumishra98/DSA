// Leetcode: 328. Odd Even Linked List   --->   Given the head of a singly linked list, group all the nodes with odd
// indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;

        // Step 1: Traverse the LL and link odd and even positioned nodes separately
        ListNode* curr = evenHead->next;
        int pos = 3;  // starting from 3rd position
        while(curr != NULL) {
            if(pos & 1) {  // odd position
                oddTail->next = curr;
                oddTail = oddTail->next;
            } else {  // even position
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            curr = curr->next;
            pos++;
        }

        // Step 2: Link oddTail with evenHead and evenTail with NULL
        oddTail->next = evenHead;
        evenTail->next = NULL;

        // Step 3: Return the head of modified LL, i.e., oddHead
        return oddHead;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = Solution().oddEvenList(head);
    ListNode* temp = result;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
