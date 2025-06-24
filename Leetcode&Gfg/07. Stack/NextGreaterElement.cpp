// This problem is already solved in 'BaseBuildingPrograms\14. Stack\S10_NextGreaterElement.cpp'.

// gfg: Next Greater Element   --->   Given an array arr[ ] of size N having elements, the task is
// to find the next greater element for each element of the array in order of their appearance in
// the array. Next greater element of an element in the array is the nearest element on the right
// which is greater than the current element. If there does not exist next greater of current
// element, then next greater element for current element is -1. For example, next greater of the
// last element is always -1.

// Example 1:
// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1

// Example 2:
// Input: 
// N = 5, arr[] [6 8 0 1 3]
// Output:
// 8 -1 1 3 -1

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

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector <long long> ans(n);
        stack <long long> st;
        st.push(-1);

        // traversing array from right to left
        for(int i=n-1; i>=0; i--) {
            long long currElement = arr[i];

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
};

/*
NOTE: ONLY DIFFERENCES IN THIS CODE FROM 'NextSmallerElement' ARE:
      1) 'currElement >= st.top()' and '!st.empty()' conditions in while condition
      2) '!st.empty()' condition during storing top element of stack into 'ans'.
*/

int main() {
    Solution obj;

    vector<long long> arr = {1, 3, 2, 4};
    int n = 4;

    vector <long long> ans = obj.nextLargerElement(arr, n);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
