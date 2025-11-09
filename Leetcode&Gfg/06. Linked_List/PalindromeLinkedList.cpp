// Leetcode: 234. Palindrome Linked List   --->   Given the head of a singly linked list, return true
// if it is a palindrome or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL) {   // did small change in the condition
            fast = fast->next;
            if(fast->next != NULL) {   // did small change in the condition
                fast = fast->next;
                slow = slow->next;
            }
        }
        // -> Why we did small change in condition ?
        // -> So that we point to first node of the two middle nodes obtained in even length linked lists.

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        while(currNode != NULL) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
        return head;
    }

    bool compareLists(ListNode* head, ListNode* head2) {
        while(head2 != NULL) {   // head2 will always be shorter than(odd length ll) or
                                // equal(even length ll) to head, thus head2 will reach NULL before
                               // or in the same iteration with head. Thus, comparing the two
                              // linked lists with only 'head2 != NULL' in while condition is sufficient.
            if(head->val != head2->val) {
                // if values don't match, its not a palindrome. Thus, we return false.
                return false;
            } else {
                // if values matches, move one step ahead.
                head = head->next;
                head2 = head2->next;
            }
        }
        // we reach here only if while loop completed its lifecycle, which means all values of 
        // the two linked lists were matching. Thus, its a palindrome and we return true.
        return true;
    }

    // leetcode given function
    bool isPalindrome(ListNode* head) {
        // finding midNode and breaking linked list from mid in 2 parts 'head to mid' and 'mid+1 to tail'.
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // reversing the new linked list
        head2 = reverseList(head2);

        // comparing both linked lists
        bool ans = compareLists(head, head2);
        return ans;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution obj;
    bool ans;
    ans = obj.isPalindrome(head);

    cout << ans << endl;

    return 0;
}

