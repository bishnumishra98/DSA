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

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int prevSmallerElement(int x, vector<int> heights) {
        int n = heights.size();
        int ans;
        stack <int> st;
        st.push(-1);

        for(int i=0; i<n; i++) {
            int currElement = heights[i];

            while(currElement <= st.top()) {
                st.pop();
            }

            ans = st.top();

            st.push(currElement);
        }

        return ans;
    }

    int nextSmallerElement(int x, vector<int> heights) {
        int n = heights.size();
        int ans;
        stack <int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--) {
            int currElement = heights[i];

            while(currElement <= st.top()) {
                st.pop();
            }

            ans = st.top();

            st.push(currElement);
        }

        return ans;
    }

    // T.C: 
    // S.C: 
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v = heights;
        int area = 0;
        int maxArea = 0;

        for(int i=0; i<v.size(); i++) {
            int currElement = v[i];
            int prevSmallerIndex = prevSmallerElement(currElement, v);
            int nextSmallerIndex = nextSmallerElement(currElement, v);
            cout << prevSmallerIndex << " " << nextSmallerIndex << endl;
            int width = nextSmallerIndex - prevSmallerIndex + 1;
            
            area = width * v[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;        
    }
};

int main() {
    Solution obj;

    vector <int> heights{2, 1, 5, 6, 2, 3};

    cout << obj.largestRectangleArea(heights);

    return 0;
}
