// gfg: 0-1 Knapsack Problem   --->   You are given weights and values of N items, put these items in a knapsack of capacity W
// to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items
// respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that
// sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or
// dont pick it (0-1 property).

// Example 1:
// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3.
// knapsack capacity(W): 4kg
// Thus, sum of items weighing less than or equal 4kg can only be placed in the knapsack.
// Weight: Item1(4Kg) Item2(5Kg) Item3(1Kg)  Value(Rs.)
//             0          0          0          0
//             0          0          1          3
//             0          1          0          0 (not possible to keep due to overweight, W < 5kg)
//             0          1          1          0 (not possible to keep due to overweight)
//             1          0          0          1
//             1          0          1          0 (not possible to keep due to overweight, W < (4+1)Kg)
//             1          1          0          0 (not possible to keep due to overweight, W < (4+5)Kg)
//             1          1          1          0 (not possible to keep due to overweight, W < (4+5+1)Kg)

// Example 2:
// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

// Your Task:
// Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n
// as a parameter and returns the maximum possible value you can get.

// DP PATTERN: Include/Exclude

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int solve(int W, int wt[], int val[], int index, int n) {
            // Base case: If we reach beyond the last item, return 0 value
            if(index >= n) return 0;

            // Case 1: Include the current item if its weight is within the capacity
            int include = 0;
            if(wt[index] <= W) include = val[index] + solve(W-wt[index], wt, val, index+1, n);

            // Case 2: Exclude the current item and move to the next item
            int exclude = 0 + solve(W, wt, val, index+1, n);

            // Return the maximum value obtained by either including or excluding the current item
            return max(include, exclude);
        }

        // T.C: O(2^n)
        // S.C: O(n)
        int knapSack_recursion(int W, int wt[], int val[], int n) {
            int index = 0;   // Start with the first item
            return solve(W, wt, val, index, n);
        }

// ---------------------------------------------------------------------------------------------------------------------------------------------

        int solve(int W, int wt[], int val[], int index, int n, vector<vector<int>> dp) {
            // Base case: If we reach beyond the last item, return 0 value
            if(index >= n) return 0;

            if(dp[W][index] != -1) return dp[W][index];

            // Case 1: Include the current item if its weight is within the capacity
            int include = 0;
            if(wt[index] <= W) include = val[index] + solve(W-wt[index], wt, val, index+1, n);

            // Case 2: Exclude the current item and move to the next item
            int exclude = 0 + solve(W, wt, val, index+1, n);

            // Return the maximum value obtained by either including or excluding the current item
            dp[W][index] = max(include, exclude);
            return dp[W][index];
        }

        // T.C: O(n)
        // S.C: O(n)
        int knapSack_memoization(int W, int wt[], int val[], int n) {
            // Creating a 2D vector with 'W+1' rows and 'n+1' columns with all elements initialized to -1.
            vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
            int index = 0;   // Start with the first item
            return solve(W, wt, val, index, n, dp);
        }

// ---------------------------------------------------------------------------------------------------------------------------------------------

        // T.C: O(n)
        // S.C: O(n)
        int knapSack_tabulation(int W, int wt[], int val[], int n) {
            // Creating a 2D vector with 'W+1' rows and 'n+1' columns with all elements initialized to -1.
            // This 2D vector dp[i][j] represents the maximum value with the first 'j' items and weight capacity of knapack 'i'.
            vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
            
            // Initialize the DP table with base case values:
            // Keeping nth index of each row as 0, because no value is returned if we reach beyond the last item
            for(int row=0; row<=W; row++) {
                dp[row][n] = 0;
            }

            // i represents 'capacity' and j represents 'index'.
            // capacity approaches from W to 0 in memoization. So in tabulation, it will approach from 0 to W.
            // index runs from 0 to n in memoization. So in tabulation, it will approach from n to 0.
            // Also as per tabulation rules, the value to be returned from tabulation function is the initial value of arguments
            // that was received by the memoization function. In memoization, W and index=0 was received initially, thus in
            // tabulation dp[W][0] shall be returned from this function. To stop the loop at index [W][0], the outer loop
            // should run from 0 to W and the inner loop should run from 'n-1' to 0. j starts from 'n-1' because dp[][n] is
            // already calculated as 0 in the above for loop. So no need of again unnecessarily run j from 'n'.

            // Build the DP table in bottom-up manner
            for(int i=0; i<=W; i++) {   // Iterate through all capacities from 1 to W
                for(int j=n-1; j>=0; j--) {   // Iterate through all items
                    int include = 0;
                    // Case 1: Include the current item if its weight is within the capacity
                    if(wt[j] <= i) include = val[j] + dp[i-wt[j]][j+1];
                    // Case 2: Exclude the current item and move to the next item
                    int exclude = 0 + dp[i][j+1];
                    dp[i][j] = max(include, exclude);
                }
            }

            return dp[W][0];
        }

};

int main() {
    int W = 4;
    int wt[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int n = 3;

    Solution sol;
    cout << "Recursion: " << sol.knapSack_recursion(W, wt, val, n) << endl;
    cout << "Memoization: " << sol.knapSack_memoization(W, wt, val, n) << endl;
    cout << "Tabulation: " << sol.knapSack_tabulation(W, wt, val, n) << endl;

    return 0;
}
