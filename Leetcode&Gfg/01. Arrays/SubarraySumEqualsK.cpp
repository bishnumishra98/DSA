// Leetcode: 560. Subarray Sum Equals K   --->   Given an array of integers nums and an integer k, return the total
// number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

// Algorithm: Approach is somewhat similar to the algorithm of 'Leetcode&Gfg\01. Arrays\LongestSubarrayWithSumK.cpp'.
// 1. Initialize a hashmap that stores prefixSum till all indexes of the given 'arr', and frequency of prefixSum.
//    Also initialize a count variable to store the count of subarrays having sum 'k'.
//    The prefixSum is the sum of all elements from the start of the array till the current index. Here, we will
//    store the first element in the hashmap always as 0, with frequency 1, meaning that the sum of elements before
//    the first element is 0, and it occurs once.
// 2. Iterate through the entire array, and at any random index, if prefixSum is 'x', and we are looking for 
//    sum of elements as 'k', then we must look for sum of 'x - k' till some index before the current index.
//    If (x - k) exists, then it means sum of elements having value 'k' is also bound to exist till the
//    current index. In this case, we can add the frequency of (x - k) to the count of subarrays having sum 'k'.
//    Then update the frequency of the prefixSum in the hashmap. If the prefixSum occurs first time, its frequency
//    should be 1. And if it occurs again, its frequency shall increased by 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Similar to optimised brute force of 'Leetcode&Gfg\01. Arrays\LongestSubarrayWithSumK.cpp'.
    // T.C: O(n^2)
    // S.C: O(1)
    int subarraySum_bruteforce(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }

// ----------------------------------------------------------------------------------------------------

    // T.C: O(n)
    // S.C: O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;   // {prefixSum -> frequency}
        mp[0] = 1;
        int preSum = 0, count = 0;

        for(int i = 0; i < n; i++) {
            preSum += nums[i];
            int complement = preSum - k;
            count += mp[complement];
            mp[preSum] += 1;   // Keep this line at the end. Otherwise you will get wrong output for test cases like nums = {1}, k = 0.
        }

        return count;
    }
};


int main() {
    vector<int> nums = {1};
    int k = 0;

    cout << Solution().subarraySum_bruteforce(nums, k) << endl;
    cout << Solution().subarraySum(nums, k);

    return 0;
}
