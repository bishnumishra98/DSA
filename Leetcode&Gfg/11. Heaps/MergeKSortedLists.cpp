// Leetcode 23. Merge k Sorted Lists   --->   You are given an array of k linked-lists lists, each linked-list
// is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

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

void printLL(ListNode* head){
    ListNode* temp = head;
    while(!temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// ----------------------------------------------------------------------------------

class Solution {
public:
    // T.C: 
    // S.C: 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    head1->next = new ListNode(6);

    vector<ListNode*> lists = {head1, head2, head3};

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    printLL(mergedList);

    return 0;
}
