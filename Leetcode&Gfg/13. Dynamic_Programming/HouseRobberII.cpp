// Leetcode: 213. House Robber II   --->   You are a professional robber planning to rob houses along a street. Each house
// has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is
// the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically
// contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
// rob tonight without alerting the police.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:
// Input: nums = [1,2,3]
// Output: 3

// Algorithm: Apply the same logic as in 'HouseRobber.cpp'. The only difference is that 0th element and the 'n-1'th element
// are adjacent, thus they cannot be robbed together. We can rob only one of them. Thus, make two arrays from given input.
// Array 1: Containing 1st element to 'n-1'th element.
// Array 2: Containing 0th element to 'n-2'th element.
// Then return the maximum of the two arrays. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This is tabulation space optimised code
    int solve(vector<int>& nums) {
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

    // T.C: O(n)
    // S.C: O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        // If array contains only 1 element, I can rob only that. So return that.
        if(n == 1) return nums[0];

        vector<int> arr1, arr2;
        for(int i = 0; i < n; i++) {
            if(i != 0) arr1.push_back(nums[i]);   // arr1 contains 1st to 'n-1'th elements of 'num'
            if(i != n-1) arr2.push_back(nums[i]);   // arr2 contains 0th to 'n-2'th elements of 'num'
        }

        return max(solve(arr1), solve(arr2));
    }
};

int main() {
    vector <int> v = {1, 2, 3, 1};
    Solution sol;
    cout << "rob: " << sol.rob(v);

    return 0;
}
