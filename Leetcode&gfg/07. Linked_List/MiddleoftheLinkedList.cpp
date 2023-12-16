// Leetcode: 876. Middle of the Linked List   --->   Given the head of a singly linked list, return
// the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: 3
// Explanation: The middle node of the list is node 3.

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: 4
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

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

// leetcode given function
// T.C: O(n/2)
// S.C: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* ans;
    ans = obj.middleNode(head);

    cout << ans->val << endl;

    return 0;
}
