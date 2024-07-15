// GFG: Geek's training   --->   Geek is going for n day training program. He can perform any one of these three activities
// Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills,
// he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array
// of points points, corresponding to each day and activity.

// Example 1:
// Input:
// n = 3
// points = [[1,2,5],[3,1,1],[3,3,3]]
// Output:
// 11
// Explanation:
// Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day
// he will do fighting and earn 3 points so, maximum point is 11.

// Example 2:
// Input:
// n = 3
// points = [[1,2,5],[3,1,1],[3,2,3]]
// Output:
// 11
// Explanation:
// Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day
// he will do running and earn 3 points so, maximum point is 11.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int day, int last, vector<vector<int>>& points) {
        // Base case: When you are at index 0, i.e., 0th day; return the maximum points possible from the all days except the last day.
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task <= 2; task++) if(task != last) maxi = max(maxi, points[0][task]);
            return maxi;
        }

        int maxi = 0;
        for(int task = 0; task <= 2; task++) {
            if(task != last) {
                // Calculate earning by taking each task(except the last day's task) of current day and return the maximum one.
                int earning = points[day][task] + solve(day-1, task, points);
                maxi = max(maxi, earning);
            }
        }
        return maxi;
    }

    // T.C: O(3^n)
    // S.C: O(n)
    int maximumPoints_recursion(vector<vector<int>>& points, int n) {
        // Start computing maximum points collected from last element to first element. Starting with last day as '3',
        // means task 3 (T3) was the last task, which actually does not exists in the list. This signifies that none of
        // the tasks are performed yet. So geek is free to take up any task(T0, T1, T2) initially.
        return solve(n-1, 3, points);
    }

// ------------------------------------------------------------------------------------------------------------

    int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task <= 2; task++) if(task != last) maxi = max(maxi, points[0][task]);
            return maxi;
        }

        if(dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for(int task = 0; task <= 2; task++) {
            if(task != last) {
                int earning = points[day][task] + solve(day-1, task, points, dp);
                maxi = max(maxi, earning);
            }
        }
        dp[day][last] = maxi;
        return dp[day][last];
    }

    // T.C: O(n * 4) = O(n)
    // S.C: O(n)(recursion stack space) + O(n * 4) = O(n)
    int maximumPoints_memoization(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));   // kept size 4 as tasks are T0, T1, T2, T3(for initial recursive call)
        return solve(n-1, 3, points, dp);
    }

// -----------------------------------------------------------------------------------------------------------------------

    // T.C: O(n * 4 * 3) = O(n)
    // S.C: O(n * 4) = O(n)
    int maximumPoints_tabulation(vector<vector<int>>& points, int n) {
        
    }

// -----------------------------------------------------------------------------------------------------------------------

    // T.C: O(n * 4 * 3) = O(n)
    // S.C: O(n * 4) = O(n)
    int maximumPoints_tabulation_SO(vector<vector<int>>& points, int n) {
        
    }
};

int main() {
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,2,3}};
    int n = points.size();
    Solution sol;

    cout  << "maximumPoints_recursion: " << sol.maximumPoints_recursion(points, n) << endl;
    cout  << "maximumPoints_memoization: " << sol.maximumPoints_memoization(points, n) << endl;
    cout  << "maximumPoints_tabulation: " << sol.maximumPoints_tabulation(points, n) << endl;
    cout  << "maximumPoints_tabulation_SO: " << sol.maximumPoints_tabulation_SO(points, n);

    return 0;
}
