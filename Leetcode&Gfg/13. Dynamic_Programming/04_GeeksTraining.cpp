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

// Algorithm: The problem is a variation of the "House Robber" problem, where we need to maximize the points collected
//            over n days. The key idea is to use recursion to keep track of the maximum points that can be
//            collected on each day while ensuring that the same activity is not performed on consecutive days.
//            We can use memoization or tabulation to optimize the recursive solution and avoid redundant calculations.
// 1. Recursion: The recursive function will take the current day(initially passing the last day) and the last activity
//               performed(initially passing T3 which doesn't exists) as arguments.
// 2. Base Case: If we are at the first day, we can choose any activity among the three available activities except
//               the last activity performed. We will return the maximum points that can be collected on that day.
//               This is done by iterating through the three activities and checking if the current activity is not
//               the same as the last activity performed. If it is not, we will take the maximum points of that activity.
//               We will return the maximum points that can be collected on that day.
// 3. Recursive Case: For each day, we will iterate through the three activities except the last activity performed to
//                    calculate the maximum points that can be collected. We will call the recursive function for the
//                    previous day with the current activity as the last activity.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // solve() function returns the maximum points collected till day 'day'. It takes two varying arguments: current day
    // and the last day's task that was performed so that we do not repeat the last day's task on current day.
    int solve(int day, int last, vector<vector<int>>& points) {
        // Base case: When you are at index 0, i.e., 0th day; return the maximum points possible from the days
        // except the task performed on the last day.
        // The last day's task is represented by the variable 'last'. Example: If last = 0, it means the last task was T0,
        // so we can take T1 or T2 on the current day.
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task <= 2; task++) {
                // Apart from the last day's task, we can take the maximum points of any task on the current day.
                if(task != last) maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }

        int maxi = 0;
        for(int task = 0; task <= 2; task++) {
            if(task != last) {   // if the task is not the same as the last day's task, we can take it.
                // Calculate the maximum points for the current day by individually adding the merits of each of the two
                // possible tasks on the current day with the maximum points collected from the previous day (day - 1).
                int earning = points[day][task] + solve(day - 1, task, points);   // solve(currrent day's task, last day's task, points)
                maxi = max(maxi, earning);
            }
        }
        return maxi;
    }

    // T.C: O(3^n)
    // S.C: O(n)
    int maximumPoints_recursion(vector<vector<int>>& points, int n) {
        // Start computing maximum points collected from last element to first element.
        // solve() function is called with first argument as the last day, i.e., n-1. The second argument is the task
        // performed on the previous day. As we are starting from the last day, we can assume that the task performed
        // on the previous day is T3 (which does not exist in the list of tasks). This signifies that none of
        // the tasks were performed. So geek is free to take up any task(T0, T1, T2) initially.
        return solve(n - 1, 3, points);
    }

// ------------------------------------------------------------------------------------------------------------

    int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task <= 2; task++) if(task != last) maxi = max(maxi, points[0][task]);
            return maxi;
        }

        if(dp[day][last] != -1) return dp[day][last];   // if this subproblem has been previously solved, return it.

        int maxi = 0;
        for(int task = 0; task <= 2; task++) {
            if(task != last) {
                int earning = points[day][task] + solve(day - 1, task, points, dp);
                maxi = max(maxi, earning);
            }
        }
        dp[day][last] = maxi;   // dp[day][last] stores the maximum points collected till day 'day' when last day's task was 'last'
        return dp[day][last];
    }

    // T.C: O(n * 4) = O(n)
    // S.C: O(n)(recursion stack space) + O(n * 4) = O(n)
    int maximumPoints_memoization(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));   // kept column size 4 as tasks are T0, T1, T2, T3(for initial recursive call)
        return solve(n - 1, 3, points, dp);
    }

// -----------------------------------------------------------------------------------------------------------------------

    // T.C: O(n * 4 * 3) = O(n)
    // S.C: O(n * 4) = O(n)
    int maximumPoints_tabulation(vector<vector<int>>& points, int n) {
        // Create a 2D DP (Dynamic Programming) table to store the maximum points
        // dp[i][j] represents the maximum points at day i, considering the last activity as j
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // Base cases: Initialize the DP table for the first day (day 0). At dp[0][last], store the
        // maximum possible points by performing any of the task except the last day's task.
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Populate 'dp' array starting from day 1 to day 'n-1'
        for(int day = 1; day <= n-1; day++) {
            for(int last = 0; last <= 3; last++) {
                // Iterate through the tasks for the current day (just copy paste the memoization logic)
                for(int task = 0; task <= 2; task++) {
                    if(task != last) {
                        int earning = points[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], earning);
                    }
                }
            }
        }

        return dp[n - 1][3];   // return the maximum points for the last day
    }

// -----------------------------------------------------------------------------------------------------------------------

    // T.C: O(n * 4 * 3) = O(n)
    // S.C: O(4)
    int maximumPoints_tabulation_SO(vector<vector<int>>& points, int n) {
        // Initialize a vector to store the maximum points for the previous day's activities
        vector<int> prev(4, 0);

        // Initialize the DP table for the first day (day 0)
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Iterate through the days starting from day 1
        for(int day = 1; day < n; day++) {
            // Create a temporary vector to store the maximum points for the current day's activities
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                // Iterate through the tasks for the current day
                for(int task = 0; task <= 2; task++) {
                    if(task != last) {
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (stored in prev)
                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            // Update prev with the maximum points for the current day
            prev = temp;
        }

        // The maximum points for the last day with any activity can be found in prev[3]
        return prev[3];
    }
};

int main() {
    vector<vector<int>> points = {{1, 2, 5},{3, 1, 1},{3, 2, 3}};
    int n = points.size();
    Solution sol;

    cout  << "maximumPoints_recursion: " << sol.maximumPoints_recursion(points, n) << endl;
    cout  << "maximumPoints_memoization: " << sol.maximumPoints_memoization(points, n) << endl;
    cout  << "maximumPoints_tabulation: " << sol.maximumPoints_tabulation(points, n) << endl;
    cout  << "maximumPoints_tabulation_SO: " << sol.maximumPoints_tabulation_SO(points, n);

    return 0;
}
