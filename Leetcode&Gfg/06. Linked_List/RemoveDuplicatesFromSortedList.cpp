// Leetcode: 83. Remove Duplicates from Sorted List   --->   Given the head of a sorted linked list,
// delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

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
    // T.C: O(n)
    // S.C: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        // If no or only 1 node exists in LL, return head simply
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;

        while(temp->next != NULL) {
            if(temp->val == temp->next->val) {
                // If next node is a duplicate node, delete the next node
                ListNode* delNode = temp->next;
                temp->next = delNode->next;
                delNode->next = NULL;
                delete delNode;
            } else {
                // If next node is not duplicate, move temp one step ahead
                temp = temp->next;
            }
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
    // Create a sample linked list: 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(4);

    printLL(head);
    cout << "\n";

    Solution obj;
    ListNode* ans = obj.deleteDuplicates(head);

    printLL(ans);

    return 0;
}
