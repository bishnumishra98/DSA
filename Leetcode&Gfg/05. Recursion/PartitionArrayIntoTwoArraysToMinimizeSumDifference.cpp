// Leetcode: 2035. Partition Array Into Two Arrays To Minimize Sum Difference   --->   You are given an integer array
    // 
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


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper function to generate all subset sums of a given array
    void generateSubsetSums(const vector<int>& arr, vector<vector<int>>& subsetSums) {
        int n = arr.size();
        int totalSubsets = pow(2, n); // Total subsets = 2^n

        for (int mask = 0; mask < totalSubsets; ++mask) {
            int sum = 0, count = 0;
            int temp = mask;
            for (int i = 0; i < n; ++i) {
                if (temp % 2 == 1) {
                    sum += arr[i];
                    count++;
                }
                temp /= 2;
            }
            subsetSums[count].push_back(sum);
        }
    }

    // Manual binary search to find lower_bound (index of first element >= target)
    int binarySearchLowerBound(const vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    // Helper function to find the minimum difference using two subset sums
    int findMinimumDifference(vector<int>& sum1, vector<int>& sum2, int totalSum) {
        int minDiff = INT_MAX;

        for (int x : sum1) {
            int target = totalSum / 2 - x;

            int idx = binarySearchLowerBound(sum2, target);

            // Check the closest higher value
            if (idx < sum2.size()) {
                int sum1Part = x + sum2[idx];
                int sum2Part = totalSum - sum1Part;
                minDiff = min(minDiff, abs(sum1Part - sum2Part));
            }

            // Check the closest lower value
            if (idx > 0) {
                int sum1Part = x + sum2[idx - 1];
                int sum2Part = totalSum - sum1Part;
                minDiff = min(minDiff, abs(sum1Part - sum2Part));
            }
        }

        return minDiff;
    }

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Split nums into two halves
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Generate all subset sums for each half
        vector<vector<int>> subsetSumsLeft(n + 1), subsetSumsRight(n + 1);
        generateSubsetSums(left, subsetSumsLeft);
        generateSubsetSums(right, subsetSumsRight);

        // Sort subset sums for efficient manual binary search
        for (auto& sums : subsetSumsRight) {
            sort(sums.begin(), sums.end());
        }

        // Find the minimum absolute difference
        int minDiff = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            minDiff = min(minDiff, findMinimumDifference(subsetSumsLeft[i], subsetSumsRight[n - i], totalSum));
        }

        return minDiff;
    }
};


int main() {
    vector<int> nums = {3, 9, 7, 3};
    Solution sol;
    cout << sol.minimumDifference(nums) << endl;
    return 0;
}
