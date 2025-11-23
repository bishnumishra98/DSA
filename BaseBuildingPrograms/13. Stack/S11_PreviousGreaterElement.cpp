// This problem is an extension of 'NextGreaterElement'

// Given an array arr[ ] of size N having elements, the task is to find the next greater element
// for each element of the array in order of their appearance in the array.

// Example 1:
// Input:   1  3  2  4
// Output: -1 -1  3 -1

// Example 2:
// Input:   6  8  0  1  3
// Output: -1 -1  8  8  8

// Algorithm(same as PreviousSmallerElement, just difference being we will start traversal from L-R):
// 1) We know that no elements are present on the left of first element of the array. Thus,
//    first element in special array will always be -1. So initialize a stack with -1.
// 2) Traversing from left to right of given array, we have to compare each element of array with
//    top element of stack. If array element is smaller than stack element, then that stack element
//    must be stored in the special array on the same index as that of the element in original array.
//    Post this, push the array element on the stack, and it becomes the new top element of stack.
// 3) If the array element is not smaller than stack element, pop out stack elements until array
//    element becomes smaller than stack element. Then follow the same process as we followed above.
//    Follow the above two steps until we reach leftmost element of array.

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

    // Traversing array from left to right
    for(int i=0; i<size; i++) {   // *ONLY THIS LINE IS CHANGED, REST ALL CODE IS SAME*
        int currElement = arr[i];

        // Popping out stack elements until array element becomes smaller than stack top element.
        while(!st.empty() && currElement >= st.top()) st.pop();

        // Storing top element of stack in ans
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1;

        // Pushing array element into stack
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
