// Leetcode: 312. Burst Balloons   --->   You are given n balloons, indexed from 0 to n - 1. Each balloon is
// painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes
// out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

// Example 1:
// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

// Example 2:
// Input: nums = [1,5]
// Output: 10

// Constraints:
// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100

// Algorithm: 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) return 0;

        int maxi = INT_MIN;
        for(int index = i; index <= j; index++) {
            int coins = nums[i - 1] * nums[index] * nums[j + 1];
            int totalCoins = solve(i, index - 1, nums) + coins + solve(index + 1, j, nums);
            maxi = max(maxi, totalCoins);
        }

        return maxi;
    }

    // T.C: Exponential
    // S.C: O(n)
    int maxCoins_recursion(vector<int>& nums) {
        int n = nums.size();

        // Add boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return solve(1, n, nums);
    }

// ----------------------------------------------------------------------------------------------------

    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for(int index = i; index <= j; index++) {
            int coins = nums[i - 1] * nums[index] * nums[j + 1];
            int totalCoins = solve(i, index - 1, nums, dp) + coins + solve(index + 1, j, nums, dp);
            maxi = max(maxi, totalCoins);
        }

        return dp[i][j] = maxi;
    }

    // T.C: O(n^3)
    // S.C: O(n^2) for dp table + O(n) for recursive stack space = O(n^2)
    int maxCoins_memoization(vector<int>& nums) {
        int n = nums.size();

        // Add boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, nums, dp);
    }

// ----------------------------------------------------------------------------------------------------

    // T.C: O(n^3)
    // S.C: O(n^2)
    int maxCoins_tabulation(vector<int>& nums) {
        int n = nums.size();

        // Add boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // Writing base case is not required as all cells are already initialized to 0.

        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                if(i > j) continue;
                int maxi = INT_MIN;
                for(int index = i; index <= j; index++) {
                    int coins = nums[i - 1] * nums[index] * nums[j + 1];
                    int totalCoins = dp[i][index - 1] + coins + dp[index + 1][j];
                    maxi = max(maxi, totalCoins);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};


int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << Solution().maxCoins_recursion(nums) << endl;

    nums = {3, 1, 5, 8};
    cout << Solution().maxCoins_memoization(nums) << endl;

    nums = {3, 1, 5, 8};
    cout << Solution().maxCoins_tabulation(nums);

    return 0;
}
