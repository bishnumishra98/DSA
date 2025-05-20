// leetcode: 198. House Robber   --->   You are a professional robber planning to rob houses
// along a street. Each house has a certain amount of money stashed, the only constraint stopping
// you from robbing each of them is that adjacent houses have security systems connected and it
// will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum
// amount of money you can rob tonight without alerting the police.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Note: This problem was solved using recursion. But now we will implemenent optimal solution with DP.
// DP PATTERN: Include/Exclude

#include <iostream>
#include <vector>
using namespace std;

int solve(int index, vector<int>& nums) {
    // Base cases:
    // 1) If I am standing at nums[0], I can rob at max nums[0] money only.
    if(index == 0) return nums[0];
    // 2) If I go beyond the left of 0th element of 'nums', I cannot rob anything. Thus, return 0 money.
    if(index < 0) return 0;   // this base case is to handle solve(index-2) when index = 1.

    // There are only 2 choices in my hand, either I can rob the house at current index or I cannot rob this house.
    // Case 1: If I rob at current index, I will make nums[index] amount of money, and then I can rob next to next house left.
    int rob = nums[index] + solve(index - 2, nums);

    // Case 2: If I rob do not rob at current index, I will make 0 money, but then I can rob the just next house left.
    int notRob = 0 + solve(index - 1, nums);

    return max(rob, notRob);   // Return the max money I can manage to rob at current index
}

// T.C: O(2^n);   where n = nums.size()
// S.C: O(n)
int rob_recursion(vector<int>& nums) {
    int n = nums.size();
    return solve(n - 1, nums);   // return the maximum money I can rob by standing on the last house
}

// --------------------------------------------------------------------------------------------------------

int solve(int index, vector<int>& nums, vector<int>& dp) {
    if(index == 0) return nums[0];
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    int rob = nums[index] + solve(index - 2, nums, dp);
    int notRob = 0 + solve(index - 1, nums, dp);

    dp[index] = max(rob, notRob);
    return dp[index];
}

// T.C: O(n);   where n = nums.size()
// S.C: O(n)
int rob_memoization(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}

// --------------------------------------------------------------------------------------------------------

// T.C: O(n);   where n = nums.size()
// S.C: O(n)
int rob_tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    
    // Fill the dp array
    for(int index = 1; index < n; index++) {
        // int rob = nums[index] + dp[index - 2];   // But dp[index - 2] should be computed only if 'index >= 2'. Thus, write like this:
        int rob = nums[index];
        if(index >= 2) rob = rob + dp[index - 2];
        int notRob = 0 + dp[index - 1];
        dp[index] = max(rob, notRob);
    }

    return dp[n - 1];
}

// --------------------------------------------------------------------------------------------------------

// T.C: O(n);   where n = nums.size()
// S.C: O(1)
int rob_tabulation_SO(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int index = 1; index < n; index++) {
        int rob = nums[index] + prev2;
        int notRob = 0 + prev;
        int curr = max(rob, notRob);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}


int main() {
    vector <int> v = {1, 2, 3, 1};
    cout << "rob_recursion: " << rob_recursion(v) << endl;
    cout << "rob_memoization: " << rob_memoization(v) << endl;
    cout << "rob_tabulation: " << rob_tabulation(v) << endl;
    cout << "rob_tabulation_SO: " << rob_tabulation_SO(v);

    return 0;
}
