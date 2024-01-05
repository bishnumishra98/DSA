// This problem is already solved in 'BaseBuildingPrograms\13. Linked_List\LL17a_SortLL.cpp'.

// Leetcode: 148. Sort List   --->   Given the head of a linked list, return the list after sorting it.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSortedList(ListNode* p1, ListNode* p2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                temp->next = p1;
                p1 = p1->next;
            } else {
                temp->next = p2;
                p2 = p2->next;
            }
            temp = temp->next;
        }

        if(p1 != NULL || p2 != NULL) {
            temp->next = (p1 != NULL) ? p1 : p2;
        }

        return ans->next;
    }

    // T.C: O(nlogn)
    // S.C: O(1)
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;

        ListNode* left_half = sortList(head);
        ListNode* right_half = sortList(head2);
        return mergeSortedList(left_half, right_half);
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
    // Create a sample linked list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    //head->next->next->next->next = new ListNode(0);

    printLL(head);
    cout << "\n";
    
    Solution obj;
    ListNode* ans = obj.sortList(head);

    printLL(ans);

    return 0;
}
