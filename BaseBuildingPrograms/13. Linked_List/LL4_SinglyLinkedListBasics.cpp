#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* next;
    public:
        Node() {
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

int main() {
    // creating nodes
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(6);
    Node* fourth = new Node(8);
    Node* fifth = new Node(10);

    // creating linked list by joining all nodes
    

    return 0;
}