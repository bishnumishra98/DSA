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

// T.C: O(nlogn)
// S.C: O(1)
Node* sortList_bestApproach(Node* head) {
    
}

// function to print elements of linked list
void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    // Create a sample linked list: -1 -> 5 -> 3 -> 4 -> 0
    Node* head = new Node(-1);
    head->next = new Node(5);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(0);

    printLL(head);
    cout << "\n";
    
    Node* ans = sortList_naiveApproach(head);

    printLL(ans);

    return 0;
}
