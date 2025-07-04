// Part I:
// Find the length of the Longest Increasing Subsequence (LIS).

// Example 1:
// Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
// Output: 4
// Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.

// Example 2:
// Input: nums = [0, 1, 0, 3, 2, 3]
// Output: 4

// Example 3:
// Input: nums = [7, 7, 7, 7, 7, 7, 7]
// Output: 1

// ----------------------------------------------------------------------------------------------------

// Part II:
// Find any one of the Longest Increasing Subsequence (LIS).

// Example 1:
// Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
// Output: [2, 3, 7, 101]

// Example 2:
// Input: nums = [0, 1, 0, 3, 2, 3]
// Output: [0,  1,  2,  3]

// Example 3:
// Input: nums = [7, 7, 7, 7, 7, 7, 7]
// Output: [7]

#include <bits/stdc++.h>
using namespace std;

// Algorithm: Create a dp array of size 'n', where n = nums.size(). Now each cell of dp[i] will store the length of
//            the longest increasing subsequence that ends at 'i'th index. It can be found out very easily by adding
//            1 (for the element itself, i.e., for nums[i]) to the maximum of all the dp[j] values where j < i
//            and nums[j] < nums[i].
//            For example:- Consider the 'nums' array = [10, 9, 2, 5, 3, 7, 101, 18]
//            dp array for the above 'nums' array =     [1,  1, 1, 2, 2, 3, 4,   4]
//            Hence, the length of the longest increasing subsequence will be the maximum value in the dp array, i.e., 4.

// T.C: O(n^2)
// S.C: O(n)
int findLISLength(vector<int> nums) {
    
}

// ----------------------------------------------------------------------------------------------------

// T.C: O(n^2)
// S.C: O(n)
vector<int> findLIS(vector<int> nums) {
    
}


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << findLISLength(nums) << endl;

    vector<int> lis = findLIS(nums);
    for(auto it: lis) cout << it << " ";

    return 0;
}
