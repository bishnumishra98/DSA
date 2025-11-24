// There may be a variant of question asked for the problems(S08 - S11), that we just solved; and
// that is you are asked to return special array, considering original array as circular.

// Let us take for example the problem 'NextGreaterElement':

// Example 1:
// Input:                       6  8  0  1  3
// Output(for regular array):   8 -1  1  3 -1
// Output(for circular array):  8 -1  1  3  6

// Algorithm:
// Same as for regular next or previous problems. The only difference is that now we have to
// duplicate the original array and double its size, then apply same logic. By duplicating the
// original array, we get a set of array for the last element of the given array so that the last
// element may get its next greater element anywhere in the duplicate set of elements.
// Don't initialize a new array of same size, it would increase space complexity. Instead think of
// it as an imaginary array, and let index of the array range from 0 to (2 * n) - 1; and replace all
// 'i' with 'i % n'. For example, for given array of size 5:
// Array:           6  8  0  1  3
// Indexes(i):      0  1  2  3  4

// ImaginaryArray:  6  8  0  1  3  6  8  0  1  3
// Indexes(i):      0  1  2  3  4  5  6  7  8  9
// [i % n]:         0  1  2  3  4  0  1  2  3  4

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C: O(n)
// S.C: O(n)
vector<int> nextGreaterElement_circularArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    // Traverse array from right to left
    for(int i = 2 * n -  1; i >= 0; i--) {    // CHANGE 1
        int currElement = arr[i % n];   // CHANGE 2

        // Continuously pop out top element of stack if current array element is greater than or equal to top element of stack
        while(!st.empty() && currElement >= st.top()) st.pop();

        // Store top element of stack in ans
        if(i < n) {   // ADDITION 1 (this condition is necessary as we want only elements from the original array to be an element of 'ans')
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
        }

        // Push the smaller array element into stack now
        st.push(currElement);
    }

    return ans;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int size = 5;

    vector <int> ans = nextGreaterElement_circularArray(arr);

    for(auto i: ans) {
        cout << i << " ";   // o/p: 8 -1 1 3 6
    }

    return 0;
}
