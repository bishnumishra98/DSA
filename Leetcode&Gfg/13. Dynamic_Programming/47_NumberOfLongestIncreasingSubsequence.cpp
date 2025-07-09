// Leetcode: 673. Number of Longest Increasing Subsequence   --->   Given an integer array nums, return the
// number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.

// Example 1:
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

// Example 2:
// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of
// length 1, so output 5.

// Algorithm: It is just an extension of the problem 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.
//            The length of LIS of the given 'nums' array is given by the value of the largest dp element.
//            But here, we are asked to find the number of LIS. To find so, we will initialize one more array with all
//            elements as 1, of size 'n', where n = nums.size(), and name it let's say 'count'.
//            An element of 'count' array, count[i] tells the number of LIS that can be formed with the element
//            nums[i] as the last element of the LIS.
//            

// ● Illustration:
//   input 'nums' = [1, 3, 5, 8, 4, 7]
//   dp array =     [1, 2, 3, 4, 3, 4]
//   count array =  [1, 1, 1, 1, 1, 2]
//   numberOfLIS = count[3] + count[5] = 1 + 2 = 3, i.e., there are 3 LIS of length 4 in the given 'nums' array.
//   Those LIS are: {1, 3, 5, 8}, {1, 3, 5, 7} and {1, 3, 4, 7}.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(n)
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);

        int maxi = 1;

        for(int i = 1; i < n; i++) {   // 'i' represents the current element
            for(int j = 0; j < i; j++) {   // 'j' represents all elements towards left of 'i'
                if(nums[i] > nums[j]) {
                    // Update dp[i] only if a larger value is supposed to be computed from '1 + dp[j]'
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if(1 + dp[j] == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            // Store the largest dp element found so far
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }

        int numberOfLIS = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) numberOfLIS += count[i];
        }

        for(auto it: count) cout << it << " ";
        cout << endl;

        return numberOfLIS;
    }
};

int main() {
    // vector<int> nums = {1, 3, 5, 4, 7};
    vector<int> nums = {1, 3, 5, 8, 4, 7};

    cout << Solution().findNumberOfLIS(nums);

    return 0;
}
