// Leetcode: 643. Maximum Average Subarray I   --->   You are given an integer array nums consisting of n elements,
// and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
// Any answer with a calculation error less than 10^-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2 pointer approach
    // T.C: O((n - k) * k) = O(n * k);   O(n - k) for outer loop, and O(k) for inner loop
    // S.C: O(1)
    double findMaxAverage_bruteforce(vector<int>& nums, int k) {
        int i = 0, j = k - 1;   // i and j surround the range of first k elements in 'nums'
        int maxSum = INT_MIN;

        while(j < nums.size()) {
            int sum = 0;
            for(int x = i; x <= j; x++) {
                sum = sum + nums[x];
            }
            maxSum = max(maxSum, sum);
            // Move pointers to check next k elements in 'nums'
            i++;
            j++;
        }

        double avg = (double)maxSum / k;
        return avg;
    }

// -------------------------------------------------------------------------------------------

    // Sliding window technique (just subtract and add one element in the window at a time; calculate sum and update maxSum if needed)
    // T.C: O(k + (n - k)) = O(n)
    // S.C: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxSum = INT_MIN;

        // Calculate sum of first k elements
        for(int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }
        maxSum = max(maxSum, sum);   // update maxSum

        // Now slide the window: subtract and add one element in the window at a time; calculate sum and update maxSum if needed.
        int i = 0, j = k;
        while(j < nums.size()) {
            sum = sum - nums[i];
            sum = sum + nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j++;
        }

        double avg = (double)maxSum / k;
        return avg;
    }
};


int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << Solution().findMaxAverage_bruteforce(nums, k) << endl;
    cout << Solution().findMaxAverage(nums, k);

    return 0;
}
