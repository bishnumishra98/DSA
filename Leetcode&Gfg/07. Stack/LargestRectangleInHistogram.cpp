// Leetcode: 84. Largest Rectangle in Histogram   --->    Given an array of integers heights
// representing the histogram's bar height where the width of each bar is 1, return the area
// of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4

#include <bits/stdc++.h>
using namespace std;

// T.C: O(n^2)
// S.C: O(1)
int largestRectangleArea_bruteForce(vector<int>& heights) {
    int n = heights.size();
    int area = 0;
    int maxArea = 0;

    // Traverse every bar and find the largest rectangle with the current bar
    for(int i = 0; i < n; i++) {
        int left = i;
        int right = i;

        // Expand towards left as long as the bars are taller or equal to heights[i]
        while(left > 0 && heights[left - 1] >= heights[i]) left--;

        // Expand towards right as long as the bars are taller or equal to heights[i]
        while(right < (n - 1) && heights[right + 1] >= heights[i]) right++;

        area = (right - left + 1) * heights[i];   // area = width * height
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

//--------------------------------------------------------------------------------------

// CHEAT CODE: Increasing stack + LR traversal
vector<int> indexOfPrevSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    // Traverse array from left to right
    for(int i = 0; i < size; i++) {
        int currElement = arr[i];

        // Continuously pop out top element of stack if arr[top element] is greater than or equal to current array element
        while(st.top() != -1 && arr[st.top()] >= currElement) st.pop();

        // Store top element of stack in ans
        ans[i] = st.top();

        // Push the bigger array element index into stack now
        st.push(i);
    }

    return ans;
}

// CHEAT CODE: Increasing stack + RL traversal
vector<int> indexOfNextSmallerElement(vector<int>& arr) {
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    // Traverse array from right to left
    for(int i = size - 1; i >= 0; i--) {
        int currElement = arr[i];

        // Continuously pop out top element of stack if arr[top element] is greater than or equal to current array element
        while(st.top() != -1 && arr[st.top()] >= currElement) st.pop();

        // Store top element of stack in ans. If stack top is -1, it means no 
        // smaller element is found on right, thus store size of array in ans.
        if(st.top() == -1) ans[i] = size;
        else ans[i] = st.top();

        // Push the bigger array element index into stack now
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
        int area = (ionse[i] - iopse[i] - 1) * heights[i];   // area = width * height
        maxArea = max(maxArea, area);
    }

    return maxArea;
}


int main() {
    vector <int> heights{2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea_bruteForce(heights) << endl;
    cout << largestRectangleArea(heights);

    return 0;
}
