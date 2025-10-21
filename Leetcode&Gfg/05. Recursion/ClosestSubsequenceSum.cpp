// Leetcode: 1755. Closest Subsequence Sum   --->   You are given an integer array nums and an integer goal.
// You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is,
// if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
// Return the minimum possible value of abs(sum - goal).
// Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

// Example 1:
// Input: nums = [5,-7,3,5], goal = 6
// Output: 0
// Explanation: Choose the whole array as a subsequence, with a sum of 6.
// This is equal to the goal, so the absolute difference is 0.

// Example 2:
// Input: nums = [7,-9,15,-2], goal = -5
// Output: 1
// Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
// The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

// Example 3:
// Input: nums = [1,2,3], goal = -7
// Output: 7

// Bruteforce Approach: The brute force approach is very simple. Just find all subsets of the array and calculate their sums.
//                      The absolute difference between the sum of each subset and the goal is calculated, and the
//                      minimum absolute difference is returned.

// Optimal Approach: The optimal approach is to use the meet in the middle (MITM) algorithm. The idea
//                   is to split the array into two halves, find all possible subset sums for each half, and then
//                   use binary search to find the closest sum to the goal in the combined sums of both halves.
//                   The steps are as follows:
//                   1) Split the array into two halves.
//                   2) Find all possible subset sums for each half.
//                   3) Sort the subset sums of the second half.
//                   4) For each subset sum in the first half, use binary search to find the closest sum in the second half
//                      that, when added to the first half's sum, is closest to the goal.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 'BaseBuildingPrograms\09. Recursion_I\17_AllSubsequencesOfArray.cpp' code:
    void subsetGenerator(int index, vector<int>& arr, int n, vector<int>& ds, vector<vector<int>>& ans) {
        // Base case: If we reach beyond the last element of 'arr', the subsequence is already built in 'ds'. Print it.
        if(index == n) {
            ans.push_back(ds);
            return;
        }

        // Case 1: Take the current element of 'arr' and proceed to make the subsequence
        ds.push_back(arr[index]);
        subsetGenerator(index + 1, arr, n, ds, ans);
        ds.pop_back();

        // Case 2: Not take the current element of 'arr' and proceed to make the subsequence
        subsetGenerator(index + 1, arr, n, ds, ans);
    }
    
    vector<vector<int>> findSubsets(vector<int>& arr) {
        int n = arr.size();
        vector<int> ds;   // helper data structure to store a subset of 'arr' at a time
        vector<vector<int>> ans;   // stores all subsets of 'arr'
        subsetGenerator(0, arr, n, ds, ans);
        return ans;
    }

    // T.C: O(2^n * n);   2^n subsets and each subset can take O(n) time to calculate its sum, where n = nums.size()
    // S.C: O(2^n);   to store all subsets of 'nums'
    int minAbsDifference_bruteforce(vector<int>& nums, int goal) {
        vector<vector<int>> subsets = findSubsets(nums);

        int diff = INT_MAX;
        for(int i = 0; i < subsets.size(); i++) {
            int setSum = 0;
            for(int j = 0; j < subsets[i].size(); j++) {
                setSum += subsets[i][j];
            }
            diff = min(diff, abs(setSum - goal));
        }

        return diff;
    }

// -------------------------------------------------------------------------------------------------------------------

    // Helper function to find all possible subset sums for a given array
    void findSubsetSums(vector<int>& arr, int index, int n, vector<int>& subsetSums, int currentSum) {
        // Base case: If we reach beyond the last element of 'arr', add the current sum to the subset sums
        if(index == n) {
            subsetSums.push_back(currentSum);
            return;
        }

        // Case 1: Include the current element in the sum
        findSubsetSums(arr, index + 1, n, subsetSums, currentSum + arr[index]);

        // Case 2: Exclude the current element from the sum
        findSubsetSums(arr, index + 1, n, subsetSums, currentSum);
    }

    // T.C: O(2^n * log(2^n));   2^n subsets and each subset can take O(log(2^n)) time to calculate its sum, where n = nums.size()
    // S.C: O(2^n);   to store all subsets of 'nums'
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> leftSubset, rightSubset;

        // Segregate the array into two halves
        for(int i = 0; i < n / 2; i++) {
            leftSubset.push_back(nums[i]);
        }
        for(int i = n / 2; i < n; i++) {
            rightSubset.push_back(nums[i]);
        }

        // Generate all possible subset sums for the left half and right half
        vector<int> leftSubsetSums, rightSubsetSums;
        findSubsetSums(leftSubset, 0, leftSubset.size(), leftSubsetSums, 0);
        findSubsetSums(rightSubset, 0, rightSubset.size(), rightSubsetSums, 0);

        // Sort the right subset sums for binary search
        sort(rightSubsetSums.begin(), rightSubsetSums.end());

        int minDiff = INT_MAX;
        // For each subset sum in the left half, find the closest sum in the right half
        // that, when added to the left half's sum, is closest to the goal
        for(int i = 0; i < leftSubsetSums.size(); i++) {
            int leftSum = leftSubsetSums[i];

            int low = 0, high = rightSubsetSums.size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int sum = leftSum + rightSubsetSums[mid];
                minDiff = min(minDiff, abs(sum - goal));

                if(minDiff == 0) {
                    return 0;   // early exit if we find an exact match
                }

                // Adjust the binary search bounds based on the current sum
                if(sum < goal) {
                    low = mid + 1;   // move to the right half
                } else {
                    high = mid - 1;   // move to the left half
                }
            }
        }

        return minDiff;   // return the minimum absolute difference found
    }
};


int main() {
    vector<int> nums = {5, -7, 3, 5};
    int goal = 6;

    cout << Solution().minAbsDifference_bruteforce(nums, goal)<< endl;
    cout << Solution().minAbsDifference(nums, goal);

    return 0;
}
