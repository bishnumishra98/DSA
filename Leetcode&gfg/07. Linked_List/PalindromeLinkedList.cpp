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

    void reverseList(ListNode* &head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;

        while(currNode != NULL) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
    }

    // leetcode given function
    bool isPalindrome(ListNode* head) {
        // finding midNode and breaking linked list from mid in 2 parts 'head to mid' and 'mid+1 to tail'.
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // reversing the new linked list
        reverseList(head2);

        while(head2 != NULL) {
            if(head->val != head2->val) {
                return false;
            }
        }

        return true; 
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

    cout << "Ans: " << ans << endl;

    return 0;
}
