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

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode given function
// T.C: 
// S.C: 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    Solution obj;
    ListNode* ans = obj.reverseKGroup(head, k);

    printLL(head);

    return 0;
}

