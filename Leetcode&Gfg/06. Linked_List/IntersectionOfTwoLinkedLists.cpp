// Leetcode: 160. Intersection of Two Linked Lists   --->   Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:
// The test cases are generated such that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

// Custom Judge:
// The inputs to the judge are given as follows (your program is not given these inputs):
// ● intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
// ● listA - The first linked list.
// ● listB - The second linked list.
// ● skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
// ● skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
// ● The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB
//   to your program. If you correctly return the intersected node, then your solution will be accepted.

// Example 1:
// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'
// Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the
// intersected node in A; There are 3 nodes before the intersected node in B.
// - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B)
// are different node references. In other words, they point to two different locations in memory, while the nodes with value 8
// in A and B (3rd node in A and 4th node in B) point to the same location in memory.

// Example 2:
// Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Intersected at '2'
// Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the
// intersected node in A; There are 1 node before the intersected node in B.

// Example 3:
// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: No intersection
// Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not
// intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values. The two lists do not intersect, so return null.

// Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int findLengthOfLL(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

public:
    // T.C: O(n1 + n2);   where n1 and n2 are the lengths of listA and listB respectively
    // S.C: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        int lengthA = findLengthOfLL(headA);
        int lengthB = findLengthOfLL(headB);
        int diff = abs(lengthA - lengthB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Advance the pointer of the longer list by 'diff' nodes so that both pointers are equally far from the end
        if(lengthA < lengthB) {
            while(diff) {
                tempB = tempB->next;
                diff--;
            }
        } else {   // if(lengthA >= lengthB)
            while(diff) {
                tempA = tempA->next;
                diff--;
            }
        }

        // Now, traverse both lists simultaneously until an intersection is found. Extra Note: while loop can also be written as: while(tempB != NULL) or while(tempA != NULL && tempB != NULL). But then return the correct pointer after the loop.
        while(tempA != NULL) {
            if(tempA == tempB) {
                break;
            } else {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }

        return tempA;
    }
};

int main() {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;   // creating intersection at node with value 8
    headB->next->next->next->next = headA->next->next->next;
    headB->next->next->next->next->next = headA->next->next->next->next;

    ListNode* intersectionNode = Solution().getIntersectionNode(headA, headB);
    if(intersectionNode != NULL) {
        cout << "Intersected at '" << intersectionNode->val << "'" << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
