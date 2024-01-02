// Leetcode: 2. Add Two Numbers   --->   You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse order, and each of their nodes contains
// a single digit. Add the two numbers and return the sum as a linked list. You may assume the two
// numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
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
    // Create two sample linked lists: 9->9->9 and 9->9
    ListNode* ll1 = new ListNode(9);
    ll1->next = new ListNode(9);
    ll1->next->next = new ListNode(9);

    ListNode* ll2 = new ListNode(9);
    ll2->next = new ListNode(9);

    printLL(ll1);
    cout << "\n";
    printLL(ll2);
    cout << "\n";
    
    Solution obj;
    ListNode* ans = obj.addTwoNumbers(ll1, ll2);

    printLL(ans);

    return 0;
}
