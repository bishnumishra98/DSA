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

class Solution {
public:
    ListNode* reverseLL(ListNode* head, int k) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        while(k--) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    // leetcode given function
    // T.C: O(n)
    // S.C: O(1)
    // In each recursive call, a constant amount of space is used for variables such as pointers
    // (prev, current, nextNode, reversedHead) and the function call stack. However, the maximum depth
    // of the recursion is limited by the size of the linked list, and the space used at each level is
    // constant. Therefore, the overall space complexity is O(1) despite the use of recursion.
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;   // By using the count variable, the code ensures that it only attempts
        // to reverse a group of nodes when there are at least k nodes available.
        ListNode* temp = head;

        // Count the number of nodes in the list
        while(temp!=NULL && count<k) {
            temp = temp->next;
            count++;
        }

        // Base case, i.e., if the number of nodes is less than k, no need to reverse
        if(count < k) {
            return head;
        }

        // Reverse the first k nodes
        ListNode* reversedHead = reverseLL(head, k);

        // Recursively reverse the rest of the nodes
        head->next = reverseKGroup(temp, k);

        return reversedHead;
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

    printLL(head);
    cout << "\n";

    int k = 2;
    Solution obj;
    ListNode* ans = obj.reverseKGroup(head, k);

    printLL(ans);

    return 0;
}
