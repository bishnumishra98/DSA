// GFG: Subset Sum Problem   --->   Given an array of positive integers arr[] and a value sum, determine if there is a
// subset of arr[] with sum equal to given sum.

// Example 1:
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

// Example 2:
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.

// Example 3:
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

// Problem link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Algorithm: This is a simple brute force problem. At each step, we have two choices:
//            1) Either we take the current element and reduce the target by the value of the current element.
//            2) Or we do not take the current element and keep the target as it is.
//            We can use recursion to explore all possible subsets and check if any of them sum up to the target value.
//            The recursive function will take the current index, the array, and the target sum as parameters.
//            f(int i, vector<int>& arr, int target) {} means in the entire array till the index i, can we form a subset
//            that sums to the target value ? If yes, return true; else return false.
//            The base cases of the function will be:
//            1) If the target is 0, we have found a subset that sums to the target.
//            2) If we have no elements left (i == 0), we can only form the subset if the first element equals the target.
//               Else, if the first element is not equal to the target, we cannot form the subset.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, vector<int>& arr, int target) {
        // Base cases:
        // 1) If the target is 0, we have found a subset that sums to the target.
        // 2) If we have no elements left (i == 0), we can only form the subset if the first element equals target.
        if(target == 0) return true;
        if(i == 0) return (arr[0] == target);

        bool notTake = solve(i - 1, arr, target);
        // By default, assume we cannot take the current element. If the current element is less than or equal to
        // the target, we can consider taking it.
        bool take = false;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i]);
        return take || notTake;
    }

    // T.C: O(2^n)
    // S.C: O(n);   recursion stack space
    bool isSubsetSum_recursion(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n - 1, arr, sum);
    }

// --------------------------------------------------------------------------------------------------------------

    bool solve(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(i == 0) return (arr[0] == target);

        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i - 1, arr, target, dp);
        bool take = false;
        if(arr[i] <= target) take = solve(i - 1, arr, target - arr[i], dp);
        
        return dp[i][target] = take || notTake;
    }

    // S.C: O(n * sum)
    // T.C: O(n * sum) for dp table + O(n) for recursion stack space = O(n * sum)
    bool isSubsetSum_memoization(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, arr, sum, dp);
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * sum)
    // S.C: O(n * sum)
    int isSubsetSum_tabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        // dp[i][j] means i are the index of the array till which we are considering elements, and j is the target sum.
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base cases:
        // 1) A subset is already formed if target is 0, so mark all rows in the first column as true.
        // 2) If the first element is equal to target, mark it as true.
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]]= true;   // if(arr[0] <= sum) condition is added to avoid the case when the
        // first element itself is greater than sum. If the first element is itself is greater than sum, then it does
        // not makes any sense to mark dp[0][arr[0]] as true, because dp[0][arr[0]] means that we can form a subset
        // with the first element itself, which is not possible if the first element is greater than sum.

        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
                dp[i][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }

// --------------------------------------------------------------------------------------------------------------

    // T.C: O(n * sum)
    // S.C: O(sum)
    int isSubsetSum_tabulation_SO(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);

        // Base cases:
        prev[0] = curr[0] = true;   // a subset is already formed if target is 0, so mark all rows in the first column as true
        if(arr[0] <= sum) prev[arr[0]] = true;   // if the first element is equal to target, mark it as true.

        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};


int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << Solution().isSubsetSum_recursion(arr, sum) << endl;
    cout << Solution().isSubsetSum_memoization(arr, sum) << endl;
    cout << Solution().isSubsetSum_tabulation(arr, sum) << endl;
    cout << Solution().isSubsetSum_tabulation_SO(arr, sum);

    return 0;
}
