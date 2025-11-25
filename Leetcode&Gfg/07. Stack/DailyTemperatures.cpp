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

// Bruteforce Algorithm:
// 1. Initialize an array 'ans' with size as that of 'temperatures', and all values as 0. 'ans' array is initialized
//    with zeros, representing that initially, we assume there are no future warmer days.
// 2. For each day in 'temperatures', iterate through the subsequent days to find a warmer temperature.
//    If a warmer temperature is found, calculate the number of days between the current day and the warmer day,
//    and store this difference in the 'ans' array. If no warmer temperature is found, the value in 'ans' remains 0.
// 3. Return the 'ans' array after processing all days.

// Algorithm:
// 1. Initialize an array 'ans' with size as that of 'temperatures', and all values as 0. 'ans' array is initialized
//    with zeros, representing that initially, we assume there are no future warmer days.
// 2. Initialize an empty stack. The stack will help us to keep track of indices of temperatures that we have encountered
//    but not yet resolved (i.e., we haven't found a warmer temperature for these days). By keeping the stack in a
//    decreasing order of temperatures, we can efficiently determine the next warmer day. When we encounter a warmer
//    temperature, we can pop elements from the stack until we find a temperature that is warmer than the current one.
//    This allows us to calculate the number of days to wait for each of those popped indices in one go.
//    For each popped index, we can directly compute the difference between the current index and the popped index,
//    which gives us the number of days to wait for a warmer temperature.
//    For each day, check if the current temperature is warmer than the temperature at the top index of the stack.
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
    // T.C: O(n^2)
    // S.C: O(n)
    vector<int> dailyTemperatures_bruteforce(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            int currTemp = temperatures[i];
            for(int j = i + 1; j < n; j++) {
                if(temperatures[j] > currTemp) {
                    ans[i] = j - i;
                    break;
                }
            } 
        }

        return ans;
    }

// -------------------------------------------------------------------------------------

    // Stack objective: Indexes of temperatures in decreasing order, i.e., bottom of stack has indxes
    //                  of highest temperature and top of stack has indexes of lowest temperature.
    // T.C: O(n)
    // S.C: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;   // stack stores the indices of temperatures

        for(int i = 0; i < temperatures.size(); i++) {
            int currTemp = temperatures[i];
            while(!st.empty() && currTemp > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);   // now push the index of current temperature when it becomes the "cooler" temperature
        }
        return ans;
    }
};


int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution sol;

    vector<int> ans1 = sol.dailyTemperatures_bruteforce(temperatures);
    for(int i: ans1) cout << i << " ";
    cout << endl;
    vector<int> ans2 = sol.dailyTemperatures(temperatures);
    for(int i: ans2) cout << i << " ";

    return 0;
}
