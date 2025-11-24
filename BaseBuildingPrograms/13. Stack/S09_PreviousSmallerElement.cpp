// This problem is an extension of 'NextSmallerElement'.

// Given an array of positive integers, return a special array of same size containing previous
// smaller element.

// Example 1:
// Input:   8  4  6  2  3
// Output: -1 -1  4 -1  2

// Example 2:
// Input:   2  4  5  3  3
// Output: -1  2  4  2  2

// Bruteforce Algorithm:
// 1. Traverse the array from left to right.
// 2. For each element at ith index, traverse the array from (i - 1)th index to leftmost index, and check for the first
//    element smaller than the element at ith index.
// 3. If found, place that element at ith index of special array, else place -1 there.

// Optimal Algorithm:
// CHEAT CODE OF THIS PROBLEM: Increasing stack + LR traversal
// ● Stack objective: Smaller elements at bottom, bigger elements on top
// ● Array traversal: Left to Right
// 1. We know that no elements are present on the left of first element of the array. Thus,
//    first element in special array will always be -1. So initialize a stack with -1.
// 2. Traversing from left to right of given array, we have to compare each element of array with
//    top element of stack.
//    If top element of stack is bigger than or equal to current array element, we pop out the top element of stack
//    until we find a smaller element than current array element. In ensures the stack has smaller elements
//    at bottom and bigger elements at top.
// 3. After popping out all the bigger or equal elements than current array element, the top element of stack
//    will be the previous smaller element for current array element. We store that top element of stack in special array.
// 4. Finally, we push the current array element into stack and move to the next element on right of current array element. 


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C: O(n)
// S.C: O(n)
vector<int> previousSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    // Traverse array from left to right
    for(int i = 0; i < size; i++) {   // *ONLY THIS LINE IS CHANGED, REST ALL CODE IS SAME*
        int currElement = arr[i];

        // Continuously pop out top element of stack if top element of stack is greater than or equal to current array element
        while(st.top() >= currElement) st.pop();

        // Store top element of stack in ans
        ans[i] = st.top();

        // Push the bigger array element into stack now
        st.push(currElement);
    }

    return ans;
}

int main() {
    vector<int> arr = {8, 4, 6, 2, 3};

    vector <int> ans = previousSmallerElement(arr);

    for(auto i: ans) {
        cout << i << " ";   // o/p: -1 -1 4 -1 2
    }

    return 0;
}
