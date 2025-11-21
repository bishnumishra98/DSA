// GFG: Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes
// the number of queries. Query can be of two types:
// 1. PUT x y: sets the value of the key x with value y
// 2. GET x: gets the value of key x if present else returns -1.
// The LRUCache class has two methods get() and put() which are defined as follows.
// 1. get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
// 2. put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache.
// If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
// 3. In the constructor of the class the capacity of the cache should be initialized.

// Example 1:
// Input: cap = 2, Q = 2, Queries = [["PUT", 1, 2], ["GET", 1]]
// Output: [2]
// Explanation: Cache Size = 2
// ["PUT", 1, 2] will insert the key-value pair (1, 2) in the cache,
// ["GET", 1] will print the value corresponding to Key 1, ie 2.

// Example 2:
// Input: cap = 2, Q = 8, Queries = [["PUT", 1, 2], ["PUT", 2, 3], ["PUT", 1, 5], ["PUT", 4, 5], ["PUT", 6, 7],
//        ["GET", 4], ["PUT", 1, 2], ["GET", 3]]
// Output: [5, -1]
// Explanation: Cache Size = 2
// ["PUT", 1, 2] will insert the pair (1,2) in the cache.
// ["PUT", 2, 3] will insert the pair (2,3) in the cache: 1->2, 2->3(the most recently used one is kept at the rightmost position) 
// ["PUT", 1, 5] will replace the value of 1 from 2 to 5 : 2 -> 3, 1 -> 5
// ["PUT", 4, 5] : 1 -> 5, 4 -> 5 (Cache size is 2, hence we delete the least recently used key-value pair)
// ["PUT", 6, 7] : 4 -> 5, 6 -> 7 
// ["GET", 4] : Prints 5 (The cache now looks like 6 -> 7, 4->5)
// ["PUT", 1, 2] : 4 -> 5, 1 -> 2  (Cache size is 2, hence we delete the least recently used key-value pair)
// ["GET", 3] : No key value pair having key = 3. Hence, -1 is printed.

// Algorithm: LRU (Least Recently Used) Cache can be implemented using a combination of a doubly linked list and a hash map.
// The doubly linked list contains the key-value pairs as data nodes, and the hashmap contains the keys and the node addresses
// of the corresponding nodes in the doubly linked list.

// 1. Create a dummy head and tail node to represent the boundaries of the doubly linked list. Initially link head to tail.
//    All new nodes will be added just after the head (most recently used position), i.e., nodes towards the head are the
//    most recently used, and nodes towards the tail are the least recently used.
//
// 2. For the get operation:
//    Case I:  If key exists in hashmap
//             i.   Retrieve the node from hashmap.
//             ii.  Remove the node from its current position in the doubly linked list.
//             iii. Insert the node right after the head (making it most recently used).
//             iv.  Return the value of the node.
//    Case II: If key does not exist in hashmap
//             i. Return -1.
//
// 3. For the put operation:
//    Case I:  If key exists in hashmap
//             i.   Retrieve the node from hashmap.
//             ii.  Update the value of the node.
//             iii. Remove the node from its current position in the doubly linked list.
//             iv.  Insert the node right after the head (making it most recently used).
//    Case II: If key does not exist in hashmap
//             Sub-case I:  If cache is not full:
//                          i.   Create a new node with the given key and value.
//                          ii.  Insert the new node right after the head.
//                          iii. Add the key and node address to the hashmap.
//             Sub-case II: If cache is full:
//                          i.   Identify the least recently used node (tail->prev).
//                          ii.  Delete its entry from the hashmap and delete the node from the doubly linked list.
//                          iii. Create a new node with the given key and value.
//                          iv.  Insert the new node right after the head.
//                          v.   Add the key and node address to the hashmap.

// Problem link: https://www.geeksforgeeks.org/problems/lru-cache/1

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k = 0, int v = 0): key(k), val(v), prev(NULL), next(NULL) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;   // key -> node's address
    Node *head, *tail;   // dummy head and tail to simplify operations

    // Remove or detach node from list (but do not delete memory here)
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node right after head (most recently used)
    void addToHead(Node* node) {
        // First attach new node between head->next and head, then adjust head->next's prev and head's next.
        // If you don't follow this order, you may lose the reference to head->next.
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node();   // dummy head
        tail = new Node();   // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Optional, but good practice to free memory. Destructor is called automatically when object goes out of scope.
    ~LRUCache() {
        Node* temp = head;
        while(temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    // T.C: O(1), S.C: O(1)
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;   // key not found
        Node* node = mp[key];
        // Move the accessed node to head (most recently used)
        removeNode(node);
        addToHead(node);
        return node->val;
    }

    // T.C: O(1), S.C: O(1)
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            // Key exists, update value and move to head
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addToHead(node);
        } else {
            // Key does not exist
            if(mp.size() == capacity) {   // if cache is full
                // Remove least recently used node (tail->prev)
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);   // detach from list
                delete lru;        // free memory
            }
            // If cache is not full or after removing LRU, add new node in the LL and key in the map
            Node* node = new Node(key, value);
            addToHead(node);
            mp[key] = node;
        }
    }
};


int main() {
    int cap = 2;
    LRUCache cache(cap);
    cache.put(1, 2);
    cache.put(2, 3);
    cache.put(1, 5);
    cache.put(4, 5);
    cache.put(6, 7);
    cout << cache.get(4) << endl;   // o/p: 5
    cache.put(1, 2);
    cout << cache.get(3) << endl;   // o/p: -1

    return 0;
}
