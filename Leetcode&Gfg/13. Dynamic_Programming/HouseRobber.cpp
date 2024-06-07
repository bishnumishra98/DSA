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

// Simple recursion
int solve(vector<int>& nums, int start) {
    // Base case: When 'start>=nums.size()', there are no houses left to rob. So we can rob 0 money.
    if(start >= nums.size()) return 0;

    // There are only 2 choices in my hand, either I can rob a house or I cannot rob a house.
    // Case 1: If I rob at 'start' index, I will make nums[start] amount of money, and then I will rob
    // next to next house; that's why next call's starting index is 'start+2'
    int option1 = nums[start] + solve(nums, start+2);

    // Case 2: If I rob do not rob at 'start' index, I will make 0 money, but then I can rob
    // next house; that's why next call's starting index is 'start+1'
    int option2 = 0 + solve(nums, start+1);

    return max(option1, option2);
}

// T.C: O(2^n);   where n = nums.size()
// S.C: O(n)
int rob_recursion(vector<int>& nums) {
    int size = nums.size();
    int start = 0;
    return solve(nums, start);
}

// --------------------------------------------------------------------------------------------------------

// Memoization
int solve(vector<int>& nums, int index, vector<int>& dp) {
    // Base case: When 'index>=nums.size()', there are no houses left to rob. So we can rob 0 money.
    if(index >= nums.size()) return 0;

    // If answer already exist in dp array, return it
    if(dp[index] != 0) return dp[index];

    // There are only 2 choices in my hand, either I can rob a house or I cannot rob a house.
    // Case 1: If I rob at current index, I will make nums[index] amount of money, and then I can rob next to next house
    int option1 = nums[index] + solve(nums, index+2, dp);

    // Case 2: If I rob do not rob at current index, I will make 0 money, but then I can rob the next house
    int option2 = 0 + solve(nums, index+1, dp);

    dp[index] = max(option1, option2);
    return dp[index];
}

// T.C: O(n);   where n = nums.size()
// S.C: O(n)
int rob_memoization(vector<int>& nums) {
    int start = 0;
    int n = nums.size();
    vector<int> dp(n, 0);
    return solve(nums, start, dp);
}

// --------------------------------------------------------------------------------------------------------

// Tabulation
// T.C: O(n);   where n = nums.size()
// S.C: O(n)
int rob_tabulation(vector<int>& nums) {
    int n = nums.size();
    // Step 1: Create 'dp' array
    vector<int> dp(n+1, 0);

    // Step 2: Fill initial data in dp according to base case.
    // dp[i] means total maximum money that can be collected from i index till the last index of 'nums'.
    // Thus, if we stand at last index, maximum money we can collect will obviously be nums[last index].
    dp[n-1] = nums[n-1];

    // Step 3: Fill rest of the dp array using iteration. Starting from second last index towards 0 index, we will find answer.
    for(int index=n-2; index>=0; index--) {
        // Case 1: If I rob at current index, I will make nums[index] amount of money, and then I can rob next to next house
        int option1 = nums[index] + dp[index+2];
        // Case 2: If I rob do not rob at current index, I will make 0 money, but then I can rob the next house
        int option2 = 0 + dp[index+1];

        dp[index] = max(option1, option2);
    }

    return dp[0];   // dp[0] represents total maximum money that can be collected from 0 till 'n-1' index of 'nums'.
}

// --------------------------------------------------------------------------------------------------------

// Tabulation space optimised
// T.C: O(n);   where n = nums.size()
// S.C: O(1)
int rob_tabulation_SO(vector<int>& nums) {
    int n = nums.size();
    // We see that dp[i] is dependent on dp[i+1] and dp[i+2]. Thus, no need to create a dp. We can directly initialize
    // 3 variables as 'prev' and 'next' indicating dp[i+1] and dp[i+2]; while 'curr' indicating dp[i].
    int prev = nums[n-1];   // last index of 'nums'
    int next = 0;   // beyond last index of 'nums'
    int curr;   // curr is dependent on prev and next. Initially curr builds answer for nums[n-2].

    // Fill rest of the dp array using iteration. Starting from second last index towards 0 index, we will find answer.
    for(int index=n-2; index>=0; index--) {
        // Case 1: If I rob at curr index, I will make nums[index] amount of money, and then I can rob next to next house
        int option1 = nums[index] + next;
        // Case 2: If I rob do not rob at curr index, I will make 0 money, but then I can rob the next house
        int option2 = 0 + prev;

        curr = max(option1, option2);

        // Update prev and next pointer towards left, i.e., shift them by 1 towards 0 index.
        next = prev;
        prev = curr;
    }

    return prev;   // curr and prev both stands on nums[0] at the end of loop. Dry run for better understanding.
}


int main() {
    vector <int> v = {1, 2, 3, 1};
    cout << "rob_recursion: " << rob_recursion(v) << endl;
    cout << "rob_memoization: " << rob_memoization(v) << endl;
    cout << "rob_tabulation: " << rob_tabulation(v) << endl;
    cout << "rob_tabulation_SO: " << rob_tabulation_SO(v) << endl;

    return 0;
}
