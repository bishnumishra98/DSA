// Leetcode: 45. Jump Game II   --->   You are given a 0-indexed array of integers nums of length n. You are initially
// positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at
// nums[i], you can jump to any nums[i + j] where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the
//              last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

// Example 3:
// Input: nums = [1, 2, 3, 1, 2, 0, 2, 5]
// Output: 5

// Problem link: https://leetcode.com/problems/jump-game-ii/description/

// Algorithm: This is a greedy approach based on range.
// 1. We will keep track of the current range of the jumps.
// 2. We will iterate from l to r, where l is the leftmost index of the current range and r is the rightmost index of
//    the current range. We will find the farthest index we can reach from the current range.
// 3. Traverse while r < n - 1, where n is the size of the array, because once r reaches 'n - 1'th index or beyond, we stop.
//    i.   Find the farthest index we can reach from the current range.
//    ii.  Update l with r + 1 and r with the farthest index.
//    iii. Increment the jumps.
// 4. Return the number of jumps.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   where n = nums.size()
    // S.C: O(1)
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;

        while(r < n - 1) {
            int farthest = 0;
            for(int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 0, 2, 5};

    Solution obj;
    cout << obj.jump(nums) << endl;

    return 0;
}
