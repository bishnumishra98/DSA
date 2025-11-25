// Leetcode: 155. Min Stack   --->   Design a stack that supports push, pop, top, and retrieving the minimum element
// in constant time.

// Implement the MinStack class:

// ● MinStack() initializes the stack object.
// ● void push(int val) pushes the element val onto the stack.
// ● void pop() removes the element on the top of the stack.
// ● int top() gets the top element of the stack.
// ● int getMin() retrieves the minimum element in the stack.
// ● You must implement a solution with O(1) time complexity for each function.

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<pair<int, int>> st;
    
public:
    MinStack() {
        // No need to do anything here as vector 'st' will be initialized
        // automatically when MinStack object is created.
    }
    
    void push(int val) {
        if(st.empty()) {
            // If vector is empty, it means we are pushing the 1st element; i.e., it itself is
            // only the smallest element. So we push the same 'val' in both 1st and 2nd part of pair.
            st.push_back({val, val});
        } else {
            // If stack is non empty, then we push 'val' in 1st part of pair,
            // and smallest element of the stack till now, in 2nd part of pair.
            st.push_back({val, min(val, st.back().second)});   // st.back() gives the last pair in the vector
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};


int main() {
    // Create a MinStack static object
    MinStack obj;

    // Perform operations
    obj.push(3);
    obj.push(2);
    obj.push(5);
    obj.push(1);

    cout << "Top element: " << obj.top() << endl;   // o/p: 1
    cout << "Minimum element: " << obj.getMin() << endl;   // o/p: 1

    obj.pop();
    cout << "After pop, top element: " << obj.top() << endl;   // o/p: 5
    cout << "After pop, minimum element: " << obj.getMin() << endl;   // o/p: 2

    return 0;
}
