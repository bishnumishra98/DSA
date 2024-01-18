// There may be a variant of question asked for the problems(S8 - S11), that we just solved; and
// that is you are asked to return special array but considering that original is circular.

// Let us take for example the problem 'NextGreaterElement':

// Example 1:
// Input:                       6  8  0  1  3
// Output(for regular array):   8 -1  1  3 -1
// Output(for circular array):  8 -1  1  3  6

// Algorithm:
// Same as for regular next or previous problems. The only difference is that now we have to
// duplicate the original array and double its size, then apply same logic.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C: O(n)
// S.C: O(n)
vector<int> nextLargerElement_circularArray(int* arr, int size) {
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

int main() {
    int arr[4] = {1, 3, 2, 4};
    int size = 4;

    vector <int> ans = nextLargerElement_circularArray(arr, size);

    for(auto i: ans) {
        cout << i << " ";
    }

    return 0;
}
