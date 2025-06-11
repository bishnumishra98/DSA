// Leetcode: 494. Target Sum   --->   You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums
// and then concatenate all the integers.
// ● For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the
// expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Example 2:
// Input: nums = [1], target = 1
// Output: 1

// Algorithm: This is the same problem as 'Leetcode&Gfg\13. Dynamic_Programming\17_PartitionsWithGivenDifference.cpp'.
//            We just need to create two subsets from the entire array, whose difference is 'target'. And number of
//            such subsets is the answer that we need to return.
//            ● Why does it work ?
//              Let's take an example: nums = [1, 2, 3, 1], target = 3
//              To achieve 3, we can form something like this: -1 +2 +3 -1
//                                                           = +2 +3 -1 - 1
//                                                           = (2 + 3) - (1 + 1)
//              Hence, any sequence can be transformed into difference of two subsets.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // '16_PerfectSumProblem.cpp' code:
    int perfectSum_tabulation_SO(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        prev[0] = curr[0] = 1;
        if(arr[0] == 0) prev[0] = 2;
        if(arr[0] <= target && arr[0] != 0) prev[arr[0]] = 1;

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                int notTake = prev[t];
                int take = 0;
                if (arr[i] <= t) take = prev[t - arr[i]];
                curr[t] = take + notTake;
            }
            prev = curr;
        }

        return prev[target];
    }

    // '17_PartitionsWithGivenDifference.cpp' code:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        if(sum - d < 0 || (sum - d) & 1) return 0;

        return perfectSum_tabulation_SO(arr, (sum - d) / 2);
    }

public:
    // T.C: O(n * x);   where x = (target + sum of all elements) / 2
    // S.C: O(x)
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << Solution().findTargetSumWays(nums, target);

    return 0;
}
