// Leetcode: 1. Two Sum   --->   Given an array of integers nums and an integer target, return indices of the two numbers such
// that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> map;

        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            // If the complement exists in the map, return the stored index for the complement and the current index.
            if(map.count(compliment)) return {map[compliment], i};
            map[nums[i]] = i;
        }

        return {};   // if no pair found, return blank vector
    }
};


int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = Solution().twoSum(nums, target);
    cout << ans[0] << ", " << ans[1];

    return 0;
}
