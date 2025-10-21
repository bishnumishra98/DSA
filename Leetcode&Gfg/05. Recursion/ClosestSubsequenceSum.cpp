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

// Bruteforce Approach: The brute force approach is very simple. Just find all subsets of the array and their respective sums.
//                      Then, calculate the absolute difference between each subset sum and the goal, and keep track of the
//                      minimum difference found.

// Optimal Approach: Same as brute force, but here we will split the array into two halves to reduce the time complexity.
//                   The optimal approach is to use the meet in the middle (MITM) algorithm. The idea
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
private:
    // Helper function to find all possible subset sums for a given array
    void findSubsetSums(int index, vector<int>& arr, vector<int>& subsetSums, int currentSum) {
        // Base case: If we reach beyond the last element of 'arr', add the current sum to the subsetSums
        if(index == arr.size()) {
            subsetSums.push_back(currentSum);
            return;
        }

        // Case 1: Include the current element in the sum
        findSubsetSums(index + 1, arr, subsetSums, currentSum + arr[index]);

        // Case 2: Exclude the current element from the sum
        findSubsetSums(index + 1, arr, subsetSums, currentSum);
    }

public:
    // T.C: O(2^n) for all subsetSum generation + O(2^n) for finding min difference = O(2^n)
    // S.C: O(2^n) to store all subsets of 'nums' + O(n) for recursion stack space = O(2^n)
    int minAbsDifference_bruteforce(vector<int>& nums, int goal) {
        vector<int> subsetSums;
        findSubsetSums(0, nums, subsetSums, 0);

        int minDiff = INT_MAX;
        for(int i = 0; i < subsetSums.size(); i++) {
            int subsetSum = subsetSums[i];
            int diff = abs(subsetSum - goal);
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }

// -------------------------------------------------------------------------------------------------------------------

    // T.C: O(2^(n/2)) + O(2^(n/2)) ≈ O(2^(n/2)) for subset sum generation 
    //      + O(2^(n/2) * log(2^(n/2))) for sorting 
    //      + O(2^(n/2) * log(2^(n/2))) for binary search 
    //      = O(2^(n/2) * (n/2) * log(2))
    //      = O(n * 2^(n/2));   because log(2) is a constant ≈ 0.693, so (n/2) * log(2) can be approximated as O(n)
    // S.C: O(2^(n/2)) for storing subset sums of both halves 
    //      + O(n) for recursion stack
    //      = O(2^(n/2))
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
        findSubsetSums(0, leftSubset, leftSubsetSums, 0);
        findSubsetSums(0, rightSubset, rightSubsetSums, 0);

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
