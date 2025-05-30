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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition_recursion(vector<int>& nums) {
        
    }

// ------------------------------------------------------------------------------------------------

    bool canPartition_memoization(vector<int>& nums) {
        
    }

// ------------------------------------------------------------------------------------------------

    bool canPartition_tabulation(vector<int>& nums) {
        
    }

// ------------------------------------------------------------------------------------------------

    bool canPartition_tabulation_SO(vector<int>& nums) {
        
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << Solution().canPartition_recursion(nums) << endl;
    cout << Solution().canPartition_memoization(nums) << endl;
    cout << Solution().canPartition_tabulation(nums) << endl;
    cout << Solution().canPartition_tabulation_SO(nums);

    return 0;
}
