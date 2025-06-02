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


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsetSums(vector<int>& arr, int index, int currentSum, int count, vector<pair<int, int>>& sums) {
        if (index == arr.size()) {
            sums.push_back({currentSum, count});
            return;
        }
        // Include the current element in the subset
        generateSubsetSums(arr, index + 1, currentSum + arr[index], count + 1, sums);
        // Exclude the current element from the subset
        generateSubsetSums(arr, index + 1, currentSum, count, sums);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Generate subset sums along with their counts for the left and right halves
        vector<pair<int, int>> leftSums, rightSums;
        generateSubsetSums(left, 0, 0, 0, leftSums);
        generateSubsetSums(right, 0, 0, 0, rightSums);

        // Organize rightSums by count
        unordered_map<int, vector<int>> rightMap;
        for (int i = 0; i < rightSums.size(); i++) {
            int sum = rightSums[i].first;
            int count = rightSums[i].second;
            rightMap[count].push_back(sum);
        }


        // Sort each subset in rightMap for binary search
        for (auto it = rightMap.begin(); it != rightMap.end(); ++it) {
            vector<int>& vec = it->second;
            sort(vec.begin(), vec.end());
        }


        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int minDiff = INT_MAX;

        // For each sum in leftSums, find the closest match in rightSums with equal subset size
        for (auto it = leftSums.begin(); it != leftSums.end(); ++it) {
            int sumLeft = it->first;
            int countLeft = it->second;

            if (rightMap.find(n - countLeft) == rightMap.end()) {
                continue;
            }

            vector<int>& rightSubset = rightMap[n - countLeft];
            int requiredSum = totalSum / 2 - sumLeft;

            // Perform binary search for the closest sum in rightSubset
            int low = 0, high = rightSubset.size() - 1, closestIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (rightSubset[mid] >= requiredSum) {
                    closestIndex = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Check the closest sum found by binary search
            if (closestIndex != -1) {
                int sum1 = sumLeft + rightSubset[closestIndex];
                int sum2 = totalSum - sum1;
                minDiff = min(minDiff, abs(sum1 - sum2));
            }

            // Check the previous sum if available (to ensure closest match)
            if (closestIndex > 0) {
                int sum1 = sumLeft + rightSubset[closestIndex - 1];
                int sum2 = totalSum - sum1;
                minDiff = min(minDiff, abs(sum1 - sum2));
            }
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
