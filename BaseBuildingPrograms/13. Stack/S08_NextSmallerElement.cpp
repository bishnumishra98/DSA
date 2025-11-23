// Given an array of positive integers, return a special array of same size following this rule:
// For an element at ith, start traversing elements from (i + 1)th index towards right of the array,
// and place the first element smaller than the element at ith index, on arr[i]. If none of the
// elements towards right is found to be smaller than the element at ith index, place -1 over there.

// Example 1:
// Input:   8  4  6  2  3
// Output:  4  2  2 -1 -1

// Example 2:
// Input:   2  4  5  3  3
// Output: -1  3  3 -1 -1

// Algorithm:
// Stack behaviour: bigger elements on bottom, smaller elements on top
// 1) We know that no elements are present on the right of last element of the array. Thus,
//    last element in special array will always be -1. So initialize a stack with -1.
// 2) Traversing from right to left of given array, we have to compare each element of array with
//    top element of stack. If array element is greater than stack element, then that stack element
//    must be stored in the special array on the same index as that of the element in original array.
//    Post this, push the array element on the stack, and it becomes the new top element of stack.
// 3) If the array element is not greater than stack element, pop out stack elements until array
//    element becomes greater than stack element. Then follow the same process as we followed above.
//    Follow the above two steps until we reach leftmost element of array.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C: O(n)
// S.C: O(n)
vector<int> nextSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);
    
    stack<int> st;
    st.push(-1);

    // Traversing array from right to left
    for(int i = size - 1; i >= 0; i--) {
        int currElement = arr[i];

        // Popping stack until currElement becomes greater than top element of stack
        while(currElement <= st.top()) st.pop();

        // Storing top element of stack in ans
        ans[i] = st.top();

        // Pushing array element into stack
        st.push(currElement);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 4, 5, 3, 3};

    vector<int> ans = nextSmallerElement(arr);

    for(auto i: ans) {
        cout << i << " ";   // o/p: -1 3 3 -1 -1
    }

    return 0;
}
