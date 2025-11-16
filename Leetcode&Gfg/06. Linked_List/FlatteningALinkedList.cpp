// GFG: Flattening a Linked List   --->   Given a linked list containing n head nodes where every node in the linked list
// contains two pointers:
// (i) next points to the next node in the list.
// (ii) bottom points to a sub-linked list where the current node is the head.
// Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the
// linked list such that all the nodes appear in a single level while maintaining the sorted order.

// Note:
// 1. ↓ represents the bottom pointer and → represents the next pointer.
// 2. The flattened list will be printed using the bottom pointer instead of the next pointer.

// Example 1:
// Input:
// Image
// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
// Explanation: 
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 10 is pointing to 20 and so on.
// So, after flattening the linked list the sorted list will be 
// 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.

// Example 2:
// Input:
// Image
// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
// Explanation:
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 8 is pointing to 30 and so on.
// So, after flattening the linked list the sorted list will be 
// 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.

// Problem link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Algorithm: It is an easy divide and conquer algorithm.
// 1. First merge two lists at a time to form 1 list.
// 2. Then recursively merge another list with it. And finally, return 1 single merged list.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
private:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* tail = dummyNode;

        while(list1 != NULL && list2 != NULL) {
            if(list1->data < list2->data) {
                tail->bottom = list1;
                tail = list1;
                list1 = list1->bottom;
            } else {
                tail->bottom = list2;
                tail = list2;
                list2 = list2->bottom;
            }
            tail->next = NULL;   // ensure next pointer of appended node is cleared, since final list uses bottom pointer only
        }

        if(list1) tail->bottom = list1;
        else tail->bottom = list2;

        return dummyNode->bottom;
    }

public:
    // T.C: O(n * 2m)   where n = no. of linked lists, m = avg. no. of nodes in each linked list
    // S.C: O(n)   for recursive stack space
    Node *flatten(Node *root) {
        if(root == NULL || root->next == NULL) return root;

        Node* mergedHead = flatten(root->next);
        return mergeTwoLists(root, mergedHead);
    }
};

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);

    head->next->next = new Node(19);
    head->next->bottom = new Node(20);

    head->next->next->next = new Node(28);
    head->next->next->bottom = new Node(22);

    head->next->next->next->bottom = new Node(40);
    head->next->next->next->bottom->bottom = new Node(45);
    
    Node* flattenedHead = Solution().flatten(head);
    Node* temp = flattenedHead;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }

    return 0;
}
