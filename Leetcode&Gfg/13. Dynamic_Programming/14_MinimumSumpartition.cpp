// Note: This problem looks similar to 'Leetcode&Gfg\05. Recursion\PartitionArrayIntoTwoArraysToMinimizeSumDifference.cpp',
//       but is slightly different. In that problem we were asked to partition the array in two equal lengths.
//       But here the array partitions can be of any length, i.e., the two partitions can contain unequal elements.
//       But the irony is, the solution for this problem is way too easier to understand than that one.

// GFG: Minimum sum partition   --->   Given an array arr[]  containing non-negative integers, the task is to
// divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and
// find the minimum difference.

// Example 1:
// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.

// Example 2:
// Input: arr[] = [1, 4]
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4
// Hence, minimum difference is 3.

// Example 3:
// Input: arr[] = [1]
// Output: 1
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {}, sum of Subset2 = 0
// Hence, minimum difference is 1.

// Problem link: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// Algorithm: The algorithm is based on 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp'.
//            The algorithm is very simple. The tabulation table in the SubsetSumProblem.cpp problem gave us
//            whether a target sum is achievable to be made within an index 'i', which was represented by
//            dp[i][target]. Meaning, if dp[3][4] was true, it meant that we can achieve a target sum of 4
//            within the index 0 to 3 of the array. Similarly, if dp[3][4] was false, it meant that we cannot
//            achieve the target sum of 4 within the index 0 to 3.

//            Now in this problem, we are asked to find partitions say 's1' and 's2', such that |s1 - s2| is least.
//            We know that s1 + s2 = sum, so if the sum of all elements of the entire array is 'sum', then the
//            least value of the partion 's1' can be 0, the case when we choose to keep no elements in this partition.
//            And, the largest value of 's1' can be 'sum', the case when we choose to keep all elements in this partition.
//            To find out the actual possible values of 's1' from '0' to 'sum', just check which values of dp[n - 1][j]
//            are true, where n is the no.of elements of the array and j ranges from 0 to 'sum'.
//            The values of 'j' for which dp[n - 1][j] are true are the actual possible sums of elements of the array,
//            i.e., possible values of 's1'. Similarly, corresponding 's2' will be always 'sum - s1' obviously.
//            Then compute the absolute differences of s1 and s2 and return the least difference amongst them.

//            Example: For the array = {2, 3, 5}, the sum of all elements will be 10. Hence, a 2D dp array of
//            size 3 * (10 + 1) will be created for tabulation.
//            Hence, for the last row (dp[2][j]), j values will be: 0   1   2   3   4   5   6   7   8   9   10
//            and the corresponding dp[2][j] values will be:        T   F   T   T   F   T   F   T   T   F   T
//            It means that the partition 's1' can have values:     0,   2,   3,   5,   7,   8,  10.
//            And as we know, s2 = sum - s1, 's2' values will be:   10,  8,   7,   5,   3,   2,   0.
//            And their corresponding absolute differences will be: 10,  6,   4,   0,   4,   6,  10.
//            At last, choose the minimum absolute difference (0 in this example) and return it.

//            Optimization tip: No need to traverse 'j' from 0 to 10, as after the 5th index, 's2' values will be
//                              nothing but mirror of 's1'. Hence, we can only check the values of dp[2][j] from
//                              0 to 'sum / 2'th index only, and assign possible values of 's1' from this range.
//                              And its common sense also, that if s1 + s2 = sum, then maximum value of s1 for which
//                              s1 - s2 will be 0, is obviously sum / 2.
//                              Thus, we will find the required least absolute difference in this range only.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // T.C: O(n * sum)
    // S.C: O(n * sum)
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];

        // 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp' code:
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]]= true;

        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
                dp[i][target] = take || notTake;
            }
        }

        // Compute the possible values of 's1' and 's2' and find the least difference between them.
        int minDiff = INT_MAX;
        for(int j = 0; j <= sum / 2; j++) {
            if(dp[n - 1][j]) {
                int s1 = j;
                int s2 = sum - s1;
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }

        return minDiff;
    }

// ---------------------------------------------------------------------------------------------------

    // T.C: O(n * sum)
    // S.C: O(sum)
    int minDifference_SO(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];

        // 'Leetcode&Gfg\13. Dynamic_Programming\13_SubsetSumProblem.cpp' code:
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);
        prev[0] = curr[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        // Compute the possible values of 's1' and 's2' and find the least difference between them.
        int minDiff = INT_MAX;
        for(int j = 0; j <= sum / 2; j++) {
            if(prev[j]) {
                int s1 = j;
                int s2 = sum - s1;
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }

        return minDiff;
    }
};


int main() {
    vector<int> arr = {1, 6, 11, 5};
    
    cout << Solution().minDifference(arr) << endl;
    cout << Solution().minDifference_SO(arr);

    return 0;
}
