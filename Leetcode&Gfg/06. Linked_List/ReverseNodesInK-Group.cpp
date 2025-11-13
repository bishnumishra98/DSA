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

// Algorithm: The code may look hard, but logic is easy.

// The idea is to reverse every k-sized group of nodes one by one and link them together.
// 1. Make a pointer 'temp'. Its objective will be to point to head of every group to be reversed.
// 2. For every group, find the k-th node using a helper function getkThNode(), and point it by a pointer say kThNode.
//    If getkThNode() returns NULL, it means there are less than k nodes left in the LL.
// 3. Preserve the next group's head (i.e., (k+1)-th node) in a pointer say nextGroupHead. We are preserving it because k-th node
//    is going to get detached from LL and become the tail of current group so that we can reverse this k-sized group independently.
// 4. Now reverse this k-sized group using another helper function reverseLL(). No need to return anything from this function.
//    Input: 1 -> 2 -> 3 -> NULL
//    Output: 3 -> 2 -> 1 -> NULL
// 5. After reversal, temp stands at the tail of the reversed group, and the kThNode stands at the head of the reversed group, i.e.,
//    their positions got swapped after reversal.
//    Now, preserve the tail of the reversed group in a pointer say prevGroupTail. This pointer will be used to link two
//    consecutive reversed groups. Initially, prevGroupTail is NULL because there is no previous group for the first group.
//    But after reversing the first group, we can preserve its tail using prevGroupTail = temp; statement.
// 6. After reversal, do the attachment of previous reversed group with the current reversed group.
//    If we have just reversed the first group, we need to update the head of the original LL to point to kThNode because, after
//    reversal, the kThNode points to head of the first reversed group.
//    if we have reversed any group other than the first group, we need to link the previous group's tail (pointed by prevGroupTail)
//    to current group's head (pointed by kThNode).
// 7. Finally, repoint temp to point to nextGroupHead for processing the next group.
// 8. Continue this until temp becomes NULL. At the end, return head of the modified LL.

// Video Illustration: https://www.youtube.com/watch?v=lIar1skcQYI&t=357s

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
    // Helper function to reverse the linked list
    // Input: 1 -> 2 -> 3 -> NULL
    // Output: 3 -> 2 -> 1 -> NULL
    void reverseLL(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        while(currNode != NULL) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        // no need to return anything from this code
    }

    // Helper function to get the k-th node from the current position. If fewer than k nodes remain, returns NULL.
    ListNode* getkThNode(ListNode* temp, int k) {
        k = k - 1;
        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // T.C: O(n) for traversing all nodes + O(n) for reversing nodes = O(2n) ~ O(n)
    // S.C: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1) return head;

        ListNode* temp = head;   // objective is to keep temp at the head of every group to be reversed
        ListNode* prevGroupTail = NULL;   // tail of the previous reversed group

        while(temp != NULL) {
            ListNode* kThNode = getkThNode(temp, k);
            // If kThNode is NULL, it means fewer than k nodes are left. In that case, we just link the remaining part to temp and stop
            if(kThNode == NULL) {
                if(prevGroupTail != NULL) prevGroupTail->next = temp;   // if(prevGroupTail != NULL) is needed because prevGroupTail only exists when there are atleast k nodes in LL. prevlast is NULL for LLs having less than k nodes.
                break;
            }

            // Preserve the next group's head as kThNode is going to get detached now and become the tail of current group
            ListNode* nextGroupHead = kThNode->next;
            kThNode->next = NULL;   // detach current group (with head pointed by temp) so that it can be reversed independently

            // Reverse this k-sized group with head pointed by temp
            reverseLL(temp);   // after reversal, temp points to tail of the reversed group

            // Do the attachment of previous reversed group with the current reversed group
            if(temp == head) {   // if its the first group being reversed
                // temp points to original head of LL only when we have reversed the first group, moreover both temp and head point
                // to tail of the first reversed group. And the kThNode points to head of the first reversed group. Thus, we need to
                // update the head of the original LL to point to kThNode.
                head = kThNode;   // update head if we have reversed the first group
            } else {
                // If we have reversed any group other than the first group, we need to link the previous group's tail to
                // current group's head (current group's head is pointed by kThNode after reversal)
                prevGroupTail->next = kThNode;
            }

            // Preserve prevGroupTail to the tail of the reversed group. After reversal, temp stands at tail of the reversed group.
            prevGroupTail = temp;

            // Repoint temp to point to its correct position, i.e., the head of the next group to be processed
            temp = nextGroupHead;
        }

        return head;
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
