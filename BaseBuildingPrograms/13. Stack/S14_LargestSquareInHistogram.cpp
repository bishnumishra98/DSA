// Given an array of integers heights representing the histogram's bar height where the width
// of each bar is 1, return the area of the largest square in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 4

// Example 2:
// Input: heights = [2,4]
// Output: 4

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> indexOfPrevSmallerElement(vector<int> arr) {
    int size = arr.size();
    vector <int> ans(size);
    stack <int> st;
    st.push(-1);

    // traversing array from left to right
    for(int i=0; i<size; i++) {   // *ONLY THIS LINE IS CHANGED, REST ALL CODE IS SAME*
        int currElement = arr[i];

        // CHANGE 1: Instead of 'st.top()', we are comparing with v[st.top()]
        // ADDITION 1: When top element of stack is -1 in the beginning, we have to make
        //             sure while loop doesn't runs, because arr[-1] makes no sense.
        // popping stack until currElement becomes greater than top element of stack
        while(st.top()!= -1 && currElement <= arr[st.top()]) st.pop();

        // storing top element of stack in ans
        ans[i] = st.top();

        // CHANGE 2: Instead of pushing array elements, we are pushing index of array elements
        // pushing index of array element into stack
        st.push(i);
    }

    return ans;
}

vector<int> indexOfNextSmallerElement(vector<int> arr) {
    int size = arr.size();
    vector <int> ans(size);
    stack <int> st;
    st.push(-1);

    // traversing array from right to left
    for(int i=size-1; i>=0; i--) {
        int currElement = arr[i];

        // CHANGE 1: Instead of 'st.top()', we are comparing with v[st.top()]
        // ADDITION 1: When top element of stack is -1 in the beginning, we have to make
        //             sure while loop doesn't runs, because arr[-1] makes no sense.
        // popping stack until currElement becomes greater than top element of stack
        while(st.top()!= -1 && currElement <= arr[st.top()]) st.pop();

        // CHANGE 2: This case is exclusive only for indexOfNextSmallerElement(). We are
        // assuming that if no next smaller element is found, then we will keep -1 element
        // on the index just after the last element of the array.
        // Thus, all -1 in 'ans' shall be replaced by 'size;, i.e., next index of last element.
        if(st.top() == -1) ans[i] = size;
        else ans[i] = st.top();

        // CHANGE 3: Instead of pushing array elements, we are pushing index of array elements
        // pushing index of array element into stack
        st.push(i);
    }

    return ans;
}

// T.C: O(n)
// S.C: O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector <int> iopse(n);
    iopse = indexOfPrevSmallerElement(heights);

    vector <int> ionse(n);
    ionse = indexOfNextSmallerElement(heights);

    int maxArea = 0;

    for(int i=0; i<n; i++) {
        int width = ionse[i] - iopse[i] - 1;
        // ONLY HERE WE HAVE LITTLE CHANGE FOR CALCULATING AREA
        int side = min(heights[i], width);
        int area = side * side;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector <int> heights{2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights) << endl;
    
    return 0;
}
