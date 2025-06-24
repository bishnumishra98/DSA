// GFG: 0-1 Knapsack Problem   --->   Given n items, each with a specific weight and value, and a knapsack with
// a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W
// and the sum of values associated with them is maximized. 
// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available
// in single quantity.

// Example 1:
// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation:
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
// Thus, choose the last item that weighs 1 unit and holds a value of 3.

// Example 2:
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

// Example 3:
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

// Problem link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Algorithm: It is a very simple problem. You have to put items in the knapsack such that the item weights is below
//            the threshold of the knapsack capacity, and the total value of items is maximum. Greedy won't work
//            here as there is no uniformity between values and weights. The only option is to try out all possible
//            combination of items using recursion.

//            Call a function solve(i, W) which returns the maximum value that can be kept in knapsack till
//            the index 'i', with a knapsack capacity of 'W'. Call the recursive function solve() from the
//            last item of the knapsack and go deeper into the recursive tree until index 0.
//            1. The base cases of the recursion will be at index 0:
//               i)  If weight of item at 0th index is less than or equal to current knapsack capacity, take it,
//                   i.e., if(wt[0] <= W) return val[0];
//               ii) If weight of item at 0th index exceeds the knapsack capacity, then reject taking it, i.e.,
//                   if(wt[0] > W) return 0;
//            2. The recursive body will have only two simple take, not take options. At index 'i', you have only
//               two choices:
//               I)  Take the item: If weight of item at 'i'th index is less than equal to current knapsack capacity,
//                                  take it and call recursion for next index with decremented knapsack capacity,
//                                  i.e., val[i] + solve(i - 1, W - wt[i]);
//               II) Not take the item: If you choose to not take the current item, just call recursion for next index
//                                      with the same knapsack capacity, i.e., 0 + solve(i - 1, W);
//            3. At the end, return the maximum value obtained from both the paths (take and not take).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int W, vector<int>& val, vector<int>& wt) {
        if(i == 0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }

        // At the current index, we have only two choices:
        // 1) Take the current item
        int take = INT_MIN;   // initially initialzed to 'INT_MIN', so that if 'wt[i] > W', the current item cannot be included
        if(wt[i] <= W) take = val[i] + solve(i - 1, W - wt[i], val, wt);

        // 2) Not take the current item
        int notTake = 0 + solve(i - 1, W, val, wt);

        return max(take, notTake);
    }

    // T.C: O(2^n)
    // S.C: O(n);   recursion stack space
    int knapsack_recursion(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();   // no.of items
        return solve(n - 1, W, val, wt);
    }

// -----------------------------------------------------------------------------------------------------------

    int solve(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if(i == 0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }

        if(dp[i][W] != -1) return dp[i][W];

        int take = INT_MIN;
        if(wt[i] <= W) take = val[i] + solve(i - 1, W - wt[i], val, wt, dp);
        int notTake = 0 + solve(i - 1, W, val, wt, dp);

        return dp[i][W] = max(take, notTake);
    }

    // T.C: O(n * W)
    // S.C: O(n * W) for dp array + O(n) for recursion stack space = O(n * W)
    int knapsack_memoization(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(n - 1, W, val, wt, dp);
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(n * W)
    // S.C: O(n * W)
    int knapsack_tabulation(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case: At index 0, if weight is less than or equal to knapsack capacity, we can take the 0th item.
        for(int j = wt[0]; j <= W; j++) dp[0][j] = val[0];

        // Fill rest of the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= W; j++) {
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + dp[i - 1][j - wt[i]];
                int notTake = 0 + dp[i - 1][j];

                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }

// -----------------------------------------------------------------------------------------------------------

    // T.C: O(n * W)
    // S.C: O(2W)
    int knapsack_tabulation_SO(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        // Base case: At index 0, if weight is less than or equal to knapsack capacity, we can take the 0th item.
        for(int j = wt[0]; j <= W; j++) prev[j] = val[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= W; j++) {
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + prev[j - wt[i]];
                int notTake = 0 + prev[j];

                curr[j] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }

// -----------------------------------------------------------------------------------------------------------

    // ● Further space optimization to only one 1D array:
    //   We can further space optimize the above code because curr values depends only on the previous row's values
    //   and not on the current row's values. Thus, we will compute the values of the current row from
    //   the previous rows only, but we will store the values of the current row in the same array 'prev'
    //   which was used to store the previous row's values.
    //   The only thing to note is that to filling a cell at index 'j' depends on the value of the cell at
    //   'j'th index itself and 'j - wt[i]' index of the same row, i.e., to fill the cell at 'j'th index, the cells
    //   at right of 'j'th index are of no use. Hence, we must traverse in the opposite fashion, i.e., from right to
    //   left so that the value of the cell at 'j - wt[i]' index is not overwritten before it is used to fill
    //   the cell at 'j'th index.
    // T.C: O(n * W)
    // S.C: O(W)
    int knapsack_tabulation_SO_1D(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        // Base case: At index 0, if weight is less than or equal to knapsack capacity, we can take the 0th item.
        for(int j = wt[0]; j <= W; j++) prev[j] = val[0];

        for(int i = 1; i < n; i++) {
            for(int j = W; j >= 0; j--) {   // go in reverse fashion, i.e., from right to left
                int take = INT_MIN;
                if(wt[i] <= j) take = val[i] + prev[j - wt[i]];
                int notTake = 0 + prev[j];

                prev[j] = max(take, notTake);
            }
            // prev = curr;   // no more required
        }

        return prev[W];
    }
};


int main() {
    int W = 4;
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    
    Solution sol;
    cout << sol.knapsack_recursion(W, val, wt) << endl;
    cout << sol.knapsack_memoization(W, val, wt) << endl;
    cout << sol.knapsack_tabulation(W, val, wt) << endl;
    cout << sol.knapsack_tabulation_SO(W, val, wt) << endl;
    cout << sol.knapsack_tabulation_SO_1D(W, val, wt);

    return 0;
}
