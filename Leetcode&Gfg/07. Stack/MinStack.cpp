// Leetcode: 155. Min Stack   --->   Design a stack that supports push, pop, top, and retrieving
// the minimum element in constant time. Implement the MinStack class:
// -> MinStack() initializes the stack object.
// -> void push(int val) pushes the element val onto the stack.
// -> void pop() removes the element on the top of the stack.
// -> int top() gets the top element of the stack.
// -> int getMin() retrieves the minimum element in the stack.
// -> You must implement a solution with O(1) time complexity for each function.

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Algorithm: We will create a vector of pairs. And store the elements of stack in 1st part of the
//            pair, and the smallest element of the stack till then, in the 2nd part pf pair.

#include <iostream>
#include <vector>
using namespace std;

/*
// Detailed code:
class MinStack {
public:
    vector <pair<int, int>> st;

    // constructor
    MinStack() { }
    
    // T.C: O(1)
    void push(int val) {
        if(st.empty()) {
            // if stack is empty, it means we are pushing the 1st element; i.e., it itself is
            // only the smallest element. So we push 'val' in both 'p.first' and 'p.second'.
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        } else {
            // if stack is non empty, then we push 'val' is 'p.first', and smallest element
            // of the stack till now, in 'p.second'.
            pair<int, int> p;
            p.first = val;
            int previousMin = st.back().second;
            p.second = min(previousMin, val);
            st.push_back(p);
        }
    }
    
    // T.C: O(1)
    void pop() {
        st.pop_back();
    }
    
    // T.C: O(1)
    int top() {
        pair<int, int> rightMostPair= st.back();
        return rightMostPair.first;
    }
    
    // T.C: O(1)
    int getMin() {
        pair<int, int> rightMostPair= st.back();
        return rightMostPair.second;
    }
};
*/

// Concise code
class MinStack {
public:
    vector <pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            // if vector is empty, it means we are pushing the 1st element; i.e., it itself is
            // only the smallest element. So we push 'val' in both 1st and 2nd part of pair.
            st.push_back({val, val});
        } else {
            // if stack is non empty, then we push 'val' is 1st part,
            // and smallest element of the stack till now, in 2nd part of pair.
            st.push_back({val, min(val, st.back().second)});
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

/*
int main() {
    // Create a MinStack static object
    MinStack obj;

    // Perform operations
    obj.push(3);
    obj.push(2);
    obj.push(5);
    obj.push(1);

    cout << "Top element: " << obj.top() << endl;
    cout << "Minimum element: " << obj.getMin() << endl;

    obj.pop();
    cout << "After pop, top element: " << obj.top() << endl;
    cout << "After pop, minimum element: " << obj.getMin() << endl;

    return 0;
}
*/

int main() {
    // Create a MinStack dynamic object
    MinStack* obj = new MinStack();

    // Perform operations
    obj->push(3);
    obj->push(2);
    obj->push(5);
    obj->push(1);

    cout << "Top element: " << obj->top() << endl;
    cout << "Minimum element: " << obj->getMin() << endl;

    obj->pop();
    cout << "After pop, top element: " << obj->top() << endl;
    cout << "After pop, minimum element: " << obj->getMin() << endl;

    // Cleanup
    delete obj;

    return 0;
}
