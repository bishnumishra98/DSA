// This problem is an extension of 'NextGreaterElement'

// Given an array arr[ ] of size N having elements, the task is to find the next greater element
// for each element of the array in order of their appearance in the array.

// Example 1:
// Input:   1  3  2  4
// Output: -1 -1  3 -1

// Example 2:
// Input:   6  8  0  1  3
// Output: -1 -1  8  8  8

// Bruteforce Algorithm:
// 1. Traverse the array from left to right.
// 2. For each element at ith index, traverse the array from (i - 1)th index to leftmost index, and check for the first
//    element greater than the element at ith index.
// 3. If found, place that element at ith index of special array, else place -1 there.

// Optimal Algorithm:
// CHEAT CODE OF THIS PROBLEM: Decreasing stack + LR traversal
// ● Stack objective: Bigger elements at bottom, smaller elements on top
// ● Array traversal: Left to Right
// 1. We know that no elements are present on the left of first element of the array. Thus,
//    first element in special array will always be -1. So initialize a stack with -1.
// 2. Traversing from left to right of given array, we have to compare each element of array with
//    top element of stack. If current array element is greater than or equal to top element of stack, we pop out the
//    top element of stack until we find a bigger element than current array element. In ensures the stack has bigger elements
//    at bottom and smaller elements at top.
// 3. After popping out all the smaller or equal elements than current array element, the top element of stack
//    will be the previous greater element for current array element. We store that top element of stack in special array.
// 4. Finally, we push the current array element into stack and move to the next element on right of current array element.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C: O(n)
// S.C: O(n)
vector<int> nextGreaterElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    // Traverse array from left to right
    for(int i = 0; i < size; i++) {
        int currElement = arr[i];

        // Continuously pop out top element of stack if current array element is greater than or equal to top element of stack
        while(!st.empty() && currElement >= st.top()) st.pop();

        // Store top element of stack in ans
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1;

        // Push the smaller array element into stack now
        st.push(currElement);
    }

    return ans;
}


/*
NOTE: ONLY DIFFERENCES IN THIS CODE FROM 'PreviousSmallerElement' ARE:
      1) 'currElement >= st.top()' and '!st.empty()' conditions in while condition
      2) '!st.empty()' condition during storing top element of stack into 'ans'.
*/

int main() {
    vector<int> arr = {1, 3, 2, 4};

    vector <int> ans = nextGreaterElement(arr);   // o/p: -1 -1 3 -1

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
