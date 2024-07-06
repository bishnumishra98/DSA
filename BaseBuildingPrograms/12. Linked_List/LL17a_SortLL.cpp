#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
class Node {
    public:
        int data;
        Node *next;
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node *next) : data(x), next(next) {}
};

// function to print elements of linked list
void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// T.C: O(nlogn)
// S.C: O(n);   n is the size of vector we are using
Node* sortList_naiveApproach(Node* head) {   // brute force approach is also called naive approach
    Node* temp = head;
    vector <int> v;
    
    // inserting all values of LL into a vector
    while(temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    // sorting the vector
    sort(v.begin(), v.end());

    temp = head;   // repointing temp pointer to head of LL

    // inserting all elements of vector back to the LL
    int i = 0;
    while(temp != NULL) {
        temp->data = v[i];
        temp = temp->next;
        i++;
    }

    return head;
}

// .....................................................................................

// This function receives a list and returns mid index(left one if 2 mids) of that list. 
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// This function receives two sorted lists, and returns a sorted list made by combining the two sorted lists
Node* mergeSortedList(Node* p1, Node* p2) {
    Node* ans = new Node(0);   // 'ans' will the temporary node on which the merged list will be build
    Node* temp = ans;

    while(p1 != NULL && p2 != NULL) {
        if(p1->data < p2->data) {
            temp->next = p1;
            p1 = p1->next;
        } else {
            temp->next = p2;
            p2 = p2->next;
        }
        temp = temp->next;
    }

    // One of the above list will finish early, and break the while loop.
    // In this case, point temp directly to the list which had some nodes left.
    if(p1 != NULL || p2 != NULL) {
        temp->next = (p1 != NULL) ? p1 : p2;
    }

    return ans->next;
}

// T.C: O(nlogn)
// S.C: O(1)
Node* sortList_mergeSortApproach(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* mid = findMid(head);
    Node* head2 = mid->next;
    mid->next = NULL;

    // Dividing the LL into two halves from 'first to mid' called as 'left_half',
    // and from 'mid->next to end' called as 'right_half'.
    Node* left_half = sortList_mergeSortApproach(head);
    Node* right_half = sortList_mergeSortApproach(head2);

    return mergeSortedList(left_half, right_half);   // merging 'left_half' and 'right_half'
}

int main() {
    // Create a sample linked list: 10 -> 50 -> 60 -> 40 -> 30 -> 20
    Node* head = new Node(10);
    head->next = new Node(50);
    head->next->next = new Node(60);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(20);

    printLL(head);
    cout << "\n";
    
    // Node* ans = sortList_naiveApproach(head);
    Node* ans = sortList_mergeSortApproach(head);

    printLL(ans);

    return 0;
}
