// Leetcode: 739. Daily Temperatures   --->   Given an array of integers temperatures represents the daily temperatures,
// return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer
// temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Algorithm:
// 1. Initialize an array 'ans' with size as that of 'temperatures', and all values as 0. 'ans' array is initialized
//    with zeros, representing that initially, we assume there are no future warmer days.
// 2. Initialize an empty stack. The stack will help us to keep track of indices of temperatures that we have encountered
//    but not yet resolved (i.e., we haven't found a warmer temperature for these days). By keeping the stack in a
//    decreasing order of temperatures, we can efficiently determine the next warmer day. When we encounter a warmer
//    temperature, it will resolve all previous days in the stack that are cooler than the current day.
// 3. For each day, check if the current temperature is warmer than the temperature at the top index of the stack.
//    If it is, this means we have found the next warmer day for the day at the top index of the stack. Thus,
//    calculate the number of days between the current day and the day at the top index of stack, and store this difference
//    in the 'ans' array. Post this, pop the stack.
//    Continue this process using a loop, until the stack is empty or the current temperature is cooler than the temperature
//    at the top index of stack. At this point, stop the loop and push the current day index into the stack. In this way,
//    the top elements of stack remains cooler than the below ones, and this stack helps to populate 'ans' array accordingly.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(temperatures);
    for(int i: ans) cout << i << " ";

    return 0;
}
