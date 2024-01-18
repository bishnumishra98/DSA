// Given an array of positive integers, return a special array of same size containing previous
// smaller element.

// Example 1:
// Input:   8  4  6  2  3
// Output: -1 -1  4 -1  2

// Example 2:
// Input:   2  4  5  3  3
// Output: -1  2  4  2  2

// Algorithm(same as NextSmallerElement, just difference is that we will start traversal from L to R):
// 1) We know that no elements are present on the left of first element of the array. Thus,
//    first element in special array will always be -1. So initialize a stack with -1.
// 2) Traversing from left to right of given array, we have to compare each element of array with
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
vector<int> previousSmallerElement(int* arr, int size) {
    vector <int> ans(size);
    stack <int> st;
    st.push(-1);

    // traversing array from right to left
    for(int i=0; i<size; i++) {   // *ONLY THIS LINE IS CHANGED, REST ALL CODE IS SAME*
        int currElement = arr[i];

        // popping stack until currElement becomes greater than top element of stack
        while(currElement <= st.top()) {
            st.pop();
        }

        // storing top element of stack in ans
        ans[i] = st.top();

        // pushing array element into stack
        st.push(currElement);
    }

    return ans;
}

int main() {
    int arr[5] = {8, 4, 6, 2, 3};
    int size = 5;

    vector <int> ans = previousSmallerElement(arr, size);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
