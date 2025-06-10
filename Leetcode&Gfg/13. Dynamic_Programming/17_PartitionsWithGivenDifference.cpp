// GFG: Partitions with Given Difference   --->   Given an array arr[], partition it into two subsets(possibly empty)
// such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1
// and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and
// the difference between sum1 and sum2 is equal to d. 

// Example 1:
// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference
// between subset sum is: (6 + 4) - (5 + 2) = 3.

// Example 2:
// Input: arr[] = [1, 1, 1, 1], d = 0 
// Output: 6 
// Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and
// remaning two 1's in sum2. Thus there are total 6 ways for partition the array arr. 

// Example 3:
// Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
// Output: 2

// Constraint:
// 1 <= arr.size() <= 50
// 0 <= d  <= 50
// 0 <= arr[i] <= 6

// Problem link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

// Algorithm: Very simple. It is just a variant of 'Leetcode&Gfg\13. Dynamic_Programming\16_PerfectSumProblem.cpp'.
//            We are asked to find the number of such dual partitions from the array, such that the partition 's1'
//            minus the partition 's2' is equal to 'd'.
//            We know that s1 + s2 = sum.
//                      => s1 = sum - s2
//                      According to the problem, s1 - s2 = d,   where s1 > s2
//                      Substituting the value of s1 in the above equation, we get: sum - s2 - s2 = d
//                                                                               => sum - d = 2 * s2
//                                                                               => s2 = (sum - d) / 2
//            Hence, the number of subsets in the array whose sum equals 's2' is the number of ways in which we
//            can partition the arrays into two halves such that their difference is 'd'.
//            Thus, the problem boils down to find the number of subsets in the array which sums up to '(sum - d) / 2'.
//            The two edge cases to handle here is:
//            1) If 'sum - d' is negative, 's2' becomes negative. And 's2' is sum of some positive integers which
//               can never be negative. Thus, return 0 stating that partitions are not possible.
//            2) If 'sum - d' is odd, 's2' becomes fractional which is not possible, as 's2' is sum of some positive
//               integers which can never be fractional. Thus, return 0 stating that partitions are not possible.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 'Leetcode&Gfg\13. Dynamic_Programming\16_PerfectSumProblem.cpp' code:
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

public:
    // T.C: O(n * target);   where target = (d + sum) / 2
    // S.C: O(target)
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        if(sum - d < 0 || (sum - d) & 1) return 0;

        return perfectSum_tabulation_SO(arr, (sum - d) / 2);
    }
};

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;

    cout << Solution().countPartitions(arr, d);

    return 0;
}
