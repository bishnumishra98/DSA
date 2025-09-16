// Leetcode: 539. Minimum Time Difference   --->   Given a list of 24-hour clock time points in "HH:MM" format,
// return the minimum minutes difference between any two time-points in the list.

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn) + O(n) = O(nlogn);   where n is the timePoints.size()
    // S.C: O(n)
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;   // to store each time points in minutes
        
        // Step 1: Convert times to minutes
        for(string &t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        // Step 2: Sort the minutes
        sort(minutes.begin(), minutes.end());
        
        int n = minutes.size();
        int ans = INT_MAX;
        
        // Step 3: Find min diff between consecutive times
        for(int i = 1; i < n; i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        
        // Step 4: Circular case (last vs first); 24 hr = 1440 min
        ans = min(ans, 1440 - minutes[n - 1] + minutes[0]);
        
        return ans;
    }
};

int main() {
    vector<string> timePoints = {"23:59", "00:00"};
    Solution obj;

    cout << obj.findMinDifference(timePoints);

    return 0;
}
