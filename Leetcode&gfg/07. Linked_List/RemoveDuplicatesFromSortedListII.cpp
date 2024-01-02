// Leetcode: 82. Remove Duplicates from Sorted List II   --->   Given the head of a sorted linked list,
// delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Return the linked list sorted as well.

// Example 1:
// Input: head = [1,2,3,3,3,4,5,5]
// Output: [1,2,5]

// Example 2:
// Input: head = [1,1,1,2,3]
// Output: [2,3]

#include <iostream>
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
        // if no or only 1 node exists in LL, return head simply
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);   // it means 'dummy->val = 0' and 'dummy-next = head'
        ListNode* prev = dummy;

        while(head != NULL) {
            if(head->next != NULL && head->val == head->next->val) {
                // move head pointer forward continuously if duplicate nodes found, until head
                // reaches last duplicate node in series.
                while(head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                // here head is at last duplicate node in series, i.e., next node after head is
                // a distinct node. So repoint prev to next node of head.
                prev->next = head->next;
            } else {
                // no duplicates found, move the prev pointer forward
                prev = prev->next;
            }
            // move head pointer forward on every iteration
            head = head->next;
        }

        return dummy->next;
    }
};

// function to print elements of linked list
void printLL(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 1 -> 3 -> 3 -> 3 -> 4 -> 5 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(5);

    printLL(head);
    cout << "\n";
    
    Solution obj;
    ListNode* ans = obj.deleteDuplicates(head);

    printLL(ans);

    return 0;
}
