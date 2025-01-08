// Leetcode: 287: Find the Duplicate Number   --->   Given an array of integers nums containing n + 1 integers where
// each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

// Example 3:
// Input: nums = [3,3,3,3,3]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(nlogn) + O(n) = O(nlogn)
    // S.C: O(1)
    int findDuplicate_bruteforce(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) return nums[i];
        }

        return -1;   // if no duplicates found
    }

    // T.C: O(n)
    // S.C: O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        // If an entry for nums[i] is already present in the map, then return nums[i]. Else, add nums[i] to the map.
        // Note that map should be made by considering nums[i] as the key, and value can be anything(for instance, lets consider i).
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) != map.end()) return nums[i];
            map[nums[i]] = i;
        }

        return -1;   // if no duplicates found
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << Solution().findDuplicate_bruteforce(nums) << endl;
    cout << Solution().findDuplicate(nums);

    return 0;
}
