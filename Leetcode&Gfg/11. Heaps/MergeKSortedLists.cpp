// Leetcode 23. Merge k Sorted Lists   --->   You are given an array of k linked-lists lists, each linked-list
// is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

// This problem is exactly same as 'BaseBuildingPrograms\18. Heaps\H11_MergeKSortedArrays.cpp', the
// only difference being there arrays were to be merged, and here linked lists are to be merged.

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

// Utility function to print the linked list
void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    // Comparator for the priority queue
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node values
        }
    };

    // T.C: O(nlogk);   where n = total number of elements across all linked lists, and O(logk) time is required
    //                  to push each element into the heap and extract from heap from k linked lists. Thus, for
    //                  n elements, total time required to push and extract from heap will be O(nlogk).
    // S.C: O(n+k);   At any given time, the min-heap stores at most k elements (one from each linked list).
    //                Hence, the space required for the min-heap is O(k). The merged linked list ans will store
    //                all n elements, thus it will require O(n) space. Thus, overall space complexity is O(n+k).
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap (priority queue) to keep track of the smallest elements from each list
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Initialize the heap with the head node of each list
        for(auto list : lists) {
            if(list) {   // Ensure the list is not empty
                minHeap.push(list);
            }
        }

        // Create a dummy node to help construct the result list.
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;   // 'current' is a pointer to the 'dummy' node

        // Extract elements from the heap, add into 'current' and keep adding new elements from the lists into the heap
        while(!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Append this node to the merged linked list
            current->next = smallest;
            current = current->next;   // Move the current pointer to the new last node

            // If there is a next node in the same list, push it into the heap
            if(smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        // The dummy node's next pointer points to the head of the merged list
        ListNode* mergedHead = dummy->next; // Store the head of the merged list
        delete dummy;   // Free the memory allocated for the dummy node

        return mergedHead;
    }
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

    vector<ListNode*> lists = {head1, head2, head3};

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    printLL(mergedList);

    return 0;
}
