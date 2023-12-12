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

// Note: This problem is being solved with recursion for now, just to understand recursion better.
// But optimal approach will be solved by dynamic programming.

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int start, int end) {
    // base case
    if(start > end) {
        return 0;   // when 'start>end', there are no houses left to rob. So we can rob 0 money.
    }

    // There are only 2 choices in my hand, either I can rob a house or I cannot rob a house.
    // Case 1: If I rob at 'start' index, I will make nums[start] amount of money, and then I will rob
    // next to next house; that's why next call's starting index is 'start+2'
    int option1 = nums[start] + solve(nums, start+2, end);

    // Case 2: If I rob do not rob at 'start' index, I will make 0 money, but then I can rob
    // next house; that's why next call's starting index is 'start+1'
    int option2 = 0 + solve(nums, start+1, end);

    return max(option1, option2);
}

// T.C: O(2^n);   where n = nums.size()
// S.C: O(n)
int rob(vector<int>& nums) {
    int size = nums.size();
    int start = 0;
    int end = size - 1;

    int ans = solve(nums, start, end);

    return ans;
}

int main() {
    vector <int> v = {1, 2, 3, 1};
    cout << rob(v);

    return 0;
}