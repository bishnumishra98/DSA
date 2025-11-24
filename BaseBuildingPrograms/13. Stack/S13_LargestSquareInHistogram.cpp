// Another variant of the Largest Rectangle in Histogram problem 'Leetcode&Gfg\07. Stack\LargestRectangleInHistogram.cpp'.

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

// CHEAT CODE: Increasing stack + LR traversal
vector<int> indexOfPrevSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);   // ans will contain indexes of previous smaller elements
    stack<int> st;
    st.push(-1);

    // Traverse array from left to right
    for(int i = 0; i < size; i++) {
        int currElement = arr[i];

        // Continuously pop out top element of stack if arr[top element] is greater than or equal to current array element.
        // This makes sure that stack has indexes of smaller elements at bottom and indexes of bigger elements at top.
        while(st.top() != -1 && arr[st.top()] >= currElement) st.pop();

        // Store top element of stack in ans
        ans[i] = st.top();

        // Push the bigger array element's index into stack now
        st.push(i);
    }

    return ans;
}

// CHEAT CODE: Increasing stack + RL traversal
vector<int> indexOfNextSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);   // ans will contain indexes of next smaller elements
    stack<int> st;
    st.push(-1);

    // Traverse array from right to left
    for(int i = size - 1; i >= 0; i--) {
        int currElement = arr[i];

        // Continuously pop out top element of stack if arr[top element] is greater than or equal to current array element.
        // This makes sure that stack has indexes of smaller elements at bottom and indexes of bigger elements at top.
        while(st.top() != -1 && arr[st.top()] >= currElement) st.pop();

        // Store top element of stack in ans. If stack top is -1, it means no 
        // smaller element is found on right, thus store size of array in ans.
        if(st.top() == -1) ans[i] = size;
        else ans[i] = st.top();

        // Push the bigger array element's index into stack now
        st.push(i);
    }

    return ans;
}

// T.C: O(n)
// S.C: O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> iopse = indexOfPrevSmallerElement(heights);
    vector<int> ionse = indexOfNextSmallerElement(heights);

    int maxArea = 0;
    for(int i = 0; i < n; i++) {       
        // For largest square, side will be minimum of height and width
        int side = min(heights[i], ionse[i] - iopse[i] - 1);

        int area = side * side;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights) << endl;   // o/p: 4
    
    return 0;
}
