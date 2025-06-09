// Leetcode: 416. Partition Equal Subset Sum   --->   Given an integer array nums, return true if you can partition
// the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Example 1:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// Algorithm: This problem is just an extension of the previous problem 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp'.
//            We are asked to find if we can partition the array into two subsets with equal sum.
//            If we can partition the array into two subsets with equal sum, then the sum of the entire array must be even.
//            And if the sum of the entire array is even, the next step is to somehow find a subset with sum equal to half
//            of the entire array sum. If found, we can conclude that the other subset will also have the same sum,
//            and hence the array can be partitioned into two subsets with equal sum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int isSubsetSum_tabulation_SO(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);

        // Base cases:
        prev[0] = curr[0] = true;   // a subset is already formed if target is 0, so mark all rows in the first column as true
        if(arr[0] <= sum) prev[arr[0]] = true;   // if the first element is equal to target, mark it as true.

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }

public:
    // T.C: O(n * sum)
    // S.C: O(sum)
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums) sum += it;
        if(sum % 2) return false;   // if the sum is odd, we cannot partition it into two equal subsets.
        return isSubsetSum_tabulation_SO(nums, sum / 2);   // return the result of the isSubsetSum_tabulation_SO() function
    }
};


int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << Solution().canPartition(nums);

    return 0;
}
