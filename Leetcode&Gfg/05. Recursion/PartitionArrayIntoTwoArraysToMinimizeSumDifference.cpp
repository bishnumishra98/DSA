// Leetcode: 2035. Partition Array Into Two Arrays To Minimize Sum Difference   --->   You are given an integer array
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

// Algorithm: The algorithm uses the meet in the middle (MITM) approach to solve the problem.
//             The idea is to split the array into two halves, find all possible subset sums for each half, and then
//             use binary search to find the closest sum to totalSum / 2 in the combined sums of both halves.
// 1. Split the array into two halves.
// 2. Generate all possible subset sums for each half and store them in a 2D vector. The index of the vector represents
//    the number of elements in the subset. For example, for an array of size 3, lets say arr = [2, 4, -1] the vector will
//    have 4 indices:
//    subsetSums[0] = [0]              // sums of all subsets of size 0 (empty subset)
//    subsetSums[1] = [-1, 4, 2]       // sums of all subsets of size 1
//    subsetSums[2] = [3, 1, 6]        // sums of all subsets of size 2
//    subsetSums[3] = [5]              // sums of all subsets of size 3
// 3. Sort the subset sums of the second half for efficient binary search.
// 4. For each subset sum in the first half, use binary search to find the closest sum in the second half that,
//    when added to the first half's sum, is closest to totalSum / 2.
// 5. Calculate the absolute difference between the two resulting partition sums and return the minimum absolute difference.


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper function to generate all subset sums of a given array. It stores the sums in a 2D vector
    // where the index represents the number of elements in the subset.
    void generateSubsetSums(const vector<int>& arr, vector<vector<int>>& subsetSums) {
        int n = arr.size();
        int totalSubsets = 1 << n;   // same as pow(2, n)

        // Iterate through all possible subsets using bit masking
        for (int mask = 0; mask < totalSubsets; mask++) {
            int sum = 0, count = 0;

            // Iterate through each bit of the mask and check if ith bit is set, then include arr[i] in the sum
            // and increment the count of elements in the subset. Exaple:-
            // For array of size 3, the masks will be:
            // 000 -> empty subset (sum = 0, count = 0)
            // 001 -> subset with only arr[0] (sum = arr[0], count = 1)
            // 010 -> subset with only arr[1] (sum = arr[1], count = 1)
            // 011 -> subset with arr[0] and arr[1] (sum = arr[0] + arr[1], count = 2)
            // 100 -> subset with only arr[2] (sum = arr[2], count = 1)
            // 101 -> subset with arr[0] and arr[2] (sum = arr[0] + arr[2], count = 2)
            // 110 -> subset with arr[1] and arr[2] (sum = arr[1] + arr[2], count = 2)
            // 111 -> subset with all elements (sum = arr[0] + arr[1] + arr[2], count = 3)
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {   // check if i-th bit is set
                    sum += arr[i];
                    count++;
                }
            }

            subsetSums[count].push_back(sum);   // store the sum in the corresponding count index
        }
    }

    // Manual binary search to find lower_bound (index of first element >= target)
    int binarySearchLowerBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;   // when loop exits, 'low' is the index of the first element >= target
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
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() / 2;

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
            // The findMinimumDifference() function takes all subset sums of size i from subsetSumsLeft, and all subset sums
            // of size (n - i) from subsetSumsRight, then finds the pair whose combined sum is closest to totalSum / 2,
            // and returns the minimum absolute difference between the two resulting partition sums.
            minDiff = min(minDiff, findMinimumDifference(subsetSumsLeft[i], subsetSumsRight[n - i], totalSum));
        }

        return minDiff;
    }
};


int main() {
    vector<int> nums = {3, 9, 7, 3};

    Solution sol;
    cout << sol.minimumDifference(nums);

    return 0;
}
