// Leetcode: 2035. Partition Array Into Two Arrays To Minimize Sum Difference   --->   You are given an integer array
// nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference
// of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
// Return the minimum possible absolute difference.

// Example 1:
// example-1
// Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

// Example 2:
// Input: nums = [-36,36]
// Output: 72
// Explanation: One optimal partition is: [-36] and [36].
// The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

// Example 3:
// example-3
// Input: nums = [2,-1,0,4,-2,-9]
// Output: 0
// Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
// The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

// Algorithm: This problem is also an extension of the previous problem 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp'.
//            In the that problem, we were asked to find if we can find a subset with a given sum in the array.
//            The thing to notice is that in that problem, the tabulation table of size n * sum, told us if we can form a subset
//            with a given sum or not. For instance, if dp[3][7] was true, it would mean that we can form a subset within the
//            index 0 to 3 of the array that sums to 7. Similarly, if dp[2][7] was false, it would mean that we cannot form a
//            subset within the index 0 to 2 of the array that sums to 7.
//            Here, we are asked to partition the array into two arrays of equal length and minimize the absolute difference.
//            The approach is very straightforward and simple.
////          1) First, we calculate the total sum of the array and divide it by 2 to get the target sum for each partition.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums) sum += it;
        sum /= 2;   // the target sum for each partition will be half of the total sum.

        // 13_SubsetSumProblem.cpp code :-
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= sum && nums[0] >= 0) dp[0][nums[0]]= true;

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if(nums[i] <= target) take = dp[i - 1][target - nums[i]];
                dp[i][target] = take || notTake;
            }
        }

        int mini = 1e9;
        for(int s1 = 0; s1 <= sum; s1++) {
            if(dp[n - 1][s1]) {
                int s2 = sum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }

// ---------------------------------------------------------------------------------------------------------------

    int minimumDifference_SO(vector<int>& nums) {

    }
};

int main() {
    vector<int> nums = {3, 9, 7, 3};
    Solution sol;

    cout << sol.minimumDifference(nums) << endl;
    cout << sol.minimumDifference_SO(nums);

    return 0;
}
