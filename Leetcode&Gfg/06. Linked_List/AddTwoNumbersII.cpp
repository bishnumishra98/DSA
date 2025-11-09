// Leetcode: 445. Add Two Numbers II   --->   You are given two non-empty linked lists representing two
// non-negative integers. The most significant digit comes first and each of their nodes contains a
// single digit. Add the two numbers and return the sum as a linked list. You may assume the two
// numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]

// Example 2:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]

// Example 3:
// Input: l1 = [0], l2 = [0]
// Output: [0]

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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        while(currNode != NULL) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }

    // T.C: O(max(m,n));   where m & n are lengths of l1 & l2 respectively
    // S.C: O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode* ans = new ListNode(0);
        ListNode* p1 = l1, *p2 = l2, *temp = ans;

        int carry = 0;
        while(p1 != NULL || p2 != NULL) {
            int x1 = (p1 != NULL) ? p1->val : 0;
            int x2 = (p2 != NULL) ? p2->val : 0;
            int sum = x1 + x2 + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            if(p1 != NULL) p1 = p1->next;
            if(p2 != NULL) p2 = p2->next;
        }

        if(carry > 0) {
            temp->next = new ListNode(1);
        }

        return reverseLL(ans->next);
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
    // Create two sample linked lists: 7->2->4->3 and 5->6->4
    ListNode* ll1 = new ListNode(7);
    ll1->next = new ListNode(2);
    ll1->next->next = new ListNode(4);
    ll1->next->next->next = new ListNode(3);

    ListNode* ll2 = new ListNode(5);
    ll2->next = new ListNode(6);
    ll2->next->next = new ListNode(4);

    printLL(ll1);
    cout << "\n";
    printLL(ll2);
    cout << "\n";
    
    Solution obj;
    ListNode* ans = obj.addTwoNumbers(ll1, ll2);

    printLL(ans);

    return 0;
}
