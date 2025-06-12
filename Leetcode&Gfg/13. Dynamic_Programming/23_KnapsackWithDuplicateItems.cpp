// GFG: Knapsack with Duplicate Items   --->   Given a set of items, each with a weight and a value, represented
// by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Example 1:
// Input: val = [1, 1], wt = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.

// Example 2:
// Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 48
// Explanation: The optimal choice is to pick the 1st element 8 times.

// Example 3:
// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element .hence, total profit is 0.

// Constraints:
// 1 <= val.size() = wt.size() <= 1000
// 1 <= capacity <= 1000
// 1 <= val[i], wt[i] <= 100

// Problem link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// Algorithm: Again a very simple problem. Its just a variant of 'Leetcode&Gfg\13. Dynamic_Programming\18_01KnapSack.cpp'.
//            In that problem, the supply of items was limited. But here the supply of items are unlimited,
//            i.e., we can take any item multiple times in the knapsack.
//            Thus, we can apply same logic for infinite supply(remaining at same index even after taking the item).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int capacity, vector<int>& val, vector<int>& wt) {
        if(i == 0) {
            if(wt[0] <= capacity) return (capacity / wt[0]) * val[0];
            else return 0;
        }

        // At the current index, we have only two choices:
        // 1) Take the current item
        int take = INT_MIN;   // initially initialzed to 'INT_MIN', so that if 'wt[i] > capacity', the current item cannot be included
        if(wt[i] <= capacity) take = val[i] + solve(i, capacity - wt[i], val, wt);

        // 2) Not take the current item
        int notTake = 0 + solve(i - 1, capacity, val, wt);

        return max(take, notTake);
    }

    // T.C: Exponential, i.e., much greater than O(2^n);   because there can be cases that we are standing at same index even after next function call
    // S.C: O(capacity);   recursion stack space
    int knapSack_recursion(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();   // no.of items
        return solve(n - 1, capacity, val, wt);
    }

// -----------------------------------------------------------------------------------------------------------

    int solve(int i, int capacity, vector<int>& val, vector<int>& wt,vector<vector<int>>& dp) {
        if(i == 0) {
            if(wt[0] <= capacity) return (capacity / wt[0]) * val[0];
            else return 0;
        }

        if(dp[i][capacity] != -1) return dp[i][capacity];

        int take = INT_MIN;
        if(wt[i] <= capacity) take = val[i] + solve(i, capacity - wt[i], val, wt, dp);
        int notTake = 0 + solve(i - 1, capacity, val, wt, dp);

        return dp[i][capacity] = max(take, notTake);
    }

    // T.C: O(n * capacity)
    // S.C: O(n * capacity) for dp array + O(n) for recursion stack space = O(n * capacity)
    int knapSack_memoization(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, capacity, val, wt, dp);
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(n * capacity)
    // S.C: O(n * capacity)
    int knapSack_tabulation(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case: At index 0, if weight is less than or equal to knapsack capacity, we can take the 0th item.
        for(int j = wt[0]; j <= capacity; j++) dp[0][j] = (j / wt[0]) * val[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + dp[i][j - wt[i]];
                int notTake = 0 + dp[i - 1][j];

                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(n * capacity)
    // S.C: O(capacity)
    int knapSack_tabulation_SO(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);

        // Base case: At index 0, if weight is less than or equal to knapsack capacity, we can take the 0th item.
        for(int j = wt[0]; j <= capacity; j++) prev[j] = (j / wt[0]) * val[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + curr[j - wt[i]];
                int notTake = 0 + prev[j];

                curr[j] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[capacity];
    }
};


int main() {
    vector<int> val = {6, 1, 7, 7}, wt = {1, 3, 4, 5};
    int capacity = 8;

    cout << Solution().knapSack_recursion(val, wt, capacity) << endl;
    cout << Solution().knapSack_memoization(val, wt, capacity) << endl;
    cout << Solution().knapSack_tabulation(val, wt, capacity) << endl;
    cout << Solution().knapSack_tabulation_SO(val, wt, capacity) << endl;

    return 0;
}
