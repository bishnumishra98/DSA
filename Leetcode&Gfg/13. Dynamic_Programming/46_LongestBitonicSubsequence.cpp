// GFG: Longest Bitonic subsequence   --->   Given an array of positive integers. Find the maximum length of
// Bitonic subsequence. A subsequence of array is called Bitonic if it is first strictly increasing, then strictly
// decreasing. Return the maximum length of bitonic subsequence.
// Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

// Example 1:
// Input: n = 5, nums[] = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get
// length 5.

// Example 2:
// Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
// Output: 6
// Explanation: The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.

// Example 3:
// Input: n = 3, nums[] = [10, 20, 30]
// Output: 0
// Explanation: The decreasing or increasing part cannot be empty

// Example 4:
// Input: n = 3, nums[] = [10, 10, 10]
// Output: 0
// Explanation: The subsequences must be strictly increasing or decreasing

// Constraints:
// 1 ≤ length of array ≤ 10^3
// 1 ≤ arr[i] ≤ 10^4

// Algorithm: Its is a simple extension of 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.
//            The dp array in LIS problem tells us the length of the longest increasing subsequence that end at 'i'th index.
//            Here we have to compute two dp arrays, one measuring the length of LIS from left to right; and the other
//            measuring the length of LIS from right to left.
//            Once we have both of these arrays, lets say dp1 tells the lengths of LIS from left to right and dp2 tells
//            the lengths of LIS from right to left; we can easily find the longest bitonic subsequence.
//            At any index 'i', the length of bitonic subsequence will be dp1[i] + dp2[i] - 1 (for the common peak element).
//            Return the largest such value.

// ● Illustration:
//   nums arr = [1, 11, 2, 10, 4, 5, 2, 1]
//   dp1 arr =  [1, 2,  2, 3,  3, 4, 2, 1]   // lengths of LIS from left to right
//   dp2 arr =  [1, 5,  2, 4,  3, 3, 2, 1]   // lengths of LIS from right to left
//   Now lets say at index 4, dp1 value is 3 and dp2 value is 3. It means there are 3 elements in increasing slope (peak
//   included), and 3 elements in decreasing slope (peak included). Hence, the bitonic subsequence at index 4 will have
//   elements of both the slopes, i.e., dp1[4] + dp2[4] - 1 (for counting common peak element only once) = 3 + 3 - 1 = 5.
//   Now find the largest such value and you will find the largest value exists at index 1, 3 and 5, which is 6.

// VERY IMPORTANT NOTE: The above illustration is considering that a strictly increasing or decreasing slope can also
//                      be considered as a bitonic slope.
//                      But in some problems, they may not consider a subsequence as bitonic if it has only increasing
//                      or only decreasing slope, and this is that problem only. Thus, we have to add an extra condition.
//                      Count the length of bitonic subsequence only when both dp1[i] and dp2[i] are greater than 1.
//                      This ensures that index 'i' is 
//                      Example:
//                      nums =    [1, 4, 5, 2, 7, 8, 9]
//                      dp1 =     [1, 2, 3, 2, 4, 5, 6]
//                      dp2 =     [1, 2, 2, 1, 1, 1, 1]
//                      bitonic = [1, 3, 4, 3, 4, 5, 6]
//                      In this example, we can see that longest bitonic subsequence is 6 + 1 - 1 = 6.
//                      But in this problem, as bitonic subsequence will be only considered if it has both increasing
//                      and decreasing slopes, we have to consider dp1[i] and dp2[i] only when both are greater than 1;
//                      because when both are greater than 1, it means the peak 'i' has both increasing and decreasing
//                      slopes, and hence, it can be considered as a bitonic subsequence.
//                      Thus, the final bitonic subsequence computed for this example will be: 4


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(n)
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);

        for(int i = 1; i < n; i++) {   // 'i' represents the current element
            for(int j = 0; j < i; j++) {   // 'j' represents all elements towards left of 'i'
                if(nums[i] > nums[j]) {
                    // Update dp1[i] only if a larger value is supposed to be computed from '1 + dp1[j]'
                    if(1 + dp1[j] > dp1[i]) {
                        dp1[i] = 1 + dp1[j];
                    }
                }
            }
        }

        for(int i = n - 2; i >= 0; i--) {   // 'i' represents the current element
            for(int j = n - 1; j > i; j--) {   // 'j' represents all elements towards right of 'i'
                if(nums[i] > nums[j]) {
                    // Update dp2[i] only if a larger value is supposed to be computed from '1 + dp2[j]'
                    if(1 + dp2[j] > dp2[i]) {
                        dp2[i] = 1 + dp2[j];
                    }
                }
            }
        }

        // for(auto it: dp2) cout << it << " ";
        // cout << endl;

        // If both increasing or decreasing slope exists, then only bitonic subsequence is valid. Thus, add the
        // additional condition 'if(dp1[i] > 1 && dp2[i] > 1)'.
        int longestBitonicSubsequence = 0;
        for(int i = 0; i < n; i++) {
            if(dp1[i] > 1 && dp2[i] > 1) longestBitonicSubsequence = max(longestBitonicSubsequence, dp1[i] + dp2[i] - 1);
        }
        return longestBitonicSubsequence;
    }
};

int main() {
    // vector<int> nums = {1, 2, 5, 3, 2};
    vector<int> nums = {1, 4, 5, 2, 7, 8, 9};
    int n = nums.size();

    cout << Solution().LongestBitonicSequence(n, nums);

    return 0;
}
