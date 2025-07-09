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

// Algorithm: It is just an easy extension of the problem 'BaseBuildingPrograms\21. Dynamic_Programming\DP04_FindLongestIncreasingSubsequence.cpp'.
//            The length of LIS of the given 'nums' array is given by the value of the largest dp element.
//            But here, we are asked to find the number of LIS. To find so, we will initialize one more array with all
//            elements as 1, of size 'n', where n = nums.size(), and name it let's say 'count'.
//            An element of 'count' array, count[i] tells the number of LIS that can be formed with the element
//            nums[i] as the last element of the LIS.
//            In the LIS code, if(nums[i] > nums[j]), we wrote 'if(1 + dp[j] > dp[i]) dp[i] = 1 + dp[j]', it means
//            if dp[i] gets updated, a longer length of LIS is formed, i.e., a new subsequence is found.
//            Now for any further values of j, if '1 + dp[j]' comes out to be equal to 'dp[i]', it means again
//            a new subsequence is found which is also of same length as LIS. It means one more LIS is found.
//            Thus, in this case increase the count at index 'i', stating that there are 2 LIS which ends at
//            index 'i' or you can say there are 2 LIS with the element nums[i] as the last element of the LIS.
//            Now for any further values of j, again if '1 + dp[j]' comes out to be equal to 'dp[i]', it means
//            one more LIS is found that ends with nums[i] as last element of LIS. Hence, again increment count[i],
//            and repeat the process until the last value of j (which is the index just on the left of i), and
//            then move to next ith index, i.e., next current element.
//            Finally, when dp and count arrays have been computed, just find the length of LIS, i.e., the largest
//            dp element. And return the count value at the same index. If there are multiple largest dp elements,
//            return the sum of their count values at corresponding indexes.

// ● Illustration:
//   input 'nums' = [1, 3, 5, 8, 4, 7]
//   dp array =     [1, 2, 3, 4, 3, 4]
//   count array =  [1, 1, 1, 1, 1, 2]
//   Largest dp element is 4. So check their corresponding count vlaues.
//   count[3] tells that the number of LIS that ends at index 3 is 1, i.e., {1, 3, 5, 8}.
//   count[5] tells that the number of LIS that ends at index 5 is 2, i.e., {1, 3, 5, 7} and {1, 3, 4, 7}.
//   Thus, total number of LIS = count[3] + count[5] = 1 + 2 = 3.


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

        return numberOfLIS;
    }
};

int main() {
    // vector<int> nums = {1, 3, 5, 4, 7};
    vector<int> nums = {1, 3, 5, 8, 4, 7};

    cout << Solution().findNumberOfLIS(nums);

    return 0;
}
