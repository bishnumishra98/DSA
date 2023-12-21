// Leetcode: 141. Linked List Cycle   --->   Given head, the head of a linked list, determine if the
// linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list
// that can be reached again by continuously following the next pointer. Internally, pos is used to
// denote the index of the node that tail's next pointer is connected to. Note that pos is not passed
// as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

#include <iostream>
#include <map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // leetcode given function
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> table;   // by default bool value is initialized with false in a map

        ListNode* temp = head;
        while(temp != NULL) {
            if(table[temp] == false) {   // if table[temp] is false, this Node is unvisited before.
            // Thus we will mark this Node as visited, by marking true.
                table[temp] = true;
            } else {
                // if table[temp] is true, this Node is visited before, which signifies a cycle.
                return true;
            }
            temp = temp->next;
        }
        // if loop ends, it means complete linked list was traversed without any cycles.
        // Thus, we return false signifying that linked list contains no cycles.
        return false;
    }
};

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(3);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;   // node5 points to node3, making a cycle

    Solution obj;
    bool ans;
    ans = obj.hasCycle(head);

    cout << ans << endl;

    return 0;
}
