// Leetcode: 23. Merge k Sorted Lists   --->   You are given an array of k linked-lists lists, each linked-list is
// sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

// Algorithm: Exactly same as 'BaseBuildingPrograms\17. Heaps\H09_MergeKSortedArrays.cpp'. The difference is that here we
//            are dealing with linked lists instead of arrays. The rest procedure is exactly same.

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
    ListNode* convertArrayToLinkedList(vector<int>& arr) {
        if(arr.size() == 0) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return head;
    }

    // T.C: O(n) + O(nlogn);   where n is the total number of nodes across all k lists
    // S.C: O(n)    for storing all the node values in a separate array
    ListNode* mergeKLists_bruteforce(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;

        // Store all the nodes of all linked lists in 'sortedValues' vector
        vector<int> sortedValues;
        for(int i = 0; i < k; i++) {
            ListNode* head = lists[i];
            while(head != NULL) {
                sortedValues.push_back(head->val);
                head = head->next;
            }
        }

        // Sort the 'sortedValues' vector
        sort(sortedValues.begin(), sortedValues.end());

        // Convert the 'sortedValues' vector to a linked list and return the head of linked list
        ListNode* sortedHead = convertArrayToLinkedList(sortedValues);
        return sortedHead;
    }

// --------------------------------------------------------------------------------------------------------


};

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);

    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    ListNode* mergedHead1 = Solution().mergeKLists_bruteforce(lists);
    ListNode* temp1 = mergedHead1;
    while (temp1 != NULL) {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }

    return 0;
}
