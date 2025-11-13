// Leetcode: 21. Merge Two Sorted Lists   --->   You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
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
    ListNode* createLinkedListFromArray(vector<int>& arr) {
        if(arr.empty()) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return head;
    }

    // T.C: O(n1 + n2) for traversing both lists + O((n1 + n2)log(n1 + n2)) for sorting the values = O((n1 + n2)log(n1 + n2))
    //      where n1 and n2 are the lengths of list1 and list2 respectively.
    // S.C: O(n1 + n2)
    ListNode* mergeTwoLists_bruteforce(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        vector<int> values;
        
        // Extract values from both linked lists inside the vector 'values'
        ListNode* temp1 = list1;
        while(temp1 != NULL) {
            values.push_back(temp1->val);
            temp1 = temp1->next;
        }

        ListNode* temp2 = list2;
        while(temp2 != NULL) {
            values.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(values.begin(), values.end());

        // Create a new sorted linked list from the sorted values
        ListNode* mergedHead = createLinkedListFromArray(values);
        return mergedHead;
    }

// -------------------------------------------------------------------------------------------

    // T.C: O(n1 + n2);   where n1 and n2 are the lengths of list1 and list2 respectively.
    // S.C: O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i = list1;   // pointer for traversing list1
        ListNode* j = list2;   // pointer for traversing list2

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Traverse both lists and repoint the next pointers accordingly
        while(i != NULL && j != NULL) {
            if(i->val < j->val) {
                temp->next = i;
                temp = i;
                i = i->next;
            } else {   // if(i->val >= j->val)
                temp->next = j;
                temp = j;
                j = j->next;
            }
        }

        // Attach the remaining nodes of the non-exhausted list
        if(i != NULL) temp->next = i;
        else temp->next = j;

        return dummy->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // ListNode* mergedList = Solution().mergeTwoLists_bruteforce(list1, list2);
    ListNode* mergedList = Solution().mergeTwoLists(list1, list2);

    ListNode* temp = mergedList;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
