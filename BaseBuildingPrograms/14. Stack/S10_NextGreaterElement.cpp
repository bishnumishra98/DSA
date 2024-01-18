// This problem is similar to 'BaseBuildingPrograms\14. Stack\S8_NextSmallerElement.cpp',
// the only difference being we have to find next greater element here.

// Given an array arr[ ] of size N having elements, the task is to find the next greater element
// for each element of the array in order of their appearance in the array.

// Example 1:
// Input:   1  3  2  4
// Output:  3  4  4 -1

// Example 2:
// Input:   6  8  0  1  3
// Output:  8 -1  1  3 -1

// Algorithm:
// 1) We know that no elements are present on the right of last element of the array. Thus,
//    last element in special array will always be -1. So initialize a stack with -1.
// 2) Traversing from right to left of given array, we have to compare each element of array with
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
vector<int> nextLargerElement(int* arr, int size){
    vector <int> ans(size);
    stack <int> st;
    st.push(-1);

    // traversing array from right to left
    for(int i=size-1; i>=0; i--) {
        int currElement = arr[i];

        // popping out stack elements until array element becomes smaller than stack top element.
        while(!st.empty() && currElement >= st.top()) {
            st.pop();
        }

        // storing top element of stack in ans
        if(!st.empty())
            ans[i] = st.top();
        else
            ans[i] = -1;

        // pushing array element into stack
        st.push(currElement);
    }

    return ans;
}


/*
NOTE: ONLY DIFFERENCES IN THIS CODE FROM 'NextSmallerElement' ARE:
      1) 'currElement >= st.top()' and '!st.empty()' conditions in while condition
      2) '!st.empty()' condition during storing top element of stack into 'ans'.
*/

int main() {
    int arr[4] = {1, 3, 2, 4};
    int size = 4;

    vector <int> ans = nextLargerElement(arr, size);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
