// Leetcode: Jump Game II   --->   You are given a 0-indexed array of integers nums of length n. You are initially
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

// Algorithm: This is a greedy approach.
// 1. We will keep track of the current end index 'currEnd' and the current farthest index 'currFarthest' we can reach.
//    Initialize jumps, currEnd, and currFarthest to 0. 'currEnd' represents the end of the current jump range, and
//    'currFarthest' is the farthest index we can reach from the current jump range.
// 2. Traverse the array from i = 0 to n-2(we stop before the last index because reaching it completes the goal), and
//    for each index i, update the currFarthest with the maximum of currFarthest and i + nums[i]. This will help us to
//    keep track of the maximum index we can reach from the current jump range.
//    If i == currEnd, it means the current jump range is exhausted, and we need to jump to the next range. Thus, increment
//    jumps and update currEnd with currFarthest.
// 3. Finally, return the number of jumps.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n);   where n = nums.size()
    // S.C: O(1)
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int jumps = 0, currEnd = 0, currFarthest = 0;
        for(int i = 0; i < n - 1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);
            if(i == currEnd) {
                jumps++;
                currEnd = currFarthest;
            }
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
