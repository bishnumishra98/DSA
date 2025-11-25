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

// Optimal Algorithm:
// Same pattern: 'BaseBuildingPrograms\13. Stack\S10_NextGreaterElement.cpp'.
// CHEAT CODE OF THIS PROBLEM: Decreasing stack + RL traversal

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

// ------------------------------------------------------------------------------------------------------------

    // Stack objective: Decreasing stack, i.e., bottom of stack has index of the highest
    //                  temperature and top of stack has index of lowest temperature.
    // T.C: O(n)
    // S.C: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices of temperatures array

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            int currTemp = temperatures[i];

            // Continuously pop out top element of stack if current temperature is greater than or equal to temperature at top index of stack
            while(!st.empty() && currTemp >= temperatures[st.top()]) st.pop();

            // If stack is not empty → next warmer day exists
            if(!st.empty()) ans[i] = st.top() - i;   // number of days to wait = index at top of stack - current index
            else ans[i] = 0;

            // Now push the current temperature's index into the stack when it becomes the new "lowest" temperature
            st.push(i);
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
