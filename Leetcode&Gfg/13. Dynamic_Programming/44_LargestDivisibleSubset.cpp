// Leetcode: 368. Largest Divisible Subset   --->   Given a set of distinct positive integers nums, return the largest
// subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// ● answer[i] % answer[j] == 0, or
// ● answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Example 2:
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 
// Constraints:
// ● 1 <= nums.length <= 1000
// ● 1 <= nums[i] <= 2 * 10^9
// ● All the integers in nums are unique.

// Algorithm: It is a simple problem. It is just a variation of 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.
// 1. Sort the given array.
// 2. Follow the same code as you wrote for LIS, just instead of checking if(nums[i] > nums[j]), check
//    if(nums[i] % nums[j] == 0).

// ● Intuition behind sorting the array and applying LIS logic:
//   One thing we know is that problem is asking for subset, not subsequence; hence order of elements doesn't matters.
//   Thus, we can sort the given input array, so that the next element is always greater than the previous element
//   as all elements given are unique.
//   This will help in identifying the divisibility of each element in a straightforward manner.
//   Lets take an example, arr = [4, 2, 8, 16, 7]
//   After sorting, arr = [2, 4, 7, 8, 16]
//   If 4 is divisible by 2, and 8 is divisible by 4, 8 is bound to be divisble by 2 also. In this way, if an element
//   is divisible by its previous element, it is also divisible by all the elements before it.
//   Now in LIS problem, we were finding the longest increasing subsequence on the condition that nums[i] > nums[j].
//   We can do the same here to find LDS. Find the longest increasing subsequence on the sorted array on the condition
//   that nums[i] should be divisible by nums[j]. If nums[i] is divisible by nums[j], nums[i] is also bound to be
//   divisible by all the elements at indexes left of j, as the array is sorted.
//   Hence here, an element of dp array, dp[i] will tell the length of longest divisible subsequence till the index 'i'
//   of 'nums'. And the hash array as usual will tell the parent of an element, which will be later useful in backtracking
//   and building up the LDS. Example:- If hash[3] = 1, it means the element at index 3 of 'nums' was computed from
//   element at index 1 of 'nums'.
//   Thus, follow the same code as you wrote for LIS, just instead of checking if(nums[i] > nums[j]), check
//   if(nums[i] % nums[j] == 0).

// ● Illustration:
//   Sorted arr = [2, 4, 7, 8, 16]
//   dp array =   [1, 2, 1, 3, 4]   // initially all elements are initialized to 1 as they are LDS in themselves
//   hash array = [0, 0, 2, 1, 3]   // those who did not came from anywhere are parent of themselves
//   LDS =        [2, 4, 8, 16]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        sort(nums.begin(), nums.end());   // CHANGE 1 (it is actually an addition on the LIS code)

        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;

        int maxi = 1;
        int lastIndex = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {   // CHANGE 2 (previously it was 'if(nums[i] > nums[j])' in LIS code)
                    if(1 + dp[j] > dp[i]) {
                        hash[i] = j;
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Starting from element of 'nums' at index of the largest dp element, start backtracking and build the LDS in 'ans'.
        vector<int> ans;
        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    // vector<int> nums = {1, 2, 3};
    vector<int> nums = {2, 4, 7, 8, 16};

    vector<int> ans1 = Solution().largestDivisibleSubset(nums);
    for(auto it: ans1) cout << it << " ";

    return 0;
}
